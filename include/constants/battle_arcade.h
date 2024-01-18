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
#define ARCADE_FUNC_EVENT_CLEAN_UP             14
#define ARCADE_FUNC_GET_IMPACT_SIDE            15
#define ARCADE_FUNC_GET_EVENT                  16
#define ARCADE_FUNC_PLAY_GAME_BOARD            17
#define ARCADE_FUNC_GENERATE_OPPONENT          18
#define ARCADE_FUNC_SET_BRAIN_OBJECT           19
#define ARCADE_FUNC_GET_PRINT_FROM_STREAK      20
#define ARCADE_FUNC_RECORDS                    21

#define ARCADE_DATA_WIN_STREAK                 1
#define ARCADE_DATA_WIN_STREAK_ACTIVE          2
#define ARCADE_DATA_LVL_MODE                   3

#define ARCADE_STREAK_NUM_0                    0
#define ARCADE_STREAK_NUM_1                    1
#define ARCADE_STREAK_NUM_2                    2
#define ARCADE_STREAK_NUM_3                    3
#define ARCADE_STREAK_NUM_4                    4
#define ARCADE_STREAK_NUM_5                    5
#define ARCADE_STREAK_NUM_6                    6
#define ARCADE_STREAK_NUM_7                    7
#define ARCADE_STREAK_NUM_COUNT                ARCADE_STREAK_NUM_7 + 1

#define ARCADE_PANEL_PROPERTIES                0

#define ARCADE_BP_SMALL                        1
#define ARCADE_BP_BASE                         2
#define ARCADE_BP_BIG                          3

#define ARCADE_SYMBOL_NONE                     0
#define ARCADE_SYMBOL_SILVER                   1
#define ARCADE_SYMBOL_GOLD                     2

#define ARCADE_SILVER_BATTLE_NUMBER            35
#define ARCADE_GOLD_BATTLE_NUMBER              70

/*
#define ARCADE_SILVER_BATTLE_NUMBER            2 // Debug
#define ARCADE_GOLD_BATTLE_NUMBER              4 // Debug
*/

#define ARCADE_RECORD_HEADER_Y_POSITION        4
#define ARCADE_RECORD_ROWS_DEFAULT_Y_POSITION  50
#define ARCADE_RECORD_ROWS_MARGIN              20
#define ARCADE_RECORD_STREAK_INDEX_COUNT       2

#define ARCADE_EVENT_INDIVIDUAL_START          0
#define ARCADE_EVENT_LOWER_HP                  0
#define ARCADE_EVENT_POISON                    1
#define ARCADE_EVENT_PARALYZE                  2
#define ARCADE_EVENT_BURN                      3
#define ARCADE_EVENT_SLEEP                     4
#define ARCADE_EVENT_FREEZE                    5
#define ARCADE_EVENT_GIVE_BERRY                6
#define ARCADE_EVENT_GIVE_ITEM                 7
#define ARCADE_EVENT_LEVEL_UP                  8
#define ARCADE_EVENT_WEATHER_START             ARCADE_EVENT_LEVEL_UP + 1
#define ARCADE_EVENT_SUN                       9
#define ARCADE_EVENT_RAIN                      10
#define ARCADE_EVENT_SAND                      11
#define ARCADE_EVENT_HAIL                      12
#define ARCADE_EVENT_FOG                       13
#define ARCADE_EVENT_TRICK_ROOM                14
#define ARCADE_EVENT_SPECIAL_START             ARCADE_EVENT_TRICK_ROOM + 1
#define ARCADE_EVENT_SWAP                      15
#define ARCADE_EVENT_SPEED_UP                  16
#define ARCADE_EVENT_SPEED_DOWN                17
#define ARCADE_EVENT_RANDOM                    18
#define ARCADE_EVENT_GIVE_BP_SMALL             19
#define ARCADE_EVENT_NO_BATTLE                 20
#define ARCADE_EVENT_GIVE_BP_BIG               21
#define ARCADE_EVENT_NO_EVENT                  22
#define ARCADE_EVENT_COUNT                     23

#define ARCADE_EVENT_SPECIAL_COUNT             ARCADE_EVENT_COUNT - ARCADE_EVENT_SPECIAL_START

#define ARCADE_IMPACT_OPPONENT                 0
#define ARCADE_IMPACT_PLAYER                   1
#define ARCADE_IMPACT_ALL                      2
#define ARCADE_IMPACT_SPECIAL                  3
#define ARCADE_IMPACT_COUNT                    4

#define ARCADE_BATTLE_NUM_0_4                  0
#define ARCADE_BATTLE_NUM_5_10                 1
#define ARCADE_BATTLE_NUM_11_15                2
#define ARCADE_BATTLE_NUM_16_20                3
#define ARCADE_BATTLE_NUM_21_PLUS              4
#define ARCADE_BATTLE_NUM_INDEX_COUNT          5

#define ARCADE_SPEED_LEVEL_0                   0
#define ARCADE_SPEED_LEVEL_1                   1
#define ARCADE_SPEED_LEVEL_2                   2
#define ARCADE_SPEED_LEVEL_3                   3
#define ARCADE_SPEED_LEVEL_4                   4
#define ARCADE_SPEED_LEVEL_5                   5
#define ARCADE_SPEED_LEVEL_6                   6
#define ARCADE_SPEED_LEVEL_7                   7
#define ARCADE_SPEED_COUNT                     ARCADE_SPEED_LEVEL_7 + 1

#define ARCADE_SPEED_DEFAULT                   ARCADE_SPEED_LEVEL_3
#define ARCADE_SPEED_LEVEL_MIN                 ARCADE_SPEED_LEVEL_0
#define ARCADE_SPEED_LEVEL_MAX                 ARCADE_SPEED_LEVEL_7

#define ARCADE_BERRY_GROUP_1                   0
#define ARCADE_BERRY_GROUP_2                   1
#define ARCADE_BERRY_GROUP_3                   2
#define ARCADE_BERRY_GROUP_COUNT               3
#define ARCADE_BERRY_GROUP_SIZE                10

#define ARCADE_ITEM_GROUP_1                    ARCADE_BERRY_GROUP_1
#define ARCADE_ITEM_GROUP_2                    ARCADE_BERRY_GROUP_2
#define ARCADE_ITEM_GROUP_3                    ARCADE_BERRY_GROUP_3
#define ARCADE_ITEM_GROUP_COUNT                ARCADE_BERRY_GROUP_COUNT
#define ARCADE_ITEM_GROUP_SIZE                10

#define ARCADE_MAX_GROUP_SIZE (max(ARCADE_ITEM_GROUP_SIZE,ARCADE_BERRY_GROUP_SIZE)+1)

#define ARCADE_HOLD_BERRY                      ARCADE_EVENT_GIVE_BERRY
#define ARCADE_HOLD_ITEM                       ARCADE_EVENT_GIVE_ITEM

#define ARCADE_EVENT_LEVEL_INCREASE            3
#define ARCADE_GAME_BOARD_SPACES               16

#define FLAG_ARCADE_SILVER_PRINT               FLAG_UNUSED_0x020
#define FLAG_ARCADE_GOLD_PRINT                 FLAG_UNUSED_0x021
#define ARCADE_BRAIN_DEFEAT_POINTS             20

#endif //GUARD_CONSTANTS_ARCADE_H
