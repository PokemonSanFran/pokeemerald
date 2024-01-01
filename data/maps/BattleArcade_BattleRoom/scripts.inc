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
	removeobject 2
# 56 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 57 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
# 58 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter
# 59 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 64 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd
# 65 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 70 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown
# 71 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 76 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 77 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 82 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 83 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 84 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_WalkToLeft
# 85 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_WalkToRight
# 86 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_0x8008
# 93 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 95 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 97 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 100 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 101 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 94 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 96 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 107 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
# 108 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 113 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 114 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_WalkToRight
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_ReturnPosition
# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_OpponentReturnPosition
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 118 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_LeaveRoom
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 120 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 125 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 127 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunToHeal
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 129 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceAttendant
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 136 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunOffBattlefield
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
	return


# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunOffBattlefield:
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceBattlefield:
# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 154 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 156 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 159 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 164 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 166 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 167 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 170 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 172 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 175 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 177 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	set_visible
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
