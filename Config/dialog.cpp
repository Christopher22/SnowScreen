/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#include "dialog.h"

namespace SnowScreen
{
    namespace Config
    {
        Dialog::Dialog(QWidget *parent) : QMainWindow(parent),
            _layout(new QFormLayout()),
            _speed(new SpeedConfig(*this)),
            _random(new RandomConfig(*this)),
            _size(new SizeConfig(*this)),
            _snowflakes(new SnowflakesConfig(*this)),
            _buttonSave(new QPushButton(tr("Save"), this))
        {
            this->setWindowTitle(tr("SnowScreen by Christopher Gundler"));

            _layout->addRow(_snowflakes->name(), _snowflakes);
            _layout->addRow(_size->name(), _size);
            _layout->addRow(_speed->name(), _speed);
            _layout->addRow(_random->name(), _random);
            _layout->addRow(tr("<i>Powered by Qt5</i>"), _buttonSave);

            connect(_buttonSave, &QPushButton::clicked, this, &Dialog::save);

            QWidget* layoutHolder = new QWidget(this);
            layoutHolder->setLayout(_layout);
            this->setCentralWidget(layoutHolder);

            this->resize(_layout->sizeHint().width() * 2, _layout->sizeHint().height()); //Increase width for better sliders
        }

        void Dialog::save()
        {
            _snowflakes->save();
            _size->save();
            _speed->save();
            _random->save();
            qApp->quit();
        }
    }
}
