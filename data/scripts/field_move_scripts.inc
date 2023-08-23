@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
    // Start frictionless_field_moves Branch
	//checkpartymove MOVE_CUT
    checkitem ITEM_CUT_TOOL, 1
    goto_if_eq VAR_RESULT, TRUE, EventScript_UseCutTool
    checkpartylearnknowsfieldmove ITEM_HM01
    // End frictionless_field_moves Branch
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

// Start frictionless_field_moves Branch
@ Use cut with item
EventScript_UseCutTool::
    lockall
	bufferitemname STR_VAR_2, ITEM_CUT_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    closemessage
    goto EventScript_CutTreeDown
	end
// End frictionless_field_moves Branch

EventScript_CutTreeDown::
    setflag FLAG_SYS_USE_CUT
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "This tree looks like it can be\n"
	.string "CUT down!\p"
	.string "Would you like to CUT it?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_PlayerUsedFieldTool: // frictionless_field_moves Branch
    .string "{PLAYER} used {STR_VAR_2}!$" @ frictionless_field_moves Branch

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "CUT down!$"

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
	//checkpartymove MOVE_ROCK_SMASH
    // Start frictionless_field_moves Branch
    checkitem ITEM_ROCKSMASH_TOOL, 1
    goto_if_eq VAR_RESULT, TRUE, EventScript_UseRockSmashTool
    checkpartylearnknowsfieldmove ITEM_HM06
    // End frictionless_field_moves Branch
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

// Start frictionless_field_moves Branch
@ Use rock smash with item
EventScript_UseRockSmashTool::
    lockall
	bufferitemname STR_VAR_2,ITEM_ROCKSMASH_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    closemessage
    goto EventScript_SmashRock
	end
// End frictionless_field_moves Branch

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

EventScript_SmashRock::
    setflag FLAG_SYS_USE_ROCK_SMASH // frictionless_field_moves Branch
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_EndSmash::
	releaseall
	end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"

Text_CantSmash:
	.string "It's a rugged rock, but a POKéMON\n"
	.string "may be able to smash it.$"

EventScript_StrengthBoulder::
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
    // Start frictionless_field_moves
	//checkpartymove MOVE_STRENGTH
    checkitem ITEM_STRENGTH_TOOL, 1
    goto_if_eq VAR_RESULT, TRUE, EventScript_ActivateStrengthTool
    checkpartylearnknowsfieldmove ITEM_HM04
    // End frictionless_field_moves
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

// Start frictionless_field_moves Branch
EventScript_ActivateStrengthTool::
    lockall
    setflag FLAG_SYS_USE_STRENGTH
	bufferitemname STR_VAR_2, ITEM_STRENGTH_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    msgbox Text_StrengthToolMade, MSGBOX_DEFAULT
    releaseall
    end
// End frictionless_field_moves Branch

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"

Text_MonUsedStrength:
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated:
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"

// Start frictionless_field_moves Branch
Text_StrengthToolMade:
    .string "{STR_VAR_2} made it possible to move \n"
	.string "boulders around.$"
// End frictionless_field_moves Branch

EventScript_UseWaterfall::
	lockall
    // Start frictionless_field_moves Branch
	//checkpartymove MOVE_WATERFALL
    checkitem ITEM_WATERFALL_TOOL, 1
    goto_if_eq VAR_RESULT, TRUE, EventScript_UseWaterfallTool
    checkpartylearnknowsfieldmove ITEM_HM07
    // End frictionless_field_moves Branch
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
EventScript_UseWaterfallMon::
	dofieldeffect FLDEFF_USE_WATERFALL
    setflag FLAG_SYS_USE_WATERFALL
	goto EventScript_EndWaterfall

// Start frictionless_field_moves Branch
@ Use waterfall with tool by walking into it
EventScript_WalkWaterfallTool::
    lockall
	bufferitemname STR_VAR_2, ITEM_WATERFALL_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    setflag FLAG_SYS_USE_WATERFALL
    waitmessage
	goto EventScript_EndWaterfall

@ Use waterfall with tool through menu
EventScript_UseWaterfallTool::
    lockall
	bufferitemname STR_VAR_2, ITEM_WATERFALL_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    waitmessage
    setflag FLAG_SYS_USE_WATERFALL
    callnative CreateClimbWaterfallTask
	goto EventScript_EndWaterfall
// End frictionless_field_moves Branch

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"

Text_MonUsedWaterfall:
	.string "{STR_VAR_1} used WATERFALL.$"

EventScript_UseDive::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

Text_CantDive:
	.string "The sea is deep here. A POKéMON\n"
	.string "may be able to go underwater.$"

Text_WantToDive:
	.string "The sea is deep here.\n"
	.string "Would you like to use DIVE?$"

Text_MonUsedDive:
	.string "{STR_VAR_1} used DIVE.$"

Text_CantSurface:
	.string "Light is filtering down from above.\n"
	.string "A POKéMON may be able to surface.$"

Text_WantToSurface:
	.string "Light is filtering down from above.\n"
	.string "Would you like to use DIVE?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"
