//
//  asmPointer.s
//  test-pointer
//
//  Created by blue5 on 14/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//
// * http://www.idryman.org/blog/2014/12/02/writing-64-bit-assembly-on-mac-os-x/
// https://stackoverflow.com/questions/25326307/using-assembly-code-inside-objective-c-program-xcode

# hello_asm2.s
# as hello_asm2.s -o hello_asm2.o
# ld hello_asm2.o -e _main -lc -o hello_asm2
//.section __DATA,__data
//str:
//.asciz "Hello asmPointer!\n"
//
//.section __TEXT,__text
//.globl _asmPointer
//_asmPointer:
//pushq %rbp
//movq %rsp, %rbp
//movq str@GOTPCREL(%rip), %rdi
//movb $0, %al
//callq _printf
//popq %rbp
//movl $0x2000001, %eax
//syscall
//ret

.text
.globl _asmPointer
_asmPointer:
add %esi, %edi  // add x and y
mov %edi, %eax  // move result to correct register for return value
ret

