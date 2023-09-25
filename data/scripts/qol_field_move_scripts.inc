Text_PlayerUsedFieldTool:
    .string "{PLAYER} used {STR_VAR_2}!$"

EventScript_UseCutTool::
    lockall
    bufferitemname STR_VAR_2, ITEM_CUT_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    closemessage
    goto EventScript_CutTreeDown

EventScript_UseRockSmashTool::
    lockall
    bufferitemname STR_VAR_2, ITEM_ROCKSMASH_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    closemessage
    goto EventScript_SmashRock

EventScript_UseStrengthTool::
    lockall
    call_if_set FLAG_SYS_USE_STRENGTH, EventScript_PushBoulderScript @ qol_field_moves
    setflag FLAG_SYS_USE_STRENGTH
	bufferitemname STR_VAR_2, ITEM_STRENGTH_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    msgbox Text_StrengthActivated, MSGBOX_DEFAULT
    releaseall
    end

EventScript_PushBoulderScript::
    callnative PushBoulderFromScript
    return

EventScript_UseWaterfallTool::
    lock
    bufferitemname STR_VAR_2, ITEM_WATERFALL_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    waitmessage
    setflag FLAG_SYS_USE_WATERFALL
EventScript_UseWaterfallFieldEffect::
    dofieldeffect FLDEFF_USE_WATERFALL_TOOL
    releaseall
    end

EventScript_CheckDiveToolAndParty::
    checkitem ITEM_DIVE_TOOL, 1
    goto_if_eq VAR_RESULT, TRUE, EventScript_UseDiveTool
    checkpartylearnknowsfieldmove ITEM_HM08
    return

EventScript_UseDiveTool::
    lockall
    bufferitemname STR_VAR_2, ITEM_DIVE_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    waitmessage
    dofieldeffect FLDEFF_USE_DIVE_TOOL
    goto EventScript_EndDive

EventScript_UseFlashTool::
    animateflash 1
    setflashlevel 1
    delay 40
    bufferitemname STR_VAR_2, ITEM_FLASH_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    closemessage
    end

EventScript_UseSurfTool::
    bufferitemname STR_VAR_2, ITEM_SURF_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
EventScript_UseSurfFieldEffect::
    dofieldeffect FLDEFF_USE_SURF_TOOL
    releaseall
    end

EventScript_AskTeleportTool::
    lock
    msgbox gStringVar4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelTeleportTool
EventScript_UseTeleportTool::
    dofieldeffect FLDEFF_USE_TELEPORT_TOOL
EventScript_CancelTeleportTool::
    releaseall
    end
