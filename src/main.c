/*
 *--------------------------------------
 * Program Name: Bloxxor
 * Author: Josiah "KaluW" Rice
 * License: BSD 3-Clause License
 * Description: Bloxxor embarks on an epic journey to craft the celestial node and restore peace in the land.
 *--------------------------------------
*/

#include <stdint.h>
#include <graphx.h>
#include <tice.h>

#include "defines.h"

void init_level(void); // Load level data 
void setup_graphics_palette(void); // Hard code color indices to graphics palette

bloxxor_t player;

int main(void)
{
    gfx_Begin();

    init_level();

    // Collision testing will be determined by the player's hitbox and the terrain's black outline
    gfx_SetColor(BLACK_INDEX);
    gfx_Line_NoClip(0, 180, 320, 180);

    do {
        handle_key_input(&player.input);
        
    } while (!player.input.clear);
    

    gfx_End();

    return 0;
}

void init_level(void)
{
    player.position.x = 160;
    player.position.y = 180;
    player.position.x_vel =
    player.position.y_vel = 
    player.position.angle = 0;

    player.properties.held_elements[none, none, none, none];
    player.properties.active_element = player.properties.held_elements;

    player.properties.isFalling = false;
}

void setup_graphics_palette(void)
{
    gfx_palette[WHITE_INDEX] = gfx_RGBTo1555(255, 255, 255);
    gfx_palette[BLACK_INDEX] = gfx_RGBTo1555(0, 0, 0);
    gfx_palette[RED_INDEX] = gfx_RGBTo1555(255, 0, 0);
    gfx_palette[GREEN_INDEX] = gfx_RGBTo1555(0, 255, 0);
    gfx_palette[BLUE_INDEX] = gfx_RGBTo1555(0, 0, 255);
    gfx_palette[BROWN_INDEX] = gfx_RGBTo1555(165,42,42);
}


