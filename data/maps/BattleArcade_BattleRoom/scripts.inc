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
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_AddSetOpponentObject::
# 189 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
	return


# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_PanCameraToBrain:
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainPanCameraToBattlefield:
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
BattleArcade_BattleRoom_Movement_BrainSpinDown360:
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
	step_end

# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinDownToUp:
# 213 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 221 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinUpToRight:
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 224 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
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
# 231 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 232 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 233 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 236 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinRightToUp:
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
	step_end

# 245 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinUpToLeft:
# 247 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 248 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 251 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 254 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkUp:
# 256 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 256 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 259 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkRight:
# 261 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 261 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 261 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 261 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 264 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkUp2:
# 266 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 266 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 266 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 269 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkFasterLeft:
# 271 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 274 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunOffBattlefield:
# 276 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 276 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 276 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 276 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 276 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 279 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceBattlefield:
# 281 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 284 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 286 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 289 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 291 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 294 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 296 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 297 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 300 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 302 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 305 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 307 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 310 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 312 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 312 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 313 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 313 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 313 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 313 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 314 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 314 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 314 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 315 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 318 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 320 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 321 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 322 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 325 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 332 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 337 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_ReturnPosition:
# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 340 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 343 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_OpponentReturnPosition:
# 345 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 348 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_LeaveRoom:
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 352 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 352 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 352 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 355 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunToHeal:
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 358 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 361 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceAttendant:
# 363 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end
