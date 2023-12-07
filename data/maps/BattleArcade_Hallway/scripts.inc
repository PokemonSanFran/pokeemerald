BattleArcade_Hallway_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_LOAD:
	setmetatile 0, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, FALSE
	setmetatile 0, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, FALSE
	return

BattleArcade_Hallway_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, BattleArcade_Hallway_EventScript_EnterCorridor
	.2byte 0


BattleArcade_Hallway_EventScript_EnterCorridor::
	setvar VAR_TEMP_0, 1
	applymovement 1, BattleArcade_Hallway_WalkToRoom_Movement
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_Hallway_Player_WalkToRoom_Movement
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_TEMP_0, 0
	warp MAP_BATTLE_ARCADE_BATTLE_ROOM, 4, 8
	waitstate
	end


BattleArcade_Hallway_WalkToRoom_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	set_invisible
	step_end

BattleArcade_Hallway_Player_WalkToRoom_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	set_invisible
	step_end
