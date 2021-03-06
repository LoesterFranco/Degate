/**
 * This file is part of the IC reverse engineering tool Degate.
 *
 * Copyright 2008, 2009, 2010 by Martin Schobert
 * Copyright 2019-2020 Dorian Bachelot
 *
 * Degate is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * Degate is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with degate. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "Core/LogicModel/ObjectSet.h"
#include "Core/LogicModel/Gate/GatePort.h"

#include <algorithm>
#include <memory>

using namespace std;
using namespace degate;


bool degate::is_removable(PlacedLogicModelObject_shptr o)
{
    return std::dynamic_pointer_cast<GatePort>(o) == nullptr;
}

bool degate::is_interconnectable(PlacedLogicModelObject_shptr o)
{
    return std::dynamic_pointer_cast<ConnectedLogicModelObject>(o) != nullptr;
}


void ObjectSet::clear()
{
    objects.clear();
}


void ObjectSet::add(PlacedLogicModelObject_shptr object)
{
    objects.insert(object);
}


void ObjectSet::remove(PlacedLogicModelObject_shptr object)
{
    object_set_type::iterator it = find(objects.begin(), objects.end(), object);

    if (it != objects.end())
    {
        objects.erase(it);
    }
}
