void CallRestrictedSparringFunc(void);
void GetContinueMenuType(void);
bool32 CheckIfPartyMonMatchesType(struct Pokemon *mon);
u32 MaxChallengeNumInRestrictingSparring(u8 challengeNum);
void ShowRestrictedSparringWinsWindow(void);
void CloseRestrictedSparringWinsWindow(void);
#ifdef RESTRICTED_SPARRING_MONS
void DestroyMonIconAndFreeResources(u16 menu);
#endif
void ShowSparringResultsWindow(void);
