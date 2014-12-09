/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_CONFIG_SPEEDCONFIG_H
#define SNOWSCREEN_CONFIG_SPEEDCONFIG_H

#include "slider.h"

namespace SnowScreen
{
    namespace Config
    {
        class SpeedConfig : public Slider
        {
        public:
            SpeedConfig(QWidget& parent) : Slider(parent, tr("Speed:"), 5, SnowScreen::loadSpeed() / 1000, 35) {}

            inline void save() Q_DECL_OVERRIDE
            {
                SnowScreen::setSpeed(_slider->value() * 1000);
            }
        };
    }
}
#endif // SPEEDCONFIG_H
