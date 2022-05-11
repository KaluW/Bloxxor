#ifndef DEFINES_H
#define DEFINES_H

#include <stdint.h>
#include <stdbool.h>

// Miscellaneous
#define MAX_HELD_ELEMENTS 4

// Color Indices

#define WHITE_INDEX 0
#define BLACK_INDEX 1
#define RED_INDEX 2
#define GREEN_INDEX 3
#define BLUE_INDEX 4
#define BROWN_INDEX 5

#define gfx_Colored_Rectangle_NoClip(a, b, c, d, color)\
    gfx_SetColor(color);\
    gfx_FillRectangle_NoClip(a, b, c, d)

typedef struct Position {
    uint16_t x;
    uint8_t y;
    uint8_t x_vel; // horizontal velocity component (px/frame)
    uint8_t y_vel; // vertical velocity component (px/frame)
    uint8_t angle; // [0, 256] == [0, 2π]
} position_t;

typedef enum Elements {
    none, water, fire, earth, air
} elements_t;

typedef struct Properties {
    bool isFalling;
    elements_t held_elements[MAX_HELD_ELEMENTS];
    elements_t *active_element; // pointer to first index in held_elements[]
} properties_t;

typedef struct Input {
    bool up;
    bool down;
    bool left;
    bool right;

    bool clear; // exit game
} input_t;

typedef struct Bloxxor {
    position_t position;
    properties_t properties;
    input_t input;
} bloxxor_t;

extern bloxxor_t player;

#endif