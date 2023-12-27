#ifndef GUARD_CONSTANTS_ARCADE_H
#define GUARD_CONSTANTS_ARCADE_H

#define ARCADE_FUNC_INIT                       0
#define ARCADE_FUNC_GET_DATA                   1
#define ARCADE_FUNC_SET_DATA                   2
#define ARCADE_FUNC_SET_BATTLE_WON             3
#define ARCADE_FUNC_SAVE                       4
#define ARCADE_FUNC_SET_OPPONENT               5
#define ARCADE_FUNC_GET_OPPONENT_INTRO         6
#define ARCADE_FUNC_GIVE_BATTLE_POINTS         7
#define ARCADE_FUNC_CHECK_SYMBOL               8
#define ARCADE_FUNC_TAKE_PLAYER_ITEMS          9
#define ARCADE_FUNC_TAKE_ENEMY_ITEMS           10
#define ARCADE_FUNC_HANDLE_GAME_RESULT         11
#define ARCADE_FUNC_CHECK_BRAIN_STATUS         12
#define ARCADE_FUNC_GET_BRAIN_INTRO            13

#define ARCADE_DATA_WIN_STREAK                 1
#define ARCADE_DATA_WIN_STREAK_ACTIVE          2
#define ARCADE_DATA_LVL_MODE                   3

#define ARCADE_BP_SMALL                        1
#define ARCADE_BP_BASE                         2
#define ARCADE_BP_BIG                          3

#define ARCADE_SYMBOL_NONE                     0
#define ARCADE_SYMBOL_SILVER                   1
#define ARCADE_SYMBOL_GOLD                     2

#define ARCADE_RECORD_LEVEL_HEADER_X_POS       8
#define ARCADE_RECORD_DATA_X_POS               80

#define ARCADE_RECORD_HEADER_Y_POS             2
#define ARCADE_RECORD_SEPERATOR_Y_POS          10
#define ARCADE_RECORD_50_LEVEL_Y_POS           49
#define ARCADE_RECORD_50_LEVEL_BEST_Y_POS      65
#define ARCADE_RECORD_OPEN_LEVEL_Y_POS         97
#define ARCADE_RECORD_OPEN_LEVEL_BEST_Y_POS    113

#define ARCADE_EVENT_LOWER_HP                  0
#define ARCADE_EVENT_POISON                    1
#define ARCADE_EVENT_PARALYZE                  2
#define ARCADE_EVENT_BURN                      3
#define ARCADE_EVENT_SLEEP                     4
#define ARCADE_EVENT_FREEZE                    5
#define ARCADE_EVENT_GIVE_BERRY                6
#define ARCADE_EVENT_GIVE_ITEM                 7
#define ARCADE_EVENT_LEVEL_UP                  8
#define ARCADE_EVENT_SUN                       9
#define ARCADE_EVENT_FIELD_START               ARCADE_EVENT_SUN
#define ARCADE_EVENT_RAIN                      10
#define ARCADE_EVENT_SAND                      11
#define ARCADE_EVENT_HAIL                      12
#define ARCADE_EVENT_FOG                       13
#define ARCADE_EVENT_TRICK_ROOM                14
#define ARCADE_EVENT_SWAP                      15
#define ARCADE_EVENT_SPEED_UP                  16
#define ARCADE_EVENT_SPEED_DOWN                17
#define ARCADE_EVENT_RANDOM                    18
#define ARCADE_EVENT_GIVE_BP_SMALL             19
#define ARCADE_EVENT_GIVE_BP_BIG               20
#define ARCADE_EVENT_NO_BATTLE                 21
#define ARCADE_EVENT_NO_EVENT                  22
#define ARCADE_EVENT_COUNT                     23

#define ARCADE_IMPACT_PLAYER                   0
#define ARCADE_IMPACT_OPPONENT                 1
#define ARCADE_IMPACT_ALL                      2

#define ARCADE_SPEED_DEFAULT                   10
#define ARCADE_SPEED_INCREMENT                 1
#define ARCADE_SPEED_DECREMENT                 2

#define ARCADE_BERRY_GROUP_1                   0
#define ARCADE_BERRY_GROUP_2                   1
#define ARCADE_BERRY_GROUP_3                   2
#define ARCADE_BERRY_GROUP_COUNT               3
#define ARCADE_BERRY_GROUP_SIZE                10

#define ARCADE_ITEM_GROUP_1                    0
#define ARCADE_ITEM_GROUP_2                    1
#define ARCADE_ITEM_GROUP_3                    2
#define ARCADE_ITEM_GROUP_COUNT                3
#define ARCADE_ITEM_GROUP_SIZE                10

#define ARCADE_ENEMY_HOLD_NOTHING              0
#define ARCADE_ENEMY_HOLD_BERRY                ARCADE_EVENT_GIVE_BERRY
#define ARCADE_ENEMY_HOLD_ITEM                 ARCADE_EVENT_GIVE_ITEM

#endif //GUARD_CONSTANTS_ARCADE_H
