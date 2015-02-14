/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <QApplication>
#include <QGraphicsView>

#include <Windows.h>

#ifdef USE_OPENGL
#include <QGLFormat>
#include <QGLWidget>
#endif

class Screensaver : public QGraphicsView
{
public:
    enum ScreensaverType {
        GUI,
        PREVIEW,
        CONFIG,
        UNKNOW
    };

    static ScreensaverType getType();

    Screensaver();
    void showScreensaver();
    virtual QGraphicsScene* getGUI(const QSize& renderArea, bool isPreview) = 0;
    QWidget* getPreviewWindow(QWidget* parent = 0) const;

    inline void keyPressEvent(QKeyEvent *) Q_DECL_OVERRIDE
    {
        qApp->quit();
    }

    inline void mouseMoveEvent(QMouseEvent *) Q_DECL_OVERRIDE
    {
        static bool ready = false;
        if(ready)
            qApp->quit();
        else
            ready = true;

    }
};

#endif
