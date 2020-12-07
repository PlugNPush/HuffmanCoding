//
//  BinaryManager.h
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#ifndef BinaryManager_h
#define BinaryManager_h

#include "global.h"

typedef struct Dico {
    char* code;
    char letter;
    struct Dico* next;
}Dico;

char *get_binary(char character); //Renvoie la chaine binaire correspondant au caractère en fonction de la table ASCII
Dico* import_dico(char* location);

#endif /* BinaryManager_h */
