#include <stdlib.h>

static char* strcheck(const char *string, char delimiter, int* array_dim);

int strdim(const char* string, char delimiter);

char** strsplit(char *string, char delimiter, int* length) {

    int words;

    char *string_to_split = strcheck(string, delimiter, &words);

    if (!string_to_split) return NULL;

    words = strdim(string_to_split, delimiter);

    char** result = malloc(words * sizeof(char*));

    int i = 0;
    int last_del = 0;
    int current_word = 0;

    while (string_to_split[i] != '\0') {
        if (string_to_split[i] == delimiter || string_to_split[i+1] == '\0') {
            int k;
            int size;
            if (last_del == 0) {
                k = 0;
                size = (string_to_split[i+1] == '\0' ) ? i+1 : i;
            }
            else {
                size = i - last_del-1;
                k = last_del + 1;
                current_word++;
            }

            if (string_to_split[i+1] == '\0' && last_del != 0) {
                size = i - last_del;
            }

            result[current_word] = malloc(size+1 * sizeof(char));
            int j = 0;
            for (; j < size; j++) {
                result[current_word][j] = string_to_split[k++];
            }
            result[current_word][j] = '\0';
            last_del = i;

        }
        i++;

    }

    *length = current_word + 1;

    return result;
}

int strdim(const char* string, char delimiter){
    int counter = 1;
    int i = 0;
    while (string[i] != '\0'){
        if (string[i] == delimiter)
            counter++;
        i++;
    }

    return counter;
}

/*
 * strcontrol "normalizza" la stringa in caso di casi particolari.
 * per prima cosa calcolo la lunghezza della stringa passata come parametro
 * calcolo la lunghezza escludendo i casi particolari
 * alloco la memoria per la nuova stringa
 * elimino tutti i possibili delimitatori inseriti all'inizio della stringa
 * successivamente controllo per casi di delimitatori ripetuti o inseriti alla fine della stringa
 * aggiungo il terminatore
 * restituisco la stringa
 */
char* strcheck(const char *string, const char delimiter, int* array_dim){
    int length = 0;
    *array_dim = 1;

    while (string[length] != '\0') {
        length++;
    }

    int new_length = length+1;

    for (int i = 0; i < length; ++i) {
        if (string[i] == delimiter)
            if (i == 0 || i == length - 1 || string[i + 1] == delimiter) new_length--;
    }

    char *copy = calloc(new_length, sizeof(char));

    int k = 0;

    while (string[k] == delimiter) k++;

    int j = 0;

    for (; k < length; ++k) {
        if (string[k] == delimiter && (k == length - 1 || string[k + 1] == delimiter))
            continue;

        copy[j] = string[k];
        j++;
    }

    copy[new_length-1] = '\0';

    return copy;
}