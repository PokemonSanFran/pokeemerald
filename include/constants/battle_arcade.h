#ifndef GUARD_CONSTANTS_ARCADE_H
#define GUARD_CONSTANTS_ARCADE_H

enum ArcadeFunctions
{
    ARCADE_FUNC_INIT,
    ARCADE_FUNC_GET_DATA,
    ARCADE_FUNC_SET_DATA,
    ARCADE_FUNC_SAVE,
    ARCADE_FUNC_GENERATE_OPPONENT,
    ARCADE_FUNC_TAKE_ENEMY_ITEMS,
    ARCADE_FUNC_PLAY_GAME_BOARD,
    ARCADE_FUNC_BATTLE_CLEAN_UP,
    ARCADE_FUNC_SET_BATTLE_WON,
    ARCADE_FUNC_GIVE_BATTLE_POINTS,
    ARCADE_FUNC_CHECK_SYMBOL,
    ARCADE_FUNC_GET_PRINT_FROM_STREAK,
    ARCADE_FUNC_CHECK_BRAIN_STATUS,
    ARCADE_FUNC_SET_BRAIN_OBJECT,
    ARCADE_FUNC_RECORDS,
    ARCADE_FUNC_TAKE_PLAYER_HELD_ITEM,
};

enum ArcadeData
{
    ARCADE_DATA_WIN_STREAK = 1,
    ARCADE_DATA_WIN_STREAK_ACTIVE,
};

enum ArcadeEvents
{
    ARCADE_EVENT_LOWER_HP,
    ARCADE_EVENT_POISON,
    ARCADE_EVENT_PARALYZE,
    ARCADE_EVENT_BURN,
    ARCADE_EVENT_SLEEP,
    ARCADE_EVENT_FREEZE,
    ARCADE_EVENT_GIVE_BERRY,
    ARCADE_EVENT_GIVE_ITEM,
    ARCADE_EVENT_LEVEL_UP,
    ARCADE_EVENT_SUN,
    ARCADE_EVENT_RAIN,
    ARCADE_EVENT_SAND,
    ARCADE_EVENT_HAIL,
    ARCADE_EVENT_FOG,
    ARCADE_EVENT_TRICK_ROOM,
    ARCADE_EVENT_SWAP,
    ARCADE_EVENT_SPEED_UP,
    ARCADE_EVENT_SPEED_DOWN,
    ARCADE_EVENT_RANDOM,
    ARCADE_EVENT_GIVE_BP_SMALL,
    ARCADE_EVENT_NO_BATTLE,
    ARCADE_EVENT_GIVE_BP_BIG,
    ARCADE_EVENT_NO_EVENT,
    ARCADE_EVENT_COUNT,
};

#define ARCADE_EVENT_INDIVIDUAL_START           ARCADE_EVENT_LOWER_HP
#define ARCADE_EVENT_WEATHER_START              ARCADE_EVENT_SUN
#define ARCADE_EVENT_SPECIAL_START              ARCADE_EVENT_SWAP

enum ArcadeBerryGroups
{
    ARCADE_BERRY_GROUP_1,
    ARCADE_BERRY_GROUP_2,
    ARCADE_BERRY_GROUP_3,
    ARCADE_BERRY_GROUP_COUNT,
};

#define ARCADE_BERRY_GROUP_SIZE                 10

enum ArcadeItemGroups
{
    ARCADE_ITEM_GROUP_1,
    ARCADE_ITEM_GROUP_2,
    ARCADE_ITEM_GROUP_3,
    ARCADE_ITEM_GROUP_COUNT,
};

#define ARCADE_ITEM_GROUP_SIZE                  10

enum ArcadeSymbol
{
    ARCADE_SYMBOL_NONE,
    ARCADE_SYMBOL_SILVER,
    ARCADE_SYMBOL_GOLD
};

#define FLAG_ARCADE_SILVER_PRINT                FLAG_UNUSED_0x020
#define FLAG_ARCADE_GOLD_PRINT                  FLAG_UNUSED_0x021

#define ARCADE_TILEMAP_BUFFER_SIZE              1024 * 2

#define ARCADE_GAME_BOARD_ROWS                  4
#define ARCADE_GAME_BOARD_COLUMNS               ARCADE_GAME_BOARD_ROWS
#define ARCADE_GAME_BOARD_SPACES                (ARCADE_GAME_BOARD_ROWS * ARCADE_GAME_BOARD_COLUMNS)

#define ARCADE_STREAK_NUM_MAX                   6
#define ARCADE_STREAK_NUM_COUNT                 (ARCADE_STREAK_NUM_MAX + 1)

enum ArcadeBoardModes
{
    ARCADE_BOARD_MODE_WAIT,
    ARCADE_BOARD_MODE_COUNTDOWN_3,
    ARCADE_BOARD_MODE_COUNTDOWN_2,
    ARCADE_BOARD_MODE_COUNTDOWN_1,
    ARCADE_BOARD_MODE_GAME_START,
    ARCADE_BOARD_MODE_GAME_FINISH,
    ARCADE_BOARD_MODE_CLEANUP
};

