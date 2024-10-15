#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

typedef enum {
    BLACK = 0,
    BROWN = 1,
    RED = 2,
    ORANGE = 3,
    YELLOW = 4,
    GREEN = 5,
    BLUE = 6,
    VIOLET = 7,
    GREY = 8,
    WHITE = 9
} Color;
typedef struct{
const char *name;
}ResistanceBand;

const char* getColorName(Color color);
void getColorList();
int getColorValue(Color color);
int color_code(Color color);

#endif