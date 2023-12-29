BattleArcade_BattleRoom_MapScripts::
# 16 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 21 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 18 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 19 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_RouletteRoom_EventScript_BeginChallenge
	.2byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 23 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0


BattleArcade_BattleRoom_EventScript_SetUpObjects::
# 29 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
	return


BattleArcade_BattleRoom_EventScript_PlayerFaceNorth::
# 34 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 35 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_BattleRoom_EventScript_EnterRoom::
# 41 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_SetInvisible
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_WatchPlayer
# 45 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Player_WalkToBattlefield
# 46 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Camera_PanBattlefield
# 47 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 48 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 49 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 50 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance::
# 55 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 56 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
# 57 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_SetVisible
# 58 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 59 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter
# 60 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 65 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd
# 66 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 71 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown
# 72 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 77 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 78 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 83 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 84 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 85 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_WalkToLeft
# 86 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_WalkToRight
# 87 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 92 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_0x8008
# 94 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 96 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 98 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 101 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 102 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 95 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 97 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 108 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
# 109 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 114 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_WalkToRight
# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_ReturnPosition
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_OpponentReturnPosition
# 118 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_LeaveRoom
# 120 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 121 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 127 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunToHeal
# 129 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceAttendant
# 131 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 136 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunOffBattlefield
# 138 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
	return


# 145 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunOffBattlefield:
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceBattlefield:
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 155 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 157 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 162 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 165 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 167 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 168 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 176 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 178 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 185 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 185 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 185 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 186 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 189 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 191 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 192 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_ReturnPosition:
# 210 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_OpponentReturnPosition:
# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 219 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_LeaveRoom:
# 221 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 221 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunToHeal:
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 229 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 232 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceAttendant:
# 234 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 237 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_SetInvisible:
# 239 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	set_invisible
	step_end

# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_SetVisible:
# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	set_visible
	step_end
