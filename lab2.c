#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab2.h"

void deleteline(FILE *input, FILE *output, const char *deletetext) {
    char line[1024];
    while (fgets(line, sizeof(line), input)) {
        if (strstr(line, deletetext) == NULL) {
            fputs(line, output);
        }
    }
}

void inserttext(FILE *input, FILE *output, const char *newinserttext, int at_start) {
    char line[1024];
    while (fgets(line, sizeof(line), input)) {
        if (at_start) {
            fprintf(output, "%s%s", newinserttext, line);
        } else {
            fprintf(output, "%s%s", line, newinserttext);
        }
    }
}

