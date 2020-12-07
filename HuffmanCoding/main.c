//
//  main.c
//  HuffmanCoding
//
//  Created by PlugN on 02/11/2020.
//
// modifié
#include "global.h"
#include "BinaryManager.h"
#include "FileManager.h"
#include "OccurrencesManager.h"
#include <unistd.h>


int main(int argc, const char * argv[]) {

    printf("RAW Value of A : %d\n", 'A');

    printf("ASCII binary of A : %s\n", get_binary((int)'A'));

    printf("\n\n");

    char* bin;
    load_binary("Alice.txt", &bin);

    OccurrencesList* ocl;
    ocl = malloc(sizeof(OccurrencesList));
    ocl->list = getOccurrences(bin);

    printf("%s\n", bin);

    Occurrences* occ = ocl->list;

    while (occ != NULL) {
        printf("%c %d\n", occ->noeud->letter, occ->noeud->poids);
        occ = occ->next;
    }

    while (ocl->list->next != NULL) {
        crea_noeud(ocl);
    }

    char* numero = malloc(sizeof(char)*(depth(ocl->list->noeud)-1));
    export_dico("Dico.txt", ocl->list->noeud, numero);

    
    char* huffman;
    load_binary("Output.txt", &huffman);
    decode_dico("Dico.txt", "HuffmannDecoded.txt", huffman, 8);
    

    printf("Alice.txt : %d caractères\nOutput.txt : %d caractères\nASCIIOutput.txt : %d caractères\n", calculate_size("Alice.txt"), calculate_size("Output.txt"), calculate_size("ASCIIOutput.txt"));
    save_output("Dico.txt", "Output.txt", "ASCIIOutput.txt", bin);

    return 0;
}
