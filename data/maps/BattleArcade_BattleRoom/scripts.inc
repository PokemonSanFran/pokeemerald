BattleArcade_BattleRoom_MapScripts::
# 19 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 24 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 21 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 22 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, BattleFrontier_RouletteRoom_EventScript_BeginChallenge
	.2byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 26 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0


BattleArcade_BattleRoom_EventScript_PlayerFaceNorth::
# 32 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 33 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_BattleRoom_EventScript_EnterRoom::
# 39 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 40 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 41 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_WatchPlayer
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Player_WalkToBattlefield
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Camera_PanBattlefield
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 45 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 46 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 47 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance::
# 52 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
# 54 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter
# 55 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 60 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd
# 61 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 66 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown
# 67 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 72 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 73 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 78 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 80 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_WalkToLeft
# 81 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_WalkToRight
# 82 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 83 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 88 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_0x8008
# 90 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 92 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 94 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 97 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 98 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 93 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 104 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
# 105 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 110 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
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
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 122 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 123 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunToHeal
# 125 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 126 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceAttendant
# 127 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunOffBattlefield
# 134 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
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
	set_visible
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 187 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 189 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 191 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 201 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_ReturnPosition:
# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_OpponentReturnPosition:
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_LeaveRoom:
# 219 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 219 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 221 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 221 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 221 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 224 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunToHeal:
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 227 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 230 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceAttendant:
# 232 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end
