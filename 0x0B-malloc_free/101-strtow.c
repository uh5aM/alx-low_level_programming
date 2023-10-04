#include <stdlib.h>
#include "main.h"  // Assuming main.h contains necessary function prototypes and includes

int len(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int num_words(char *str) {
    int words = 0;
    int in_word = 0;

    for (int i = 0; i <= len(str); i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    return words;
}

char **strtow(char *str) {
    char **split;
    int i, j = 0, temp = 0, size = 0, words = num_words(str);

    if (words == 0)
        return (NULL);

    split = (char **)malloc(sizeof(char *) * (words + 1));

    if (split != NULL) {
        for (i = 0; i <= len(str) && words; i++) {
            if ((str[i] != ' ') && (str[i] != '\0')) {
                size++;
            } else if (((str[i] == ' ') || (str[i] == '\0')) && i && (str[i - 1] != ' ')) {
                split[j] = (char *)malloc(sizeof(char) * (size + 1));
                if (split[j] != NULL) {
                    for (int k = temp; k < i; k++) {
                        split[j][k - temp] = str[k];
                    }
                    split[j][size] = '\0';
                    size = 0;
                    temp = i;
                    j++;
                    words--;
                } else {
                    // Memory allocation failed
                    for (int k = 0; k < j; k++) {
                        free(split[k]);
                    }
                    free(split);
                    return NULL;
                }
            }
        }
        split[j] = NULL;
    }

    return split;
}
