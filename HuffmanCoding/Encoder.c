#include <stdlib.h>
#include <stdio.h>

#include "Encoder.h"
#include "FileManager.h"


char* get_dico(char character) {

    printf("Chargement du dictionnaire\n");
    FILE *Dico = fopen("Dico.txt", "r");

    if (Dico == NULL) {
        perror("Impossible de charger la base de donnees!\n");
        fclose(Dico);
        return;
    }

    char* chaine = NULL;

    while (fgetc(Dico) != character) {
    }
    fgetc(Dico); //pour les deux points
    //lire_ligne(&chaine, Dico);
    fscanf(Dico, "%[^\n]\n", chaine);
    printf("%s\n", chaine);


    fclose(Dico);
    return chaine;
}
