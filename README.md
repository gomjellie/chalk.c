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

CHALK_RED(), CHALK_BG_BLUE(), ... 등은 `매크로 함수`입니다. 

함수가 아닌 매크로 함수임을 인지하는것은 굉장히 중요합니다.

### 글자색 설정의 원리

CHALK_RED 로 예를 들어서 설명을 하겠습니다.

CHALK_RED(문자열)는 `<RED> 문자열 </RED>` 으로 변경됩니다. 

정확히는 "\x1b[31m" 문자열 "\x1b[39m" 입니다. 

여기서 \x1b 등의 표현은 굉장히 가독성이 좋지 않기 때문에 JSX의 Element를 표현하는 방식처럼 `<RED> </RED>` 따위의 표현을 빌려서 앞으로 대신 설명하겠습니다.

  - C에서 문자열을 연속해서 열거해두면 하나의 문자열로 합쳐지기 때문에 ("hello " "world" 는 "hello world"와 같습니다), "\<RED>" 문자열 "\</RED>"는 "\<RED>문자열\</RED>" 처럼 자연스럽게 하나의 스트링으로 합쳐지게 됩니다.
  - 이 속성은 C에서 문자열을 다루는데 요긴하게 사용되기 때문에 속성1이라고 지칭하고 이후에 다시 사용할 것입니다.

### 여러가지 속성을 함께 설정하는 원리

CHALK는 여러가지 속성을 함께 사용할 수 있습니다.

예를들어서 글자색과 배경색을 함께 사용하는경우에 대해서 살펴보겠습니다.

CHALK_BG_RED(CHALK_BLUE("문자열"))

위 표현식에서 먼저 CHALK_BLUE("문자열")은 `"<BLUE>문자열</BLUE>"`로 변환됩니다. 그리고 변환된 문자열은 CHALK_BG_RED에 인자로 들어가서 `"<BG_RED><BLUE>문자열</BLUE></BG_RED>"` 로 변환되게 됩니다.

매크로함수이기 때문에 실행시간(Runtime)에 변환되는것이아닌, 컴파일시간(Compile-time)에 수행됩니다. 전처리기에의해서 변환된 결과는 당연하게도 문자열 리터럴(String Literal)입니다.

## ansi color table

https://github.com/shiena/ansicolor/blob/master/README.md

https://en.wikipedia.org/wiki/ANSI_escape_code#SGR_parameters

https://tforgione.fr/posts/ansi-escape-codes/

