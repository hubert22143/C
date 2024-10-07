#include "resistor_color.h"
#include <stdio.h>
#include <string.h>
const ResistanceBand resistance_band_t[] = {
    {"BLACK"},
    {"BROWN"},
    {"RED"},
    {"ORANGE"},
    {"YELLOW"},
    {"GREEN"},
    {"BLUE"},
    {"VIOLET"},
    {"GREY"},
    {"WHITE"}
};
int getColorValue(Color color) {
    return (int)color;
}
int color_code(Color color) {
    return getColorValue(color);
}
const char* getColorName(Color color) {
    if (color < 0 || color > 9) {
        return "Invalid color";
    }
    return resistance_band_t[color].name;
}
void getColorList(){
    for(int i = 0; i<9; i++){
        printf("%s\n",resistance_band_t[i].name);
    }
}
int main(){
    // getColorList();
    // const int redValue = getColorValue(RED);
    // printf("The value of red is: %d\n",redValue);
    // const int greenCode = color_code(GREEN);
    // printf("The value of green is: %d\n",greenCode);
    // const char* codeFour = getColorName(8);
    // printf("The color for code 8 is : %s\n ",codeFour);

}