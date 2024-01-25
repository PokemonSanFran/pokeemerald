#ifndef GUARD_CONSTANTS_ARCADE_H
#define GUARD_CONSTANTS_ARCADE_H

#define ARCADE_FUNC_INIT                        0
#define ARCADE_FUNC_GET_DATA                    1
#define ARCADE_FUNC_SET_DATA                    2
#define ARCADE_FUNC_SAVE                        3
#define ARCADE_FUNC_GENERATE_OPPONENT           5
#define ARCADE_FUNC_TAKE_ENEMY_ITEMS            6
#define ARCADE_FUNC_PLAY_GAME_BOARD             7
#define ARCADE_FUNC_EVENT_CLEAN_UP              9
#define ARCADE_FUNC_SET_BATTLE_WON              10
#define ARCADE_FUNC_GIVE_BATTLE_POINTS          11
#define ARCADE_FUNC_CHECK_SYMBOL                12
#define ARCADE_FUNC_GET_PRINT_FROM_STREAK       13
#define ARCADE_FUNC_CHECK_BRAIN_STATUS          14
#define ARCADE_FUNC_SET_BRAIN_OBJECT            15
#define ARCADE_FUNC_RECORDS                     16

#define ARCADE_DATA_WIN_STREAK                  1
#define ARCADE_DATA_WIN_STREAK_ACTIVE           2

#define ARCADE_STREAK_NUM_0                     0
#define ARCADE_STREAK_NUM_1                     1
#define ARCADE_STREAK_NUM_2                     2
#define ARCADE_STREAK_NUM_3                     3
#define ARCADE_STREAK_NUM_4                     4
#define ARCADE_STREAK_NUM_5                     5
#define ARCADE_STREAK_NUM_6                     6
#define ARCADE_STREAK_NUM_COUNT                 ARCADE_STREAK_NUM_6 + 1

#define ARCADE_BP_SMALL                         1
#define ARCADE_BP_BASE                          2
#define ARCADE_BP_BIG                           3

#define ARCADE_EVENT_LEVEL_INCREASE             3

#define ARCADE_SYMBOL_NONE                      0
#define ARCADE_SYMBOL_SILVER                    1
#define ARCADE_SYMBOL_GOLD                      2

#define ARCADE_SILVER_BATTLE_NUMBER             35
#define ARCADE_GOLD_BATTLE_NUMBER               70

#define ARCADE_RECORD_HEADER_Y_POSITION         4
#define ARCADE_RECORD_ROWS_DEFAULT_Y_POSITION   50
#define ARCADE_RECORD_ROWS_MARGIN               20
#define ARCADE_RECORD_STREAK_INDEX_COUNT        2

#define ARCADE_EVENT_LOWER_HP                   0
#define ARCADE_EVENT_POISON                     1
#define ARCADE_EVENT_PARALYZE                   2
#define ARCADE_EVENT_BURN                       3
#define ARCADE_EVENT_SLEEP                      4
#define ARCADE_EVENT_FREEZE                     5
#define ARCADE_EVENT_GIVE_BERRY                 6
#define ARCADE_EVENT_GIVE_ITEM                  7
#define ARCADE_EVENT_LEVEL_UP                   8
#define ARCADE_EVENT_SUN                        9
#define ARCADE_EVENT_RAIN                       10
#define ARCADE_EVENT_SAND                       11
#define ARCADE_EVENT_HAIL                       12
#define ARCADE_EVENT_FOG                        13
#define ARCADE_EVENT_TRICK_ROOM                 14
#define ARCADE_EVENT_SWAP                       15
#define ARCADE_EVENT_SPEED_UP                   16
#define ARCADE_EVENT_SPEED_DOWN                 17
#define ARCADE_EVENT_RANDOM                     18
#define ARCADE_EVENT_GIVE_BP_SMALL              19
#define ARCADE_EVENT_NO_BATTLE                  20
#define ARCADE_EVENT_GIVE_BP_BIG                21
#define ARCADE_EVENT_NO_EVENT                   22

#define ARCADE_EVENT_INDIVIDUAL_START           0
#define ARCADE_EVENT_WEATHER_START              ARCADE_EVENT_LEVEL_UP + 1
#define ARCADE_EVENT_SPECIAL_START              ARCADE_EVENT_TRICK_ROOM + 1
#define ARCADE_EVENT_COUNT                      ARCADE_EVENT_NO_EVENT + 1
#define ARCADE_EVENT_SPECIAL_COUNT              ARCADE_EVENT_COUNT - ARCADE_EVENT_SPECIAL_START

