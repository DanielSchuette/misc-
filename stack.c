/* stack.c implements a basic stack with push and pop ops */
#include <stdio.h>
#define  STACK_SIZE  2

int push(char);
char pop();

char    stack[STACK_SIZE];
char    *stack_ptr;

int main()
{
    char    c;
    stack_ptr = stack;

    while (1) {
        if ((c = getchar()) != EOF) {
            char    c_pop;
            int     err;

            /*
             * 'p' and 'e' have special meanings and are not pushed
             * onto the stack.
             */
            switch (c) {
                /* ignore line breaks, etc. */
                case '\r':
                case '\t':
                case '\n':
                    break;

                /* exit on 'e' (in addition to EOF) */
                case 'e':
                    return 0;

                /* pop from stack on 'p' */
                case 'p':
                    if ((c_pop = pop()) == 1) {
                        fprintf(stderr, "cannot pop from stack\n");
                        break;
                    }
                    fprintf(stderr, "popped: %c\n", c_pop);
                    break;

                /* otherwise, push onto stack */
                default:
                    err = push(c);
                    if (err)
                        fprintf(stderr, "cannot push onto stack\n");
                    break;
            }
        }
    }
    return 0;
}

int push(char c)
{
    /* check if stack is full */
    if ((stack_ptr - stack) >= STACK_SIZE)
        return 1;

    /* otherwise, push c onto stack and return */
    *stack_ptr = c;
    stack_ptr++;
    return 0;
}

char pop()
{
    char    c;

    /* check if stack is empty */
    if (stack_ptr == stack)
        return 1;

    /* otherwise, pop char off stack and return it */
    stack_ptr--;
    c = *stack_ptr;
    return c;
}
