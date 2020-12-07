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
    save_output("Output.txt", bin);

    OccurrencesList* ocl;
    ocl = malloc(sizeof(OccurrencesList));
    ocl->list = getOccurrences(bin);

    printf("%s\n", bin);

    Occurrences* occ = ocl->list;

    while (occ != NULL) {
        printf("%c %d\n", occ->letter, occ->count);
        occ = occ->next;
    }
    
    Dico* dico = import_dico("Dico.txt");
    
    printf("Alice.txt : %d caractères\nOutput.txt : %d caractères\nASCIIOutput.txt : %d caractères\n", calculate_size("Alice.txt"), calculate_size("Output.txt"), calculate_size("ASCIIOutput.txt"));
    save_output("Dico.txt", "Output.txt", "ASCIIOutput.txt", bin);

    return 0;
}
