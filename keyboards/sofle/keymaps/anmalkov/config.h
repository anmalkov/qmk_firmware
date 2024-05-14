// Copyright 2024 Andrew Malkov (@anmalkov)

#pragma once

// Tri Layer
#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4

// Encoder
#define ENCODER_RESOLUTION 2
#ifdef ENCODER_RESOLUTION_RIGHT
#undef ENCODER_RESOLUTION_RIGHT
#endif // ENCODER_RESOLUTION_RIGHT
#define ENCODER_RESOLUTION_RIGHT 4

// // Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

// #undef TAPPING_TERM
// #define TAPPING_TERM 200
// #define QUICK_TAP_TERM 0

// // Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

#define NO_MUSIC_MODE

// Unfortunately, some applications drop or misorder fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#ifdef TAP_CODE_DELAY
#undef TAP_CODE_DELAY
#endif // TAP_CODE_DELAY
#define TAP_CODE_DELAY 5

#define MK_KINETIC_SPEED

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
