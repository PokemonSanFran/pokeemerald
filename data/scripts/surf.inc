EventScript_UseSurf::
    // Start frictionless_field_moves
	//checkpartymove MOVE_SURF
    checkitem ITEM_SURF_TOOL, 1
    goto_if_eq VAR_RESULT, TRUE, EventScript_UseSurfToolMessage
    checkpartylearnknowsfieldmove ITEM_HM03
    //End frictionless_field_moves
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_EndUseSurf
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
EventScript_UseSurfWithMon:: @ frictionless_field_moves
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

    // Start frictionless_field_moves
EventScript_UseSurfToolMessage::
	bufferitemname STR_VAR_2,ITEM_SURF_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    callnative(CreateStartSurfingTask)
    releaseall
    end
    //End frictionless_field_moves
