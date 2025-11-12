BattleArcade_Hallway_MapScripts::
# 6 "data/maps/BattleArcade_Hallway/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_LOAD
# 11 "data/maps/BattleArcade_Hallway/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_LOAD:
# 8 "data/maps/BattleArcade_Hallway/scripts.pory"
	setmetatile 8, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
# 9 "data/maps/BattleArcade_Hallway/scripts.pory"
	setmetatile 8, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
	return

BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/BattleArcade_Hallway/scripts.pory"
	map_script_2 VAR_TEMP_0, FALSE, BattleArcade_Hallway_EventScript_EnterCorridor
	.2byte 0


BattleArcade_Hallway_EventScript_EnterCorridor::
# 19 "data/maps/BattleArcade_Hallway/scripts.pory"
	setvar VAR_TEMP_0, TRUE
# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
	applymovement 1, BattleArcade_Hallway_EventScript_EnterCorridor_Movement_0
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_Hallway_EventScript_EnterCorridor_Movement_1
# 22 "data/maps/BattleArcade_Hallway/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 23 "data/maps/BattleArcade_Hallway/scripts.pory"
	setvar VAR_TEMP_0, FALSE
# 24 "data/maps/BattleArcade_Hallway/scripts.pory"
	warp MAP_BATTLE_ARCADE_BATTLE_ROOM, 7, 17
# 25 "data/maps/BattleArcade_Hallway/scripts.pory"
	waitstate
	end


# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
BattleArcade_Hallway_EventScript_EnterCorridor_Movement_0:
# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_up
# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
	set_invisible
	step_end

# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
BattleArcade_Hallway_EventScript_EnterCorridor_Movement_1:
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_up
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	set_invisible
	step_end
