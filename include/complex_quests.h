#ifndef GUARD_COMPLEX_QUESTS_H
#define GUARD_COMPLEX_QUESTS_H

#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_use.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "quests.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"
#include "pokemon_icon.h"

/////////////////////////////////////////////
/////////////BEGIN STRING EXTERNS/////////////

//Descriptions
//Hearts and Diamonds
extern const u8 gText_Quest3Desc_1[];
extern const u8 gText_Quest3Desc_2[];
extern const u8 gText_Quest3Desc_3[];

extern const u8 *const gTable_Quest3Descs[];

//Maps
//Heart Quest
extern const u8 gText_Quest3Map_1[];
extern const u8 gText_Quest3Map_2[];
extern const u8 gText_Quest3Map_3[];

extern const u8 *const gTable_Quest3Maps[];

/////////////END STRING EXTERNS/////////////
////////////////////////////////////////////

/////////////////////////////////////////
///////////BEGIN QUEST STRINGS///////////

/////BEGIN DESCRIPTIONS/////

//Hearts and Diamonds Descriptions
const u8 gText_Quest3Desc_1[] = _("Content 1");
const u8 gText_Quest3Desc_2[] = _("Content 2");
const u8 gText_Quest3Desc_3[] = _("Content 3");

//////END DESCRIPTIONS//////

//////////BEGIN MAPS////////

//Heart Quest Maps
const u8 gText_Quest3Map_1[] = _("Content 1");
const u8 gText_Quest3Map_2[] = _("Content 2");
const u8 gText_Quest3Map_3[] = _("Content 3");

/////////END MAPS///////////

////////////////////////////////////////
///////////BEGIN QUEST ARRAYS///////////

//Hearts Quest Arrays
const u8 *const gTable_Quest3Descs[3] = {
    gText_Quest3Desc_1,
    gText_Quest3Desc_2,
    gText_Quest3Desc_3,
};

const u8 *const gTable_Quest3Maps[3] = {
    gText_Quest3Map_1,
    gText_Quest3Map_2,
    gText_Quest3Map_3,
};

static const u16 Quest3Sprites[3]={
	OBJ_EVENT_GFX_WALLY,
	OBJ_EVENT_GFX_WALLY,
	OBJ_EVENT_GFX_WALLY,
};

static const u8 Quest3SpriteTypes[3]={
	OBJECT,
	OBJECT,
	OBJECT,
};

/////////END QUEST ARRAYS/////////
//////////////////////////////////

#endif