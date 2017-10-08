//
//  floatPointer.c
//  test-pointer
//
//  Created by blue5 on 8/10/2017.
//  Copyright © 2017 blue5. All rights reserved.
//

#include "floatPointer.h"

int floatPointer() {
    
    printf("testing pointers understanding! ==floatPointer start== \n\n");

    float p, q, *ip, *iq;
    
    p = (float) 3;
    q = (float) 12;
    ip = &p;
    iq=  &q;
    
    printf("\n-- after init --\n\n");
    printf("p   %f and p  address is %p \n",p,   (void *)&p);
    printf("q   %f and q  address is %p \n",q,   (void *)&q);
    printf("*ip %f and ip address is %p \n",*ip, (void *)ip);
    printf("*iq %f and iq address is %p \n",*iq, (void *)iq);
    
    *ip = *ip + 10;
    
    printf("\n-- after *ip = *ip + 10; --\n\n");
    printf("p   %f and p  address is %p \n",p,   (void *)&p);
    printf("q   %f and q  address is %p \n",q,   (void *)&q);
    printf("*ip %f and ip address is %p \n",*ip, (void *)ip);
    printf("*iq %f and iq address is %p \n",*iq, (void *)iq);
    
    ++*ip;
    
    printf("\n-- after ++*ip; --\n\n");
    printf("p   %f and p  address is %p \n",p,   (void *)&p);
    printf("q   %f and q  address is %p \n",q,   (void *)&q);
    printf("*ip %f and ip address is %p \n",*ip, (void *)ip);
    printf("*iq %f and iq address is %p \n",*iq, (void *)iq);
    
    (*ip)++;
    
    printf("\n-- after (*ip)++; note () as ++ is higher precedence to * --\n\n");
    printf("p   %f and p  address is %p \n",p,   (void *)&p);
    printf("q   %f and q  address is %p \n",q,   (void *)&q);
    printf("*ip %f and ip address is %p \n",*ip, (void *)ip);
    printf("*iq %f and iq address is %p \n",*iq, (void *)iq);
    
    iq = ip;
    
    printf("\n-- after iq = ip; --\n\n");
    printf("p   %f and p  address is %p \n",p,   (void *)&p);
    printf("q   %f and q  address is %p \n",q,   (void *)&q);
    printf("*ip %f and ip address is %p \n",*ip, (void *)ip);
    printf("*iq %f and iq address is %p \n",*iq, (void *)iq);
    
    printf("\n");

    printf("testing pointers understanding! ==floatPointer end== \n\n");

    
    return 0;
}
