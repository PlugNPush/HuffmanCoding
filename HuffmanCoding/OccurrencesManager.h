//
//  OccurencesManager.h
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#ifndef OccurrencesManager_h
#define OccurrencesManager_h

#include "global.h"

typedef struct Occurrences {
    char letter;
    int count;
    struct Occurrences* next;
} Occurrences;

typedef struct OccurrencesList {
    Occurrences *list;
} OccurrencesList;

typedef struct Arbre {
    struct Arbre* left;
    struct Arbre* right;
    int poids;
    char letter;
} Arbre;

Occurrences* getOccurrences(char* texte);
void removeAt(int it, OccurrencesList* forList);
Occurrences* removeMin(OccurrencesList* listHost);
void removeAt(int it, OccurrencesList* forList);
int minpos(OccurrencesList* listHost);

#endif /* OccurrencesManager_h */
