#ifndef BACKEND_H
#define BACKEND_H

// Include the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

// Structs
typedef struct {
    int state;          // Flag state (-1 for unset, 0 for false, 1 for true)

    long value;         // Value associated with the flag

    int index;          // Index of the flag in the route

    int allocated;      // Number of allocated memory blocks

    char *text;         // Text associated with the flag (e.g., flag value)
} FLAG;

typedef struct {
    // The primary flag for managing parsing
    FLAG head;          // Flag representing the primary control for parsing and managing other flags.

    // Flags for displaying help and version information
    FLAG help;          // Flag to request and display program usage and help information.
    FLAG version;       // Flag to request and display program version details.

    // Flag for specifying raw output
    FLAG raw;           // Flag to enable raw output, suppressing additional messages and formatting.

    // Flags for controlling password length and generation
    FLAG length;        // Flag to specify the desired length of generated passwords.
    FLAG count;         // Flag to indicate the number of passwords to be generated.
    FLAG choose;        // Flag to enable selection of passwords from a predefined set.

    // Flag for generating monoset passwords
    FLAG monoset;       // Flag to generate passwords with characters from a single character set.

    // Flags for including specific character sets in passwords
    FLAG upper;         // Flag to include uppercase letters in generated passwords.
    FLAG lower;         // Flag to include lowercase letters in generated passwords.
    FLAG number;        // Flag to include numeric digits in generated passwords.
    FLAG special;       // Flag to include special symbols in generated passwords.

    // Flag for generating pronounceable passwords
    FLAG pronounce;     // Flag to generate passwords that are phonetically pronounceable and readable.

    // Flag for generating PINs
    FLAG pin;           // Flag to generate personal identification numbers (PINs) for secure access.

    // Flags for including strings in passwords
    FLAG include;       // Flag to insert specific strings at random positions in generated passwords.
    FLAG include_by;    // Flag to insert strings at user-defined positions in generated passwords.

    // Flag for customizing character set for password generation
    FLAG charset;       // Flag to specify a custom character set for password generation.

    FLAG prompt;
} FLAGS;

typedef struct {
    char *option;        // Command line option

    FLAG *flag;          // Pointer to the associated flag

    int active;          // Flag activation state (0 for inactive, 1 for active, -1 for deactivation)

    int takes_args;

    void (*retrieval_function)(FLAGS *flags);
} ROUTE;

// Total count of the available flags and the number of routes for the flags
#define FLAGS_COUNT (int)(sizeof(FLAGS) / sizeof(FLAG) - 1)

// Default values
#define COUNT_DEFAULT 1
#define PIN_DEFAULT 4
#define LENGTH_DEFAULT 12
#define SEED_MAX 1000000

// Return code
static int rc = 0;

void help();

void version();

void _init_(FLAGS *flags);

int get_random(int limit);

void get_length(FLAGS *flags);

void get_count(FLAGS *flags);

void get_seed(FLAGS *flags);

void get_set(FLAGS *flags);

void parse_include(FLAGS *flags);

void parse_charset(FLAGS *flags);

int parse_args(const int argc, char **argv, FLAGS *flags, ROUTE *route);

char *get_password(FLAGS *flags);

void free_allocated(FLAGS *flags);

char *recurse(const char *arguments);

#endif