/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#include "snowscreen.h"

namespace SnowScreen {

    QSettings* SnowScreen::_getSettings()
    {
        static QSettings settings("Christopher Gundler", "SnowScreen");
        return &settings;
    }

    SnowScreen::SnowScreen() : Screensaver()
    {
        qsrand(QTime::currentTime().msec()); //Enable random
    }

    QGraphicsScene* SnowScreen::getGUI(const QSize& renderArea, bool isPreview)
    {
        GUI::SnowStorm* storm = new GUI::SnowStorm(renderArea, this->loadRandomSnowflakes(), this->loadMaxSize(), this->loadSpeed(), this);
        if(isPreview)
        {
            //Show preview...
            GUI::SnowFlake* tmp = storm->spawnSnow(false);
            tmp->setPos(renderArea.width() / 2 - tmp->getSize().width() / 2, renderArea.height() / 2 - tmp->getSize().height() / 2);
        }
        else
            storm->spawnSnow(this->loadNumberOfSnowflakes());

        return storm;
    }

    void SnowScreen::setSpeed(qreal speed)
    {
        SnowScreen::_getSettings()->setValue("speed", speed);
    }

    void SnowScreen::setMaxSize(int maxSize)
    {
        SnowScreen::_getSettings()->setValue("size", maxSize);
    }

    void SnowScreen::setRandomSnowflakes(bool random)
    {
        SnowScreen::_getSettings()->setValue("random", random);
    }

    void SnowScreen::setNumberOfSnowflakes(uint number)
    {
        SnowScreen::_getSettings()->setValue("snowflakes", number);
    }

    qreal SnowScreen::loadSpeed()
    {
        bool ok;
        qreal speed = SnowScreen::_getSettings()->value("speed", 20000).toDouble(&ok);
        return ok ? speed : 20000;
    }

    int SnowScreen::loadMaxSize()
    {
        bool ok;
        int size = SnowScreen::_getSettings()->value("size", 4).toInt(&ok);
        return ok && size >= 1 ? size : 4;
    }

    bool SnowScreen::loadRandomSnowflakes()
    {
        return SnowScreen::_getSettings()->value("random", true).toBool();
    }

    uint SnowScreen::loadNumberOfSnowflakes()
    {
        bool ok;
        uint snowflakes = SnowScreen::_getSettings()->value("snowflakes", 8).toUInt(&ok);
        return ok ? snowflakes : 8;
    }
}
