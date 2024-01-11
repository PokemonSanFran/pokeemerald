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
	call BattleArcade_BattleRoom_EventScript_AddSetOpponent
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	frontier_isbrain
# 54 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance_1
# 60 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentIntro
	return

BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance_1:
# 56 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntranceMovement
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 66 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd
# 67 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 72 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown
# 73 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 78 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 84 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 85 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 86 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_WalkToLeft
# 87 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_WalkToRight
# 88 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 89 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 94 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_0x8008
# 96 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 98 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 100 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 103 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 104 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 97 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 99 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 110 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
# 111 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_ReturnPosition
# 118 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_OpponentReturnPosition
# 119 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 120 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_LeaveRoom
# 121 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 122 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
# 123 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 129 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunToHeal
# 131 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 132 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceAttendant
# 133 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 138 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunOffBattlefield
# 140 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 148 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_PanCameraToBrain
# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntrance
	return


BattleArcade_BattleRoom_EventScript_BrainEntrance::
# 156 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinDown360
# 157 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 159 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	playse SE_APPLAUSE
# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitse
# 162 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinDownToUp
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 165 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_BrainPanCameraToBattlefield
# 167 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkUp
# 168 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 170 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinUpToRight
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkRight
# 174 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 176 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinRightToUp
# 177 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkUp2
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinUpToLeft
# 185 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 187 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 188 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 189 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_AddSetOpponent::
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
	return


BattleArcade_BattleRoom_EventScript_OpponentIntro::
# 201 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_PanCameraToBrain:
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 210 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainPanCameraToBattlefield:
# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinDown360:
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 219 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
	step_end

# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinDownToUp:
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 227 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 229 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 230 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 233 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinUpToRight:
# 235 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 236 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 237 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 238 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 239 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 240 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 241 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 245 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 248 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinRightToUp:
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 251 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 252 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 253 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 254 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 257 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinUpToLeft:
# 259 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 260 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 261 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 262 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 263 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 266 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkUp:
# 268 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 268 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 271 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkRight:
# 273 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 273 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 273 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 273 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 276 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkUp2:
# 278 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 278 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 278 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 281 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkFasterLeft:
# 283 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 286 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunOffBattlefield:
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 291 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceBattlefield:
# 293 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 296 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 298 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 301 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 303 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 306 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 308 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 309 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 312 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 314 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 317 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 319 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 322 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 324 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 324 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 325 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 325 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 325 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 325 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 330 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 332 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 337 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 340 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 340 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 340 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 340 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 341 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 341 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 341 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 344 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 349 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_ReturnPosition:
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 352 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 355 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_OpponentReturnPosition:
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 360 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_LeaveRoom:
# 362 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 362 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 363 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 363 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 363 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 363 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 364 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 364 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 364 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunToHeal:
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 370 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 373 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceAttendant:
# 375 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end
