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
    int min = listHost->list->noeud->poids;
    Occurrences *tmp = listHost->list;

    int i = 0;
    while ((tmp) != NULL) {
        if ((tmp)->noeud->poids < min) {
            min = (tmp)->noeud->poids;
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
    occ->noeud = malloc(sizeof(Arbre));
    if (texte[0] != '\0') {
        occ->noeud->poids = 1;
        occ->noeud->letter = texte[0];
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
            if (texte[i] == (*tmp)->noeud->letter) {
                (*tmp)->noeud->poids++;
                placed = 1;
            }
            tmp = &(*tmp)->next;
        }

        if (placed != 1) {
            (*tmp) = malloc(sizeof(Occurrences));
            (*tmp)->noeud = malloc(sizeof(Arbre));
            (*tmp)->noeud->letter = texte[i];
            (*tmp)->noeud->poids = 1;
            (*tmp)->next = NULL;
        }

        // Parcourir, condition d'arrêt \0, vérif char == [i] à chaque iter, sinon ->next malloc
    }
    return occ;
}
