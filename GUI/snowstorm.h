/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_GUI_SNOWSTORM_H
#define SNOWSCREEN_GUI_SNOWSTORM_H

#include <QGraphicsScene>
#include <QTimer>
#include <QBrush>

#include "snowflake.h"

namespace SnowScreen
{
    namespace GUI
    {
        class SnowStorm : public QGraphicsScene
        {
            Q_OBJECT

        private:
            const QSize _renderArea;
            bool _differentSizes;
            int _maxSize;
            qreal _speed;

        private slots:
            void _flakeFallen(SnowFlake* theFallen);

        public:
            SnowStorm(const QSize& area, bool differentSnowflakeSizes, int maxSnowflakeSize, qreal speed, QObject* parent = 0);
            void spawnSnow(uint snowFlakes, uint delay = 2000);

            Q_DECL_CONSTEXPR inline QSize renderArea() const
            {
                return _renderArea;
            }

            Q_DECL_CONSTEXPR inline int maxSnowflakeSize() const
            {
                return _maxSize;
            }

            Q_DECL_CONSTEXPR inline qreal speed() const
            {
                return _speed;
            }

            Q_DECL_CONSTEXPR inline bool differentSnowflakeSizes() const
            {
                return _differentSizes;
            }

            inline void setMaxSnowflakeSize(int value)
            {
                _maxSize = value;
            }

            inline void setSpeed(qreal speed)
            {
                _speed = speed;
            }

            inline void setDifferentSnowflakeSizes(bool differentSizes)
            {
                _differentSizes = differentSizes;
            }

        public slots:
            SnowFlake* spawnSnow(bool spawnSnow = true);
        };
    }
}
#endif // SNOWSTORM_H
