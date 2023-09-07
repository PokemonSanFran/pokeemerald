#ifndef GUARD_ITEM_USE_H
#define GUARD_ITEM_USE_H

void ItemUseOutOfBattle_Mail(u8);
void ItemUseOutOfBattle_Bike(u8);
void ItemUseOutOfBattle_Rod(u8);
void ItemUseOutOfBattle_Itemfinder(u8);
void ItemUseOutOfBattle_PokeblockCase(u8);
void ItemUseOutOfBattle_CoinCase(u8);
void ItemUseOutOfBattle_PowderJar(u8);
void ItemUseOutOfBattle_SSTicket(u8);
void ItemUseOutOfBattle_WailmerPail(u8);
void ItemUseOutOfBattle_Medicine(u8);
void ItemUseOutOfBattle_ReduceEV(u8);
void ItemUseOutOfBattle_SacredAsh(u8);
void ItemUseOutOfBattle_PPRecovery(u8);
void ItemUseOutOfBattle_PPUp(u8);
void ItemUseOutOfBattle_RareCandy(u8);
void ItemUseOutOfBattle_TMHM(u8);
void ItemUseOutOfBattle_Repel(u8);
void ItemUseOutOfBattle_EscapeRope(u8);
void ItemUseOutOfBattle_BlackWhiteFlute(u8);
void ItemUseOutOfBattle_EvolutionStone(u8);
void ItemUseOutOfBattle_Berry(u8);
void ItemUseOutOfBattle_EnigmaBerry(u8);
void ItemUseOutOfBattle_CannotUse(u8);
void ItemUseInBattle_PokeBall(u8);
void ItemUseInBattle_StatIncrease(u8);
void ItemUseInBattle_Medicine(u8);
void ItemUseInBattle_PPRecovery(u8);
void ItemUseInBattle_Escape(u8);
void ItemUseInBattle_EnigmaBerry(u8);
void Task_UseDigEscapeRopeOnField(u8 taskId);
u8 CanUseDigOrEscapeRopeOnCurMap(void);
u8 CheckIfItemIsTMHMOrEvolutionStone(u16 itemId);

void ItemUseOutOfBattle_Cut_Tool(u8);
static void ItemUseOnFieldCB_Cut_Tool(u8);

void ItemUseOutOfBattle_Fly_Tool(u8);
static void CB2_OpenFly_ToolFromBag(void);
static void Task_OpenRegisteredFly_Tool(u8 taskId);

void ItemUseOutOfBattle_Surf_Tool(u8);
static void ItemUseOnFieldCB_Surf_Tool(u8);

void ItemUseOutOfBattle_Strength_Tool(u8);
static void ItemUseOnFieldCB_Strength_Tool(u8);

void ItemUseOutOfBattle_Flash_Tool(u8);
void ItemUseOnFieldCB_Flash_Tool(u8 taskId);

void ItemUseOutOfBattle_RockSmash_Tool(u8);
static void ItemUseOnFieldCB_RockSmash_Tool(u8);

void ItemUseOutOfBattle_Waterfall_Tool(u8);
static void ItemUseOnFieldCB_Waterfall_Tool(u8);

void ItemUseOutOfBattle_Dive_Tool(u8);
static void ItemUseOnFieldCB_Dive_Tool(u8);

void ItemUseOutOfBattle_Teleport_Tool(u8);
static void ItemUseOnFieldCB_Teleport_Tool(u8);

void ItemUseOutOfBattle_SweetScent_Tool(u8);
static void ItemUseOnFieldCB_SweetScent_Tool(u8);

#endif // GUARD_ITEM_USE_H
