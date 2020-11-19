# chalk.c
colorful terminal C Macro library

![chalk.git](./.github/chalk.gif)

`chalk.c`는 C언어로 컬러 출력을 쉽게 할 수 있게 만드는 매크로 라이브러리입니다. 

라이브러리 자체가 매크로이기 때문에 [chalk.h](./chalk.h) 파일 하나만 복사해서 프로젝트에 넣으면 바로 사용할 수 있습니다.


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

printf(CHALK_BLINK("깜빡깜빡"));
       ^ ~~ 깜빡이 효과를 씌웁니다.
```

## 동작 원리

CHALK_색깔, CHALK_BG_색깔 ... 등은 매크로 함수입니다.

여기서는 하나만 예를들어서 CHALK_RED 로 설명을 하겠습니다.

CHALK_RED(STRING)는 <RED> STRING </RED> 으로 변경됩니다. 

정확히는 "\x1b[31m" STRING "\x1b[39m" 입니다. 

하지만 \x1b 등의 표현은 굉장히 가독성이 좋지 않기 때문에 JSX의 Element를 표현하는 방식처럼 <RED> </RED> 따위의 표현을 빌려서 앞으로 대신 설명하겠습니다.



## ansi color table

https://github.com/shiena/ansicolor/blob/master/README.md

https://en.wikipedia.org/wiki/ANSI_escape_code#SGR_parameters

https://tforgione.fr/posts/ansi-escape-codes/