#define ARCADE_IMPACT_OPPONENT                  0
#define ARCADE_IMPACT_PLAYER                    1
#define ARCADE_IMPACT_ALL                       2
#define ARCADE_IMPACT_SPECIAL                   3
#define ARCADE_IMPACT_COUNT                     4

#define ARCADE_WINSTREAK_BRACKET_0_4            0
#define ARCADE_WINSTREAK_BRACKET_5_10           1
#define ARCADE_WINSTREAK_BRACKET_11_15          2
#define ARCADE_WINSTREAK_BRACKET_16_20          3
#define ARCADE_WINSTREAK_BRACKET_21_PLUS        4
#define ARCADE_WINSTREAK_BRACKET_INDEX_COUNT    ARCADE_WINSTREAK_BRACKET_21_PLUS + 1

#define ARCADE_SPEED_LEVEL_0                    0
#define ARCADE_SPEED_LEVEL_1                    1
#define ARCADE_SPEED_LEVEL_2                    2
#define ARCADE_SPEED_LEVEL_3                    3
#define ARCADE_SPEED_LEVEL_4                    4
#define ARCADE_SPEED_LEVEL_5                    5
#define ARCADE_SPEED_LEVEL_6                    6
#define ARCADE_SPEED_LEVEL_7                    7
#define ARCADE_SPEED_COUNT                      ARCADE_SPEED_LEVEL_7 + 1

#define ARCADE_SPEED_DEFAULT                    ARCADE_SPEED_LEVEL_4
#define ARCADE_SPEED_LEVEL_MIN                  ARCADE_SPEED_LEVEL_0
#define ARCADE_SPEED_LEVEL_MAX                  ARCADE_SPEED_LEVEL_7

#define ARCADE_BERRY_GROUP_1                    0
#define ARCADE_BERRY_GROUP_2                    1
#define ARCADE_BERRY_GROUP_3                    2
#define ARCADE_BERRY_GROUP_COUNT                ARCADE_BERRY_GROUP_3 + 1
#define ARCADE_BERRY_GROUP_SIZE                 10

#define ARCADE_ITEM_GROUP_1                     ARCADE_BERRY_GROUP_1
#define ARCADE_ITEM_GROUP_2                     ARCADE_BERRY_GROUP_2
#define ARCADE_ITEM_GROUP_3                     ARCADE_BERRY_GROUP_3
#define ARCADE_ITEM_GROUP_COUNT                 ARCADE_BERRY_GROUP_COUNT
#define ARCADE_ITEM_GROUP_SIZE                  10

#define ARCADE_GAME_BOARD_ROWS                  4
#define ARCADE_GAME_BOARD_SPACES_PER_ROWS       4
#define ARCADE_GAME_BOARD_SPACES                ARCADE_GAME_BOARD_ROWS * ARCADE_GAME_BOARD_SPACES_PER_ROWS

#define ARCADE_BRAIN_DEFEAT_POINTS              20

#define ARCADE_BOARD_MODE_WAIT                  0
#define ARCADE_BOARD_MODE_COUNTDOWN_3           1
#define ARCADE_BOARD_MODE_COUNTDOWN_2           2
#define ARCADE_BOARD_MODE_COUNTDOWN_1           3
#define ARCADE_BOARD_MODE_GAME_START            4
#define ARCADE_BOARD_MODE_GAME_FINISH           5
#define ARCADE_BOARD_MODE_CLEANUP               6

#define ARCADE_FRAMES_PER_SECOND                60

#define ARCADE_BOARD_COUNTDOWN_SECONDS          3
#define ARCADE_BOARD_COUNTDOWN_TIMER            ARCADE_BOARD_COUNTDOWN_SECONDS * ARCADE_FRAMES_PER_SECOND

#define ARCADE_BOARD_GAME_SECONDS               30
#define ARCADE_BOARD_GAME_TIMER                 ARCADE_BOARD_GAME_SECONDS * ARCADE_FRAMES_PER_SECOND

