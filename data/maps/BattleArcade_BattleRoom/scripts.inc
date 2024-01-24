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
	map_script_2 VAR_TEMP_0, 1, BattleArcade_Challenge_EventScript_BeginChallenge
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


BattleArcade_BattleRoom_EventScript_MoveMCToTrainer::
# 110 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8008, ARCADE_IMPACT_PLAYER
	goto_if_eq BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_2
# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkToOpponent
BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1:
# 118 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return

BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_2:
# 112 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkToPlayer
	goto BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1


BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer::
# 123 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8008, ARCADE_IMPACT_PLAYER
	goto_if_eq BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1
# 129 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkFromOpponent
	return

BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1:
# 125 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_WalkFromPlayer
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_BERRY
	goto_if_ne BattleArcade_BattleRoom_EventScript_MoveMCBack_3
BattleArcade_BattleRoom_EventScript_MoveMCBack_1:
# 139 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return

BattleArcade_BattleRoom_EventScript_MoveMCBack_2:
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack
	goto BattleArcade_BattleRoom_EventScript_MoveMCBack_1

BattleArcade_BattleRoom_EventScript_MoveMCBack_3:
# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_ITEM
	goto_if_ne BattleArcade_BattleRoom_EventScript_MoveMCBack_2
	goto BattleArcade_BattleRoom_EventScript_MoveMCBack_1


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 144 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 145 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_ReturnPosition
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_OpponentReturnPosition
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 148 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_LeaveRoom
# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 156 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 157 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 158 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunToHeal
# 159 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceAttendant
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 166 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_FaceBattlefield
# 167 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_RunOffBattlefield
# 168 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 169 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
# 174 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 175 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 176 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 177 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_PanCameraToBrain
# 178 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntrance
	return


BattleArcade_BattleRoom_EventScript_BrainEntrance::
# 184 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinDown360
# 185 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 187 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	playse SE_APPLAUSE
# 188 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitse
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinDownToUp
# 191 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 193 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_BrainPanCameraToBattlefield
# 195 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkUp
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinUpToRight
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 201 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkRight
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 204 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinRightToUp
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkUp2
# 210 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainSpinUpToLeft
# 213 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_AddSetOpponent::
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 224 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
	return


BattleArcade_BattleRoom_EventScript_OpponentIntro::
# 229 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter
# 230 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


# 233 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_PanCameraToBrain:
# 235 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 235 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 235 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 235 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 238 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainPanCameraToBattlefield:
# 240 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 240 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 240 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 240 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinDown360:
# 245 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 246 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 247 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 248 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
	step_end

# 251 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinDownToUp:
# 253 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 254 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 255 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 256 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 257 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 258 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 261 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinUpToRight:
# 263 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 264 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 266 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 267 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 268 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 269 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 270 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 271 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 272 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 273 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 276 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinRightToUp:
# 278 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 279 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 280 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 281 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 282 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 285 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainSpinUpToLeft:
# 287 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 289 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 290 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 291 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 294 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkUp:
# 296 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 296 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 299 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkRight:
# 301 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 301 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 301 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 301 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 304 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkUp2:
# 306 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 306 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 306 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 309 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkFasterLeft:
# 311 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 314 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunOffBattlefield:
# 316 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 316 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 316 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 316 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 316 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 319 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceBattlefield:
# 321 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 324 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToLeft:
# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_WalkToRight:
# 331 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MoveBack:
# 336 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 337 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 340 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_FaceCrowd:
# 342 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 345 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkDown:
# 347 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_OpponentEnter:
# 352 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 352 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 353 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 353 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 353 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 353 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 354 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 354 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 354 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 355 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 358 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 360 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 361 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 362 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 365 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 368 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 368 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 368 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 368 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 372 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 374 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 377 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_ReturnPosition:
# 379 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 380 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 383 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_OpponentReturnPosition:
# 385 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 388 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_LeaveRoom:
# 390 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 390 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 391 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 391 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 391 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 391 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 392 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 392 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 392 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 395 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_RunToHeal:
# 397 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 397 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 397 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 397 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 397 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 397 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 398 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 401 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_FaceAttendant:
# 403 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 406 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkToPlayer:
# 408 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 409 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 409 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 409 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 411 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkToOpponent:
# 413 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 414 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 414 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 414 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 416 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkFromPlayer:
# 418 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 418 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 418 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 419 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 419 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 420 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 422 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_WalkFromOpponent:
# 424 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 424 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 424 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 425 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 425 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 426 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end
