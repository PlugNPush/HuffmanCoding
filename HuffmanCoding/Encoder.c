#include <stdlib.h>
#include <stdio.h>

#include "Encoder.h"
#include "FileManager.h"


char* get_dico(char* location, char character) {

    printf("Chargement depuis l'emplacement: %s\n", location);
    FILE *Dico = fopen(location, "r");

    if (Dico == NULL) {
        exit(EXIT_FAILURE);
    }

    char* chaine = (char*)malloc(sizeof(char)*10); //modifier plus tard

    while (fgetc(Dico) != character) { //Pour aller au caractere voulu
    }

    if (fgetc(Dico) != ':') { //Pour les deux points et le retour a la ligne
        fgetc(Dico);
    }

    fscanf(Dico, "%[^\n]\n", chaine);


    fclose(Dico);
    return chaine;
}
