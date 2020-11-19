#include <stdio.h>
#define CHALK_NO_PREFIX
#include "../chalk.h"

int main() {
    const char *hello_chalk[] = {
        BG_LIGHT_BLUE(BLACK("H")),
        BG_LIGHT_CYAN(BLACK("E")),
        BG_LIGHT_GREEN(BLACK("L")),
        BG_LIGHT_MAGENTA("L"),
        BG_LIGHT_RED("O"),
        BG_LIGHT_WHITE(" "),
        BG_LIGHT_YELLOW(BLACK("C")),
        BG_MAGENTA("H"),
        BG_BLACK("A"),
        BG_RED("L"),
        BG_LIGHT_WHITE(BLACK("K")),
    };

    for (int i = 0; i < 11; i++)
        printf(BLINK("%s"), hello_chalk[i]);

    puts("");
    for (int i = 0; i < 11; i++) {
        printf(INVERSE("%s"), hello_chalk[i]);
    }
    printf("\n" ITALIC(BG_LIGHT_GREEN(BLACK("햇빛이 선명하게 나뭇잎을 핥고 있었다."))) "\n");
    puts(UNDERLINE(LIGHT_GREEN("https://github.com/gomjellie/chalk.c")));
    printf(BOLD(CYAN("THIS IS BOLD, CYAN: %d x %d = %d")) "\n", 2, 2, 4);
    
    printf(UNDERLINE("%s %s"), RED("你好"), LIGHT_YELLOW("世界") "\n");

    printf(BLINK("ㄷㄷㄷㅈ") "\n");
    printf(BLINK(MAGENTA("DUDUDUNGA")) "\n");
    printf(ITALIC("기울인" BOLD("굵은 글씨")));
    return 0;
}
