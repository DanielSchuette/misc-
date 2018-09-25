#include <stdio.h>

#define FAHRENHEIT_FACTOR (5.0/9.0)
#define START   0
#define END     300
#define STEP    20

/* function declarations */
float fahrenheit(float x);

int main() {
    /* define integer type counter variables */
    float current;
    current = START;

    while (current <= END) {
        printf("%3.0f %6.1f\n", current, fahrenheit(current));
        current += STEP;
    }
    return 0;
}

float fahrenheit(float x) {
    return FAHRENHEIT_FACTOR * (x-32.0);
}
