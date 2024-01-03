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
	call BattleArcade_BattleRoom_EventScript_AddSetOpponentObject
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
# 82 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 87 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_0x8008
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
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_ReturnPosition
# 111 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_OpponentReturnPosition
# 112 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 113 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_LeaveRoom
# 114 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
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
	waitmovement 1
# 134 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 140 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_AddSetOpponentObject
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 142 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 143 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_PanCameraToBrain
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 145 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntrance
	return


BattleArcade_BattleRoom_EventScript_BrainEntrance::
# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinDown360
# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 153 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	playse SE_APPLAUSE
# 154 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitse
# 156 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinDownToUp
# 157 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 159 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_BrainPanCameraToBattlefield
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkUp
# 162 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 164 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinUpToRight
# 165 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 167 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkRight
# 168 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 170 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinRightToUp
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 175 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkUp2
# 176 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 178 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinUpToLeft
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 183 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
	return


BattleArcade_BattleRoom_EventScript_AddSetOpponentObject::
# 188 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 189 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
	return


# 192 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_PanCameraToBrain:
# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 194 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainPanCameraToBattlefield:
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinDown360:
# 204 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
	step_end

# 210 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinDownToUp:
# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 213 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinUpToRight:
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 224 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 227 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 229 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 230 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 231 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 232 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 235 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinRightToUp:
# 237 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 238 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 239 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 240 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 241 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinUpToLeft:
# 246 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 247 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 248 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 253 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkUp:
# 255 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 255 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 258 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkRight:
# 260 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 260 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 260 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 260 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 263 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkUp2:
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 268 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkFasterLeft:
# 270 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 273 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunOffBattlefield:
# 275 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 275 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 275 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 275 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 275 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 278 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceBattlefield:
# 280 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 283 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 285 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 290 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 293 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 295 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 296 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 299 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 301 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 304 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 306 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 309 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 311 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 311 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 312 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 312 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 312 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 312 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 313 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 313 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 313 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 314 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 317 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 319 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 320 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 321 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 324 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 331 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 336 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_ReturnPosition:
# 338 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 342 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_OpponentReturnPosition:
# 344 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 347 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_LeaveRoom:
# 349 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 349 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 354 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunToHeal:
# 356 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 356 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 356 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 356 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 356 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 356 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 360 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceAttendant:
# 362 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end
