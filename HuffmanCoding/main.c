//
//  main.c
//  HuffmanCoding
//
//  Created by PlugN on 02/11/2020.
//

#include "global.h"
#include "BinaryManager.h"
#include "FileManager.h"
#include "OccurencesManager.h"

int main(int argc, const char * argv[]) {

    printf("RAW Value of A : %d\n", 'A');

    printf("ASCII binary of A : %s\n", get_binary((int)'A'));

    printf("\n\n");

    char* bin;
    load_binary("Alice.txt", &bin);
    save_output("Output.txt", bin);

    printf("Alice.txt : %d caractères\nOutput.txt : %d caractères\n", calculate_size("Alice.txt"), calculate_size("Output.txt"));

    Occurences* occ = getOccurences(bin);

    while (occ->next != NULL) {
        printf("%c %d\n", occ->letter, occ->count);
        occ = occ->next;
    }

    printf("%s\n", bin);


    return 0;
}
