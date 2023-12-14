BattleArcade_BattleRoom_MapScripts::
# 10 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 19 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 16 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 17 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_RouletteRoom_EventScript_BeginChallenge
	.2byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 21 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0


BattleArcade_BattleRoom_EventScript_PlayerFaceNorth::
# 27 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 28 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_BattleRoom_EventScript_EnterRoom::
# 34 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_SetInvisible
# 35 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 36 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 37 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_WatchPlayer
# 38 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Player_WalkToBattlefield
# 39 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Camera_PanBattlefield
# 40 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 41 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance::
# 48 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 49 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter
# 50 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 55 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd
# 56 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 61 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown
# 62 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 67 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 68 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 73 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 74 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 75 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_WalkToLeft
# 76 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_WalkToRight
# 77 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 83 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_TEMP_2
# 85 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 87 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 89 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 92 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 93 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 86 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 88 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 99 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
# 100 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 105 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 106 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_WalkToRight
# 107 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_LeaveRoom
# 108 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_ReturnPosition
# 109 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 110 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunToHeal
# 118 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceAttendant
# 120 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 125 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunOffBattlefield
# 127 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunOffBattlefield:
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceBattlefield:
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 140 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 145 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 153 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 156 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 158 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 166 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 168 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 168 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 169 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 169 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 169 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 169 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 170 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 170 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 170 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 174 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 176 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 177 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 178 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 185 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 185 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 185 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 188 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_ReturnPosition:
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_LeaveRoom:
# 201 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 201 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunToHeal:
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceAttendant:
# 213 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_SetInvisible:
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	set_invisible
	step_end
