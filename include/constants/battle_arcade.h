#ifndef GUARD_CONSTANTS_ARCADE_H
#define GUARD_CONSTANTS_ARCADE_H

#define ARCADE_FUNC_INIT                        0
#define ARCADE_FUNC_GET_DATA                    1
#define ARCADE_FUNC_SET_DATA                    2
#define ARCADE_FUNC_SAVE                        3
#define ARCADE_FUNC_GENERATE_OPPONENT           4
#define ARCADE_FUNC_TAKE_ENEMY_ITEMS            5
#define ARCADE_FUNC_PLAY_GAME_BOARD             6
#define ARCADE_FUNC_BATTLE_CLEAN_UP             7
#define ARCADE_FUNC_SET_BATTLE_WON              8
#define ARCADE_FUNC_GIVE_BATTLE_POINTS          9
#define ARCADE_FUNC_CHECK_SYMBOL                10
#define ARCADE_FUNC_GET_PRINT_FROM_STREAK       11
#define ARCADE_FUNC_CHECK_BRAIN_STATUS          12
#define ARCADE_FUNC_SET_BRAIN_OBJECT            13
#define ARCADE_FUNC_RECORDS                     14
#define ARCADE_FUNC_TAKE_PLAYER_HELD_ITEM       15

#define ARCADE_DATA_WIN_STREAK                  1
#define ARCADE_DATA_WIN_STREAK_ACTIVE           2

#define FRONTIER_SAVEDATA                       gSaveBlock2Ptr->frontier
#define ARCADE_SAVEDATA_CURRENT_STREAK          FRONTIER_SAVEDATA.arcadeWinStreaks
#define ARCADE_SAVEDATA_RECORD_STREAK           FRONTIER_SAVEDATA.arcadeRecordWinStreaks
#define ARCADE_SAVEDATA_CURSOR                  FRONTIER_SAVEDATA.gameCursor

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
#define ARCADE_EVENT_COUNT                      ARCADE_EVENT_NO_EVENT + 1

#define ARCADE_EVENT_INDIVIDUAL_START           ARCADE_EVENT_LOWER_HP
#define ARCADE_EVENT_WEATHER_START              ARCADE_EVENT_SUN
#define ARCADE_EVENT_SPECIAL_START              ARCADE_EVENT_SWAP

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

#define VAR_ARCADE_BERRY                        VAR_UNUSED_0x40FA
#define VAR_ARCADE_ITEM                         VAR_UNUSED_0x409D

#define ARCADE_BRAIN_DEFEAT_POINTS              20

#define FLAG_ARCADE_SILVER_PRINT                FLAG_UNUSED_0x020
#define FLAG_ARCADE_GOLD_PRINT                  FLAG_UNUSED_0x021

#define ARCADE_SYMBOL_NONE                      0
#define ARCADE_SYMBOL_SILVER                    1
#define ARCADE_SYMBOL_GOLD                      2

#define ARCADE_TILEMAP_BUFFER_SIZE              1024 * 2

#define ARCADE_GAME_BOARD_ROWS                  4
#define ARCADE_GAME_BOARD_COLUMNS               ARCADE_GAME_BOARD_ROWS
#define ARCADE_GAME_BOARD_SPACES                ARCADE_GAME_BOARD_ROWS * ARCADE_GAME_BOARD_COLUMNS

#define ARCADE_STREAK_NUM_MAX                   6
#define ARCADE_STREAK_NUM_COUNT                 ARCADE_STREAK_NUM_MAX + 1

#define ARCADE_BOARD_MODE_WAIT                  0
#define ARCADE_BOARD_MODE_COUNTDOWN_3           1
#define ARCADE_BOARD_MODE_COUNTDOWN_2           2
#define ARCADE_BOARD_MODE_COUNTDOWN_1           3
#define ARCADE_BOARD_MODE_GAME_START            4
#define ARCADE_BOARD_MODE_GAME_FINISH           5
#define ARCADE_BOARD_MODE_CLEANUP               6

#define ARCADE_BOARD_COUNTDOWN_SECONDS          3
#define ARCADE_BOARD_GAME_SECONDS               30
#define ARCADE_FRAMES_PER_SECOND                60

