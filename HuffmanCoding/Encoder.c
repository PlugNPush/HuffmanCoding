#include <stdlib.h>
#include <stdio.h>

#include "Encoder.h"
#include "FileManager.h"


char* get_dico(char* location, char character) {

    printf("Chargement depuis l'emplacement: %s\n", location);
    FILE *dico = fopen(location, "r");

    if (dico == NULL) {
        exit(EXIT_FAILURE);
    }

    int* size;
    fscanf(dico, "MAX_BITS:%d\n", &size);
    printf("%d", size);

    char* chaine = (char*)malloc(sizeof(char)*(*size)); //modifier plus tard

    while (fgetc(dico) != character) { //Pour aller au caractere voulu
    }

    if (fgetc(dico) != ':') { //Pour les deux points et le retour a la ligne
        fgetc(dico);
    }

    fscanf(dico, "%[^\n]\n", chaine);
    fclose(dico);
    return chaine;
}


