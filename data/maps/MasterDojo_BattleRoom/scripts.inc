MasterDojo_BattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MasterDojo_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MasterDojo_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

MasterDojo_BattleRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, RestrictedSparring_BattleCourt_EventScript_SetUpOpponent
	.2byte 0

MasterDojo_BattleRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_1, 0, MasterDojo_Lobby_EventScript_PlayerFaceEast
	.2byte 0


MasterDojo_Lobby_EventScript_PlayerFaceEast::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end


MasterDojo_BattleRoom_EventScript_EnterRoomMovement::
	applymovement 1, MasterDojo_BattleRoom_Movement_AttendantEnter
	applymovement OBJ_EVENT_ID_PLAYER, MasterDojo_BattleRoom_Movement_PlayerEnter
	waitmovement 1
	goto RestrictedSparring_BattleCourt_EventScript_OpponentEnter
	return


MasterDojo_BattleRoom_EventScript_ContinueChallengeMovement::
	applymovement OBJ_EVENT_ID_PLAYER, MasterDojo_BattleRoom_Movement_PlayerStartBattle
	applymovement OBJ_EVENT_ID_CAMERA, MasterDojo_BattleRoom_Movement_CameraPanRight
	applymovement 1, MasterDojo_BattleRoom_Movement_AttendantReturnToPosition
	waitmovement 1
	return


MasterDojo_BattleRoom_EventScript_OpponentEnterMovement::
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	applymovement 1, Common_Movement_WalkInPlaceDown
	return


MasterDojo_BattleRoom_EventScript_DeafeatedOpponentMovement::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MasterDojo_BattleRoom_Movement_CameraPanLeft
	applymovement OBJ_EVENT_ID_PLAYER, MasterDojo_BattleRoom_Movement_PlayerReturnPosition
	applymovement 1, MasterDojo_BattleRoom_Movement_AttendantApproachPlayer
	waitmovement OBJ_EVENT_ID_CAMERA
	removeobject 2
	waitmovement 1
	return


MasterDojo_BattleRoom_EventScript_RefreshOpponentObject::
	removeobject 2
	addobject 2
	return


MasterDojo_BattleRoom_Movement_AttendantEnter:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_down
	step_end

MasterDojo_BattleRoom_Movement_AttendantApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MasterDojo_BattleRoom_Movement_AttendantReturnToPosition:
	walk_up
	walk_right
	walk_right
	walk_right
	face_down
	step_end

MasterDojo_BattleRoom_Movement_PlayerEnter:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MasterDojo_BattleRoom_Movement_PlayerStartBattle:
	walk_right
	walk_right
	step_end

MasterDojo_BattleRoom_Movement_PlayerReturnPosition:
	walk_left
	walk_left
	face_up
	step_end

MasterDojo_BattleRoom_Movement_CameraPanLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MasterDojo_BattleRoom_Movement_CameraPanRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
