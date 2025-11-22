#ifndef GUARD_CONFIG_H
#define GUARD_CONFIG_H

// In the Generation 3 games, Asserts were used in various debug builds.
// Ruby/Sapphire and Emerald do not have these asserts while Fire Red
// still has them in the ROM. This is because the developers forgot
// to define NDEBUG before release, however this has been changed as
// Ruby's actual debug build does not use the AGBPrint features.
#define NDEBUG

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

// Start restricted_sparring

// Uncomment to enable the storage of which Pokémon were used during a Restricted Sparring challenge
// https://github.com/PokemonSanFran/pokeemerald/wiki/restricted_sparring#record-used-mons
//#define RESTRICTED_SPARRING_MONS

// To use the following features, change the 0 for a var present in include/constants/vars.h, preferably an unused one.
// Eg: You may rename VAR_UNUSED_0x404E to a descriptive name and use it below.

#define VAR_RESTRICTEDSPARRING_HEAL_COUNT 0 // This variable stores how many times the player has healed during this challenge. If this is not set, the player will never be able to heal.
#define VAR_SPARRING_TYPE 0 // This variable stores the type that the player has chosen to challenge with. If this is not set, the player will only be able to challenge with Normal-tupe Pokemon.

// Flag settings
// To use the following features, change the 0 for a flag present in include/constants/flags.h, preferably an unused one.
// Eg: You may rename FLAG_UNUSED_0x264 to a descriptive name and use it below.
#define FLAG_SPARRING_FIRST_TYPE_WIN 0 // This flag is set when the player clears a type for the first time. If this is not set, the player will never be acknowledged (or rewarded) for mastering a type.
// End restricted_sparring

#endif // GUARD_CONFIG_H
