#include <stdio.h>

/* function declarations */
int fahrenheit(int x);

int main() {
    /* define integer type counter variables */
    int start, end, step, current;
    start = 0;
    end = 300;
    step = 20;
    current = start;

    while (current <= end) {
        printf("%d\t%d\n", current, fahrenheit(current));
        current += step;
    }
    return 0;
}

int fahrenheit(int x) {
    return (5.0/9.0)*(x-32);
}
