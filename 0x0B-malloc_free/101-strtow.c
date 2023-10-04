#include "main.h"
#include <stdlib.h>
#include <string.h>

int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

char **strtow(char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    int word_count = 0;
    int in_word = 0;
    char **words = NULL;
    char *word_start = NULL;

    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (is_space(*ptr)) {
            if (in_word) {
                in_word = 0;
                word_count++;
            }
        } else {
            if (!in_word) {
                in_word = 1;
                word_start = ptr;
            }
        }
    }

    if (in_word) {
        word_count++;
    }

    words = (char **)malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL; // Memory allocation failed
    }

    in_word = 0;
    int word_index = 0;
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (is_space(*ptr)) {
            if (in_word) {
                int word_length = ptr - word_start;
                words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
                if (words[word_index] == NULL) {
                    // Memory allocation failed
                    for (int i = 0; i < word_index; i++) {
                        free(words[i]);
                    }
                    free(words);
                    return NULL;
                }
                strncpy(words[word_index], word_start, word_length);
                words[word_index][word_length] = '\0';
                word_index++;
                in_word = 0;
            }
        } else {
            if (!in_word) {
                in_word = 1;
                word_start = ptr;
            }
        }
    }

    if (in_word) {
        int word_length = ptr - word_start;
        words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
        if (words[word_index] == NULL) {
            // Memory allocation failed
            for (int i = 0; i <= word_index; i++) {
                free(words[i]);
            }
            free(words);
            return NULL;
        }
        strncpy(words[word_index], word_start, word_length);
        words[word_index][word_length] = '\0';
        word_index++;
    }

    words[word_index] = NULL;
    return words;
}

