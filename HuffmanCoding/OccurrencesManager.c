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
                if (tmp->next != NULL) {
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
        occ->noeud->left = NULL;
        occ->noeud->right = NULL;
        occ->next = NULL;
    } else {
        return occ;
    }

    int i = 1;
    for (i = 1; texte[i] != '\0'; i++) {
        Occurrences **tmp = &occ;
        int placed = 0;

        // texte[i] -> contient le caractère.
        
        if (texte[i] == '\r') {
            texte[i] = '\n';
        }

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
            (*tmp)->noeud->left = NULL;
            (*tmp)->noeud->right = NULL;
            (*tmp)->noeud->letter = texte[i];
            (*tmp)->noeud->poids = 1;
            (*tmp)->next = NULL;
        }
    }
    return occ;
}

void crea_noeud(OccurrencesList* ocl){
    if(ocl){
        Occurrences* tmp = ocl->list;
        Occurrences* new_occ = malloc(sizeof(Occurrences));
        new_occ->noeud = malloc(sizeof(Arbre));
        Occurrences* min1 = removeMin(ocl);
        new_occ->noeud->left = min1->noeud;
        Occurrences* min2 = removeMin(ocl);
        new_occ->noeud->right = min2->noeud;
        new_occ->noeud->poids = min1->noeud->poids + min2->noeud->poids;
        new_occ->noeud->letter = '\0';
        new_occ->next = NULL;
        while (tmp->next != NULL){
            tmp = (tmp)->next;
        }
        
        if (ocl->list == NULL) {
            ocl->list = new_occ;
        } else {
            tmp->next = new_occ;
        }
            
    }
}
