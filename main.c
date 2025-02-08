#include <stdio.h>
#include <stdlib.h>
#include "generator.h"
#include "utils.h"

int main() {
    int length;

    printf("Enter desired password length: ");
    if (scanf("%d", &length) != 1 || length <= 0) {
        fprintf(stderr, "Invalid password length.\n");
        return 1;
    }

    char *password = generate_password(length);

    if (password == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Generated password: %s\n", password);

    free(password); // Important to free allocated memory
    return 0;
}