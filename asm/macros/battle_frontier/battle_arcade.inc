#ifdef BATTLE_ARCADE
	@ Initialize the Battle Arcade challenge
	.macro arcade_init
	setvar VAR_0x8004, ARCADE_FUNC_INIT
	special CallBattleArcadeFunc
	.endm

	@ Get the value of some ARCADE_DATA_*. See GetArcadeData for the data types that can be retrieved
	.macro arcade_get data:req
	setvar VAR_0x8004, ARCADE_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallBattleArcadeFunc
	.endm

	@ Set some TOWER_DATA_* to val. See SetArcadeData for the data types that can be set
	.macro arcade_set data:req, val=0xFFFF
	setvar VAR_0x8004, ARCADE_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val != 0xFFFF
	setvar VAR_0x8006, \val
	.endif
	special CallBattleArcadeFunc
	.endm

	@ Choose and set the gfx for the next opponent. Also used by Battle Tents
	.macro arcade_setopponent
	setvar VAR_0x8004, ARCADE_FUNC_SET_OPPONENT
	special CallBattleArcadeFunc
	.endm

	@ Increments the battle number and returns the new one. Also clears E-Reader trainer if defeated, and saves the current win streak
	.macro arcade_setbattlewon
	setvar VAR_0x8004, ARCADE_FUNC_SET_BATTLE_WON
	special CallBattleArcadeFunc
	.endm

	@ Save the game and set the challenge status
	.macro arcade_save challengeStatus:req
	setvar VAR_0x8004, ARCADE_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattleArcadeFunc
	.endm

	@ Buffer the opponent's easy chat intro speech to STR_VAR_4
	.macro arcade_getopponentintro
	setvar VAR_0x8004, ARCADE_FUNC_GET_OPPONENT_INTRO
	special CallBattleArcadeFunc
	.endm

    @ Determine what continue menu type to show player
    .macro arcade_getcontinuemenutype
    setvar VAR_0x8004, ARCADE_FUNC_GET_CONTINUE_MENU_TYPE
    special CallBattleArcadeFunc
    .endm

    @ Heal player in Battle Arcade
    .macro arcade_restore
    call Common_EventScript_OutOfCenterPartyHeal
    subvar VAR_ARCADE_HEAL_COUNT,1
    .endm

    @ Restore player's non-berry held items
    .macro arcade_restorehelditems
    setvar VAR_0x8004, ARCADE_FUNC_RESTORE_HELD_ITEMS
    special CallBattleArcadeFunc
    .endm

	@ If any moves were copied using Sketch during the challenge then restore them to Sketch, but don't store the party to the saveblock
	.macro arcade_resetsketch
	setvar VAR_0x8004,ARCADE_FUNC_RESET_SKETCH_MOVES
	special CallBattleArcadeFunc
	.endm

	@ Awards battle points depending on the number of wins and if that type has already been completed
	.macro arcade_givepoints
	setvar VAR_0x8004, ARCADE_FUNC_GIVE_BATTLE_POINTS
	special CallBattleArcadeFunc
	.endm

    @ Gets the name of the type chosen for Battle Arcade and buffers it to gStringVar3
    .macro arcade_bufferarcadetype
    setvar VAR_0x8004, ARCADE_FUNC_GET_TYPE_NAME
    special CallBattleArcadeFunc
    .endm

    @ Check the number of types the player has previously won and sets VAR_RESULT to TRUE if the player has not have the appropriate symbol but has qualified for it
    .macro arcade_checksymbol
    setvar VAR_0x8004, ARCADE_FUNC_CHECK_SYMBOL
    special CallBattleArcadeFunc
    .endm

    @ Take the input from ShowBattleArcadeTypeWinsWindow and set VAR_ARCADE_TYPE by skipping TYPE_MYSTERY
    .macro arcade_convertmenutotype
    setvar VAR_0x8004, ARCADE_FUNC_CONVERT_TYPE
    special CallBattleArcadeFunc
    .endm

    @ Check the number of wins for the player, and if over the max, returns TRUE to VAR_RESULT
    .macro arcade_checkmaxstreak
    setvar VAR_0x8004, ARCADE_FUNC_CHECK_MAX
    special CallBattleArcadeFunc
    .endm
#endif
