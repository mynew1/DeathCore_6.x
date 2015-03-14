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
    max_now       =  9
};

int32 SpiresofArak_lever[max_now] = 
{
126074,
126075,
126076,
126077,
126078,
126079,
126080,
126081,
126082
};

int32 SpiresofArak_door[max_now] = 
{
229038,
234310,
234311,
234312,
234313,
234314,
234315,
234316,
235994
};

class SpiresofArak_doorlevers : public GameObjectScript
{
public:
    SpiresofArak_doorlevers() : GameObjectScript("SpiresofArak_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * SpiresofArak_Door = go->FindNearestGameObject(SpiresofArak_door[i], 100.0f))
        {
                SpiresofArak_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_SpiresofArak_doorlevers()
{
	new SpiresofArak_doorlevers();
}
