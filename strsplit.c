#include <stdlib.h>

char** strsplit(char *string, const char delimiter, int* length) {
    char** result;

    int i = 0;
    int last_del = 0; //ultimo delimitatore
    int numwords = 0; //numero parole

    while (string[i] != '\0') {
        if (string[i] == ' ' || string[i+1] == '\0') {
            int k;
            int size;
            if (last_del == 0) {
                result = malloc(1*sizeof(char*));
                k = 0;
                size = i;
            }
            else {
                size = i - last_del-1;
                k = last_del + 1;
                numwords++;
                result = realloc(result, (numwords + 1) * sizeof(char *));
            }

            if (string[i+1] == '\0') {
                size = i - last_del;
            }

            result[numwords] = malloc(size+1 * sizeof(char));
            int j = 0;
            for (; j < size; j++) {
                result[numwords][j] = string[k++];
            }
            result[numwords][j] = '\0';
            last_del = i;

        }
        i++;
    }

    return result;
}