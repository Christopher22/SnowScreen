/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_GUI_SNOWFLAKE_H
#define SNOWSCREEN_GUI_SNOWFLAKE_H

#include <QGraphicsSvgItem>
#include <QSvgRenderer>
#include <QPropertyAnimation>

namespace SnowScreen
{
    namespace GUI
    {
        class SnowFlake : public QGraphicsSvgItem
        {
            Q_OBJECT

        private:
            static QSvgRenderer* _getSnowFlake();
            QPropertyAnimation* _moveAnim;
            qreal _exitPoint;

        private slots:
            inline void _isFallen()
            {
                emit this->fallen(this);
            }

        public:
            SnowFlake(const QSize& area, bool randomSize, int maxSize, QGraphicsItem* parent = 0);
            void start(qreal speed);
            QSize getSize() const;

        signals:
            void fallen(SnowFlake* flake);
        };
    }
}

#endif
