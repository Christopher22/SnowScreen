/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#include "snowflake.h"

namespace SnowScreen
{
    namespace GUI
    {
        QSvgRenderer* SnowFlake::_getSnowFlake()
        {
            static QSvgRenderer renderer(QLatin1String(":/snowflake.svg"));
            return &renderer;
        }

        SnowFlake::SnowFlake(const QSize& area, bool randomSize, int maxSize, QGraphicsItem* parent) : QGraphicsSvgItem(parent),
            _moveAnim(new QPropertyAnimation(this, "pos", this)),
            _exitPoint(area.height())
        {
            this->setSharedRenderer(this->_getSnowFlake());

            qreal scale = area.width() / maxSize / this->getSize().width();
            if(scale > 0) //Prevent the snowflsake being invisible in preview
                this->setScale(randomSize ?  1 + ( qrand() * scale) / RAND_MAX : scale);

            QSize size(this->getSize());
            this->setZValue(size.width());
            this->setPos(qrand() % (area.width() - 2 * size.width()), -size.height());
            _exitPoint += size.height();
        }

        void SnowFlake::start(qreal speed)
        {
            connect(_moveAnim, &QPropertyAnimation::finished, this, &SnowFlake::_isFallen);
            _moveAnim->setEndValue(QPointF(this->pos().x(), _exitPoint));
            _moveAnim->setDuration(speed);
            _moveAnim->start();
        }

        QSize SnowFlake::getSize() const
        {
            QSize tmp(this->renderer()->defaultSize());
            Q_ASSERT_X(tmp.width() > 0, "loading SVG", "Invalid size!");
            return (tmp.width() > 0 ? tmp * this->scale() : QSize());
        }
    }
}

