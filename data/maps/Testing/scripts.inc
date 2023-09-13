Testing_MapScripts::
	.byte 0

YoureGood_Script::
	msgbox YoureGood_Script_Text_0, MSGBOX_NPC
	closemessage
	release
	end


GivePlayerTool_Script::
	lock
	checkitem ITEM_CUT_TOOL
	compare VAR_RESULT, 0
	goto_if_ne GivePlayerTool_Script_2
GivePlayerTool_Script_1:
	additem ITEM_CUT_TOOL, 1
	additem ITEM_FLY_TOOL, 1
	additem ITEM_SURF_TOOL, 1
	additem ITEM_STRENGTH_TOOL, 1
	additem ITEM_FLASH_TOOL, 1
	additem ITEM_ROCKSMASH_TOOL, 1
	additem ITEM_WATERFALL_TOOL, 1
	additem ITEM_DIVE_TOOL, 1
	additem ITEM_TELEPORT_TOOL, 1
	additem ITEM_SWEETSCENT_TOOL, 1
	call GivePlayerFlags_Script
	msgbox GivePlayerTool_Script_Text_0, MSGBOX_NPC
	closemessage
	release
	end

GivePlayerTool_Script_2:
	goto YoureGood_Script
	goto GivePlayerTool_Script_1


GivePlayerMons_Script::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, GivePlayerMons_Script_2
GivePlayerMons_Script_1:
	checkitem ITEM_HM01
	compare VAR_RESULT, 0
	goto_if_ne GivePlayerMons_Script_5
GivePlayerMons_Script_4:
	checkitem ITEM_HM01
	compare VAR_RESULT, 0
	goto_if_eq GivePlayerMons_Script_8
GivePlayerMons_Script_7:
	closemessage
	release
	end

GivePlayerMons_Script_2:
	goto YoureGood_Script
	goto GivePlayerMons_Script_1

GivePlayerMons_Script_5:
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	msgbox GivePlayerBadge_Script_Text_0, MSGBOX_NPC
	goto GivePlayerMons_Script_4

GivePlayerMons_Script_8:
	call GivePlayerFlags_Script
	additem ITEM_HM01
	additem ITEM_HM02
	additem ITEM_HM03
	additem ITEM_HM04
	additem ITEM_HM05
	additem ITEM_HM06
	additem ITEM_HM07
	additem ITEM_HM08
	givemon SPECIES_GOLDUCK, 100, 0
	givemon SPECIES_TROPIUS, 100, 0
	givemon SPECIES_GENGAR, 100, 0
	givemon SPECIES_ODDISH, 8, 0
	givemon SPECIES_ABRA, 2, 0
	msgbox GivePlayerMons_Script_Text_0, MSGBOX_NPC
	goto GivePlayerMons_Script_7


YoureGood_Script_Text_0:
	.string "you're good!$"

GivePlayerFlags_Script::
    setflag FLAG_SYS_B_DASH
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_VISITED_OLDALE_TOWN
	setflag FLAG_VISITED_DEWFORD_TOWN
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_VISITED_SLATEPORT_CITY
	setflag FLAG_VISITED_MAUVILLE_CITY
	setflag FLAG_VISITED_RUSTBORO_CITY
	setflag FLAG_VISITED_FORTREE_CITY
	setflag FLAG_VISITED_LILYCOVE_CITY
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_SYS_POKEMON_GET
	setrespawn HEAL_LOCATION_FORTREE_CITY
	return


GivePlayerTool_Script_Text_0:
	.string "now you have all the items.$"

GivePlayerMons_Script_Text_0:
	.string "now you have mons.$"

GivePlayerBadge_Script_Text_0:
    .string "now you have badges.$"
