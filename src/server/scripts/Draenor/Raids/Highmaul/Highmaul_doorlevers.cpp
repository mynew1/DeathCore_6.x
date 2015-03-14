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
    max_now       =  7
};

int32 Highmaul_lever[max_now] = 
{
126060,
126061,
126062,
126063,
126064,
126065,
126066
};

int32 Highmaul_door[max_now] = 
{
231780,
231781,
239124,
239125,
239126,
239127,
239128,
};

class Highmaul_doorlevers : public GameObjectScript
{
public:
    Highmaul_doorlevers() : GameObjectScript("Highmaul_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * Highmaul_Door = go->FindNearestGameObject(Highmaul_door[i], 100.0f))
        {
                Highmaul_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_Highmaul_doorlevers()
{
	new Highmaul_doorlevers();
}
