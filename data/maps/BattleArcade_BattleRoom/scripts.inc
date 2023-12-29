BattleArcade_BattleRoom_MapScripts::
# 12 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 17 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 15 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_RouletteRoom_EventScript_BeginChallenge
	.2byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 19 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0


BattleArcade_BattleRoom_EventScript_SetUpObjects::
# 25 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
	return


BattleArcade_BattleRoom_EventScript_PlayerFaceNorth::
# 30 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 31 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_BattleRoom_EventScript_EnterRoom::
# 37 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_SetInvisible
# 38 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 39 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 40 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_WatchPlayer
# 41 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Player_WalkToBattlefield
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Camera_PanBattlefield
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 45 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 46 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance::
# 51 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 52 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_SetVisible
# 54 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 55 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter
# 56 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 61 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd
# 62 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 67 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown
# 68 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 73 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 74 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 80 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 81 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_WalkToLeft
# 82 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_WalkToRight
# 83 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 88 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	arcade_getimpactedside
# 89 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_RESULT
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 93 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 95 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 98 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 99 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 92 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 94 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 105 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
# 106 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 111 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 112 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_WalkToRight
# 113 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_ReturnPosition
# 114 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_OpponentReturnPosition
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_LeaveRoom
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 118 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 123 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 125 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunToHeal
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 127 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceAttendant
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 134 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunOffBattlefield
# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
	return


# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunOffBattlefield:
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceBattlefield:
# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 154 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 157 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 159 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 162 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 164 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 165 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 168 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 170 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 175 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 178 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 186 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 188 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 189 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_ReturnPosition:
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_OpponentReturnPosition:
# 213 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_LeaveRoom:
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 219 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 219 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 219 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 219 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunToHeal:
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 229 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceAttendant:
# 231 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 234 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_SetInvisible:
# 236 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	set_invisible
	step_end

# 239 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_SetVisible:
# 241 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	set_visible
	step_end
