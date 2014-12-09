/*
 *  Copyright (C) 2014 Christopher Gundler <c.gundler@mail.de>
 *  This file is part of SnowScreen.
 *
 *  You should have received a copy of the GNU General Public License (version 3)
 *  along with SnowScreen. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SNOWSCREEN_CONFIG_CONFIGITEM_H
#define SNOWSCREEN_CONFIG_CONFIGITEM_H

#include <QString>
#include <QWidget>

#include "../snowscreen.h"

namespace SnowScreen
{
    namespace Config
    {
        template <class T>
        class Item : public T
        {
        protected:
            const QString _name;

        public:
            Item(QWidget& parent, const QString& name) : T(&parent), _name(name) {}

            Q_DECL_CONSTEXPR inline QString name() const
            {
                return _name;
            }

            virtual void save() = 0;
        };
    }
}

#endif
