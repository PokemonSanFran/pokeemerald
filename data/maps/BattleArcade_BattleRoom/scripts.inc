BattleArcade_BattleRoom_MapScripts::
# 9 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 13 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 18 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 15 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 16 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_RouletteRoom_EventScript_BeginChallenge
	.2byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 20 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0


BattleArcade_BattleRoom_EventScript_PlayerFaceNorth::
# 26 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 27 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_BattleRoom_EventScript_EnterRoom::
# 33 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
# 34 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 35 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 36 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_WatchPlayer
# 37 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Player_WalkToBattlefield
# 38 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Camera_PanBattlefield
# 39 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 40 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 41 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance::
# 46 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 47 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter
# 48 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown
# 54 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 59 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 60 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 65 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 66 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 67 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_WalkToLeft
# 68 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_WalkToRight
# 69 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 75 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_TEMP_2
# 77 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 81 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 84 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 85 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 78 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 80 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
# 92 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


# 95 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 97 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 100 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 102 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 105 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 107 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 108 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 111 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 113 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 118 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 118 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 118 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 120 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 120 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 120 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 121 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 127 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 131 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 134 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 134 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 134 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 134 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 136 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end
