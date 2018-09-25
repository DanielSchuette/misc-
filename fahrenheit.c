#include <stdio.h>
#define FAHRENHEIT_FACTOR (5.0/9.0)

/* function declarations */
float fahrenheit(float x);

int main() {
    /* define integer type counter variables */
    float start, end, step, current;
    start = 0.0;
    end = 300.0;
    step = 20.0;
    current = start;

    while (current <= end) {
        printf("%3.0f %6.1f\n", current, fahrenheit(current));
        current += step;
    }
    return 0;
}

float fahrenheit(float x) {
    return FAHRENHEIT_FACTOR * (x-32.0);
}
