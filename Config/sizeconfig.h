/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_CONFIG_SIZECONFIG_H
#define SNOWSCREEN_CONFIG_SIZECONFIG_H

#include "slider.h"

namespace SnowScreen
{
    namespace Config
    {
        class SizeConfig : public Slider
        {
        public:
            SizeConfig(QWidget& parent) : Slider(parent, tr("Size of snowflakes:"), 1, SnowScreen::loadMaxSize(), 8) {}

            inline void save() Q_DECL_OVERRIDE
            {
                SnowScreen::setMaxSize(_slider->value());
            }
        };
    }
}

#endif
