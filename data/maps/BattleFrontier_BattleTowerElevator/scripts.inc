BattleFrontier_BattleTowerElevator_MapScripts::
# 4 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerElevator_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 7 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerElevator_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BattleFrontier_BattleTowerElevator_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 5 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerElevator_EventScript_EnterElevator
	.2byte 0

BattleFrontier_BattleTowerElevator_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerElevator_EventScript_TurnPlayerNorth
	.2byte 0


BattleFrontier_BattleTowerElevator_EventScript_TurnPlayerNorth::
# 13 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	setvar VAR_TEMP_1, 1
# 14 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleFrontier_BattleTowerElevator_EventScript_EnterElevator::
# 19 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	setvar VAR_TEMP_0, 1
# 20 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement 1, BattleFrontier_BattleTowerElevator_Movement_AttendantEnter
# 21 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_PlayerEnter
# 22 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitmovement 0
# 23 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	special BufferBattleTowerElevatorFloors
# 24 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitse
# 25 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	special MoveElevator
# 26 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 27 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	delay 48
# 28 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement 1, BattleFrontier_BattleTowerElevator_Movement_AttendantExit
# 29 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_PlayerExit
# 30 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitmovement 0
# 31 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom
	end


BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom::
# 36 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 37 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_3
# 38 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_3
# 39 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	case FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_4
# 40 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	case FRONTIER_MODE_LINK_MULTIS, BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_5
BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_1:
	return

BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_3:
# 38 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor
	goto BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_1

BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_4:
# 39 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti
	goto BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_1

BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_5:
# 40 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridorMulti
	goto BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom_1


BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor::
# 46 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR, 8, 1
# 47 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
	return


BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti::
# 52 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	goto_if_unset FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti_2
BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti_1:
# 56 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridorMulti
	return

BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti_2:
# 53 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	goto BattleFrontier_BattleTowerElevator_EventScript_WarpToPartnerRoom
	goto BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti_1


BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridorMulti::
# 60 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR, 7, 2
# 61 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
	return


BattleFrontier_BattleTowerElevator_EventScript_WarpToPartnerRoom::
# 66 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 1
# 67 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
	return


# 71 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_AttendantEnter:
# 72 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 73 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_right
# 74 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	face_down
# 75 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end

# 78 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_PlayerEnter:
# 79 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 79 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 80 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	face_down
# 81 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end

# 84 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_AttendantExit:
# 85 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 85 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 86 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	set_invisible
# 87 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end

# 90 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_PlayerExit:
# 91 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_right
# 92 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 92 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 93 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
