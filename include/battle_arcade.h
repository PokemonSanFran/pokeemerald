#ifdef BATTLE_ARCADE
void CallBattleArcadeFunc(void);
bool32 Arcade_CheckIfPartyMonMatchesType(struct Pokemon *mon);
u32 Arcade_SetChallengeNumToMax(u8);
void Arcade_FillWindows(u16);
void Arcade_ShowResultsWindow(void);
void Arcade_CloseWinsWindow(void);
void Arcade_ShowWinsWindow(void);
void DoSpecialRouletteTrainerBattle(void);
#endif
