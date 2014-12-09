/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_CONFIG_CONFIGDIALOG_H
#define SNOWSCREEN_CONFIG_CONFIGDIALOG_H

#include <QMainWindow>
#include <QFormLayout>
#include <QPushButton>

#include "speedconfig.h"
#include "randomconfig.h"
#include "sizeconfig.h"
#include "snowflakesconfig.h"

namespace SnowScreen
{
    namespace Config
    {
        class Dialog : public QMainWindow
        {
            Q_OBJECT

        private:
            QFormLayout* _layout;
            QPushButton* _buttonSave;

            SpeedConfig* _speed;
            SizeConfig* _size;
            SnowflakesConfig* _snowflakes;
            RandomConfig* _random;

        public:
            explicit Dialog(QWidget *parent = 0);

        public slots:
            void save();
        };
    }
}

#endif
