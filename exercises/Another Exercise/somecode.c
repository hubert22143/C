#include <stdio.h>
#include <string.h>

// Define the Color enum
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

// Define the ResistanceBand struct
typedef struct {
    Color color;
    const char *name;
} ResistanceBand;

// Initialize the resistance band array
const ResistanceBand resistance_band_t[] = {
    {BLACK, "BLACK"},
    {BROWN, "BROWN"},
    {RED, "RED"},
    {ORANGE, "ORANGE"},
    {YELLOW, "YELLOW"},
    {GREEN, "GREEN"},
    {BLUE, "BLUE"},
    {VIOLET, "VIOLET"},
    {GREY, "GREY"},
    {WHITE, "WHITE"}
};

// Function to get the numeric value of a color
int getColorValue(Color color) {
    return (int)color; // Cast to int for explicit return
}

// Function to get the color code (returns numeric value)
int color_code(Color color) {
    return getColorValue(color);
}

// Function to get the color name from the Color enum
const char* getColorName(Color color) {
    if (color < 0 || color > 9) {
        return "Invalid color"; // Handle invalid color values
    }
    return resistance_band_t[color].name; // Return the name associated with the color
}

// Function to convert string to Color enum
Color stringToColor(const char *colorName) {
    for (int i = 0; i < sizeof(resistance_band_t) / sizeof(resistance_band_t[0]); i++) {
        if (strcmp(colorName, resistance_band_t[i].name) == 0) {
            return resistance_band_t[i].color; // Return corresponding Color value
        }
    }
    return -1; // Return an invalid value if not found
}

int main() {
    const char *colorString = "GREEN"; // Define a color string
    Color color = stringToColor(colorString); // Convert string to Color enum
    
    if (color != -1) { // Check for a valid color
        printf("Color code for %s: %d\n", getColorName(color), color_code(color));
    } else {
        printf("Invalid color name: %s\n", colorString);
    }

    return 0;
}