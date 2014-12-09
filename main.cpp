/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QApplication>

#include "snowscreen.h"
#include "Config/dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(Screensaver::getType() == Screensaver::CONFIG || Screensaver::getType() == Screensaver::UNKNOW)
    {
        SnowScreen::Config::Dialog config;
        config.show();
        return a.exec();
    }
    else
    {
        SnowScreen::SnowScreen screensaver;
        screensaver.showScreensaver();
        return a.exec();
    }


}
