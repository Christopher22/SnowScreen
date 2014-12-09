/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_SNOWSCREEN_H
#define SNOWSCREEN_SNOWSCREEN_H

#include <QTime>
#include <QSettings>

#include "screensaver.h"
#include "./GUI/snowstorm.h"

namespace SnowScreen
{
    class SnowScreen : public Screensaver
    {
        Q_OBJECT

    private:
        static QSettings* _getSettings();

    public:
        static void setSpeed(qreal speed = 20000);
        static void setMaxSize(int maxSize = 4);
        static void setRandomSnowflakes(bool random = true);
        static void setNumberOfSnowflakes(uint number = 8);

        static qreal loadSpeed();
        static int loadMaxSize();
        static bool loadRandomSnowflakes();
        static uint loadNumberOfSnowflakes();

        explicit SnowScreen();
        QGraphicsScene* getGUI(const QSize& renderArea, bool isPreview) Q_DECL_OVERRIDE;
    };
}

#endif
