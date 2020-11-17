#include <stdio.h>
#include "chalk.h"

int main() {
    const char *hello_chalk[] = {
        CHALK_BG_LIGHT_BLUE("H"),
        CHALK_BG_LIGHT_CYAN("E"),
        CHALK_BG_LIGHT_GREEN("L"),
        CHALK_BG_LIGHt_MAGENTA("L"),
        CHALK_BG_LIGHT_RED("O"),
        CHALK_BG_LIGHT_WHITE(" "),
        CHALK_BG_LIGHT_YELLOW(CHALK_BLACK("C")),
        CHALK_BG_MAGENTA("H"),
        CHALK_BG_BLACK("A"),
        CHALK_BG_RED("L"),
        CHALK_BG_LIGHT_WHITE(CHALK_BLACK("K")),
    };

    for (int i = 0; i < 11; i++)
        printf("%s", hello_chalk[i]);

    printf("\n%s\n", CHALK_ITALIC(CHALK_BG_LIGHT_GREEN(CHALK_WHITE("hello?"))));
    puts(CHALK_UNDERLINE(CHALK_LIGHT_GREEN("hello")));
    printf(CHALK_CYAN("%d x %d = %d"), 2, 2, 4);
    
    printf("%s\n", CHALK_RED("bye"));

    return 0;
}