#define ARCADE_BOARD_COUNTDOWN_SECONDS          3
#define ARCADE_BOARD_GAME_SECONDS               30
#define ARCADE_FRAMES_PER_SECOND                60

#define ARCADE_COUNTDOWN_SHOW_FRAMES_1          ARCADE_FRAMES_PER_SECOND
#define ARCADE_COUNTDOWN_SHOW_FRAMES_2          (ARCADE_FRAMES_PER_SECOND * (ARCADE_BOARD_COUNTDOWN_SECONDS - 1))
#define ARCADE_BOARD_COUNTDOWN_TIMER            (ARCADE_FRAMES_PER_SECOND * ARCADE_BOARD_COUNTDOWN_SECONDS)
#define ARCADE_BOARD_FINISH_TIMER               (ARCADE_BOARD_COUNTDOWN_TIMER)
#define ARCADE_BOARD_COUNTDOWN_TIMER_END        (ARCADE_BOARD_COUNTDOWN_TIMER + 10)
#define ARCADE_BOARD_GAME_TIMER                 (ARCADE_BOARD_GAME_SECONDS * ARCADE_FRAMES_PER_SECOND)

#define ARCADE_COUNTDOWN_ANIM                   0

#define ARCADE_GFXTAG_EVENT                     1000
#define ARCADE_GFXTAG_CURSOR                    2000

#define ARCADE_PALTAG_EVENT                     1000
#define ARCADE_PALTAG_OPPONENT                  (ARCADE_PALTAG_EVENT + ARCADE_IMPACT_OPPONENT)
#define ARCADE_PALTAG_PLAYER                    (ARCADE_PALTAG_EVENT + ARCADE_IMPACT_PLAYER)
#define ARCADE_PALTAG_CURSOR                    (ARCADE_PALTAG_OPPONENT)

#define ARCADE_CURSOR_COLOR_CHANGE_FRAMES       8

enum ArcadeImpactTypes
{
    ARCADE_IMPACT_OPPONENT,
    ARCADE_IMPACT_PLAYER,
    ARCADE_IMPACT_ALL,
    ARCADE_IMPACT_SPECIAL,
    ARCADE_IMPACT_COUNT
};

enum ArcadeSpeedLevels
{
    ARCADE_SPEED_LEVEL_0,
    ARCADE_SPEED_LEVEL_1,
    ARCADE_SPEED_LEVEL_2,
    ARCADE_SPEED_LEVEL_3,
    ARCADE_SPEED_LEVEL_4,
    ARCADE_SPEED_LEVEL_5,
    ARCADE_SPEED_LEVEL_6,
    ARCADE_SPEED_LEVEL_7,
    ARCADE_SPEED_COUNT,
};

#define ARCADE_SPEED_DEFAULT                    ARCADE_SPEED_LEVEL_4
#define ARCADE_SPEED_LEVEL_MIN                  ARCADE_SPEED_LEVEL_0
#define ARCADE_SPEED_LEVEL_MAX                  ARCADE_SPEED_LEVEL_7

#define ARCADE_CURSOR_WAIT_LEVEL_0              (20 * (ARCADE_FRAMES_PER_SECOND / 30))
#define ARCADE_CURSOR_WAIT_LEVEL_1              (16 * (ARCADE_FRAMES_PER_SECOND / 30))
#define ARCADE_CURSOR_WAIT_LEVEL_2              (8 * (ARCADE_FRAMES_PER_SECOND / 30))
#define ARCADE_CURSOR_WAIT_LEVEL_3              (3 * (ARCADE_FRAMES_PER_SECOND / 30))
#define ARCADE_CURSOR_WAIT_LEVEL_4              (4 * (ARCADE_FRAMES_PER_SECOND / 30))
#define ARCADE_CURSOR_WAIT_LEVEL_5              (2 * (ARCADE_FRAMES_PER_SECOND / 30))
#define ARCADE_CURSOR_WAIT_LEVEL_6              (1 * (ARCADE_FRAMES_PER_SECOND / 30))
#define ARCADE_CURSOR_WAIT_LEVEL_7              (0 * (ARCADE_FRAMES_PER_SECOND / 30))

enum ArcadeStreakBrackets
{
    ARCADE_PERFORMANCE_BRACKET_0_4,
    ARCADE_PERFORMANCE_BRACKET_5_10,
    ARCADE_PERFORMANCE_BRACKET_11_15,
    ARCADE_PERFORMANCE_BRACKET_16_20,
    ARCADE_PERFORMANCE_BRACKET_21_PLUS
};

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

enum ArcadeRecord_WindowIds
{
    WIN_RECORD_TEXT,
    WIN_RECORD_DUMMY,
    WIN_RECORD_COUNT,
};

enum ArcadeRecord_BackgroundIds
{
    BG_RECORD_TEXT,
    BG_RECORD_BACKGROUND,
    BG_RECORD_COUNT,
};

#endif //GUARD_CONSTANTS_ARCADE_H
