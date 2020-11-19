# chalk.c
colorful terminal C Macro library

![chalk.git](./.github/chalk.gif)

`chalk.c` C언어로 컬러 출력을 쉽게 할 수 있게 만드는 매크로 라이브러리입니다. 

[chalk.h](./chalk.h) 파일 하나만 복사해서 프로젝트에 넣으면 바로 사용할 수 있습니다.

## 예제

```c
#include <chalk.h>

printf(CHALK_RED("Hello World"));
       ^ ~ "Hello World" 문자열의 글자를 빨간색으로 바꿔줍니다.

printf(CHALK_BG_BLUE("안녕 세상아"));
       ^ ~ "안녕 세상아" 문자열의 배경을 파란색으로 바꿔줍니다.

printf(CHALK_BG_BLUE(CHALK_RED("혼합 사용")));
                     ^ ~~ 글자색 빨강
        ^ ~~ 배경은 파랑

```



## ansi color table

https://github.com/shiena/ansicolor/blob/master/README.md

https://en.wikipedia.org/wiki/ANSI_escape_code#SGR_parameters

https://tforgione.fr/posts/ansi-escape-codes/

