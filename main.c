#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    CHALK_BLACK = 30,
    CHALK_RED = 31,
    CHALK_GREEN = 32,
    CHALK_YELLOW = 33,
    CHALK_BLUE = 34,
    CHALK_MAGENTA = 35,
    CHALK_CYAN = 36,
    CHALK_WHITE = 37,
    
    CHALK_LIGHT_BLACK = 90,
    CHALK_LIGHT_RED = 91,
    CHALK_LIGHT_GREEN = 92,
    CHALK_LIGHT_YELLOW = 93,
    CHALK_LIGHT_BLUE = 94,
    CHALK_LIGHT_MAGENTA = 95,
    CHALK_LIGHT_CYAN = 96,
    CHALK_LIGHT_WHITE = 97,

    CHALK_BG_BLACK = 40,
    CHALK_BG_RED = 41,
    CHALK_BG_GREEN = 42,
    CHALK_BG_YELLOW = 43,
    CHALK_BG_BLUE = 44,
    CHALK_BG_MAGENTA = 45,
    CHALK_BG_CYAN = 46,
    CHALK_BG_WHITE = 47,
    
    CHALK_BG_LIGHT_BLACK = 100,
    CHALK_BG_LIGHT_RED = 101,
    CHALK_BG_LIGHT_GREEN = 102,
    CHALK_BG_LIGHT_YELLOW = 103,
    CHALK_BG_LIGHT_BLUE = 104,
    CHALK_BG_LIGHt_MAGENTA = 105,
    CHALK_BG_LIGHT_CYAN = 106,
    CHALK_BG_LIGHT_WHITE = 107,

    CHALK_POP = 0,
    CHALK_ITALIC = 3,
    CHALK_BOLD = 1,
    CHALK_UNDERLINE = 4,
    CHALK_INVERSE = 7, // inverse bg and foreground colors
    CHALK_HIDDEN = 8,
} chalk_option_t;

const char *chalk_options[] = {
    [CHALK_BLACK] = "\x1b[30m",
    [CHALK_RED] = "\x1b[31m",
    [CHALK_GREEN] = "\x1b[32m",
    [CHALK_YELLOW] = "\x1b[33m",
    [CHALK_BLUE] = "\x1b[34m",
    [CHALK_MAGENTA] = "\x1b[35m",
    [CHALK_CYAN] = "\x1b[36m",
    [CHALK_WHITE] = "\x1b[37m",

    [CHALK_LIGHT_BLACK] = "\x1b[90m",
    [CHALK_LIGHT_RED] = "\x1b[91m",
    [CHALK_LIGHT_GREEN] = "\x1b[92m",
    [CHALK_LIGHT_YELLOW] = "\x1b[93m",
    [CHALK_LIGHT_BLUE] = "\x1b[94m",
    [CHALK_LIGHT_MAGENTA] = "\x1b[95m",
    [CHALK_LIGHT_CYAN] = "\x1b[96m",
    [CHALK_LIGHT_WHITE] = "\x1b[97m",
    
    [CHALK_BG_BLACK] = "\x1b[40m",
    [CHALK_BG_RED] = "\x1b[41m",
    [CHALK_BG_GREEN] = "\x1b[42m",
    [CHALK_BG_YELLOW] = "\x1b[43m",
    [CHALK_BG_BLUE] = "\x1b[44m",
    [CHALK_BG_MAGENTA] = "\x1b[45m",
    [CHALK_BG_CYAN] = "\x1b[46m",
    [CHALK_BG_WHITE] = "\x1b[47m",
    
    [CHALK_BG_LIGHT_BLACK] = "\x1b[100m",
    [CHALK_BG_LIGHT_RED] = "\x1b[101m",
    [CHALK_BG_LIGHT_GREEN] = "\x1b[102m",
    [CHALK_BG_LIGHT_YELLOW] = "\x1b[103m",
    [CHALK_BG_LIGHT_BLUE] = "\x1b[104m",
    [CHALK_BG_LIGHt_MAGENTA] = "\x1b[105m",
    [CHALK_BG_LIGHT_CYAN] = "\x1b[106m",
    [CHALK_BG_LIGHT_WHITE] = "\x1b[107m",
    
    [CHALK_POP] = "\x1b[0m",
    [CHALK_BOLD] = "\x1b[1m",
    [CHALK_UNDERLINE] = "\x1b[4m",
    [CHALK_ITALIC] = "\x1b[3m",
    [CHALK_INVERSE] = "\x1b[7m",
    [CHALK_HIDDEN] = "\x1b[8m",
};

typedef struct garbage_collector {
    void *body[1024];
    size_t sz;
} garbage_collector_t;

garbage_collector_t gc = (garbage_collector_t) {
    .sz = 0,
};

void gc_collect(garbage_collector_t *gc) {
    for (size_t s = 0; s < gc->sz; s++) {
        free(gc->body[s]);
    }
    gc->sz = 0;
};

// chalk formatted
const char *chalkf(const chalk_option_t chalk_option, const char *fmt, ...) {
    va_list args;
    char *ret = malloc(256);
    gc.body[gc.sz ++] = ret;
    char buf[256];
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    sprintf(ret, "%s%s%s", chalk_options[chalk_option], buf, chalk_options[CHALK_POP]);
    
    return ret;
}

int main() {
    printf("%s\n", chalkf(CHALK_ITALIC, chalkf(CHALK_BG_LIGHT_GREEN, chalkf(CHALK_WHITE, "hello?"))));
    printf("%s\n", chalkf(CHALK_UNDERLINE, chalkf(CHALK_LIGHT_GREEN, "hello")));
    printf("%s\n", chalkf(CHALK_CYAN, "%d x %d = %d", 2, 2, 4));
    
    printf("%s", chalkf(CHALK_RED, "bye"));

    gc_collect(&gc);
    return 0;
}
