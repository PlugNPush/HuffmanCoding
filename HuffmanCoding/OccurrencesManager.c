//
//  OccurencesManager.c
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#include "OccurrencesManager.h"

void removeAt(int it, OccurrencesList* forList) {
    int i = 0;
    
    if (it <= 0) {
        forList->list = forList->list->next;
    } else {
        Occurrences *tmp = (forList->list);
        while ((tmp) != NULL) {
            if (i == it-1) {
                if (tmp->next == NULL) {
                    free(tmp);
                } else {
                    (tmp)->next = (tmp)->next->next;
                }
            }
            (tmp) = (tmp)->next;
            i++;
        }
    }
}

int minpos(OccurrencesList* listHost) {
    int minpos = 0;
    int min = listHost->list->count;
    Occurrences *tmp = listHost->list;
    
    int i = 0;
    while ((tmp) != NULL) {
        if ((tmp)->count < min) {
            min = (tmp)->count;
            minpos = i;
        }
        (tmp) = (tmp)->next;
        i++;
    }
    return minpos;
}

Occurrences* removeMin(OccurrencesList* listHost) {
    Occurrences *tmp = listHost->list;
    int i = 0;
    int min = minpos(listHost);
    while (i < min) {
        (tmp) = (tmp)->next;
        i++;
    }
    Occurrences* ret = tmp;
    removeAt(min, listHost);
    return ret;
    
}

Occurrences* getOccurrences(char* texte) {
    Occurrences* occ = malloc(sizeof(Occurrences));
    
    if (texte[0] != '\0') {
        occ->count = 1;
        occ->letter = texte[0];
        occ->next = NULL;
    } else {
        return occ;
    }
    
    int i = 1;
    for (i = 1; texte[i] != '\0'; i++) {
        Occurrences **tmp = &occ;
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
            (*tmp) = malloc(sizeof(Occurrences));
            (*tmp)->letter = texte[i];
            (*tmp)->count = 1;
            (*tmp)->next = NULL;
        }
        
        // Parcourir, condition d'arrêt \0, vérif char == [i] à chaque iter, sinon ->next malloc
    }
    return occ;
}
