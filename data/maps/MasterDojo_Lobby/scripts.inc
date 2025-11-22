MasterDojo_Lobby_MapScripts::
# 11 "data/maps/MasterDojo_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MasterDojo_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 16 "data/maps/MasterDojo_Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MasterDojo_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MasterDojo_Lobby_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 13 "data/maps/MasterDojo_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, MasterDojo_Lobby_EventScript_PlayerFaceNorth
	.2byte 0

MasterDojo_Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 18 "data/maps/MasterDojo_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, RestrictedSparring_Entrance_EventScript_GetChallengeStatus
# 19 "data/maps/MasterDojo_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, RestrictedSparring_Entrance_EventScript_QuitWithoutSaving
# 20 "data/maps/MasterDojo_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, RestrictedSparring_Entrance_EventScript_ResumeChallenge
# 21 "data/maps/MasterDojo_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, RestrictedSparring_Entrance_EventScript_JudgeChallenge
# 22 "data/maps/MasterDojo_Lobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, RestrictedSparring_Entrance_EventScript_JudgeChallenge
	.2byte 0


MasterDojo_Lobby_EventScript_PlayerFaceNorth::
# 28 "data/maps/MasterDojo_Lobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 29 "data/maps/MasterDojo_Lobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

