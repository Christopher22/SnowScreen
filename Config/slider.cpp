/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#include "slider.h"

namespace SnowScreen
{
    namespace Config
    {
        Slider::Slider(QWidget& parent, QString name, int min, int value, int max) : Item(parent, name),
            _slider(new QSlider(Qt::Horizontal, this)),
            _value(new QLabel(QString::number(value), this))
        {
            _slider->setMinimum(min);
            _slider->setValue(value);
            _slider->setMaximum(max);

            connect(_slider, &QSlider::valueChanged, this, &Slider::_updateValue);

            QHBoxLayout* layout = new QHBoxLayout(this);
            layout->addWidget(_slider);
            layout->addWidget(_value);
        }
    }
}
