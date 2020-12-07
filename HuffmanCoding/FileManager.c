//
//  FileManager.c
//  HuffmanCoding
//
//  Created by PlugN on 6.12.20..
//

#include "FileManager.h"


void save_output(char* dico_location, char* compressedLocation, char* asciiLocation, char* texte) {

    printf("Enregistrement a l'emplacement: %s\n", compressedLocation);
    printf("Enregistrement a l'emplacement: %s\n", asciiLocation);
    FILE *output = fopen(compressedLocation, "w");
    FILE *asciiOutput = fopen(asciiLocation, "w");

    if (output == NULL || asciiOutput == NULL || texte == NULL) {
        exit(EXIT_FAILURE);
    }

    int i = 0;

    while (texte[i] != '\0') {
        fprintf(output, "%s", get_dico(dico_location, texte[i]));
        fprintf(asciiOutput, "%s", get_binary(texte[i]));
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
    FILE *Text = fopen(location, "r");

    if (Text == NULL) {
        exit(EXIT_FAILURE);
    }

    int size = calculate_size(location);
    *binaire = (char*) malloc(sizeof(char)*size);
    fscanf(Text, "%[^\0]", *binaire);
    fclose(Text);
}

char* get_dico(char* location, char character) {

    FILE *dico = fopen(location, "r");

    if (dico == NULL) {
        exit(EXIT_FAILURE);
    }

    int* size = malloc(sizeof(int));
    fscanf(dico, "MAX_BITS:%d", size);

    char* chaine = (char*)malloc(sizeof(char)*(*size));
    char temp = fgetc(dico);
    while (temp != character && temp != EOF) {
        temp = fgetc(dico); //Pour aller au caractere voulu
    }

    if (fgetc(dico) != ':') { //Pour les deux points et le retour a la ligne
        fgetc(dico);
    }

    fscanf(dico, "%[^\n]\n", chaine);
    fclose(dico);
    return chaine;
}
