/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_CONFIG_RANDOMCONFIG_H
#define SNOWSCREEN_CONFIG_RANDOMCONFIG_H

#include <QCheckBox>

#include "item.h"

namespace SnowScreen
{
    namespace Config
    {
        class RandomConfig : public Item<QCheckBox>
        {
        public:
            RandomConfig(QWidget& parent) : Item(parent, tr("Random sizes:"))
            {
                this->setChecked(SnowScreen::loadRandomSnowflakes());
            }

            inline void save() Q_DECL_OVERRIDE
            {
                SnowScreen::setRandomSnowflakes(this->isChecked());
            }
        };
    }
}

#endif
