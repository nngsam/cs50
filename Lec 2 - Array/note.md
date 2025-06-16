- when using a library, it's sometimes not sufficiently only to include the header ***#include <cs50.h>*** at your top of your code which just tell the compiler that functions you gonna use below are exist. <br>
  → You additionally need to tell the computer where to find the 0's and 1's that someone has written to implement a function (inside the lib)


### Compiling
these steps that computer is going to do for you when compiling the code 
- preprocessing: take your own source code and preprocess the code top to bottom, left to right
  - preprocessing means it looks for any lines that start with a hash symblol **#...** and _replace_ which is go ahead and copy the contents of the file or lib (mentioned behind the hash symbol)
- compiling: to assembly code 
- assembling: complile assembly code to machine code 0's and 1's
- linking: we have 0_1 from lib, from cs50, from printf for ex then linking all these parts to represent the program <br>
    ❓where the library installed: 
      - Standard library: Comes built-in with the compiler (like GCC, Clang, MSVC).
      - Non-Standard Library (aka third parties libraries): Not included by default with the compiler, have to install manually


### Array


### String

| **Khái niệm**                 | **Có null terminator không?** | **Giải thích**                                |
| ----------------------------- | ----------------------------- | --------------------------------------------- |
| `'a'` (character literal)     | ❌ Không                       | Là 1 ký tự, không phải string                 |
| `"a"` (string literal)        | ✅ Có (`\0`)                   | Là mảng ký tự: `{'a', '\0'}`                  |
| `char s[] = {'a', 'b', 'c'};` | ❌ Không                       | Không có `\0`, không phải string đúng chuẩn C |
| `char s[] = "abc";`           | ✅ Có (`\0`)                   | Chính xác là mảng `{'a', 'b', 'c', '\0'}`     |
| `char *s = "abc";`            | ✅ Có (`\0`)                   | Trỏ đến string literal `"abc"` đã có `\0`     |

- stop sign - null terminator <br>
- char* s;  // hợp lệ 
  char *s;  // cũng hợp lệ 



