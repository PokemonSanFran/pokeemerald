#include "constants/battle_arcade.h"

void CallBattleArcadeFunc(void);
void ConvertFacilityFromArcadeToPike(u32*);
u32 GetArcadePrintCount();

enum GameBoard_WindowIds
{
	WIN_BOARD_HELP_BAR,
	WIN_BOARD_COUNT,
};

enum GameBoard_BackgroundIds
{
	BG_BOARD_HELP_BAR,
	BG_BOARD_EVENTS,
	BG_BOARD_BACKGROUND,
	BG_BOARD_BACKBOARD,
	BG_BOARD_COUNT,
};

enum ArcadeRecord_WindowIds
{
    WIN_RECORD_TEXT,
	WIN_RECORD_DUMMY,
    WIN_RECORD_COUNT,
};

enum ArcadeRecord_BackgroundIds
{
    BG_RECORD_TEXT,
    BG_RECORD_BACKGROUND,
    BG_RECORD_COUNT,
};

struct GameResult
{
    u8 impact:2;
    u8 event:5;
};
