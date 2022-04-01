# TMA-32 Assembly Language Spec

In TMA-32 Assembly, RAM is divided into 32-bit words, so (ptr+1) starts four eight-bit bytes after (ptr).

## Supported Instructions

`jmp <address>`: sets the instruction pointer to `<address>`.

`movl <register> <value>`: moves a 32-bit value into a register.

`addu <reg1> <reg2> <reg3>`: performs *unsigned* addition on registers `<reg1>` and `<reg2>` storing the result in `<reg3>`.

`addi <reg1> <reg2> <reg3>`: performs *signed* addition on registers `<reg1>` and `<reg2>` storing the result in `<reg3>`.

`addf <reg1> <reg2> <reg3>`: performs *IEEE-754 floating point* addition on registers `<reg1>` and `<reg2>` storing the result in `<reg3>`.

`prnts <register>`: prints the null-terminated string which is pointed to by the value in `<register>`.

`prntu <register>`: prints the value in `<register>` as an unsigned 32-bit integer.

`prnti <register>`: prints the value in `<register>` as a signed 32-bit integer.

`prntf <register>`: prints the value in `<register>` as an IEEE-754 float. Not to be confused with libc function `printf()`.

`prntc <register>`: prints the value in `<register>` as a character.

`halt`: cease execution.

TODO come up with more instructions...

## Assembler Dircetives

`#include "path"`: copy-pastes the contents of the file `path` at the specified point.

`#define <identifier> <value>`: directive for making a macro. Useful for defining integral constants.

`.asciz "string"`: the binary will have the bytes of `"string"` at the point of the directive, terminated by a nul character. These will not be packed; practically speaking, the TMA-32 uses UTF-32 to store strings.

`.zero <n>`: the binary will have `<n>` machine words zeroed out at the point of the directive.
