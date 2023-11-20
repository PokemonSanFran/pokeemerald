#ifdef BATTLE_ARCADE
#ifndef GUARD_CONSTANTS_ARCADE_H
#define GUARD_CONSTANTS_ARCADE_H

#define ARCADE_FUNC_INIT                                     0
#define ARCADE_FUNC_GET_DATA                                 1
#define ARCADE_FUNC_SET_DATA                                 2
#define ARCADE_FUNC_SET_BATTLE_WON                           3
#define ARCADE_FUNC_SAVE                                     4
#define ARCADE_FUNC_GET_OPPONENT_INTRO                       5
#define ARCADE_FUNC_GET_CONTINUE_MENU_TYPE                   6
#define ARCADE_FUNC_RESTORE_HELD_ITEMS                       7
#define ARCADE_FUNC_RESET_SKETCH_MOVES                       8
#define ARCADE_FUNC_GIVE_BATTLE_POINTS                       9
#define ARCADE_FUNC_GET_TYPE_NAME                            10
#define ARCADE_FUNC_CHECK_SYMBOL                             11
#define ARCADE_FUNC_CONVERT_TYPE                             12
#define ARCADE_FUNC_CHECK_MAX                                13

#define ARCADE_DATA_WIN_STREAK                               1
#define ARCADE_DATA_LVL_MODE                                 2
#define ARCADE_DATA_TYPE_MODE                                3

#define ARCADE_RECORDYES_HEALYES                             0
#define ARCADE_RECORDYES_HEALNO                              1
#define ARCADE_RECORDNO_HEALYES                              2
#define ARCADE_RECORDNO_HEALNO                               3

#define ARCADE_MAX_NUM_RESTORE                               2

#define ARCADE_BP_BASE                                       3
#define ARCADE_BP_BONUS_MATCH                                ARCADE_MIN_STREAK
#define ARCADE_BP_STREAK_BONUS                               20
#define ARCADE_BP_TYPE_WIN_BONUS                             30

#define ARCADE_SYMBOL_NONE                                   0
#define ARCADE_SYMBOL_SILVER                                 1
#define ARCADE_SYMBOL_GOLD                                   2

#define ARCADE_MIN_STREAK                                    5
#define ARCADE_MAX_STREAK                                    UCHAR_MAX

#define ARCADE_TILES                                         8
#define ARCADE_TYPE_MON_X_OFFSET                             14
#define ARCADE_TYPE_MON_ICON_SIZE                            33

#define ARCADE_RECORD_LEVEL_HEADER_X_POS                     8
#define ARCADE_RECORD_DATA_X_POS                             80

#define ARCADE_RECORD_HEADER_Y_POS                           2
#define ARCADE_RECORD_SEPERATOR_Y_POS                        10
#define ARCADE_RECORD_50_LEVEL_Y_POS                         49
#define ARCADE_RECORD_50_LEVEL_BEST_Y_POS                    65
#define ARCADE_RECORD_OPEN_LEVEL_Y_POS                       97
#define ARCADE_RECORD_OPEN_LEVEL_BEST_Y_POS                  113

#endif //GUARD_CONSTANTS_ARCADE_H
#endif
