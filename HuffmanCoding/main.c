//
//  main.c
//  HuffmanCoding
//
//  Created by PlugN on 02/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

///color////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

///lecture//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int lire(char *chaine, int longueur){ ////agie comme un scanf mais securise la limite de taille en general
    char *positionEntree = NULL;
    if (fgets(chaine, longueur, stdin) != NULL){
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL){
            *positionEntree = '\0';
        }
        else{viderBuffer();}
        return 1;
    }
    else{
        viderBuffer();
        return 0;
    }
}

int lire_fichier(char *chaine, int longueur,FILE* fic){ //agie comme un scanf mais securise la limite de taille sur un fichier
    char *positionEntree = NULL;
    if (fgets(chaine, longueur, fic) != NULL){
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL){
            *positionEntree = '\0';
        }
        else{viderBuffer();}
        return 1;
    }
    else{
        viderBuffer();
        return 0;
    }
}

/// Texte//////

void lire_texte(FILE* t){
}

int main(int argc, const char * argv[]) {
    FILE *fic_texte=fopen("Texte.txt","r"); //lecture des informations dans Texte
    lire_texte(fic_texte);
    fclose(fic_texte);
    return 0;
}
