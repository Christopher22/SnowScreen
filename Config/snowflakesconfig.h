/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_CONFIG_SNOWFLAKESCONFIG_H
#define SNOWSCREEN_CONFIG_SNOWFLAKESCONFIG_H

#include "slider.h"

namespace SnowScreen
{
    namespace Config
    {
        class SnowflakesConfig : public Slider
        {
        public:
            SnowflakesConfig(QWidget& parent) : Slider(parent, tr("Snowflakes:"), 1, SnowScreen::loadNumberOfSnowflakes(), 16) {}

            inline void save() Q_DECL_OVERRIDE
            {
                SnowScreen::setNumberOfSnowflakes(_slider->value());
            }
        };
    }
}

#endif
