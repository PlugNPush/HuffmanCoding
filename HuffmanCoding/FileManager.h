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

int depth(Arbre* tree);
void export_dico(char* location, Arbre* noeud,char* val);
void create_dico(FILE *output, Arbre* noeud, char* val);
void load_binary(char* location, char **binaire); //Recupere un texte depuis un fichier
int calculate_size(char* location); //Renvoie le nombre de caracteres d'un ficher
void save_output(char* dico_location, char* compressedLocation, char* asciiLocation, char* texte); //Creer le ficher compresse
char* get_dico(char* location, char character); //Renvoie la chaine binaire correspondant au caractËre en fonction du dictionnaire
void decode_dico(char* dicoLocation, char* exportLocation, char* sequence, int max_bits);

#endif /* FileManager_h */
