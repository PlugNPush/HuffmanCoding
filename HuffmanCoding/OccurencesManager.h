//
//  OccurencesManager.h
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#ifndef OccurencesManager_h
#define OccurencesManager_h

#include "global.h"

typedef struct Occurences {
    char letter;
    int count;
    struct Occurences* next;
} Occurences;

Occurences* getOccurences(char* texte);

#endif /* OccurencesManager_h */
