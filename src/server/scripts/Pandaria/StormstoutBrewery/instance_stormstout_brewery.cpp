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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "stormstout_brewery.h"

class instance_stormstout_brewery : public InstanceMapScript
{
public:
    instance_stormstout_brewery() : InstanceMapScript("instance_stormstout_brewery", 961) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_stormstout_brewery_InstanceMapScript(map);
    }

    struct instance_stormstout_brewery_InstanceMapScript : public InstanceScript
    {
        uint64 ookookGuid;
        uint64 hoptallusGuid;
        uint64 yanzhuGuid;

        instance_stormstout_brewery_InstanceMapScript(Map* map) : InstanceScript(map)
        {}

        void Initialize()
        {
            ookookGuid      = 0;
            hoptallusGuid   = 0;
            yanzhuGuid      = 0;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_OOK_OOK:
                    ookookGuid = creature->GetGUID();
                    break;
                case NPC_HOPTALLUS:
                    hoptallusGuid = creature->GetGUID();
                    break;
                case NPC_YAN_ZHU:
                    yanzhuGuid = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
        }

        void SetData(uint32 type, uint32 data)
        {}

        uint32 GetData(uint32 type)
        {
            return 0;
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
                case NPC_OOK_OOK:
                    return ookookGuid;
                case NPC_HOPTALLUS:
                    return hoptallusGuid;
                case NPC_YAN_ZHU:
                    return yanzhuGuid;
            }

            return 0;
        }
    };

};

void AddSC_instance_stormstout_brewery()
{
    new instance_stormstout_brewery();
}
