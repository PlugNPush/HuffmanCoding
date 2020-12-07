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

    if (texte == NULL) {
        exit(EXIT_FAILURE);
    }

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

int get_max_bits(char* location) {
    FILE *dico = fopen(location, "r");

    if (dico == NULL) {
        exit(EXIT_FAILURE);
    }

    int* size = malloc(sizeof(int));
    fscanf(dico, "MAX_BITS:%d", size);
    fclose(dico);
    
    return *size;
}

char* get_dico(char* location, char character) {

    FILE *dico = fopen(location, "r");

    if (dico == NULL) {
        exit(EXIT_FAILURE);
    }
    
    if (character == '\n') {
        character = '\a';
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

int depth(Arbre* tree){
    if(tree == NULL){
        return 0;
    }
    else{
        int left_depth = depth(tree->left);
        int right_depth = depth(tree->right);
        if (left_depth > right_depth){
            return 1 + left_depth;
        }
        else{
            return 1 + right_depth;
        }
    }
}

void create_dico(FILE *output, Arbre* noeud, char* val) {
    if (noeud != NULL){
        if (noeud->letter != '\0') {
            if (noeud->letter == '\n') {
                fprintf(output, "%c:%s\n", '\a', val);
            } else {
                fprintf(output, "%c:%s\n",noeud->letter,val);
            }
        }
        char* x = malloc(sizeof(depth(noeud)));
        char* y = malloc(sizeof(depth(noeud)));
        strcpy(x, val);
        strcpy(y, val);
        create_dico(output, noeud->left, strcat(x, "0"));
        create_dico(output, noeud->right, strcat(y, "1"));
    }
}

void export_dico(char* location, Arbre* noeud,char* val){
    printf("Enregistrement a l'emplacement: %s\n", location);
    FILE *output = fopen(location, "wa");
    
    if (output == NULL) {
        exit(EXIT_FAILURE);
    }
    
    fprintf(output, "MAX_BITS:%d\n", depth(noeud));
    
    create_dico(output, noeud, val);
    
    fclose(output);
}

char* appendChar(char* array, char a) {
    size_t len = strlen(array);

    char* ret = malloc(sizeof(char)*len+2);

    strcpy(ret, array);
    ret[len] = a;
    ret[len+1] = '\0';

    return ret;
}

void decode_dico(char* dicoLocation, char* exportLocation, char* sequence, int max_bits) {
    
    Dico* dico = import_dico(dicoLocation);
    Dico* copy;
    
    printf("Enregistrement a l'emplacement: %s\n", exportLocation);
    FILE *output = fopen(exportLocation, "wa");
    
    if (output == NULL) {
        exit(EXIT_FAILURE);
    }
    
    char iteration = sequence[0];
    char* check = malloc(sizeof(char)*max_bits);
    int placed = 0;
    int i = 0;
    int j = 1;
    while (iteration != '\0') {
        check = appendChar(check, iteration);
        copy = dico;
        while (copy != NULL && placed == 0) {
            if (strcmp(copy->code, check) == 0) {
                fprintf(output, "%c", copy->letter);
                placed = 1;
            }
            copy = copy->next;
        }
        if (placed==1) {
            i = 0;
            check[i] = '\0';
            placed = 0;
        }
        iteration = sequence[j];
        i++;
        j++;
    }
    
    fclose(output);
}
