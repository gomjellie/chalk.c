/**
 * 누가 코드를 이렇게 짜요?
 * 이렇게 코드를 짜니 구구단이 느리게 돌아가지.
 * 
 */

#define CHALK_NO_PREFIX
#include "../chalk.h"
#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i < 10; i++) {
        for (j = 1; j < 10; j++) {
            printf(RED("%d x %d") " = " BG_CYAN("%d") "\n", i, j, i * j);
        }
    }
    return 0;
}
