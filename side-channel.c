#include <stdio.h>
#include <string.h>
#include <time.h>

#define KEY_LEN 16
#define DELAY_FACTOR 500000

int secret_key[KEY_LEN + 1] = ...; //the key is removed.


void artificial_delay(int count) {
    for(int i = 0; i < count * DELAY_FACTOR; i++) {
        // Just a dummy computation
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2 || strlen(argv[1]) != KEY_LEN) {
        printf("Usage: %s <16-character string>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int matching_chars = 0;
    for(int i = 0; i < KEY_LEN; i++) {
        if(input[i] - 1 == secret_key[i]) {
            matching_chars++;
            artificial_delay(1); // Introduce delay for each matched character
        } 
        else {
            break;
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if(matching_chars == KEY_LEN) {
        printf("Input matches the key!\n");
    } else {
        printf("Input does not match the key.\n");
    }

    printf("Total computation time: %f seconds\n", cpu_time_used);
    return 0;
}