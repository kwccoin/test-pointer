//
//  integerPointer.c
//  test-pointer
//
//  Created by blue5 on 8/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//

#include "integerPointer.h"

//
//  main.c
//  test-pointer
//
//  Created by blue5 on 8/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//
// https://users.cs.cf.ac.uk/Dave.Marshall/C/node10.html
//

#include <stdio.h>
#include "integerPointer.h"


int integerPointer() {
    // insert code here...
    printf("testing pointers understanding! ==integerPointer start== \n\n");
    
    int x, y, a, b;
    long int c;
    int *ip;
    
    /*
     
     x  1 and x  address is 0x7fff5fbff69c
     y  2 and y  address is 0x7fff5fbff698
     a  31 and a  address is 0x7fff5fbff694
     b  32 and b  address is 0x7fff5fbff690 4 bytes 32 bit ...
     c  53 and c  address is 0x7fff5fbff688 only 2 byte !!!
     ip 1 and ip address is 0x7fff5fbff69c
     */
    
    x = 1;
    y = 2;
    a = 31;
    b = 32;
    c = 53;
    ip = &x;
    
    printf("x  %i and x  address is %p \n",x,   (void *)&x);
    printf("y  %i and y  address is %p \n",y,   (void *)&y);
    printf("a  %i and a  address is %p \n",a,   (void *)&a);
    printf("b  %i and b  address is %p \n",b,   (void *)&b);
    printf("c  %li and c  address is %p \n",c,   (void *)&c);
    // a better one is to use C99 standard but not here : https://stackoverflow.com/questions/9053658/correct-format-specifier-to-print-pointer-address
    printf("ip %i and ip address is %p \n",*ip, (void *)ip);
    
    x = 13;
    
    printf("\nafter x changed to 13\n\n");
    
    printf("x  %i and x  address is %p \n",x,   (void *)&x);
    printf("y  %i and y  address is %p \n",y,   (void *)&y);
    printf("ip %i and ip address is %p \n",*ip, (void *)ip);
    
    y = *ip;
    
    printf("\nafter y changed to *ip\n\n");
    
    printf("x  %i and x  address is %p \n",x,   (void *)&x);
    printf("y  %i and y  address is %p \n",y,   (void *)&y);
    printf("ip %i and ip address is %p \n",*ip, (void *)ip);
    
    printf("you do not use ip on the rhs and use on the lhs for &");
    
    x = ip;
    
    printf("\nafter x changed to ip -- warning - not right as ip is *int and x is int type\n\n");
    printf("\nafter x changed to ip -- lost some info as int cannot store the address\n\n");
    
    printf("x  0x%x and x  address is %p \n",x,   (void *)&x); // lossing the 0x7fff only 5fbff69c left!!!
    printf("x  %i and x  address is %p \n",x,   (void *)&x);
    printf("y  %i and y  address is %p \n",y,   (void *)&y);
    printf("ip %i and ip address is %p \n",*ip, (void *)ip);
    
    *ip = 42;
    
    printf("\nafter ip content is still the old x address and *ip = &x changed to 42\n\n");
    
    printf("x  %i and x  address is %p \n",x,   (void *)&x);
    printf("y  %i and y  address is %p \n",y,   (void *)&y);
    printf("ip %i and ip address is %p \n",*ip, (void *)ip);
    
    printf("\n");
    
    printf("when = x i.e. x is on the rhs, the address of x is use to get     the content pointed by it to   LHS\n");
    printf("when x = i.e. x is on the lhs, the address of x is use to replace the content pointed by it from LHS\n");
    
    printf("similar except it is address of x here\n");
    
    printf("when = *ip i.e. *ip is on the rhs, the address in ip is use to get     the content pointed by it to   LHS\n");
    printf("when *ip = i.e. *ip is on the lhs, the address in ip is use to replace the content pointed by it from LHS\n");
    
    printf("similar except it is address in ip here\n");
    
    printf("you do not use ip on the rhs and use on the lhs for &");
    
    printf("\n");

    printf("testing pointers understanding! ==integerPointer end== \n\n");

    
    return 0;
}

