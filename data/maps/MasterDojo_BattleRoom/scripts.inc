MasterDojo_BattleRoom_MapScripts::
# 10 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MasterDojo_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 15 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MasterDojo_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

MasterDojo_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, RestrictedSparring_BattleCourt_EventScript_SetUpOpponent
	.2byte 0

MasterDojo_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 17 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, MasterDojo_Lobby_EventScript_PlayerFaceEast
	.2byte 0


MasterDojo_Lobby_EventScript_PlayerFaceEast::
# 23 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 24 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end


MasterDojo_BattleRoom_EventScript_EnterRoomMovement::
# 30 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	applymovement 1, MasterDojo_BattleRoom_EventScript_EnterRoomMovement_Movement_0
# 31 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MasterDojo_BattleRoom_EventScript_EnterRoomMovement_Movement_1
# 32 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	waitmovement 1
	return


MasterDojo_BattleRoom_EventScript_ContinueChallengeMovement::
# 38 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MasterDojo_BattleRoom_EventScript_ContinueChallengeMovement_Movement_0
# 39 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, MasterDojo_BattleRoom_EventScript_ContinueChallengeMovement_Movement_1
# 40 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	applymovement 1, MasterDojo_BattleRoom_EventScript_ContinueChallengeMovement_Movement_2
# 41 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	waitmovement 1
	return


MasterDojo_BattleRoom_EventScript_OpponentEnterMovement::
# 47 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 48 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	special RemoveCameraObject
# 49 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceDown
	return


MasterDojo_BattleRoom_EventScript_DeafeatedOpponentMovement::
# 55 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	special SpawnCameraObject
# 56 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, MasterDojo_BattleRoom_EventScript_DeafeatedOpponentMovement_Movement_0
# 57 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MasterDojo_BattleRoom_EventScript_DeafeatedOpponentMovement_Movement_1
# 58 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	applymovement 1, MasterDojo_BattleRoom_EventScript_DeafeatedOpponentMovement_Movement_2
# 59 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 60 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	removeobject 2
# 61 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	waitmovement 1
	return


MasterDojo_BattleRoom_EventScript_RefreshOpponentObject::
# 67 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	removeobject 2
# 68 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	addobject 2
	return


# 30 "data/maps/MasterDojo_BattleRoom/scripts.pory"
MasterDojo_BattleRoom_EventScript_EnterRoomMovement_Movement_0:
	step_end

# 31 "data/maps/MasterDojo_BattleRoom/scripts.pory"
MasterDojo_BattleRoom_EventScript_EnterRoomMovement_Movement_1:
# 31 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 31 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 31 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 31 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 31 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 31 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
	step_end

# 38 "data/maps/MasterDojo_BattleRoom/scripts.pory"
MasterDojo_BattleRoom_EventScript_ContinueChallengeMovement_Movement_0:
# 38 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 38 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
	step_end

# 39 "data/maps/MasterDojo_BattleRoom/scripts.pory"
MasterDojo_BattleRoom_EventScript_ContinueChallengeMovement_Movement_1:
# 39 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 39 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 39 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 39 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 39 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
	step_end

# 40 "data/maps/MasterDojo_BattleRoom/scripts.pory"
MasterDojo_BattleRoom_EventScript_ContinueChallengeMovement_Movement_2:
# 40 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_up
# 40 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 40 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 40 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_right
# 40 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	face_down
	step_end

# 56 "data/maps/MasterDojo_BattleRoom/scripts.pory"
MasterDojo_BattleRoom_EventScript_DeafeatedOpponentMovement_Movement_0:
# 56 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
# 56 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
# 56 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
# 56 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
# 56 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
	step_end

# 57 "data/maps/MasterDojo_BattleRoom/scripts.pory"
MasterDojo_BattleRoom_EventScript_DeafeatedOpponentMovement_Movement_1:
# 57 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
# 57 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
# 57 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	face_up
	step_end

# 58 "data/maps/MasterDojo_BattleRoom/scripts.pory"
MasterDojo_BattleRoom_EventScript_DeafeatedOpponentMovement_Movement_2:
# 58 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
# 58 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
# 58 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_left
# 58 "data/maps/MasterDojo_BattleRoom/scripts.pory"
	walk_down
	step_end
