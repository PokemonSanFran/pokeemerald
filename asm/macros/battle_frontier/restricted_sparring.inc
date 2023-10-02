	@ Initialize the Battle Tower challenge
	.macro sparring_init
	setvar VAR_0x8004, SPARRING_FUNC_INIT
	special CallBattleTowerFunc
	.endm

	@ Get the value of some TOWER_DATA_*. See GetTowerData for the data types that can be retrieved
	.macro sparring_get data:req
	setvar VAR_0x8004, SPARRING_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallBattleTowerFunc
	.endm

	@ Set some TOWER_DATA_* to val. See SetTowerData for the data types that can be set
	.macro sparring_set data:req, val=0xFFFF
	setvar VAR_0x8004, SPARRING_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val != 0xFFFF
	setvar VAR_0x8006, \val
	.endif
	special CallBattleTowerFunc
	.endm

	@ Choose and set the gfx for the next opponent. Also used by Battle Tents
	.macro sparring_setopponent
	setvar VAR_0x8004, SPARRING_FUNC_SET_OPPONENT
	special CallBattleTowerFunc
	.endm

	@ Increments the battle number and returns the new one. Also clears E-Reader trainer if defeated, and saves the current win streak
	.macro sparring_setbattlewon
	setvar VAR_0x8004, SPARRING_FUNC_SET_BATTLE_WON
	special CallBattleTowerFunc
	.endm

	@ Save the game and set the challenge status
	.macro sparring_save challengeStatus:req
	setvar VAR_0x8004, SPARRING_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattleTowerFunc
	.endm

	@ Buffer the opponent's easy chat intro speech to STR_VAR_4
	.macro sparring_getopponentintro opponent:req
	setvar VAR_0x8004, SPARRING_FUNC_GET_OPPONENT_INTRO
	setvar VAR_0x8005, \opponent
	special CallBattleTowerFunc
	.endm

    @ Determine what continue menu type to show player
    .macro sparring_getcontinuemenutype
    setvar VAR_0x8004, SPARRING_FUNC_GET_CONTINUE_MENU_TYPE
    special CallRestrictedSparringFunc
    .endm

    @ Heal player in Restricted Sparring
    .macro sparring_restore
    call Common_EventScript_OutOfCenterPartyHeal
    subvar VAR_RESTRICTEDSPARRING_HEAL_COUNT,1
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
