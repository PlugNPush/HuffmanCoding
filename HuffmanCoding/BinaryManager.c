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

Dico* import_dico(char* location) {
    
    FILE *dico = fopen(location, "r");

    if (dico == NULL) {
        exit(EXIT_FAILURE);
    }

    int* size = malloc(sizeof(int));
    fscanf(dico, "MAX_BITS:%d", size);
    
    Dico* dict = malloc(sizeof(Dico));
    Dico** temp = &dict;
    getc(dico);
    char letter = getc(dico);
    getc(dico);
    char* binary = (char*)malloc(sizeof(char) * (*size));
    printf("BEGIN READ\n");
    while (fscanf(dico, "%s\n", binary) != EOF) {
        printf("%c:%s\n", letter, binary);
        (*temp)->letter = letter;
        (*temp)->code = (char*)malloc(sizeof(char) * (*size));
        strcpy((*temp)->code, binary);
        (*temp)->next = malloc(sizeof(Dico));
        printf("%c:%s\n", (*temp)->letter, (*temp)->code);
        temp = &(*temp)->next;
        letter = getc(dico);
        getc(dico);
    }
    printf("END READ");
    
    return dict;
    
}