#define ARCADE_COUNTDOWN_SHOW_FRAMES_1          ARCADE_FRAMES_PER_SECOND
#define ARCADE_COUNTDOWN_SHOW_FRAMES_2          ARCADE_FRAMES_PER_SECOND * (ARCADE_BOARD_COUNTDOWN_SECONDS - 1)
#define ARCADE_BOARD_COUNTDOWN_TIMER            ARCADE_FRAMES_PER_SECOND * ARCADE_BOARD_COUNTDOWN_SECONDS
#define ARCADE_BOARD_FINISH_TIMER               ARCADE_BOARD_COUNTDOWN_TIMER
#define ARCADE_BOARD_COUNTDOWN_TIMER_END        ARCADE_BOARD_COUNTDOWN_TIMER + 10
#define ARCADE_BOARD_GAME_TIMER                 ARCADE_BOARD_GAME_SECONDS * ARCADE_FRAMES_PER_SECOND

#define ARCADE_COUNTDOWN_ANIM                   0

#define ARCADE_GFXTAG_EVENT                     1000
#define ARCADE_GFXTAG_CURSOR                    2000

#define ARCADE_PALTAG_EVENT                     1000
#define ARCADE_PALTAG_OPPONENT                 	ARCADE_PALTAG_EVENT + ARCADE_IMPACT_OPPONENT
#define ARCADE_PALTAG_PLAYER                    ARCADE_PALTAG_EVENT + ARCADE_IMPACT_PLAYER
#define ARCADE_PALTAG_CURSOR                    ARCADE_PALTAG_OPPONENT

#define ARCADE_CURSOR_COLOR_CHANGE_FRAMES       8

#define ARCADE_IMPACT_OPPONENT                  0
#define ARCADE_IMPACT_PLAYER                    1
#define ARCADE_IMPACT_ALL                       2
#define ARCADE_IMPACT_SPECIAL                   3
#define ARCADE_IMPACT_COUNT                     4

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

#define ARCADE_CURSOR_WAIT_LEVEL_0              20 * (ARCADE_FRAMES_PER_SECOND / 30)
#define ARCADE_CURSOR_WAIT_LEVEL_1              16 * (ARCADE_FRAMES_PER_SECOND / 30)
#define ARCADE_CURSOR_WAIT_LEVEL_2              8 * (ARCADE_FRAMES_PER_SECOND / 30)
#define ARCADE_CURSOR_WAIT_LEVEL_3              3 * (ARCADE_FRAMES_PER_SECOND / 30)
#define ARCADE_CURSOR_WAIT_LEVEL_4              4 * (ARCADE_FRAMES_PER_SECOND / 30)
#define ARCADE_CURSOR_WAIT_LEVEL_5              2 * (ARCADE_FRAMES_PER_SECOND / 30)
#define ARCADE_CURSOR_WAIT_LEVEL_6              1 * (ARCADE_FRAMES_PER_SECOND / 30)
#define ARCADE_CURSOR_WAIT_LEVEL_7              0 * (ARCADE_FRAMES_PER_SECOND / 30)

#define ARCADE_STREAK_BRACKET_0_4               0
#define ARCADE_STREAK_BRACKET_5_10              1
#define ARCADE_STREAK_BRACKET_11_15             2
#define ARCADE_STREAK_BRACKET_16_20             3
#define ARCADE_STREAK_BRACKET_21_PLUS           4

#define ARCADE_EVENT_LEVEL_INCREASE             3

#define ARCADE_BP_SMALL                         1
#define ARCADE_BP_BIG                           3

#define ARCADE_SILVER_BATTLE_NUMBER             35
#define ARCADE_GOLD_BATTLE_NUMBER               70

#define ARCADE_RECORD_HEADER_Y_POSITION         4
#define ARCADE_RECORD_STREAK_INDEX_COUNT        2

#define LOCAL_VAR_GAME_BOARD_EVENT              gSpecialVar_0x8007
#define LOCAL_VAR_GAME_BOARD_IMPACT             gSpecialVar_0x8008
#define LOCAL_VAR_GAME_BOARD_SUCCESS            gSpecialVar_0x8009

#endif //GUARD_CONSTANTS_ARCADE_H
