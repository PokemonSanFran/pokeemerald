void CallRestrictedSparringFunc(void);
bool32 Sparring_CheckIfPartyMonMatchesType(struct Pokemon *mon);
u32 Sparring_SetChallengeNumToMax(u8);
void Sparring_FillWindows(u16);
#ifdef RESTRICTED_SPARRING_MONS
void Sparring_DestroyMonIconFreeResources(u16);
#endif
void Sparring_ShowResultsWindow(void);
void Sparring_CloseWinsWindow(void);
void Sparring_ShowWinsWindow(void);
