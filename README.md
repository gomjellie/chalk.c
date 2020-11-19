# chalk.c
🌈 Colorful Console C MACRO library

![chalk.git](./.github/chalk.gif)

## 특징

높은 이식성

  - 매크로함수만으로 구성되어서 [chalk.h](./chalk.h) 파일 하나만 복사해서 프로젝트에 넣으면 바로 사용할 수 있습니다.

가볍습니다.

  - 런타임에 실행되는것이 아닌, 전처리되기 때문에 실행이 빠릅니다.

유연한 표현력

  - C언어의 String Literal, `생각보다` 유연합니다.

## Examples

```c
#include "chalk.h"

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

```c
#define CHALK_NO_PREFIX
        ^ ~~ 앞의 CHALK_ 를 쓰지 않아도 됩니다.
        ^ ~~ 예를들면, CHALK_RED 대신에 RED만 써도 됩니다!
#include "chalk.h"

printf(BG_BLACK(MAGENTA("블랙")) " " BG_MAGENTA(BLACK("핑크")));

printf(BOLD("굵은 글씨") " " DIM("연한 글씨") "\n");

printf(ITALIC("ITALIC " BOLD("ITALIC AND BOLD")));

```

```c
/* template 만들기 */
const char *int_template = MAGENTA("%d") "\n";
printf(int_template, 15);
  ~~> 선홍색 15 출력

const char *n_times_m = BLUE("%d X %d") " = " BG_CYAN("%d");
printf(n_times_m, 5, 6, 30);
  ~~> 5 X 6 파란색 
        ~~> = 
          ~~> 30 청록 배경

```

## MACRO Functions

|MACRO Function | 글자 색깔 |
|---------------|-----|
|CHALK_BLACK    | 검정 |
|CHALK_RED      | 빨강 |
|CHALK_GREEN    | 초록 |
|CHALK_YELLOW   | 노랑 |
|CHALK_BLUE     | 파랑 |
|CHALK_MAGENTA  | 심홍 |
|CHALK_CYAN     | 청록 |
|CHALK_WHITE    | 하양 |

|MACRO Function     | 글자 색깔 |
|-------------------|---------|
|CHALK_LIGHT_BLACK  | 연한 검정 |
|CHALK_LIGHT_RED    | 연한 빨강 |
|CHALK_LIGHT_GREEN  | 연한 초록 |
|CHALK_LIGHT_YELLOW | 연한 노랑 |
|CHALK_LIGHT_BLUE   | 연한 파랑 |
|CHALK_LIGHT_MAGENTA| 연한 심홍 |
|CHALK_LIGHT_CYAN   | 연한 청록 |
|CHALK_LIGHT_WHITE  | 연한 하양 |

|MACRO Function  | 배경 색깔 |
|----------------|-----|
|CHALK_BG_BLACK  | 검정 |
|CHALK_BG_RED    | 빨강 |
|CHALK_BG_GREEN  | 초록 |
|CHALK_BG_YELLOW | 노랑 |
|CHALK_BG_BLUE   | 파랑 |
|CHALK_BG_MAGENTA| 심홍 |
|CHALK_BG_CYAN   | 청록 |
|CHALK_BG_WHITE  | 하양 |

| MACRO Function       | 배경 색깔 |
|----------------------|---------|
|CHALK_BG_LIGHT_BLACK  | 연한 검정 |
|CHALK_BG_LIGHT_RED    | 연한 빨강 |
|CHALK_BG_LIGHT_GREEN  | 연한 초록 |
|CHALK_BG_LIGHT_YELLOW | 연한 노랑 |
|CHALK_BG_LIGHT_BLUE   | 연한 파랑 |
|CHALK_BG_LIGHT_MAGENTA| 연한 심홍 |
|CHALK_BG_LIGHT_CYAN   | 연한 청록 |
|CHALK_BG_LIGHT_WHITE  | 연한 하양 |

| MACRO Function| 효과 |
|---------------|-----|
|CHALK_BOLD     | 굵게 |
|CHALK_DIM      | 연하게 |
|CHALK_ITALIC   | 기울임 |
|CHALK_UNDERLINE| 밑줄 |
|CHALK_BLINK    | 깜빡임 |
|CHALK_STRIKE   | 취소선 |
|CHALK_INVERSE  | 배경색과 글자색 뒤집기 |
|CHALK_HIDE     | 글자 숨기기 |

## 동작 원리

CHALK_RED(), CHALK_BG_BLUE(), ... 등은 `매크로 함수`입니다. 

함수가 아닌 매크로 함수임을 인지하는것은 굉장히 중요합니다.

### 글자색 설정의 원리

CHALK_RED 로 예를 들어서 설명을 하겠습니다.

CHALK_RED(문자열)는 `<RED> 문자열 </RED>` 으로 변경됩니다. 

정확히는 "\x1b[31m" 문자열 "\x1b[39m" 입니다. [ANSI ESCAPE CODE](https://en.wikipedia.org/wiki/ANSI_escape_code)를 이용했습니다.

여기서 \x1b 등의 표현은 굉장히 가독성이 좋지 않기 때문에 JSX의 Element를 표현하는 방식처럼 `<RED> </RED>` 따위의 표현을 빌려서 앞으로 대신 설명하겠습니다.

  - C에서 문자열을 연속해서 열거해두면 하나의 문자열로 합쳐지기 때문에 (`"hello " "world"` 는 `"hello world"`와 같습니다), `"<RED>" 문자열 "</RED>"`는 `"<RED>문자열</RED>"` 처럼 자연스럽게 하나의 스트링으로 합쳐지게 됩니다.
  - 이 속성은 C에서 문자열을 다루는데 요긴하게 사용되기 때문에 속성1이라고 지칭하고 이후에 다시 사용할 것입니다.

### 여러가지 속성을 함께 설정하는 원리

CHALK는 여러가지 속성을 함께 사용할 수 있습니다.

예를들어서 글자색과 배경색을 함께 사용하는경우에 대해서 살펴보겠습니다.

CHALK_BG_RED(CHALK_BLUE("문자열"))

위 표현식에서 먼저 CHALK_BLUE("문자열")은 `"<BLUE>문자열</BLUE>"`로 변환됩니다. 그리고 변환된 문자열은 CHALK_BG_RED에 인자로 들어가서 `"<BG_RED><BLUE>문자열</BLUE></BG_RED>"` 로 변환되게 됩니다.

매크로함수이기 때문에 실행시간(Runtime)에 변환되는것이아닌, 컴파일시간(Compile-time)에 수행됩니다. 전처리기에의해서 변환된 결과는 당연하게도 문자열 리터럴(String Literal)이라는 사실을 인지해야합니다.

만약 초록색 문자열과 파란색 문자열을 함께 기울여서 쓰고싶다면 아래와같은 문자열을 만들어야 할 것입니다.

`"<ITALIC><GREEN>초록색문자열</GREEN><BLUE>파란색문자열</BLUE></ITALIC>"`

앞서 설명한 속성1을 이용해서 CHALK_ITALIC(CHALK_GREEN("초록색문자열") CHALK_BLUE("파란색문자열")) 로 표현할 수 있습니다.

## References

[자바스크립트 chalk](https://github.com/chalk/chalk) 의 네이밍을 따왔습니다.
