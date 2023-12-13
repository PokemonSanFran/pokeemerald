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


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd
# 54 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 59 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown
# 60 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 65 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 66 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 71 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 72 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 73 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_WalkToLeft
# 74 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_WalkToRight
# 75 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 81 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_TEMP_2
# 83 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 85 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 87 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 90 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 84 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 86 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 97 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
# 98 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


# 101 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 103 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 106 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 108 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 111 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 113 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 114 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 122 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 127 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 129 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 129 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 131 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 131 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 131 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 138 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 145 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 145 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 145 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 145 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end
