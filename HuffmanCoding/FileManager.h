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

void load_binary(char* location, char **binaire);
int calculate_size(char* location);
void save_output(char* location, char* texte);

#endif /* FileManager_h */
