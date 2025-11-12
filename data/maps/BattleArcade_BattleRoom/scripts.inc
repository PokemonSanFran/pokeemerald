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
	applymovement 1, BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_0
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_1
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_2
# 45 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 46 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 47 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield
# 48 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_MCFaceCrowd::
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MCFaceCrowd_Movement_0
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
	applymovement 2, BattleArcade_BattleRoom_EventScript_OpponentIntro_Movement_0
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
	applymovement 3, BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition_Movement_0
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
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCBack_Movement_0
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
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_Movement_1
BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1:
# 130 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 3
	return

BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_2:
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_Movement_0
	goto BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_1


BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer::
# 135 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	compare VAR_0x8008, ARCADE_IMPACT_PLAYER
	goto_if_eq BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_Movement_1
	return

BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_1:
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 3, BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_Movement_0
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition::
# 147 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	lock
# 148 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_0
# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_1
# 151 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 152 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special RemoveCameraObject
	return


BattleArcade_BattleRoom_EventScript_MoveBattlersBack::
# 157 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 158 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_MoveBattlersBack_Movement_0
# 159 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_1
# 160 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_MoveBattlersBack_Movement_1
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
	applymovement 1, BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement_Movement_0
# 172 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 1
# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement_Movement_1
# 174 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
	return


BattleArcade_BattleRoom_EventScript_AttendantLeave::
# 179 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 1, BattleArcade_BattleRoom_EventScript_AttendantLeave_Movement_0
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
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_BrainEntranceMovement_Movement_0
# 191 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 192 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	call BattleArcade_BattleRoom_EventScript_BrainEntrance
	return


BattleArcade_BattleRoom_EventScript_BrainEntrance::
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_0
# 198 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 200 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	playse SE_APPLAUSE
# 201 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitse
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_1
# 204 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_2
# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_3
# 209 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_4
# 212 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_5
# 215 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_6
# 218 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 220 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_7
# 223 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	waitmovement 2
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement 2, BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_8
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


BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield::
# 236 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield_Movement_0
	return


# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_0:
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	delay_8
# 42 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_up
	step_end

# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_1:
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 43 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_EnterRoom_Movement_2:
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 44 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MCFaceCrowd_Movement_0:
# 53 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	face_down
	step_end

# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_OpponentIntro_Movement_0:
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 79 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_left
	step_end

# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MCMoveIntoPosition_Movement_0:
# 91 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCBack_Movement_0:
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 115 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_Movement_0:
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 124 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCToTrainer_Movement_1:
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 128 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_Movement_0:
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 137 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveMCFromTrainer_Movement_1:
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 141 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_fast_down
	step_end

# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_0:
# 149 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
	step_end

# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveBattlersIntoPosition_Movement_1:
# 150 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 158 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveBattlersBack_Movement_0:
# 158 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 158 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MoveBattlersBack_Movement_1:
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_left
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 161 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement_Movement_0:
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_up
# 171 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end

# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_HandleHealAttendantMovement_Movement_1:
# 173 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_AttendantLeave_Movement_0:
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
# 180 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_faster_down
	step_end

# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntranceMovement_Movement_0:
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
# 190 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_down
	step_end

# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_0:
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 197 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
	step_end

# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_1:
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 203 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_2:
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 206 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_3:
# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 208 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_4:
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 211 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
	step_end

# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_5:
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
# 214 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_right
	step_end

# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_6:
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 217 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
	step_end

# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_7:
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
# 222 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_up
	step_end

# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_BrainEntrance_Movement_8:
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_down
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_right
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_up
# 225 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_left
	step_end

# 236 "data/maps/BattleArcade_BattleRoom/scripts.pory"
BattleArcade_BattleRoom_EventScript_MovePlayerBattlefield_Movement_0:
# 236 "data/maps/BattleArcade_BattleRoom/scripts.pory"
	walk_in_place_faster_right
	step_end
