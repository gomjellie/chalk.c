/**
 * https://github.com/gomjellie/chalk.c
 * 
 * MIT 라이선스
 * Copyright (c) 2020 gomjellie@gmail.com
 * 
 * 이 소프트웨어의 복제본과 관련된 문서화 파일(“소프트웨어”)을 획득하는 사람은
 * 누구라도 소프트웨어를 별다른 제한 없이 무상으로 사용할 수 있는 권한을 부여 받는다.
 * 여기에는 소프트웨어의 복제본을 무제한으로
 * 사용, 복제, 수정, 병합, 공표, 배포, 서브라이선스 설정 및 판매할 수 있는 권리와
 * 이상의 행위를 소프트웨어를 제공받은 다른 수취인들에게 허용할 수 있는 권리가 포함되며,
 * 다음과 같은 조건을 충족시키는 것을 전제로 한다.
 * 
 * 위와 같은 저작권 안내 문구와 본 허용 문구가 소프트웨어의 모든 복제본 및 중요 부분에 포함되어야 한다.
 * 
 * 이 소프트웨어는 상품성, 특정 목적 적합성, 그리고 비침해에 대한 보증을 포함한
 * 어떠한 형태의 보증도 명시적이나 묵시적으로 설정되지 않은 “있는 그대로의” 상태로 제공된다.
 * 소프트웨어를 개발한 프로그래머나 저작권자는 어떠한 경우에도 소프트웨어나 소프트웨어의
 * 사용 등의 행위와 관련하여 일어나는 어떤 요구사항이나 손해 및 기타 책임에 대해
 * 계약상, 불법행위 또는 기타 이유로 인한 책임을 지지 않는다.
 * 
 * MIT License
 * 
 * Copyright (c) 2020 gomjellie@gmail.com

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#ifndef _CHALK_H_
#define _CHALK_H_

#define CHALK_DEFAULT_FG "\x1b[39m"
#define CHALK_DEFAULT_BG "\x1b[49m"
#define CHALK_DEFAULT_STRIKE "\x1b[29m"
#define CHALK_DEFAULT_REVEAL "\x1b[28m"
#define CHALK_DEFAULT_INVERSE "\x1b[27m"
#define CHALK_DEFAULT_BLINK "\x1b[25m"
#define CHALK_DEFAULT_UNDERLINE "\x1b[24m"
#define CHALK_DEFAULT_ITALIC "\x1b[23m"
#define CHALK_DEFAULT_INTENSITY "\x1b[22m"
#define CHALK_DEFAULT_BOLD "\x1b[21m"
#define CHALK_RESET "\x1b[0m"

#define CHALK_BLACK(FMT) "\x1b[30m" FMT CHALK_DEFAULT_FG
#define CHALK_RED(FMT) "\x1b[31m" FMT CHALK_DEFAULT_FG
#define CHALK_GREEN(FMT) "\x1b[32m" FMT CHALK_DEFAULT_FG
#define CHALK_YELLOW(FMT) "\x1b[33m" FMT CHALK_DEFAULT_FG
#define CHALK_BLUE(FMT) "\x1b[34m" FMT CHALK_DEFAULT_FG
#define CHALK_MAGENTA(FMT) "\x1b[35m" FMT CHALK_DEFAULT_FG
#define CHALK_CYAN(FMT) "\x1b[36m" FMT CHALK_DEFAULT_FG
#define CHALK_WHITE(FMT) "\x1b[37m" FMT CHALK_DEFAULT_FG
#define CHALK_LIGHT_BLACK(FMT) "\x1b[90m" FMT CHALK_DEFAULT_FG
#define CHALK_LIGHT_RED(FMT) "\x1b[91m" FMT CHALK_DEFAULT_FG
#define CHALK_LIGHT_GREEN(FMT) "\x1b[92m" FMT CHALK_DEFAULT_FG
#define CHALK_LIGHT_YELLOW(FMT) "\x1b[93m" FMT CHALK_DEFAULT_FG
#define CHALK_LIGHT_BLUE(FMT) "\x1b[94m" FMT CHALK_DEFAULT_FG
#define CHALK_LIGHT_MAGENTA(FMT) "\x1b[95m" FMT CHALK_DEFAULT_FG
#define CHALK_LIGHT_CYAN(FMT) "\x1b[96m" FMT CHALK_DEFAULT_FG
#define CHALK_LIGHT_WHITE(FMT) "\x1b[97m" FMT CHALK_DEFAULT_FG

#define CHALK_BG_BLACK(FMT) "\x1b[40m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_RED(FMT) "\x1b[41m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_GREEN(FMT) "\x1b[42m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_YELLOW(FMT) "\x1b[43m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_BLUE(FMT) "\x1b[44m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_MAGENTA(FMT) "\x1b[45m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_CYAN(FMT) "\x1b[46m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_WHITE(FMT) "\x1b[47m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_LIGHT_BLACK(FMT) "\x1b[100m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_LIGHT_RED(FMT) "\x1b[101m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_LIGHT_GREEN(FMT) "\x1b[102m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_LIGHT_YELLOW(FMT) "\x1b[103m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_LIGHT_BLUE(FMT) "\x1b[104m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_LIGHT_MAGENTA(FMT) "\x1b[105m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_LIGHT_CYAN(FMT) "\x1b[106m" FMT CHALK_DEFAULT_BG
#define CHALK_BG_LIGHT_WHITE(FMT) "\x1b[107m" FMT CHALK_DEFAULT_BG

#define CHALK_BOLD(FMT) "\x1b[1m" FMT CHALK_DEFAULT_BOLD
#define CHALK_DIM(FMT) "\x1b[2m" FMT CHALK_DEFAULT_INTENSITY
#define CHALK_ITALIC(FMT) "\x1b[3m" FMT CHALK_DEFAULT_ITALIC
#define CHALK_UNDERLINE(FMT) "\x1b[4m" FMT CHALK_DEFAULT_UNDERLINE
#define CHALK_BLINK(FMT) "\x1b[5m" FMT CHALK_DEFAULT_BLINK
#define CHALK_STRIKE(FMT) "\x1b[9m" FMT CHALK_DEFAULT_STRIKE
#define CHALK_INVERSE(FMT) "\x1b[7m" FMT CHALK_DEFAULT_INVERSE
#define CHALK_HIDE(FMT) "\x1b[8m" FMT CHALK_DEFAULT_REVEAL

#ifdef CHALK_NO_PREFIX

#define BLACK CHALK_BLACK
#define RED CHALK_RED
#define GREEN CHALK_GREEN
#define YELLOW CHALK_YELLOW
#define BLUE CHALK_BLUE
#define MAGENTA CHALK_MAGENTA
#define CYAN CHALK_CYAN
#define WHITE CHALK_WHITE
#define LIGHT_BLACK CHALK_LIGHT_BLACK
#define LIGHT_RED CHALK_LIGHT_RED
#define LIGHT_GREEN CHALK_LIGHT_GREEN
#define LIGHT_YELLOW CHALK_LIGHT_YELLOW
#define LIGHT_BLUE CHALK_LIGHT_BLUE
#define LIGHT_MAGENTA CHALK_LIGHT_MAGENTA
#define LIGHT_CYAN CHALK_LIGHT_CYAN
#define LIGHT_WHITE CHALK_LIGHT_WHITE

#define BG_BLACK CHALK_BG_BLACK
#define BG_RED CHALK_BG_RED
#define BG_GREEN CHALK_BG_GREEN
#define BG_YELLOW CHALK_BG_YELLOW
#define BG_BLUE CHALK_BG_BLUE
#define BG_MAGENTA CHALK_BG_MAGENTA
#define BG_CYAN CHALK_BG_CYAN
#define BG_WHITE CHALK_BG_WHITE
#define BG_LIGHT_BLACK CHALK_BG_LIGHT_BLACK
#define BG_LIGHT_RED CHALK_BG_LIGHT_RED
#define BG_LIGHT_GREEN CHALK_BG_LIGHT_GREEN
#define BG_LIGHT_YELLOW CHALK_BG_LIGHT_YELLOW
#define BG_LIGHT_BLUE CHALK_BG_LIGHT_BLUE
#define BG_LIGHT_MAGENTA CHALK_BG_LIGHT_MAGENTA
#define BG_LIGHT_CYAN CHALK_BG_LIGHT_CYAN
#define BG_LIGHT_WHITE CHALK_BG_LIGHT_WHITE

#define BOLD CHALK_BOLD
#define DIM CHALK_DIM
#define ITALIC CHALK_ITALIC
#define UNDERLINE CHALK_UNDERLINE
#define BLINK CHALK_BLINK
#define STRIKE CHALK_STRIKE
#define INVERSE CHALK_INVERSE
#define HIDE CHALK_HIDE

#endif /* CHALK_NO_PREFIX */

#endif /* _CHALK_H_ */
