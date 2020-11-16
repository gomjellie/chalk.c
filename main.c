#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    text_black = 30,
    text_red = 31,
    text_green = 32,
    text_yellow = 33,
    text_blue = 34,
    text_magenta = 35,
    text_cyan = 36,
    text_white = 37,
    
    text_light_black = 90,
    text_light_red = 91,
    text_light_green = 92,
    text_light_yellow = 93,
    text_light_blue = 94,
    text_light_magenta = 95,
    text_light_cyan = 96,
    text_light_white = 97,

    bg_black = 40,
    bg_red = 41,
    bg_green = 42,
    bg_yellow = 43,
    bg_blue = 44,
    bg_magenta = 45,
    bg_cyan = 46,
    bg_white = 47,
    
    bg_light_black = 100,
    bg_light_red = 101,
    bg_light_green = 102,
    bg_light_yellow = 103,
    bg_light_blue = 104,
    bg_light_magenta = 105,
    bg_light_cyan = 106,
    bg_light_white = 107,

    chalk_pop = 0,
    text_bold = 1,
    text_underline = 4,
} chalk_option_t;

const char *chalk_options[] = {
    [text_black] = "\x1b[30m",
    [text_red] = "\x1b[31m",
    [text_green] = "\x1b[32m",
    [text_yellow] = "\x1b[33m",
    [text_blue] = "\x1b[34m",
    [text_magenta] = "\x1b[35m",
    [text_cyan] = "\x1b[36m",
    [text_white] = "\x1b[37m",

    [text_light_black] = "\x1b[90m",
    [text_light_red] = "\x1b[91m",
    [text_light_green] = "\x1b[92m",
    [text_light_yellow] = "\x1b[93m",
    [text_light_blue] = "\x1b[94m",
    [text_light_magenta] = "\x1b[95m",
    [text_light_cyan] = "\x1b[96m",
    [text_light_white] = "\x1b[97m",
    
    [bg_black] = "\x1b[40m",
    [bg_red] = "\x1b[41m",
    [bg_green] = "\x1b[42m",
    [bg_yellow] = "\x1b[43m",
    [bg_blue] = "\x1b[44m",
    [bg_magenta] = "\x1b[45m",
    [bg_cyan] = "\x1b[46m",
    [bg_white] = "\x1b[47m",
    
    [bg_light_black] = "\x1b[100m",
    [bg_light_red] = "\x1b[101m",
    [bg_light_green] = "\x1b[102m",
    [bg_light_yellow] = "\x1b[103m",
    [bg_light_blue] = "\x1b[104m",
    [bg_light_magenta] = "\x1b[105m",
    [bg_light_cyan] = "\x1b[106m",
    [bg_light_white] = "\x1b[107m",
    
    [chalk_pop] = "\x1b[0m",
    [text_bold] = "\x1b[1m",
    [text_underline] = "\x1b[4m",
};

// chalk formatted
char *chalkf(const chalk_option_t chalk_option, const char *fmt, ...) {
    va_list vl;
    void *ret = malloc(256);
    void *buf = malloc(256);
    va_start(vl, fmt);
    vsprintf(buf, fmt, vl);
    va_end(vl);
    sprintf(ret, "%s%s%s", chalk_options[chalk_option], buf, chalk_options[chalk_pop]);
    free(buf);

    return ret;
}

int main() {
    printf("%s\n", chalkf(text_underline, chalkf(text_light_green, "hello")));
    printf("%s\n", chalkf(text_cyan, "%d x %d = %d", 2, 2, 4));
    
    printf("%s", chalkf(text_red, "bye"));

    return 0;
}
