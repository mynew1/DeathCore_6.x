/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

enum DoorLever{
    max_now       =  15
};

int32 lever[max_now] = 
{
126091,
126092,
126093,
126094,
126095,
126096,
126097,
126098,
126099,
126100,
126101,
126102,
126103,
126104,
126105
};

int32 door[max_now] = 
{
225945,
225944,
233920,
227851,
231933,
231932,
233921,
231938,
236211,
236212,
236213,
236214,
236033,
230848,
230849
};

class bossdoor_levers1 : public GameObjectScript
{
public:
    bossdoor_levers1() : GameObjectScript("bossdoor_levers1") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * Door = go->FindNearestGameObject(door[i], 100.0f))
        {
                Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_bossdoor_levers1()
{
	new bossdoor_levers1();
}
