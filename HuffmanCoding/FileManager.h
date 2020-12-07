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

void load_binary(char* location, char **binaire); //Recupere un texte depuis un fichier
int calculate_size(char* location); //Renvoie le nombre de caracteres d'un ficher
void save_output(char* dico_location, char* location, char* texte); //Creer le ficher compresse

#endif /* FileManager_h */
