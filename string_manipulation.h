#ifndef STRING_MANIPULATION_H
#define STRING_MANIPULATION_H

// Include the necessary backend header for access to FLAGS struct
#include "backend.h"

int check_string(const char *string);

int cure_string(char *string, int include_LF);

int hash(const char *string);

int insert_string(char *target_string, const char *insertion_string, int index);

char **split(char separator, const char *string, int *word_count);

char *generate_password(FLAGS *flags, char **words, int word_count);

#endif