#define ARCADE_GFXTAG_EVENT                     1000
#define ARCADE_GFXTAG_LOWER_HP                  ARCADE_GFXTAG_EVENT + ARCADE_EVENT_LOWER_HP
#define ARCADE_GFXTAG_POISON                    ARCADE_GFXTAG_EVENT + ARCADE_EVENT_POISON
#define ARCADE_GFXTAG_PARALYZE                  ARCADE_GFXTAG_EVENT + ARCADE_EVENT_PARALYZE
#define ARCADE_GFXTAG_BURN                      ARCADE_GFXTAG_EVENT + ARCADE_EVENT_BURN
#define ARCADE_GFXTAG_SLEEP                     ARCADE_GFXTAG_EVENT + ARCADE_EVENT_SLEEP
#define ARCADE_GFXTAG_FREEZE                    ARCADE_GFXTAG_EVENT + ARCADE_EVENT_FREEZE
#define ARCADE_GFXTAG_GIVE_BERRY                ARCADE_GFXTAG_EVENT + ARCADE_EVENT_GIVE_BERRY
#define ARCADE_GFXTAG_GIVE_ITEM                 ARCADE_GFXTAG_EVENT + ARCADE_EVENT_GIVE_ITEM
#define ARCADE_GFXTAG_LEVEL_UP                  ARCADE_GFXTAG_EVENT + ARCADE_EVENT_LEVEL_UP
#define ARCADE_GFXTAG_SUN                       ARCADE_GFXTAG_EVENT + ARCADE_EVENT_SUN
#define ARCADE_GFXTAG_RAIN                      ARCADE_GFXTAG_EVENT + ARCADE_EVENT_RAIN
#define ARCADE_GFXTAG_SAND                      ARCADE_GFXTAG_EVENT + ARCADE_EVENT_SAND
#define ARCADE_GFXTAG_HAIL                      ARCADE_GFXTAG_EVENT + ARCADE_EVENT_HAIL
#define ARCADE_GFXTAG_FOG                       ARCADE_GFXTAG_EVENT + ARCADE_EVENT_FOG
#define ARCADE_GFXTAG_TRICK_ROOM                ARCADE_GFXTAG_EVENT + ARCADE_EVENT_TRICK_ROOM
#define ARCADE_GFXTAG_SWAP                      ARCADE_GFXTAG_EVENT + ARCADE_EVENT_SWAP
#define ARCADE_GFXTAG_SPEED_UP                  ARCADE_GFXTAG_EVENT + ARCADE_EVENT_SPEED_UP
#define ARCADE_GFXTAG_SPEED_DOWN                ARCADE_GFXTAG_EVENT + ARCADE_EVENT_SPEED_DOWN
#define ARCADE_GFXTAG_RANDOM                    ARCADE_GFXTAG_EVENT + ARCADE_EVENT_RANDOM
#define ARCADE_GFXTAG_GIVE_BP_SMALL             ARCADE_GFXTAG_EVENT + ARCADE_EVENT_GIVE_BP_SMALL
#define ARCADE_GFXTAG_NO_BATTLE                 ARCADE_GFXTAG_EVENT + ARCADE_EVENT_NO_BATTLE
#define ARCADE_GFXTAG_GIVE_BP_BIG               ARCADE_GFXTAG_EVENT + ARCADE_EVENT_GIVE_BP_BIG
#define ARCADE_GFXTAG_NO_EVENT                  ARCADE_GFXTAG_EVENT + ARCADE_EVENT_NO_EVENT

#define ARCADE_GFXTAG_CURSOR                    2000

#define BAR_LEFT_PADDING                        4
#define BAR_TOP_PADDING                         1

#define ARCADE_TILEMAP_BUFFER_SIZE              1024 * 2

#define FRONTIER_SAVEDATA                       gSaveBlock2Ptr->frontier
#define ARCADE_CURRENT_STREAK_WINS              FRONTIER_SAVEDATA.arcadeWinStreaks
#define ARCADE_RECORDED_WINS                    FRONTIER_SAVEDATA.arcadeRecordWinStreaks
#define ARCADE_CURSOR                           FRONTIER_SAVEDATA.gameCursor

#define LOCAL_VAR_GAME_BOARD_EVENT              gSpecialVar_0x8007
#define LOCAL_VAR_GAME_BOARD_IMPACT             gSpecialVar_0x8008
#define LOCAL_VAR_GAME_BOARD_SUCCESS            gSpecialVar_0x8009

#define VAR_FACILITY_CHALLENGE_STATUS           VAR_TEMP_0

#define VAR_ARCADE_BERRY                        VAR_UNUSED_0x40FA
#define VAR_ARCADE_ITEM                         VAR_UNUSED_0x409D

#define FLAG_ARCADE_SILVER_PRINT                FLAG_UNUSED_0x020
#define FLAG_ARCADE_GOLD_PRINT                  FLAG_UNUSED_0x021

#define DEFAULT_ANIM                            0

#endif //GUARD_CONSTANTS_ARCADE_H
