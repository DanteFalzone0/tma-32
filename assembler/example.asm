; Example program written in TMA-32 Assembly

jmp @main

@my_fun_string:
  .asciz "Hello, world!\n"

@another_string:
  .asciz "6 + (-2) equals "

@main:
  movl    ra  @my_fun_string  ; move a char pointer into ra 
  prints  ra                  ; print the char pointer to stdout
  movl    ra  6i              ; move a signed integer into ra
  movl    rb  -2i             ; move a negative signed integer into rb
  addi    ra  rb  rc          ; add the signed integers in ra and rb into rc
  movl    ra  @another_string ; move another char pointer into ra
  prints  ra                  ; print the char pointer
  printi  rc                  ; print the signed integer in rc
  movl    ra  '\n'            ; move a single character into ra
  printc  ra                  ; print that single character
  halt                        ; cease execution
