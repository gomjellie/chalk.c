#include <stdio.h>
#include "chalk.h"

int main() {
    const char *hello_chalk[] = {
        CHALK_BG_LIGHT_BLUE(CHALK_BLACK("H")),
        CHALK_BG_LIGHT_CYAN(CHALK_BLACK("E")),
        CHALK_BG_LIGHT_GREEN(CHALK_BLACK("L")),
        CHALK_BG_LIGHT_MAGENTA("L"),
        CHALK_BG_LIGHT_RED("O"),
        CHALK_BG_LIGHT_WHITE(" "),
        CHALK_BG_LIGHT_YELLOW(CHALK_BLACK("C")),
        CHALK_BG_MAGENTA("H"),
        CHALK_BG_BLACK("A"),
        CHALK_BG_RED("L"),
        CHALK_BG_LIGHT_WHITE(CHALK_BLACK("K")),
    };

    for (int i = 0; i < 11; i++)
        printf(CHALK_BLINK("%s"), hello_chalk[i]);

    puts("");
    for (int i = 0; i < 11; i++) {
        printf(CHALK_UNDERLINE(CHALK_INVERSE("%s")), hello_chalk[i]);
    }
    printf("\n%s\n", CHALK_ITALIC(CHALK_BG_LIGHT_GREEN(CHALK_BLACK("hello?"))));
    puts(CHALK_UNDERLINE(CHALK_LIGHT_GREEN("https://github.com/gomjellie/chalk.c")));
    printf(CHALK_BOLD(CHALK_CYAN("THIS IS BOLD, CYAN: %d x %d = %d")), 2, 2, 4);
    
    printf("\n%s\n", CHALK_BLINK(CHALK_RED("bye")));

    return 0;
}
