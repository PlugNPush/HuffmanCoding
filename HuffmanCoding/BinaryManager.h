/*****************************************************************//**
 * \file   BinaryManager.h
 * \brief  Header of the library allowing the management of Dico.
 *
 * \author Michael NASS michael.nass@efrei.net, Nassim BELLIK nassim.bellik@efrei.net, Vincent MARGUET vincent.marguet@efrei.net, Martin GAYET martin.gayet@efrei.net, Martin FRIN martin.frin@efrei.net
 * \date   December 2020
*********************************************************************/


//
//  BinaryManager.h
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#ifndef BinaryManager_h
#define BinaryManager_h

#include "global.h"

/** 
 * \typedef struct Dico
 * \brief The Dico struct is a list containing a couple of letters and Huffman binary codes.
 */
typedef struct Dico {
    char* code;  /**< the Huffman binary code for a specific letter */
    char letter;    /**< the letter associated with the Huffman binary code */
    struct Dico* next;  /**< the next value of the Dico list */
}Dico;

/**
 * \brief Function to get the ASCII binary code for a given character.
 *		   \n Example :
 *			\code{.c}
 *			char* a_ascii = get_binary('a');
 *			\endcode
 * \return the ASCII binary code's char pointer.
 */
char *get_binary(char character); //Renvoie la chaine binaire correspondant au caract�re en fonction de la table ASCII

/**
 * \brief Function to create a Dico via the reading of a given file.
 *		   \n Example :
 *			\code{.c}
 *			Dico* dico = import_dico("Dico.txt");
 *			\endcode
 * \return the Dico's pointer.
 */
Dico* import_dico(char* location);

#endif /* BinaryManager_h */
