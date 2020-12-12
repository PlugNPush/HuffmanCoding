/*****************************************************************//**
 * \file   OccurrencesManager.h
 * \brief  Header of the library allowing the management of Arbre, Occurrences and OccurrencesList.
 *
 * \author Michael NASS michael.nass@efrei.net, Nassim BELLIK nassim.bellik@efrei.net, Vincent MARGUET vincent.marguet@efrei.net, Martin GAYET martin.gayet@efrei.net, Martin FRIN martin.frin@efrei.net
 * \date   December 2020
*********************************************************************/


//
//  OccurencesManager.h
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#ifndef OccurrencesManager_h
#define OccurrencesManager_h

#include "global.h"

/** 
 * \typedef struct Arbre
 * \brief The Arbre struct is a tree containing a weight, a letter and two childs.
 */
typedef struct Arbre {
    struct Arbre* left; /**< the left value of the Arbre tree */
    struct Arbre* right;    /**< the right value of the Arbre tree */
    int poids;  /**< the weight of the current item */
    char letter;    /**< the letter of the current item */
} Arbre;

/** 
 * \typedef struct Occurrences
 * \brief The Occurences struct is a list containing an Arbre tree knot.
 */
typedef struct Occurrences {
    struct Arbre* noeud;    /**< the Arbre tree knot */
    struct Occurrences* next;   /**< the next value of the Occurrences list */
} Occurrences;

/** 
 * \typedef struct OccurrencesList
 * \brief The OccurrencesList struct is a host containing an Occurrences list.
 */
typedef struct OccurrencesList {
    Occurrences *list;  /**< the Occurrences list */
} OccurrencesList;

/**
 * \brief Function to create a Occurrences via a char* text.
 *		   \n Example :
 *			\code{.c}
 *			Occurrences* occurrences = getOccurrences("Hello World!");
 *			\endcode
 * \return the Occurrences's pointer.
 */
Occurrences* getOccurrences(char* texte);

/**
 * \brief Function to remove the minimum Occurrences in an OccurrencesList.
 *		   \n Example :
 *			\code{.c}
 *			Occurrences* minimum = removeMin(occurrencesList);
 *			\endcode
 * \return the minimum Occurrences's pointer.
 */
Occurrences* removeMin(OccurrencesList* listHost);

/**
 * \brief Function to remove a Occurrences on the given position in the OccurrencesList list.
 *		   \n Example :
 *			\code{.c}
 *			removeAt(2, occurrencesList);
 *			\endcode
 */
void removeAt(int it, OccurrencesList* forList);

/**
 * \brief Function to retrive the minimum Occurrences position in the OccurrencesList list.
 *		   \n Example :
 *			\code{.c}
 *			int minpos = minpos(occurrencesList);
 *			\endcode
 * \return the int position of the minimum.
 */
int minpos(OccurrencesList* listHost);

/**
 * \brief Function to create an Arbre tree knot.
 *		   \n Example :
 *			\code{.c}
 *			crea_noeud(occurrencesList);
 *			\endcode
 */
void crea_noeud(OccurrencesList* ocl);

#endif /* OccurrencesManager_h */
