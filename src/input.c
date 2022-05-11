#include <keypadc.h>

#include "defines.h"
#include "input.h"

static void reset_input(input_t *input) // clear previous frame's inputs
{
    input->down = false;
    input->right = false;
    input->up = false;
    input->left = false;
}

void handle_key_input(input_t *input)
{
    reset_input(input);

    /* Arrow Keys */
    kb_key_t dpad;

    /* Update kb_Data */
    kb_Scan();

    /* Load group 7 registers */
    dpad = kb_Data[7];

    switch (dpad)
    {
        case kb_Down:
            input->down = true;

        case kb_Right:
            input->right = true;

        case kb_Up:
            input->up = true;

        case kb_Left:
            input->left = true;

        default:
            break;
    }

    input->clear = (kb_Data[6] & kb_Clear);

}