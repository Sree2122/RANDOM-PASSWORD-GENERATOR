#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"
#include "utils.h"

char *generate_password(int length) {
    char *password = (char *)malloc(sizeof(char) * (length + 1)); // +1 for null terminator
    if (password == NULL) {
        return NULL; // Indicate failure
    }

    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-`~[]\{}|;':\",./<>?";
    int charset_len = sizeof(charset) - 1; // -1 to exclude the null terminator

    for (int i = 0; i < length; i++) {
        int index = random_int(0, charset_len -1); // Use the random function from utils
        password[i] = charset[index];
    }

    password[length] = '\0'; // Null-terminate the string
    return password;
}