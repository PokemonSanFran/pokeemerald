BattleArcade_BattleRoom_MapScripts::
# 20 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 24 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 22 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleArcade_BattleRoom_EventScript_PlayerFaceNorth
	.2byte 0

BattleArcade_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 26 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleArcade_BattleRoom_EventScript_EnterRoom
# 27 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 1, BattleArcade_Challenge_EventScript_BeginChallenge
	.2byte 0


BattleArcade_BattleRoom_EventScript_PlayerFaceNorth::
# 33 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 34 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleArcade_BattleRoom_EventScript_EnterRoom::
# 40 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 41 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_WatchPlayer
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Player_WalkToBattlefield
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Camera_PanBattlefield
# 45 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 46 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 47 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_Player_FaceBattlefield
# 48 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_FaceCrowd
# 54 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance::
# 59 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_AddSetOpponent
# 60 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	frontier_isbrain
# 61 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance_1
# 67 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_OpponentIntro
	return

BattleArcade_BattleRoom_EventScript_SpawnOpponentEntrance_1:
# 63 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntranceMovement
	return


BattleArcade_BattleRoom_EventScript_AddSetOpponent::
# 73 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 2
# 74 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 2, 7, 11
	return


BattleArcade_BattleRoom_EventScript_OpponentIntro::
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleFrontier_BattleArcadeBattleRoom_Movement_Opponent_Enter
# 80 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_OpponentBattleMovement::
# 85 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceLeft
# 86 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
	return


BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition::
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkDown
# 92 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return


BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact::
# 97 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	switch VAR_0x8008
# 99 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_PLAYER, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3
# 101 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_OPPONENT, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4
# 103 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	case ARCADE_IMPACT_ALL, BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5
BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1:
# 106 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
# 107 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay 16
	return

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_3:
# 100 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FacePlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_4:
# 102 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, Common_Movement_FaceAwayPlayer
	goto BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_1

BattleArcade_BattleRoom_EventScript_ApplyOverworldImpact_5:
	return


BattleArcade_BattleRoom_EventScript_MoveMCBack::
# 113 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_BERRY
	goto_if_ne BattleArcade_BattleRoom_EventScript_MoveMCBack_3
BattleArcade_BattleRoom_EventScript_MoveMCBack_1:
# 117 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return

BattleArcade_BattleRoom_EventScript_MoveMCBack_2:
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_MoveBack
	goto BattleArcade_BattleRoom_EventScript_MoveMCBack_1

BattleArcade_BattleRoom_EventScript_MoveMCBack_3:
# 113 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8007, ARCADE_EVENT_GIVE_ITEM
	goto_if_ne BattleArcade_BattleRoom_EventScript_MoveMCBack_2
	goto BattleArcade_BattleRoom_EventScript_MoveMCBack_1


BattleArcade_BattleRoom_EventScript_MoveMCToTrainer::
# 122 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8008, ARCADE_IMPACT_PLAYER
	goto_if_eq BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_2
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkToOpponent
BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1:
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return

BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_2:
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkToPlayer
	goto BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1


BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer::
# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8008, ARCADE_IMPACT_PLAYER
	goto_if_eq BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkFromOpponent
	return

BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1:
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkFromPlayer
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 148 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_Opponent_WalkToLeft
# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_Player_WalkToRight
# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 157 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 158 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_Player_ReturnPosition
# 159 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Opponent_ReturnPosition
# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Opponent_LeaveRoom
# 162 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 163 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 2
# 164 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement::
# 169 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	addobject 1
# 170 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	setobjectxy 1, 2, 12
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_Attendant_RunToHeal
# 172 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_Player_FaceAttendant
# 174 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_Movement_Player_FaceBattlefield
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_Movement_Attendant_RunOffBattlefield
# 181 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 182 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	removeobject 1
	return


BattleArcade_BattleRoom_EventScript_BrainEntranceMovement::
# 187 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 188 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, Common_Movement_FaceDown
# 189 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_Camera_PanToBrain
# 191 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 192 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntrance
	return


BattleArcade_BattleRoom_EventScript_BrainEntrance::
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinDown360
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	playse SE_APPLAUSE
# 201 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitse
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinDownToUp
# 204 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_Movement_Camera_BrainPanCameraToBattlefield
# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_WalkUp
# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinUpToRight
# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_BrainWalkRight
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinRightToUp
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_WalkUp2
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_Movement_Brain_SpinUpToLeft
# 226 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 228 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 229 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 230 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 231 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


# 234 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_WatchPlayer:
# 236 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 237 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 238 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 241 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Player_WalkToBattlefield:
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 243 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 244 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 245 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 245 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 245 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 248 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Camera_PanBattlefield:
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 250 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 253 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Player_FaceBattlefield:
# 255 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 258 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_FaceCrowd:
# 260 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 262 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_Opponent_Enter:
# 264 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 264 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 265 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 266 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 266 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 266 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 267 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 269 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkDown:
# 271 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 275 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_MoveBack:
# 277 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 278 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 281 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkToPlayer:
# 283 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 284 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 284 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 284 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 286 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkToOpponent:
# 288 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 289 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 289 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 289 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 291 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkFromPlayer:
# 293 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 293 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 293 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 294 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 294 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 295 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 297 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleFrontier_BattleArcadeBattleRoom_Movement_MC_WalkFromOpponent:
# 299 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 299 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 299 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 300 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 300 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 301 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 304 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_Opponent_WalkToLeft:
# 306 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 309 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_Player_WalkToRight:
# 311 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 315 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_Player_ReturnPosition:
# 317 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 318 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 321 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Opponent_ReturnPosition:
# 323 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 326 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Opponent_LeaveRoom:
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 328 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 329 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 330 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 330 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 330 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 333 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Attendant_RunToHeal:
# 335 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 335 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 335 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 335 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 335 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 335 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 336 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 339 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Player_FaceAttendant:
# 341 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 344 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Attendant_RunOffBattlefield:
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 346 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 349 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Camera_PanToBrain:
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 351 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 354 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinDown360:
# 356 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 357 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 358 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 359 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
	step_end

# 362 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinDownToUp:
# 364 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 365 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 366 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 367 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 368 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 369 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 372 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Camera_BrainPanCameraToBattlefield:
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
BattleArcade_BattleRoom_Movement_Brain_WalkUp:
# 379 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 379 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 382 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinUpToRight:
# 384 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 385 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 386 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 387 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 388 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 389 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 390 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 391 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 392 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 393 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 394 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 397 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_BrainWalkRight:
# 399 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 399 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 399 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 399 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 402 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinRightToUp:
# 404 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 405 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 406 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 407 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 408 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 411 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_WalkUp2:
# 413 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 413 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 413 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 416 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_Movement_Brain_SpinUpToLeft:
# 418 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 419 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 420 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 421 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 422 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end
