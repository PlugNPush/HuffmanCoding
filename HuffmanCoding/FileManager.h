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

void load_binary(char* location, char **binaire);
int calculate_size(char* location);
void save_output(char* location, char* texte);
int depth(Arbre* tree);
void lire_arbre(Arbre* noeud,char* val);

#endif /* FileManager_h */
