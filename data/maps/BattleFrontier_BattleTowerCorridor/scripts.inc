BattleFrontier_BattleTowerCorridor_MapScripts::
# 4 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BattleFrontier_BattleTowerCorridor_MapScripts_MAP_SCRIPT_ON_LOAD
# 12 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerCorridor_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleFrontier_BattleTowerCorridor_MapScripts_MAP_SCRIPT_ON_LOAD:
# 5 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	compare VAR_0x8006, 1
	goto_if_eq BattleFrontier_BattleTowerCorridor_MapScripts_MAP_SCRIPT_ON_LOAD_2
BattleFrontier_BattleTowerCorridor_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 8 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 12, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
# 9 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 12, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
	end

BattleFrontier_BattleTowerCorridor_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 6 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto BattleFrontier_BattleTowerCorridor_EventScript_OpenFarDoor
	goto BattleFrontier_BattleTowerCorridor_MapScripts_MAP_SCRIPT_ON_LOAD_1

BattleFrontier_BattleTowerCorridor_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor
	.2byte 0


BattleFrontier_BattleTowerCorridor_EventScript_OpenFarDoor::
# 18 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 15, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
# 19 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 15, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
	end


BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor::
# 24 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 25 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	compare VAR_0x8006, 1
	goto_if_eq BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor_2
# 29 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement 1, BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToDoor
# 30 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor
BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor_1:
# 32 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitmovement 0
# 33 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto BattleFrontier_BattleTowerCorridor_EventScript_WarpToBattleRoom
	return

BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor_2:
# 26 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement 1, BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor
# 27 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToFarDoor
	goto BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor_1


BattleFrontier_BattleTowerCorridor_EventScript_WarpToBattleRoom::
# 37 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setvar VAR_TEMP_0, 0
# 38 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 4, 8
# 39 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitstate
	end


# 43 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToFarDoor:
# 44 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 44 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 44 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 44 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 44 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 44 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 44 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 45 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_up
# 46 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	set_invisible
# 47 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	step_end

# 50 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor:
# 51 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 51 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 51 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 51 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 51 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 51 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 52 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_up
# 53 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	set_invisible
# 54 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	step_end

# 57 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor:
# 58 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 58 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 58 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 58 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 59 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_up
# 60 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	set_invisible
# 61 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	step_end

# 64 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToDoor:
# 65 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 65 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 65 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 66 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_up
# 67 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	set_invisible
# 68 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	step_end
