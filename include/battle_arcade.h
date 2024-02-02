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


#define ARCADE_GEN4_EFFECTS_BANNED //If the Battle Arcade feature is being used in a repo where Trick Room and Fog are implemented field effects, comment out or delete this line. Changes to BattleArcade_DoFog and BattleArcade_DoTrickRoom may be required.
