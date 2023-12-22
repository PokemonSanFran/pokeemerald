BattleArcade_BattleRoom_MapScripts::
# 10 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 15 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 13 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_RouletteRoom_EventScript_BeginChallenge
	.2byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 17 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0


BattleArcade_BattleRoom_EventScript_SetUpObjects::
# 23 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
	return


BattleArcade_BattleRoom_EventScript_PlayerFaceNorth::
# 28 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 29 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_BattleRoom_EventScript_EnterRoom::
# 35 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_SetInvisible
# 36 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 37 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 38 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_WatchPlayer
# 39 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Player_WalkToBattlefield
# 40 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Camera_PanBattlefield
# 41 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance::
# 49 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 50 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
# 51 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_SetVisible
# 52 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter
# 54 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 59 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd
# 60 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 65 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown
# 66 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 71 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 72 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 77 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 78 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_WalkToLeft
# 80 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_WalkToRight
# 81 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 87 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_TEMP_2
# 89 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 93 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 96 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 97 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 90 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 92 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 103 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
# 104 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 109 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 110 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_WalkToRight
# 111 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_ReturnPosition
# 112 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_OpponentReturnPosition
# 113 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 114 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_LeaveRoom
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 121 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 122 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 123 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunToHeal
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 125 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceAttendant
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 131 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunOffBattlefield
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
	return


# 140 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunOffBattlefield:
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 145 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceBattlefield:
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 155 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 157 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 162 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 166 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 168 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 176 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 178 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 178 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 186 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 187 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 188 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 191 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_ReturnPosition:
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_OpponentReturnPosition:
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_LeaveRoom:
# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 221 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunToHeal:
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 224 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 227 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceAttendant:
# 229 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 232 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_SetInvisible:
# 234 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	set_invisible
	step_end

# 237 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_SetVisible:
# 239 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	set_visible
	step_end
