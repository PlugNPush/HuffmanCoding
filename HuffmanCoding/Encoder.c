#include <stdlib.h>
#include <stdio.h>

#include "Encoder.h"
#include "FileManager.h"


char* get_dico(char character) {

    printf("Chargement du dictionnaire\n");
    FILE *Dico = fopen("Dico.txt", "r");

    if (Dico == NULL) {
        exit(EXIT_FAILURE);
    }

    char* chaine = (char*)malloc(sizeof(char)*10);

    while (fgetc(Dico) != character) {
    }
    fgetc(Dico); //pour les deux points
    fscanf(Dico, "%[^\n]\n", chaine);


    fclose(Dico);
    return chaine;
}
