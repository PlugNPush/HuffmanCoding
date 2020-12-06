//
//  OccurencesManager.c
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#include "OccurencesManager.h"

Occurences* getOccurences(char* texte) {
    Occurences* occ = malloc(sizeof(Occurences));
    
    if (texte[0] != '\0') {
        occ->count = 1;
        occ->letter = texte[0];
        occ->next = NULL;
    } else {
        return occ;
    }
    
    int i = 1;
    for (i = 1; texte[i] != '\0'; i++) {
        Occurences **tmp = &occ;
        int placed = 0;
        
        // texte[i] -> contient le caractère.
        
        while ((*tmp) != NULL && placed != 1) {
            if (texte[i] == (*tmp)->letter) {
                (*tmp)->count++;
                placed = 1;
            }
            tmp = &(*tmp)->next;
        }
        
        if (placed != 1) {
            (*tmp) = malloc(sizeof(Occurences));
            (*tmp)->letter = texte[i];
            (*tmp)->count = 1;
            (*tmp)->next = NULL;
        }
        
        // Parcourir, condition d'arrêt \0, vérif char == [i] à chaque iter, sinon ->next malloc
    }
    return occ;
}
