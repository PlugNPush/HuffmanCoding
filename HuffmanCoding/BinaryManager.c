//
//  BinaryManager.c
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#include "BinaryManager.h"

char *get_binary(char character) {
    int n = (int)character;
    int c, d, t;
    char *p;

    t = 0;
    p = (char*)malloc(8+1);

    if (p == NULL)
      exit(EXIT_FAILURE);

    for (c = 7 ; c >= 0 ; c--) {
        d = n >> c;

        if (d & 1)
            *(p+t) = 1 + '0';
        else
            *(p+t) = 0 + '0';

        t++;
    }
    *(p+t) = '\0';

    return  p;
}
