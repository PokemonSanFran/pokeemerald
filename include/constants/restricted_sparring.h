#ifdef RESTRICTED_SPARRING
#ifndef GUARD_CONSTANTS_SPARRING_H
#define GUARD_CONSTANTS_SPARRING_H

#define SPARRING_FUNC_INIT                                     0
#define SPARRING_FUNC_GET_DATA                                 1
#define SPARRING_FUNC_SET_DATA                                 2
#define SPARRING_FUNC_SET_BATTLE_WON                           3
#define SPARRING_FUNC_SAVE                                     4
#define SPARRING_FUNC_GET_OPPONENT_INTRO                       5
#define SPARRING_FUNC_GET_CONTINUE_MENU_TYPE                   6
#define SPARRING_FUNC_RESTORE_HELD_ITEMS                       7
#define SPARRING_FUNC_RESET_SKETCH_MOVES                       8
#define SPARRING_FUNC_GIVE_BATTLE_POINTS                       9
#define SPARRING_FUNC_GET_TYPE_NAME                            10
#define SPARRING_FUNC_CHECK_SYMBOL                             11
#define SPARRING_FUNC_CONVERT_TYPE                             12
#define SPARRING_FUNC_CHECK_MAX                                13

#define SPARRING_DATA_WIN_STREAK                               1
#define SPARRING_DATA_LVL_MODE                                 2
#define SPARRING_DATA_TYPE_MODE                                3

#define SPARRING_RECORDYES_HEALYES                             0
#define SPARRING_RECORDYES_HEALNO                              1
#define SPARRING_RECORDNO_HEALYES                              2
#define SPARRING_RECORDNO_HEALNO                               3

#define SPARRING_MAX_NUM_RESTORE                               2

#define SPARRING_BP_BASE                                       3
#define SPARRING_BP_BONUS_MATCH                                SPARRING_MIN_STREAK
#define SPARRING_BP_STREAK_BONUS                               20
#define SPARRING_BP_TYPE_WIN_BONUS                             30

#define SPARRING_SYMBOL_NONE                                   0
#define SPARRING_SYMBOL_SILVER                                 1
#define SPARRING_SYMBOL_GOLD                                   2

#define SPARRING_MIN_STREAK                                    5
#define SPARRING_MAX_STREAK                                    UCHAR_MAX

#define SPARRING_TILES                                         8
#define SPARRING_TYPE_MON_X_OFFSET                             14
#define SPARRING_TYPE_MON_ICON_SIZE                            33

#define SPARRING_RECORD_LEVEL_HEADER_X_POS                     8
#define SPARRING_RECORD_DATA_X_POS                             80

#define SPARRING_RECORD_HEADER_Y_POS                           2
#define SPARRING_RECORD_SEPERATOR_Y_POS                        10
#define SPARRING_RECORD_50_LEVEL_Y_POS                         49
#define SPARRING_RECORD_50_LEVEL_BEST_Y_POS                    65
#define SPARRING_RECORD_OPEN_LEVEL_Y_POS                       97
#define SPARRING_RECORD_OPEN_LEVEL_BEST_Y_POS                  113

#endif //GUARD_CONSTANTS_SPARRING_H
#endif
