//
//  FileManager.c
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#include "FileManager.h"

void save_output(char* location, char* texte) {
    
    printf("Enregistrement a l'emplacement: %s\n", location);
    FILE *output = fopen(location, "w");
    
    if (output == NULL) {
        exit(EXIT_FAILURE);
    }
    
    int i = 0;
    
    if (texte == NULL) {
        exit(EXIT_FAILURE);
    }
    
    while (texte[i] != '\0') {
        fprintf(output, "%s", get_binary(texte[i]));
        i++;
    }
    
    fclose(output);
}

int calculate_size(char* location) {
    FILE *integrity_module = fopen(location, "r");
    
    if (integrity_module == NULL) {
        return -1;
    }
    
    char c;
    int integrity = 0;
    for (c = getc(integrity_module); c != EOF; c = getc(integrity_module)) {
        integrity++;
    }
    fclose(integrity_module);
    
    return integrity;
}

void load_binary(char* location, char **binaire) {
    printf("Chargement depuis l'emplacement: %s\n", location);
    FILE *Alice = fopen(location, "r");
    
    if (Alice == NULL) {
        perror("Impossible de charger la base de donnees!\n");
        fclose(Alice);
        return;
    }
    
    int size = calculate_size(location);
    *binaire = (char*) malloc(sizeof(char)*size);
    fscanf(Alice, "%[^\n]\n", *binaire);
    
    fclose(Alice);
}
