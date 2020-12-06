//
//  OccurencesManager.h
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#ifndef OccurrencesManager_h
#define OccurrencesManager_h

#include "global.h"

typedef struct Arbre {
    struct Arbre* left;
    struct Arbre* right;
    int poids;
    char letter;
} Arbre;

typedef struct Occurrences {
    struct Arbre* noeud;
    struct Occurrences* next;
} Occurrences;

typedef struct OccurrencesList {
    Occurrences *list;
} OccurrencesList;

Occurrences* getOccurrences(char* texte);
void removeAt(int it, OccurrencesList* forList);
Occurrences* removeMin(OccurrencesList* listHost);
void removeAt(int it, OccurrencesList* forList);
int minpos(OccurrencesList* listHost);

#endif /* OccurrencesManager_h */