/*
 
 test-pointer`main:
 0x100000820 <+0>:   pushq  %rbp
 0x100000821 <+1>:   movq   %rsp, %rbp
 0x100000824 <+4>:   subq   $0xc0, %rsp
 0x10000082b <+11>:  leaq   0x380(%rip), %rax         ; "testing pointers understanding!\n\n"
 0x100000832 <+18>:  movl   $0x0, -0x4(%rbp)
 0x100000839 <+25>:  movl   %edi, -0x8(%rbp)
 0x10000083c <+28>:  movq   %rsi, -0x10(%rbp)
 0x100000840 <+32>:  movq   %rax, %rdi
 0x100000843 <+35>:  movb   $0x0, %al
 0x100000845 <+37>:  callq  0x100000b92               ; symbol stub for: printf
 0x10000084a <+42>:  leaq   0x383(%rip), %rdi         ; "x  %i and x  address is %p \n"
 0x100000851 <+49>:  leaq   -0x14(%rbp), %rsi
 ->  0x100000855 <+53>:  movl   $0x1, -0x14(%rbp)
 0x10000085c <+60>:  movl   $0x2, -0x18(%rbp)
 0x100000863 <+67>:  movl   $0x1f, -0x1c(%rbp)
 0x10000086a <+74>:  movl   $0x20, -0x20(%rbp)
 0x100000871 <+81>:  movq   $0x35, -0x28(%rbp)
 0x100000879 <+89>:  movq   %rsi, -0x30(%rbp)
 0x10000087d <+93>:  movl   -0x14(%rbp), %ecx
 0x100000880 <+96>:  movq   %rsi, -0x38(%rbp)
 0x100000884 <+100>: movl   %ecx, %esi
 0x100000886 <+102>: movq   -0x38(%rbp), %rdx
 0x10000088a <+106>: movl   %eax, -0x3c(%rbp)
 0x10000088d <+109>: movb   $0x0, %al
 0x10000088f <+111>: callq  0x100000b92               ; symbol stub for: printf
 0x100000894 <+116>: leaq   0x356(%rip), %rdi         ; "y  %i and y  address is %p \n"
 0x10000089b <+123>: leaq   -0x18(%rbp), %rdx
 0x10000089f <+127>: movl   -0x18(%rbp), %esi
 0x1000008a2 <+130>: movl   %eax, -0x40(%rbp)
 0x1000008a5 <+133>: movb   $0x0, %al
 0x1000008a7 <+135>: callq  0x100000b92               ; symbol stub for: printf
 0x1000008ac <+140>: leaq   0x35b(%rip), %rdi         ; "a  %i and a  address is %p \n"
 0x1000008b3 <+147>: leaq   -0x1c(%rbp), %rdx
 0x1000008b7 <+151>: movl   -0x1c(%rbp), %esi
 0x1000008ba <+154>: movl   %eax, -0x44(%rbp)
 0x1000008bd <+157>: movb   $0x0, %al
 0x1000008bf <+159>: callq  0x100000b92               ; symbol stub for: printf
 0x1000008c4 <+164>: leaq   0x360(%rip), %rdi         ; "b  %i and b  address is %p \n"
 0x1000008cb <+171>: leaq   -0x20(%rbp), %rdx
 0x1000008cf <+175>: movl   -0x20(%rbp), %esi
 0x1000008d2 <+178>: movl   %eax, -0x48(%rbp)
 0x1000008d5 <+181>: movb   $0x0, %al
 0x1000008d7 <+183>: callq  0x100000b92               ; symbol stub for: printf
 0x1000008dc <+188>: leaq   0x365(%rip), %rdi         ; "c  %li and c  address is %p \n"
 0x1000008e3 <+195>: leaq   -0x28(%rbp), %rdx
 0x1000008e7 <+199>: movq   -0x28(%rbp), %rsi
 0x1000008eb <+203>: movl   %eax, -0x4c(%rbp)
 0x1000008ee <+206>: movb   $0x0, %al
 0x1000008f0 <+208>: callq  0x100000b92               ; symbol stub for: printf
 0x1000008f5 <+213>: leaq   0x36a(%rip), %rdi         ; "ip %i and ip address is %p \n"
 0x1000008fc <+220>: movq   -0x30(%rbp), %rdx
 0x100000900 <+224>: movl   (%rdx), %esi
 0x100000902 <+226>: movq   -0x30(%rbp), %rdx
 0x100000906 <+230>: movl   %eax, -0x50(%rbp)
 0x100000909 <+233>: movb   $0x0, %al
 0x10000090b <+235>: callq  0x100000b92               ; symbol stub for: printf
 0x100000910 <+240>: leaq   0x36c(%rip), %rdi         ; "\nafter x changed to 13\n\n"
 0x100000917 <+247>: movl   $0xd, -0x14(%rbp)
 0x10000091e <+254>: movl   %eax, -0x54(%rbp)
 0x100000921 <+257>: movb   $0x0, %al
 0x100000923 <+259>: callq  0x100000b92               ; symbol stub for: printf
 0x100000928 <+264>: leaq   0x2a5(%rip), %rdi         ; "x  %i and x  address is %p \n"
 0x10000092f <+271>: leaq   -0x14(%rbp), %rdx
 0x100000933 <+275>: movl   -0x14(%rbp), %esi
 0x100000936 <+278>: movl   %eax, -0x58(%rbp)
 0x100000939 <+281>: movb   $0x0, %al
 0x10000093b <+283>: callq  0x100000b92               ; symbol stub for: printf
 0x100000940 <+288>: leaq   0x2aa(%rip), %rdi         ; "y  %i and y  address is %p \n"
 0x100000947 <+295>: leaq   -0x18(%rbp), %rdx
 0x10000094b <+299>: movl   -0x18(%rbp), %esi
 0x10000094e <+302>: movl   %eax, -0x5c(%rbp)
 0x100000951 <+305>: movb   $0x0, %al
 0x100000953 <+307>: callq  0x100000b92               ; symbol stub for: printf
 0x100000958 <+312>: leaq   0x307(%rip), %rdi         ; "ip %i and ip address is %p \n"
 0x10000095f <+319>: movq   -0x30(%rbp), %rdx
 0x100000963 <+323>: movl   (%rdx), %esi
 0x100000965 <+325>: movq   -0x30(%rbp), %rdx
 0x100000969 <+329>: movl   %eax, -0x60(%rbp)
 0x10000096c <+332>: movb   $0x0, %al
 0x10000096e <+334>: callq  0x100000b92               ; symbol stub for: printf
 0x100000973 <+339>: leaq   0x322(%rip), %rdi         ; "\nafter y changed to *ip\n\n"
 0x10000097a <+346>: movq   -0x30(%rbp), %rdx
 0x10000097e <+350>: movl   (%rdx), %ecx
 0x100000980 <+352>: movl   %ecx, -0x18(%rbp)
 0x100000983 <+355>: movl   %eax, -0x64(%rbp)
 0x100000986 <+358>: movb   $0x0, %al
 0x100000988 <+360>: callq  0x100000b92               ; symbol stub for: printf
 0x10000098d <+365>: leaq   0x240(%rip), %rdi         ; "x  %i and x  address is %p \n"
 0x100000994 <+372>: leaq   -0x14(%rbp), %rdx
 0x100000998 <+376>: movl   -0x14(%rbp), %esi
 0x10000099b <+379>: movl   %eax, -0x68(%rbp)
 0x10000099e <+382>: movb   $0x0, %al
 0x1000009a0 <+384>: callq  0x100000b92               ; symbol stub for: printf
 0x1000009a5 <+389>: leaq   0x245(%rip), %rdi         ; "y  %i and y  address is %p \n"
 0x1000009ac <+396>: leaq   -0x18(%rbp), %rdx
 0x1000009b0 <+400>: movl   -0x18(%rbp), %esi
 0x1000009b3 <+403>: movl   %eax, -0x6c(%rbp)
 0x1000009b6 <+406>: movb   $0x0, %al
 0x1000009b8 <+408>: callq  0x100000b92               ; symbol stub for: printf
 0x1000009bd <+413>: leaq   0x2a2(%rip), %rdi         ; "ip %i and ip address is %p \n"
 0x1000009c4 <+420>: movq   -0x30(%rbp), %rdx
 0x1000009c8 <+424>: movl   (%rdx), %esi
 0x1000009ca <+426>: movq   -0x30(%rbp), %rdx
 0x1000009ce <+430>: movl   %eax, -0x70(%rbp)
 0x1000009d1 <+433>: movb   $0x0, %al
 0x1000009d3 <+435>: callq  0x100000b92               ; symbol stub for: printf
 0x1000009d8 <+440>: leaq   0x2d7(%rip), %rdi         ; "\nafter x changed to ip -- warning - not right as ip is *int and x is int type\n\n"
 0x1000009df <+447>: movq   -0x30(%rbp), %rdx
 0x1000009e3 <+451>: movl   %edx, %ecx
 0x1000009e5 <+453>: movl   %ecx, -0x14(%rbp)
 0x1000009e8 <+456>: movl   %eax, -0x74(%rbp)
 0x1000009eb <+459>: movb   $0x0, %al
 0x1000009ed <+461>: callq  0x100000b92               ; symbol stub for: printf
 0x1000009f2 <+466>: leaq   0x30d(%rip), %rdi         ; "\nafter x changed to ip -- lost some info as int cannot store the address\n\n"
 0x1000009f9 <+473>: movl   %eax, -0x78(%rbp)
 0x1000009fc <+476>: movb   $0x0, %al
 0x1000009fe <+478>: callq  0x100000b92               ; symbol stub for: printf
 0x100000a03 <+483>: leaq   0x347(%rip), %rdi         ; "x  0x%x and x  address is %p \n"
 0x100000a0a <+490>: leaq   -0x14(%rbp), %rdx
 0x100000a0e <+494>: movl   -0x14(%rbp), %esi
 0x100000a11 <+497>: movl   %eax, -0x7c(%rbp)
 0x100000a14 <+500>: movb   $0x0, %al
 0x100000a16 <+502>: callq  0x100000b92               ; symbol stub for: printf
 0x100000a1b <+507>: leaq   0x1b2(%rip), %rdi         ; "x  %i and x  address is %p \n"
 0x100000a22 <+514>: leaq   -0x14(%rbp), %rdx
 0x100000a26 <+518>: movl   -0x14(%rbp), %esi
 0x100000a29 <+521>: movl   %eax, -0x80(%rbp)
 0x100000a2c <+524>: movb   $0x0, %al
 0x100000a2e <+526>: callq  0x100000b92               ; symbol stub for: printf
 0x100000a33 <+531>: leaq   0x1b7(%rip), %rdi         ; "y  %i and y  address is %p \n"
 0x100000a3a <+538>: leaq   -0x18(%rbp), %rdx
 0x100000a3e <+542>: movl   -0x18(%rbp), %esi
 0x100000a41 <+545>: movl   %eax, -0x84(%rbp)
 0x100000a47 <+551>: movb   $0x0, %al
 0x100000a49 <+553>: callq  0x100000b92               ; symbol stub for: printf
 0x100000a4e <+558>: leaq   0x211(%rip), %rdi         ; "ip %i and ip address is %p \n"
 0x100000a55 <+565>: movq   -0x30(%rbp), %rdx
 0x100000a59 <+569>: movl   (%rdx), %esi
 0x100000a5b <+571>: movq   -0x30(%rbp), %rdx
 0x100000a5f <+575>: movl   %eax, -0x88(%rbp)
 0x100000a65 <+581>: movb   $0x0, %al
 0x100000a67 <+583>: callq  0x100000b92               ; symbol stub for: printf
 0x100000a6c <+588>: leaq   0x2fd(%rip), %rdi         ; "\nafter ip content is still the old x address and *ip = &x changed to 42\n\n"
 0x100000a73 <+595>: movq   -0x30(%rbp), %rdx
 0x100000a77 <+599>: movl   $0x2a, (%rdx)
 0x100000a7d <+605>: movl   %eax, -0x8c(%rbp)
 0x100000a83 <+611>: movb   $0x0, %al
 0x100000a85 <+613>: callq  0x100000b92               ; symbol stub for: printf
 0x100000a8a <+618>: leaq   0x143(%rip), %rdi         ; "x  %i and x  address is %p \n"
 0x100000a91 <+625>: leaq   -0x14(%rbp), %rdx
 0x100000a95 <+629>: movl   -0x14(%rbp), %esi
 0x100000a98 <+632>: movl   %eax, -0x90(%rbp)
 0x100000a9e <+638>: movb   $0x0, %al
 0x100000aa0 <+640>: callq  0x100000b92               ; symbol stub for: printf
 0x100000aa5 <+645>: leaq   0x145(%rip), %rdi         ; "y  %i and y  address is %p \n"
 0x100000aac <+652>: leaq   -0x18(%rbp), %rdx
 0x100000ab0 <+656>: movl   -0x18(%rbp), %esi
 0x100000ab3 <+659>: movl   %eax, -0x94(%rbp)
 0x100000ab9 <+665>: movb   $0x0, %al
 0x100000abb <+667>: callq  0x100000b92               ; symbol stub for: printf
 0x100000ac0 <+672>: leaq   0x19f(%rip), %rdi         ; "ip %i and ip address is %p \n"
 0x100000ac7 <+679>: movq   -0x30(%rbp), %rdx
 0x100000acb <+683>: movl   (%rdx), %esi
 0x100000acd <+685>: movq   -0x30(%rbp), %rdx
 0x100000ad1 <+689>: movl   %eax, -0x98(%rbp)
 0x100000ad7 <+695>: movb   $0x0, %al
 0x100000ad9 <+697>: callq  0x100000b92               ; symbol stub for: printf
 0x100000ade <+702>: leaq   0x2d5(%rip), %rdi         ; "'\n'"
 0x100000ae5 <+709>: movl   %eax, -0x9c(%rbp)
 0x100000aeb <+715>: movb   $0x0, %al
 0x100000aed <+717>: callq  0x100000b92               ; symbol stub for: printf
 0x100000af2 <+722>: leaq   0x2c3(%rip), %rdi         ; "when = x i.e. x is on the rhs, the address of x is use to get     the content pointed by it to   LHS\n"
 0x100000af9 <+729>: movl   %eax, -0xa0(%rbp)
 0x100000aff <+735>: movb   $0x0, %al
 0x100000b01 <+737>: callq  0x100000b92               ; symbol stub for: printf
 0x100000b06 <+742>: leaq   0x315(%rip), %rdi         ; "when x = i.e. x is on the lhs, the address of x is use to replace the content pointed by it from LHS\n"
 0x100000b0d <+749>: movl   %eax, -0xa4(%rbp)
 0x100000b13 <+755>: movb   $0x0, %al
 0x100000b15 <+757>: callq  0x100000b92               ; symbol stub for: printf
 0x100000b1a <+762>: leaq   0x367(%rip), %rdi         ; "similar except it is address of x here\n"
 0x100000b21 <+769>: movl   %eax, -0xa8(%rbp)
 0x100000b27 <+775>: movb   $0x0, %al
 0x100000b29 <+777>: callq  0x100000b92               ; symbol stub for: printf
 0x100000b2e <+782>: leaq   0x37b(%rip), %rdi         ; "when = *ip i.e. *ip is on the rhs, the address in ip is use to get     the content pointed by it to   LHS\n"
 0x100000b35 <+789>: movl   %eax, -0xac(%rbp)
 0x100000b3b <+795>: movb   $0x0, %al
 0x100000b3d <+797>: callq  0x100000b92               ; symbol stub for: printf
 0x100000b42 <+802>: leaq   0x3d2(%rip), %rdi         ; "when *ip = i.e. *ip is on the lhs, the address in ip is use to replace the content pointed by it from LHS\n"
 0x100000b49 <+809>: movl   %eax, -0xb0(%rbp)
 0x100000b4f <+815>: movb   $0x0, %al
 0x100000b51 <+817>: callq  0x100000b92               ; symbol stub for: printf
 0x100000b56 <+822>: leaq   0x429(%rip), %rdi         ; "similar except it is address in ip here\n"
 0x100000b5d <+829>: movl   %eax, -0xb4(%rbp)
 0x100000b63 <+835>: movb   $0x0, %al
 0x100000b65 <+837>: callq  0x100000b92               ; symbol stub for: printf
 0x100000b6a <+842>: leaq   0x249(%rip), %rdi         ; "'\n'"
 0x100000b71 <+849>: movl   %eax, -0xb8(%rbp)
 0x100000b77 <+855>: movb   $0x0, %al
 0x100000b79 <+857>: callq  0x100000b92               ; symbol stub for: printf
 0x100000b7e <+862>: xorl   %ecx, %ecx
 0x100000b80 <+864>: movl   %eax, -0xbc(%rbp)
 0x100000b86 <+870>: movl   %ecx, %eax
 0x100000b88 <+872>: addq   $0xc0, %rsp
 0x100000b8f <+879>: popq   %rbp
 0x100000b90 <+880>: retq
 
 */
