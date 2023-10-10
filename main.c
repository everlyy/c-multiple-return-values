#include "multiret.h"
#include <stdio.h>

MULTIPLE_RETURN(returns_two_ints, (int a, int b), int, {
    RETURN(a * 2);
    RETURN(b + 1);
});

int main(void) {
    int a;
    int b;
    CALL_MULTIPLE_RETURN(returns_two_ints, (5, 7), int, &a, &b);

    printf("returns_two_ints returned a=%d b=%d\n", a, b);
    return 0;
}