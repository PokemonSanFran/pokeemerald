BattleFrontier_BattleTowerMultiCorridor_MapScripts::
# 7 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 13 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 16 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 9 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 10 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 9 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx
	return

BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 10 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx
	return

BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 14 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattleTowerMultiCorridor_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 17 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor
	.2byte 0


BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx::
# 26 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	tower_setpartnergfx
# 27 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	checkplayergender
# 28 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	compare VAR_RESULT, FEMALE
	goto_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx_2
# 31 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BRENDAN_NORMAL
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx_1:
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx_2:
# 29 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_MAY_NORMAL
	goto BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx_1


BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx::
# 37 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	special SetBattleTowerLinkPlayerGfx
	return


BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects::
# 42 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 43 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat 1, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 44 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat 4, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 45 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	special OffsetCameraForBattle
	end


BattleFrontier_BattleTowerMultiCorridor_EventScript_SetDoorCoordinates::
# 50 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 51 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8004, 14
# 52 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8005, 1
	return


BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor::
# 57 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	lockall
# 58 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_SetDoorCoordinates
# 59 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	opendoor 1, 1
# 60 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 61 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 62 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	showobjectat 1, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 63 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	showobjectat 4, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 64 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 1, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
# 65 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 4, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
# 66 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 67 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_SetDoorCoordinates
# 68 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	closedoor 1, 1
# 69 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 70 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 71 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 1, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor
# 72 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 4, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor
# 73 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 3, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor
# 74 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 2, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor
# 75 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 76 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay 40
# 77 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 3, Common_Movement_WalkInPlaceFasterUp
# 78 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
# 79 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 80 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	opendoor 7, 1
# 81 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 82 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 3, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
# 83 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 2, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
# 84 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 1, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
# 85 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement 4, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
# 86 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 87 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	closedoor 7, 1
# 88 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 89 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay 30
# 90 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 91 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom
# 92 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	releaseall
	end


BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom::
# 97 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 98 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom_3
# 99 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom_3
# 101 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom_4
# 102 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom_4
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom_1:
# 105 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
	return

BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom_3:
# 100 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 4, 8
	goto BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom_1

BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom_4:
# 103 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 4, 5
	goto BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom_1


# 109 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor:
# 110 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 111 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 111 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 111 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 111 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 111 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 111 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 112 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end

# 115 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor:
# 116 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 117 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 117 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 117 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 117 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 117 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 117 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 118 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end

# 121 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor:
# 122 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 122 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 122 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 122 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 122 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 122 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 123 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 124 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_in_place_faster_right
# 125 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end

# 128 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor:
# 129 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 129 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 129 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 129 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 129 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 129 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 130 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 131 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_in_place_faster_left
# 132 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end

# 135 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor:
# 136 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay_16
# 137 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 137 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 138 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	set_invisible
# 139 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end

# 142 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor:
# 143 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 144 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	set_invisible
# 145 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end

# 148 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator:
# 149 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 150 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
