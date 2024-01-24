BattleArcade_BattleRoom_MapScripts::
# 19 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 23 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 21 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 25 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 26 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_Challenge_EventScript_BeginChallenge
	.2byte 0


BattleArcade_BattleRoom_EventScript_PlayerFaceNorth::
# 32 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 33 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_BattleRoom_EventScript_EnterRoom::
# 39 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
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
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_Player_FaceBattlefield
# 47 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 52 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_FaceCrowd
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance::
# 58 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_AddSetOpponent
# 59 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	frontier_isbrain
# 60 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance_1
# 66 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentIntro
	return

BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance_1:
# 62 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntranceMovement
	return


BattleArcade_BattleRoom_EventScript_AddSetOpponent::
# 72 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 73 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
	return


BattleArcade_BattleRoom_EventScript_OpponentIntro::
# 78 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_Opponent_Enter
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 84 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 85 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 90 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkDown
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 96 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_0x8008
# 98 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 100 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 102 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 105 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 106 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 99 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 101 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 112 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_BERRY
	goto_if_ne BattleArcade_BattleRoom_EventScript_MoveMCBack_3
BattleArcade_BattleRoom_EventScript_MoveMCBack_1:
# 116 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return

BattleArcade_BattleRoom_EventScript_MoveMCBack_2:
# 114 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_MoveBack
	goto BattleArcade_BattleRoom_EventScript_MoveMCBack_1

BattleArcade_BattleRoom_EventScript_MoveMCBack_3:
# 112 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_ITEM
	goto_if_ne BattleArcade_BattleRoom_EventScript_MoveMCBack_2
	goto BattleArcade_BattleRoom_EventScript_MoveMCBack_1


BattleArcade_BattleRoom_EventScript_MoveMCToTrainer::
# 121 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8008, ARCADE_IMPACT_PLAYER
	goto_if_eq BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_2
# 127 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkToOpponent
BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1:
# 129 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return

BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_2:
# 123 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkToPlayer
	goto BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1


BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer::
# 134 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8008, ARCADE_IMPACT_PLAYER
	goto_if_eq BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1
# 140 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkFromOpponent
	return

BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1:
# 136 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkFromPlayer
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 146 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 148 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_Opponent_WalkToLeft
# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_Player_WalkToRight
# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 156 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 157 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_Player_ReturnPosition
# 158 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Opponent_ReturnPosition
# 159 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Opponent_LeaveRoom
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 162 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 168 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 169 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 170 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_Attendant_RunToHeal
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 172 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_Player_FaceAttendant
# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 178 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_Player_FaceBattlefield
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_Attendant_RunOffBattlefield
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
# 186 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 187 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 188 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 189 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_Camera_PanToBrain
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 191 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntrance
	return


BattleArcade_BattleRoom_EventScript_BrainEntrance::
# 196 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinDown360
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 199 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	playse SE_APPLAUSE
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitse
# 202 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinDownToUp
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 205 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_Camera_BrainPanCameraToBattlefield
# 207 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_WalkUp
# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 210 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinUpToRight
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 213 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkRight
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 216 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinRightToUp
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 219 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 221 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_WalkUp2
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 224 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinUpToLeft
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 227 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 229 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 230 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


# 233 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 235 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 236 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 237 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 240 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 242 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 247 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 249 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 252 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Player_FaceBattlefield:
# 254 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 257 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_FaceCrowd:
# 259 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 261 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_Opponent_Enter:
# 263 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 263 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 264 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 264 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 264 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 264 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 266 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 268 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkDown:
# 270 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 274 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_MoveBack:
# 276 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 277 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 280 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkToPlayer:
# 282 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 283 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 283 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 283 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 285 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkToOpponent:
# 287 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 290 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkFromPlayer:
# 292 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 292 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 292 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 293 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 293 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 294 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 296 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkFromOpponent:
# 298 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 298 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 298 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 299 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 299 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 300 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 303 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_Opponent_WalkToLeft:
# 305 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 308 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_Player_WalkToRight:
# 310 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 314 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_Player_ReturnPosition:
# 316 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 317 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 320 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Opponent_ReturnPosition:
# 322 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 325 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Opponent_LeaveRoom:
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 327 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 332 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Attendant_RunToHeal:
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 334 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 335 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 338 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Player_FaceAttendant:
# 340 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 343 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Attendant_RunOffBattlefield:
# 345 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 345 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 345 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 345 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 345 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 348 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Camera_PanToBrain:
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 350 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 353 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinDown360:
# 355 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 356 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 358 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
	step_end

# 361 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinDownToUp:
# 363 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 364 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 365 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 366 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 368 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 371 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Camera_BrainPanCameraToBattlefield:
# 373 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 373 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 373 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 373 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 376 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_WalkUp:
# 378 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 378 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 381 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinUpToRight:
# 383 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 384 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 385 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 386 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 387 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 388 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 389 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 390 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 391 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 392 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 393 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 396 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkRight:
# 398 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 398 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 398 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 398 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 401 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinRightToUp:
# 403 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 404 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 405 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 406 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 407 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 410 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_WalkUp2:
# 412 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 412 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 412 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 415 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinUpToLeft:
# 417 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 418 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 419 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 420 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 421 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end
