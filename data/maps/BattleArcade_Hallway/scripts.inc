BattleArcade_Hallway_MapScripts::
# 5 "data/maps/BattleArcade_Hallway/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_LOAD
# 10 "data/maps/BattleArcade_Hallway/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/BattleArcade_Hallway/scripts.pory"
	setmetatile 8, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
# 8 "data/maps/BattleArcade_Hallway/scripts.pory"
	setmetatile 8, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
	return

BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/BattleArcade_Hallway/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_Hallway_EventScript_EnterCorridor
	.2byte 0


BattleArcade_Hallway_EventScript_EnterCorridor::
# 18 "data/maps/BattleArcade_Hallway/scripts.pory"
	setvar VAR_TEMP_0, 1
# 19 "data/maps/BattleArcade_Hallway/scripts.pory"
	applymovement 1, BattleArcade_Hallway_WalkToRoom_Movement
# 20 "data/maps/BattleArcade_Hallway/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_Hallway_Player_WalkToRoom_Movement
# 21 "data/maps/BattleArcade_Hallway/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 22 "data/maps/BattleArcade_Hallway/scripts.pory"
	setvar VAR_TEMP_0, 0
# 23 "data/maps/BattleArcade_Hallway/scripts.pory"
	warp MAP_BATTLE_ARCADE_BATTLE_ROOM, 4, 7
# 24 "data/maps/BattleArcade_Hallway/scripts.pory"
	waitstate
	end


# 28 "data/maps/BattleArcade_Hallway/scripts.pory"
BattleArcade_Hallway_WalkToRoom_Movement:
# 30 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 30 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 30 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 30 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 30 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 30 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 31 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_up
# 32 "data/maps/BattleArcade_Hallway/scripts.pory"
	set_invisible
	step_end

# 35 "data/maps/BattleArcade_Hallway/scripts.pory"
BattleArcade_Hallway_Player_WalkToRoom_Movement:
# 37 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 37 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 37 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 37 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 37 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 37 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 37 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_right
# 38 "data/maps/BattleArcade_Hallway/scripts.pory"
	walk_up
# 39 "data/maps/BattleArcade_Hallway/scripts.pory"
	set_invisible
	step_end
