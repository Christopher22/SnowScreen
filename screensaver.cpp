/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#include "screensaver.h"

Screensaver::ScreensaverType Screensaver::getType()
{
    static int cache = -1;
    if(cache == -1)
    {
        QStringList args(qApp->arguments());

        if(args.contains("/s", Qt::CaseInsensitive))
            cache = (int)Screensaver::GUI;
        else if(args.indexOf(QRegExp("^\\/[cC](:[0-9]+)?$")) != -1)
            cache = (int)Screensaver::CONFIG;
        else
            cache = (int)args.indexOf(QRegExp("^\\/[pP](:[0-9]+)?$")) != -1 ? Screensaver::PREVIEW : Screensaver::UNKNOW;
    }

    return (ScreensaverType)cache;
}

Screensaver::Screensaver() : QGraphicsView()
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFrameShape(QGraphicsView::NoFrame);
    this->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing, true);
    this->setCacheMode(QGraphicsView::CacheBackground);

#ifdef USE_OPENGL
    QGLFormat fmt = QGLFormat::defaultFormat();
    fmt.setSampleBuffers(true);
    fmt.setDoubleBuffer(true);
    fmt.setSamples(256);
    fmt.setDirectRendering(true);
    this->setViewport(new QGLWidget(fmt));
#endif
}

void Screensaver::showScreensaver()
{
    if(Screensaver::getType() == Screensaver::PREVIEW)
    {
        QWidget* preview = this->getPreviewWindow();

        if(preview != Q_NULLPTR)
        {
            this->setParent(preview);
            this->setScene(this->getGUI(preview->size(), true));
            this->show();
        }
    }
    else
    {
        this->setCursor(Qt::BlankCursor);
        this->showFullScreen();
        this->setMouseTracking(true);

        QRectF size(this->mapToScene(this->viewport()->rect()).boundingRect());
        this->setScene(this->getGUI(QSize(size.width(), size.height()), false));
    }
}

QWidget* Screensaver::getPreviewWindow(QWidget* parent) const
{
    if(Screensaver::getType() != Screensaver::PREVIEW)
        return Q_NULLPTR;

    QStringList args = qApp->arguments();
    int position = args.indexOf(QRegExp("^\\/[pP](:[0-9]+)?$"));
    QString handleString(args.at(position).size() > 2 ? args.at(position).split(":")[1] : args.at(position + 1));

    bool ok = false;
    HWND handle = (HWND)(handleString.toUInt(&ok));
    if(!ok)
        return Q_NULLPTR;

    QWidget* tmp = new QWidget(parent);
    tmp->setAttribute(Qt::WA_PaintOnScreen);
    tmp->setAttribute(Qt::WA_NativeWindow);

    SetParent((HWND)tmp->winId(), handle);
    SetWindowLong((HWND)tmp->winId(), GWL_STYLE, WS_CHILDWINDOW|WS_VISIBLE);
    RECT parentRect;
    GetClientRect(handle,&parentRect);
    LONG width = parentRect.right - parentRect.left;
    LONG height = parentRect.bottom - parentRect.top;

    tmp->resize(width,height);
    tmp->move(0,0);
    tmp->show();
    return tmp;
}
