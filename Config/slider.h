/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_CONFIG_CONFIGSLIDER_H
#define SNOWSCREEN_CONFIG_CONFIGSLIDER_H

#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>

#include "item.h"

namespace SnowScreen
{
    namespace Config
    {
        class Slider : public Item<QWidget>
        {
            Q_OBJECT

        private slots:
            inline void _updateValue(int value)
            {
                _value->setText(QString::number(value));
            }

        protected:
            QSlider* _slider;
            QLabel* _value;

        public:
            Slider(QWidget& parent, QString name, int min, int value, int max);
        };
    }
}

#endif
