#ifndef GUARD_CONFIG_H
#define GUARD_CONFIG_H

// In the Generation 3 games, Asserts were used in various debug builds.
// Ruby/Sapphire and Emerald do not have these asserts while Fire Red
// still has them in the ROM. This is because the developers forgot
// to define NDEBUG before release, however this has been changed as
// Ruby's actual debug build does not use the AGBPrint features.
//#define NDEBUG

// To enable printf debugging, comment out "#define NDEBUG". This allows
// the various AGBPrint functions to be used. (See include/gba/isagbprint.h).
// See below for enabling different pretty printing versions.

#ifndef NDEBUG

#define PRETTY_PRINT_MINI_PRINTF (0)
#define PRETTY_PRINT_LIBC (1)

#define LOG_HANDLER_AGB_PRINT (0)
#define LOG_HANDLER_NOCASH_PRINT (1)
#define LOG_HANDLER_MGBA_PRINT (2)

// Use this switch to choose a handler for pretty printing.
// NOTE: mini_printf supports a custom pretty printing formatter to display preproc encoded strings. (%S)
//       some libc distributions (especially dkp arm-libc) will fail to link pretty printing.
#define PRETTY_PRINT_HANDLER (PRETTY_PRINT_MINI_PRINTF)

// Use this switch to choose a handler for printf output.
// NOTE: These will only work on the respective emulators and should not be used in a productive environment.
//       Some emulators or real hardware might (and is allowed to) crash if they are used.
//       AGB_PRINT is supported on respective debug units.

#define LOG_HANDLER (LOG_HANDLER_MGBA_PRINT)
#endif

#define ENGLISH

#ifdef ENGLISH
#define UNITS_IMPERIAL
#define CHAR_DEC_SEPARATOR CHAR_PERIOD // Period is used as a decimal separator only in the UK and the US.
#else
#define UNITS_METRIC
#define CHAR_DEC_SEPARATOR CHAR_COMMA
#endif

// Uncomment to fix some identified minor bugs
//#define BUGFIX

// Various undefined behavior bugs may or may not prevent compilation with
// newer compilers. So always fix them when using a modern compiler.
#if MODERN || defined(BUGFIX)
#ifndef UBFIX
#define UBFIX
#endif
#endif

#define BATTLE_ARCADE // Uncomment this line to enable the battle_arcade functionality.
#ifdef BATTLE_ARCADE
//#define ARCADE_GEN4_EFFECTS_UNBANNED //If the Battle Arcade feature is being used in a repo where Trick Room and Fog are implemented field effects, uncomment this line. Changes to BattleArcade_DoFog and BattleArcade_DoTrickRoom may be required.
#define FLAG_ARCADE_SILVER_PRINT           FLAG_UNUSED_0x020
#define FLAG_ARCADE_GOLD_PRINT             FLAG_UNUSED_0x021
#define FLAG_ARCADE_RANDOM_CURSOR          FLAG_UNUSED_0x022
#define VAR_ARCADE_GIVE_PLAYER_HOLD_ITEM   VAR_UNUSED_0x409D

//should be replaced with a u8 on the saveblock bitshifted to hold ARCADE_EVENT_COUNT
#define VAR_ARCADE_EVENT                   VAR_UNUSED_0x4083

// replace with a u8, bitshifted to hold ARCADE_EVENT_GIVE_BERRY or ARCADE_EVENT_GIVE_ITEM
#define VAR_ARCADE_GIVE_ENEMY_TYPE         VAR_UNUSED_0x408B

//replace with a u8, bitshifted to hold up to ARCADE_SPEED_LEVEL_MAX
#define VAR_ARCADE_CURSOR_SPEED            VAR_UNUSED_0x4091

#endif
#endif // GUARD_CONFIG_H
