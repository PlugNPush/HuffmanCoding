//
//  main.c
//  HuffmanCoding
//
//  Created by PlugN on 02/11/2020.
//

#include "global.h"
#include "BinaryManager.h"
#include "FileManager.h"
#include "OccurrencesManager.h"

int main(int argc, const char * argv[]) {

    printf("RAW Value of A : %d\n", 'A');

    printf("ASCII binary of A : %s\n", get_binary((int)'A'));

    printf("\n\n");

    char* bin;
    load_binary("Tasses.txt", &bin);
    save_output("Output.txt", bin);

    printf("Tasses.txt : %d caractères\nOutput.txt : %d caractères\n", calculate_size("Tasses.txt"), calculate_size("Output.txt"));

    OccurrencesList* ocl;
    ocl = malloc(sizeof(OccurrencesList));
    ocl->list = getOccurrences(bin);

    printf("%s\n", bin);

    Occurrences* occ = ocl->list;

    while (occ != NULL) {
        printf("%c %d\n", occ->letter, occ->count);
        occ = occ->next;
    }



    char * character = get_dico('T');
    char * character1 = get_dico('A');
    char * character2 = get_dico('S');
    char * character3 = get_dico('E');


    printf("Chaine du dico de T: %s\n\n", character);
    printf("Chaine du dico de A: %s\n\n", character1);
    printf("Chaine du dico de S: %s\n\n", character2);
    printf("Chaine du dico de E: %s\n\n", character3);

    return 0;
}
