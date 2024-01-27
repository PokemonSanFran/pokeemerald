void CallBattleArcadeFunc(void);
void ConvertFacilityFromArcadeToPike(u32*);
u32 GetArcadePrintCount();

#define ARCADE_GEN4_EFFECTS_BANNED //If the Battle Arcade feature is being used in a repo where Trick Room and Fog are implemented field effects, comment out or delete this line. Changes to BattleArcade_DoFog and BattleArcade_DoTrickRoom may be required.
