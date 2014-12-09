/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#include "snowstorm.h"

namespace SnowScreen
{
    namespace GUI
    {
        SnowStorm::SnowStorm(const QSize& area, bool differentSnowflakeSizes, int maxSnowflakeSize, qreal speed, QObject* parent) : QGraphicsScene(parent),
            _renderArea(area),
            _differentSizes(differentSnowflakeSizes),
            _maxSize(maxSnowflakeSize),
            _speed(speed)
        {
            this->setSceneRect(0,0, area.width(), area.height());

            QLinearGradient background(QPointF(area.width() / 2, 0), QPointF(area.width() / 2, area.height()));
            background.setColorAt(0, QColor(255, 250, 250));
            background.setColorAt(1, QColor(135, 206, 250));
            this->setBackgroundBrush(QBrush(background));
        }

        void SnowStorm::spawnSnow(uint snowFlakes, uint delay)
        {
            for(uint i = 0; i < snowFlakes; ++i)
                QTimer::singleShot(i * delay, this, SLOT(spawnSnow()));
        }

        SnowFlake* SnowStorm::spawnSnow(bool start)
        {
            SnowFlake* target = new SnowFlake(_renderArea, _differentSizes, _maxSize);
            connect(target, &SnowFlake::fallen, this, &SnowStorm::_flakeFallen);
            this->addItem(target);
            if(start)
                target->start(_speed);
            return target;
        }

        void SnowStorm::_flakeFallen(SnowFlake* theFallen)
        {
            //Could use "QObject::sender()" instead, but this is bad style... ;)
            this->removeItem(theFallen);
            delete theFallen;
            this->spawnSnow();
        }
    }
}
