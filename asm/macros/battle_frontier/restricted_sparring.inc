	@ Initialize the Battle Tower challenge
	.macro sparring_init
	setvar VAR_0x8004, SPARRING_FUNC_INIT
	special CallRestrictedSparringFunc
	.endm

	@ Get the value of some TOWER_DATA_*. See GetTowerData for the data types that can be retrieved
	.macro sparring_get data:req
	setvar VAR_0x8004, SPARRING_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallRestrictedSparringFunc
	.endm

	@ Set some TOWER_DATA_* to val. See SetTowerData for the data types that can be set
	.macro sparring_set data:req, val=0xFFFF
	setvar VAR_0x8004, SPARRING_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val != 0xFFFF
	setvar VAR_0x8006, \val
	.endif
	special CallRestrictedSparringFunc
	.endm

	@ Choose and set the gfx for the next opponent. Also used by Battle Tents
	.macro sparring_setopponent
	setvar VAR_0x8004, SPARRING_FUNC_SET_OPPONENT
	special CallRestrictedSparringFunc
	.endm

	@ Increments the battle number and returns the new one. Also clears E-Reader trainer if defeated, and saves the current win streak
	.macro sparring_setbattlewon
	setvar VAR_0x8004, SPARRING_FUNC_SET_BATTLE_WON
	special CallRestrictedSparringFunc
	.endm

	@ Save the game and set the challenge status
	.macro sparring_save challengeStatus:req
	setvar VAR_0x8004, SPARRING_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallRestrictedSparringFunc
	.endm

	@ Buffer the opponent's easy chat intro speech to STR_VAR_4
	.macro sparring_getopponentintro
	setvar VAR_0x8004, SPARRING_FUNC_GET_OPPONENT_INTRO
	special CallRestrictedSparringFunc
	.endm

    @ Determine what continue menu type to show player
    .macro sparring_getcontinuemenutype
    setvar VAR_0x8004, SPARRING_FUNC_GET_CONTINUE_MENU_TYPE
    special CallRestrictedSparringFunc
    .endm

    @ Heal player in Restricted Sparring
    .macro sparring_restore
    call Common_EventScript_OutOfCenterPartyHeal
    subvar VAR_SPARRING_HEAL_COUNT,1
    .endm

    @ Restore player's non-berry held items
    .macro sparring_restorehelditems
    setvar VAR_0x8004, SPARRING_FUNC_RESTORE_HELD_ITEMS
    special CallRestrictedSparringFunc
    .endm

	@ If any moves were copied using Sketch during the challenge then restore them to Sketch, but don't store the party to the saveblock
	.macro sparring_resetsketch
	setvar VAR_0x8004,SPARRING_FUNC_RESET_SKETCH_MOVES
	special CallRestrictedSparringFunc
	.endm

	@ Awards battle points depending on the number of wins and if that type has already been completed
	.macro sparring_givepoints
	setvar VAR_0x8004, SPARRING_FUNC_GIVE_BATTLE_POINTS
	special CallRestrictedSparringFunc
	.endm

    @ Gets the name of the type chosen for Restricted Sparring and buffers it to gStringVar3
    .macro sparring_buffersparringtype
    setvar VAR_0x8004, SPARRING_FUNC_GET_TYPE_NAME
    special CallRestrictedSparringFunc
    .endm

    @ Check the number of types the player has previously won and sets VAR_RESULT to TRUE if the player has not have the appropriate symbol but has qualified for it
    .macro sparring_checksymbol
    setvar VAR_0x8004, SPARRING_FUNC_CHECK_SYMBOL
    special CallRestrictedSparringFunc
    .endm

    @ Take the input from ShowRestrictedSparringTypeWinsWindow and set VAR_SPARRING_TYPE by skipping TYPE_MYSTERY
    .macro sparring_convertmenutotype
    setvar VAR_0x8004, SPARRING_FUNC_CONVERT_TYPE
    special CallRestrictedSparringFunc
    .endm

    @ Check the number of wins for the player, and if over the max, returns TRUE to VAR_RESULT
    .macro sparring_checkmaxstreak
    setvar VAR_0x8004, SPARRING_FUNC_CHECK_MAX
    special CallRestrictedSparringFunc
    .endm
