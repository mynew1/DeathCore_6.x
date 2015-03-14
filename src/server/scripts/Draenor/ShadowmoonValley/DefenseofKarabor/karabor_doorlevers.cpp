/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
    max_now       =  4
};

int32 karabor_lever[max_now] = 
{
126067,
126068,
126069,
126070
};

int32 karabor_door[max_now] = 
{
236081,
236082,
236083,
236084
};

class karabor_doorlevers : public GameObjectScript
{
public:
    karabor_doorlevers() : GameObjectScript("karabor_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * karabor_Door = go->FindNearestGameObject(karabor_door[i], 100.0f))
        {
                karabor_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_karabor_doorlevers()
{
	new karabor_doorlevers();
}
