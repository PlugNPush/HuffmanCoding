/*****************************************************************//**
 * \file   FileManager.h
 * \brief  Header of the library allowing the management, encoding and decoding of FILE using Arbre.
 *
 * \author Michael NASS michael.nass@efrei.net, Nassim BELLIK nassim.bellik@efrei.net, Vincent MARGUET vincent.marguet@efrei.net, Martin GAYET martin.gayet@efrei.net, Martin FRIN martin.frin@efrei.net
 * \date   December 2020
*********************************************************************/


//
//  FileManager.h
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#ifndef FileManager_h
#define FileManager_h

#include "BinaryManager.h"
#include "global.h"
#include "OccurrencesManager.h"

/**
 * \brief Function to get the depth of an Arbre tree.
 *		   \n Example :
 *			\code{.c}
 *			int depth = depth(tree);
 *			\endcode
 * \return the depth of the Arbre tree.
 */
int depth(Arbre* tree);

/**
 * \brief Function to write a Dico to a given location using an Arbre tree and an empty char pointer.
 *		   \n Example :
 *			\code{.c}
 *			export_dico("Dico.txt", tree, emptyChar);
 *			\endcode
 */
void export_dico(char* location, Arbre* noeud,char* val);

/**
 * \brief Function to write a Dico to a given FILE using an Arbre tree and an empty char pointer.
 *		   \n Example :
 *			\code{.c}
 *			create_dico(output, tree, emptyChar);
 *			\endcode
 */
void create_dico(FILE *output, Arbre* noeud, char* val);

/**
 * \brief Function to read an entire file of a given location into a char pointer.
 *		   \n Example :
 *			\code{.c}
 *			load_binary("Alice.txt", text);
 *			\endcode
 */
void load_binary(char* location, char **binaire); //Recupere un texte depuis un fichier

/**
 * \brief Function to get the number of characters in a given file location.
 *		   \n Example :
 *			\code{.c}
 *			int size = calculate_size("Output.txt");
 *			\endcode
 * \return the int number of characters in the file.
 */
int calculate_size(char* location); //Renvoie le nombre de caracteres d'un ficher

/**
 * \brief Function to save the Huffman and ASCII binary codes for a given text using given dictionnary and export locations.
 *		   \n Example :
 *			\code{.c}
 *			save_output("Dico.txt", "Output.txt", "ASCIIOutput.txt", text);
 *			\endcode
 */
void save_output(char* dico_location, char* compressedLocation, char* asciiLocation, char* texte); //Creer le ficher compresse

/**
 * \brief Function to get the Huffman binary code for a given character.
 *		   \n Example :
 *			\code{.c}
 *			char* a_huffman = get_dico("Dico.txt", 'a');
 *			\endcode
 * \return the Huffman binary code's char pointer.
 */
char* get_dico(char* location, char character); //Renvoie la chaine binaire correspondant au caractËre en fonction du dictionnaire

/**
 * \brief Function to get the dictionnary translation for a given Huffman binary code sequence, dictionnary location, export location and maximum bits.
 *		   \n Example :
 *			\code{.c}
 *			decode_dico("Dico.txt", "HuffmanDecoded.txt", sequence, maxBits);
 *			\endcode
 */
void decode_dico(char* dicoLocation, char* exportLocation, char* sequence, int max_bits);

/**
 * \brief Function to get the maximum bits in a dictionnary.
 *		   \n Example :
 *			\code{.c}
 *			int size = get_max_bits("Dico.txt");
 *			\endcode
 * \return the int value of the maximum bits.
 */
int get_max_bits(char* location);

#endif /* FileManager_h */
