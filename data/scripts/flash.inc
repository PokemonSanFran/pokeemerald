EventScript_UseFlash::
	animateflash 1
	setflashlevel 1
	end

    // Start frictionless_field_moves Branch
EventScript_UseFlashTool::
    animateflash 1
    setflashlevel 1
    delay 40
    bufferitemname STR_VAR_2, ITEM_FLASH_TOOL
    msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
    closemessage
    //End frictionless_field_moves Branch
