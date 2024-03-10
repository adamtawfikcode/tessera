#include "backend.h"
#include "string_manipulation.h"

void help()
{
    printf(
        ".--------------------------------------------------------------------------------------------------------.\n"
        "                                                 TESSERA (1)                                            \n"
        "                                     -   -  - - User Commands - -  -                                    \n"
        "--------------------------------------------------------------------------------------------------------\n"
        " NAME                                                                                                   \n"
        "     Tessera                                                                                            \n"
        "--------------------------------------------------------------------------------------------------------\n"
        " SYNOPSIS                                                                                               \n"
        "     tessera [OPTIONS]                                                                                  \n"
        "--------------------------------------------------------------------------------------------------------\n"
        " OPTIONS                                                                                                \n"
        "     --help / -h / ?                                                                                    \n"
        "            Display this help message and exit.                                                         \n"
        "                                                                                                        \n"
        "     --version / -v                                                                                     \n"
        "            Display version information and exit.                                                       \n"
        "                                                                                                        \n"
        "     --prompt | --                                                                                      \n"
        "           Type every argument for any flag that takes arguments manually.                              \n"
        "           [e.g. --charset, --include, ...], highly adviced when working with                           \n"
        "           more than one genclude.                                                                      \n"
        "                                                                                                        \n"
        "           Must be the first flag.                                                                      \n"
        "                                                                                                        \n"
        "     --raw                                                                                              \n"
        "            Print the raw string without any descriptive message.                                       \n"
        "                                                                                                        \n"
        "     --seed <seed> | -s <seed>                                                                          \n"
        "           Use a custom seed to generate a string from.                                                 \n"
        "           The same seed generates the same string over and over again.                                 \n"
        "                                                                                                        \n"
        "     --length <length> / -len <length>                                                                  \n"
        "            Specify the length of the generated string.                                                 \n"
        "            Must be a positive integer > 0.                                                             \n"
        "                                                                                                        \n"
        "     --count <count> / -c <count>                                                                       \n"
        "            Specify the number of passwords to generate.                                                \n"
        "            Must be a positive integer > 0.                                                             \n"
        "                                                                                                        \n"
        "     --upper / -u                                                                                       \n"
        "            All uppercase letters.                                                                      \n"
        "                                                                                                        \n"
        "     --no-upper / -nu                                                                                   \n"
        "            Exclude uppercase letters.                                                                  \n"
        "                                                                                                        \n"
        "     --lower / -l                                                                                       \n"
        "            All lowercase letters.                                                                      \n"
        "                                                                                                        \n"
        "     --no-lower / -nl                                                                                   \n"
        "            Exclude lowercase letters.                                                                  \n"
        "                                                                                                        \n"
        "     --number / -n                                                                                      \n"
        "            All numbers.                                                                                \n"
        "                                                                                                        \n"
        "     --no-number / -nn                                                                                  \n"
        "            Exclude numbers.                                                                            \n"
        "                                                                                                        \n"
        "     --symbols / -s                                                                                     \n"
        "            All symbols.                                                                                \n"
        "                                                                                                        \n"
        "     --no-symbols / -ns                                                                                 \n"
        "            Exclude symbols.                                                                            \n"
        "                                                                                                        \n"
        "     --monoset / -mono                                                                                  \n"
        "            Generate a string from a random default charset.                                            \n"
        "            [Uppercase, Lowercase, Numbers or Symbols].                                                 \n"
        "                                                                                                        \n"
        "     --charset <charset> / -set                                                                         \n"
        "            Specify a custom character set.                                                             \n"
        "                                                                                                        \n"
        "     --pin / -p                                                                                         \n"
        "            Generate a 4-digit pin code.                                                                \n"
        "                                                                                                        \n"
        "     --pronounce / -word                                                                                \n"
        "            Generate \"pronounceable\" strings (or just words).                                         \n"
        "                                                                                                        \n"
        "     --include <string> / --include <string1;string2;string3;...>                                       \n"
        "     | -inc <string> / -inc <string1;string2;string3;...>                                               \n"
        "            Specify one or more strings to include in the generated string.                             \n"
        "            The <words> argument should be a string of characters without any                           \n"
        "            spaces in the case of a single word.                                                        \n"
        "                                                                                                        \n"
        "            In the case of multiple words, each word should be separated by a                           \n"
        "            semicolon except for the last word and the entire string must be                            \n"
        "            wrapped by double quotes due to the behavior of shells like bash.                           \n"
        "                                                                                                        \n"
        "            [e.g., --include \"string1;string2;string3\"]                                               \n"
        "            One word will be chosen randomly to be included in the generated string.                    \n"
        "                                                                                                        \n"
        "     --finclude <string> / --finclude <string1;string2;string3;...>                                     \n"
        "     | -finc <string> / -finc <string1;string2;string3;...>                                             \n"
        "           Same as [--include] but will replace every asterisk (*) in the include string/s              \n"
        "           with random characters from your own charset if provided, else the default charset/s.        \n"
        "                                                                                                        \n"
        "           [e.g., --finclude \"s*ring1;st**ng2;str***\"]                                                \n"
        "           The chosen word will have each asterisk replaced by a random character.                      \n"
        "                                                                                                        \n"
        "     --genclude <arguments> | -genc <arguments>                                                         \n"
        "           Same as [--include] but instead of explicitly specifying a string you can generate           \n"
        "           one using the same flags you use for Tessera itself.                                         \n"
        "--------------------------------------------------------------------------------------------------------\n"
        "  EXAMPLES                                                                                              \n"
        "                                                                                                        \n"
        "     Generate a single password with a length of 12 characters:                                         \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --length 12                                                                         \n"
        " |                                                                                                      \n"
        " '------> JnWsL6M6Nq9`                                                                                  \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate 5 passwords with a length of 8 characters, excluding special                              \n"
        "     characters:                                                                                        \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --length 8 --count 5 --no-special                                                   \n"
        " |                                                                                                      \n"
        " '------> JnWsL6M6Nq9`                                                                                  \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate a single password using the seed \"Tessera\":                                             \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --seed \"Tessera\"                                                                  \n"
        " |                                                                                                      \n"
        " '------> uYG6{tRx4u4&                                                                                  \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate 20 passwords with a length of 16 characters, excluding uppercase                          \n"
        "     letters and choose one of them to be displayed:                                                    \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --length 8 --count 5 --no-number --choose                                           \n"
        " |                                                                                                      \n"
        " '------> [1]: Co.FNk0S                                                                                 \n"
        "          [2]: %%^vUlr5%%                                                                               \n"
        "          [3]: 9JUI=ZJ/                                                                                 \n"
        "          [4]: 67?59I60                                                                                 \n"
        "          [5]: ql~y.V'7                                                                                 \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate a PIN code:                                                                               \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --pin                                                                               \n"
        " |                                                                                                      \n"
        " '------> 2285                                                                                          \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate a PIN code with the length of 12 numbers:                                                 \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --pin --length 12                                                                   \n"
        " |                                                                                                      \n"
        " '------> 691131983989                                                                                  \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate 3 passwords with a length of 16 characters, including uppercase and                       \n"
        "     lowercase letters:                                                                                 \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --length 16 --count 3 --upper --lower                                               \n"
        " |                                                                                                      \n"
        " '------> [1]: IVQlRGeKfgdulxsR                                                                         \n"
        "          [2]: bMcZbESEhcxqBGpM                                                                         \n"
        "          [3]: mekQLMdXGYicseZU                                                                         \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate two 16 letter pronounceable password (or just a word):                                    \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --pronounce --count 2 --length 16                                                   \n"
        " |                                                                                                      \n"
        " '------> [1]: qukolekukixukaqu                                                                         \n"
        "          [2]: zufaxaruyunebeji                                                                         \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate 10 passwords with a length of 10 characters, including uppercase                          \n"
        "     letters and special characters and choose one of them to be displayed:                             \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --length 10 --count 10 --upper --special --choose                                   \n"
        " |                                                                                                      \n"
        " '------> [1]: %%W~P!>ZI'T                                                                              \n"
        "          [2]: G!HXL@%%X:T                                                                              \n"
        "          [3]: ?_/Z%%JY))$                                                                              \n"
        "          [4]: UANOA\\A=?!                                                                              \n"
        "          [5]: T&'G='@HI>                                                                               \n"
        "          [6]: J~I[_KZ=A.                                                                               \n"
        "          [7]: =KW%%]ACQG%%                                                                             \n"
        "          [8]: M<;S%%,JQ-Q                                                                              \n"
        "          [9]: GF\"$]+Q\"=K                                                                             \n"
        "          [10]: ?_F^NG?KE&                                                                              \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate a single password with a custom character set.                                            \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --length 12 --charset \"aleph10\"                                                   \n"
        " |                                                                                                      \n"
        " '------> l10h11lael0a                                                                                  \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate a single password that includes the word \"Secret\" as part of it:                        \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --include \"Secret\"                                                                \n"
        " |                                                                                                      \n"
        " '------> o5Secret47i\"                                                                                 \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate a single password around the word \"Pass*ord\" and the asterisk (*)                       \n"
        "     is replaced by a random character:                                                                 \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --finclude \"Pass*ord\"                                                             \n"
        " |                                                                                                      \n"
        " '------> :5Passtord'7                                                                                  \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate 5 passwords with a length of 12 characters, including only numbers                        \n"
        "     and special characters, and replace the asterisk (*) with a random character                       \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --length 12 --count 5 --number --special --finclude \"*0123;45*7;89*^&*()_+-=\"     \n"
        " |                                                                                                      \n"
        " '------> [1]: 759-57?336989:^&)()_+-=6                                                                 \n"
        "          [2]: 4/%%&2?^{%%-\\45&7*=:6\\1}2                                                              \n"
        "          [3]: 01550\\%%7)89:^&)()_+-=$/^                                                               \n"
        "          [4]: <73\"20123\"9\"9&~=?%%?(22}$                                                             \n"
        "          [5]: _1|8]289:^&)()_+-=8]7\\::                                                                \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Genarate 5 passwords with a length of 16 consisting of only numbers, and then generate a           \n"
        "     string with a default length of 12 that is only special characters and insert it into the          \n"
        "     generated password.                                                                                \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --length 16 --count 5 --number --genclude \"--special\"                             \n"
        " |                                                                                                      \n"
        " '------> [1]: 289`(]=%%?#&~<`\\4                                                                       \n"
        "          [2]: 4;|<*(]<~*><<061                                                                         \n"
        "          [3]: '[)<.$:@(_)_6155                                                                         \n"
        "          [4]: 33->$('~<~';+;55                                                                         \n"
        "          [5]: 548-$>}_^>?*%%-!4                                                                        \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "     Generate a password but generate the include string and use a custom charset and prompt for        \n"
        "     each one of these option to be entered separately.                                                 \n"
        "                                                                                                        \n"
        "========================================================================================================\n"
        " '------> $ tessera --prompt --genclude \"\" --charset \"\"                                             \n"
        " |-> Include string: --upper                                                                            \n"
        " |-> Charset: ABCabc123                                                                                 \n"
        " |                                                                                                      \n"
        " '------> CAc2TBLTAHFPAYIL2A1b2Caa                                                                      \n"
        "========================================================================================================\n"
        "                                                                                                        \n"
        "  =--.                                                                                                  \n"
        "  |  | -> As you can see, the only limit is you imagination, and the options..                          \n"
        "  '--=                                                                                                  \n"
        "                                                                                                        \n"
        "--------------------------------------------------------------------------------------------------------\n"
        " AUTHOR                                                                                                 \n"
        "     Abdelrahman Tawfik                                                                                 \n"
        "--------------------------------------------------------------------------------------------------------\n"
        " REPORTING BUGS                                                                                         \n"
        "     Report bugs at: https://github.com/theadamtawfik                                                   \n"
        "--------------------------------------------------------------------------------------------------------\n"
        " COPYRIGHT                                                                                              \n"
        "     Copyright © 2023 Adam Tawfik. This is free software; see the                                       \n"
        "     source code for copying conditions.                                                                \n"
        "--------------------------------------------------------------------------------------------------------\n"
        " SEE ALSO                                                                                               \n"
        "     For more information and updates, visit the project's GitHub repository:                           \n"
        "     <https://github.com/theadamtawfik>                                                                 \n"
        "'-------------------------------------------------------------------------------------------------------'\n"
    );

    exit(0);
}

void version()
{
    // Last version was unfortunately lost
    printf("Tessera version 0.0.2\n");
    exit(0);
}

/**
 * Function: _init_
 *
 * Description:
 *      Initializes a [FLAGS] struct and its members to default values.
 *
 *      This function initializes a [FLAGS] struct and all its [FLAG] members to
 *      their default values. It also sets up the random number generator seed
 *      using nanoseconds for improved randomness.
 *
 * Parameters:
 *      (*flag_ptr) - A pointer to a [FLAGS] struct to be initialized.
 *
 * Return:
 *      [int] 0 on successful initialization.
 *      [int] (other) on error.
 */

// Function to initialize a single flag with default values
void init_flag(FLAG *flag_ptr)
{
    flag_ptr->state = 0;
    flag_ptr->value = 0;
    flag_ptr->index = 0;
    flag_ptr->allocated = 0;
    flag_ptr->text = NULL;
}

// Core initialization function
void _init_(FLAGS *flags)
{
    struct timeval tv;
    long long time_in_nanoseconds;

    if (gettimeofday(&tv, NULL) == 0) 
    {
        // Convert seconds to nanoseconds
        time_in_nanoseconds = tv.tv_sec * 1000000000LL;
        // Add microseconds converted to nanoseconds
        time_in_nanoseconds += tv.tv_usec * 1000LL;

        // Seed the random number generator with nanoseconds for improved randomness
        srand(time_in_nanoseconds);
    } 
    
    else 
    {
        // Handle error
        perror("gettimeofday failed");
    }

    // Initialize the head of the struct with default values
    FLAG *flag_ptr = &flags->head;
    init_flag(flag_ptr++);

    // Iterate through the struct members and initialize them with default values
    for (int i = 0; i < FLAGS_COUNT; i++)
    {
        init_flag(flag_ptr++);
    }
}

/**
 * Function: parse_args
 *
 * Description:
 *      Parses the command line arguments and populates a [FLAGS] struct based on command line arguments.
 *
 *      This function is responsible for parsing the command line arguments provided
 *      by the user and populating the [FLAGS] struct according to the specified options.
 *      It processes each argument, checks for matches in the [ROUTE] array, and sets
 *      corresponding [FLAG] states. The function handles various options like monoset,
 *      derived flag states, seed, length, count, include, and charset. It also performs
 *      validation checks and returns appropriate error codes on failure.
 *
 * Parameters:
 *      (argc)  -> Number of command line arguments.
 *      (argv)  -> Array of command line argument strings.
 *      (flags) -> A pointer to a [FLAGS] struct to hold parsed options.
 *      (route) -> Array of [ROUTE] structs defining valid options, their properties and pointers to their
 *                 corresponding flags.
 *
 * Return:
 *      [int] 0 on successful parsing and initialization.
 *      [int] (other) on error.
 */

// Function helpers
int find_flag(char *arg, ROUTE *route)
{
    // Find and process the option in the route array
    for (int i = 0; route[i].flag != NULL; i++)
    {
        // If there's a match between the option and the argument
        if ((strlen(arg) == strlen(route[i].option)) && (strcmp(arg, route[i].option) == 0))
        {
            return i;
        }
    }

    return -1;
}

int parse_args(const int argc, char **argv, FLAGS *flags, ROUTE *route)
{
    // Iterate through each argument
    for (int i = 0; i < argc; i++)
    {
        int index = find_flag(argv[i], route);
        if (index >= 0)
        {
            route[index].flag->state = route[index].active;
            route[index].flag->index = i;

            if (argc > route[index].flag->index)
            {
                route[index].flag->text = argv[i + 1];
            }

            if (route[index].retrieval_function)
            {
                (*route[index].retrieval_function)(flags);
            }

            if (!flags->prompt.state)
            {
                i += route[index].takes_args;
            }
        }
    }

    // Calculate derived flag states based on user inputs
    flags->upper.state -= (flags->lower.state == 1) || (flags->number.state == 1) || (flags->special.state == 1) || (flags->pin.state == 1);
    flags->lower.state -= (flags->upper.state == 1) || (flags->number.state == 1) || (flags->special.state == 1) || (flags->pin.state == 1);
    flags->number.state -= (flags->upper.state == 1) || (flags->lower.state == 1) || (flags->special.state == 1);
    flags->special.state -= (flags->upper.state == 1) || (flags->lower.state == 1) || (flags->number.state == 1) || (flags->pin.state == 1);

    // Handle the charset option
    parse_charset(flags);

    if (flags->upper.state == -1 && flags->lower.state == -1 && flags->number.state == -1 && flags->special.state == -1)
    {
        printf("Unable to satisfy conditions.\n");

        free_allocated(flags);
        exit(1);
    }

    if (!flags->length.state)
    {
        // Use default length value if length option is not provided
        flags->length.value = ((flags->pin.state == 1) * PIN_DEFAULT) + ((flags->pin.state == 0) * LENGTH_DEFAULT);
    }

    if (!flags->count.state)
    {
        // Use default count value if count option is not provided
        flags->count.value = COUNT_DEFAULT;
    }

    // Check if pronounce option is valid
    if (flags->pronounce.state == 1 &&
       (flags->number.state == 1 || flags->special.state == 1 || flags->charset.state == 1))
    {
        printf("Pronounce option is only available in uppercase and lowercase.\n");

        free_allocated(flags);
        exit(1);
    }

    // Return 0 for no errors
    return 0;
}

/**
 * Function: get_random
 *
 * Description:
 *      Generates a random integer within the range (0, limit).
 *
 *      This function generates a random integer within the specified range (0, limit),
 *      where limit is an integer provided as a parameter. It avoids floating point
 *      exceptions by checking if the limit is zero, and returns 0 in such cases. For
 *      non-zero limits, it calculates a random number using the modulo operator and
 *      returns the result.
 *
 * Parameters:
 *      (limit) -> The upper limit (exclusive) of the random number range.
 *
 * Return:
 *      [int] A random integer within the range (0, limit).
 */
int get_random(int limit)
{
    // Avoid floating point exceptions
    if (limit == 0)
    {
        return 0;
    }

    // Return a random number from 0 to (limit - 1)
    return rand() % limit;
}

/**
 * Function: get_length
 *
 * Description:
 *      Retrieves and validates the password length from command line arguments.
 *
 *      This function retrieves the desired password length from the command line
 *      arguments based on the specified value in the command line arguments.
 *      It checks for both valid and invalid values for the password length.
 *      If the provided value is invalid - NULL - or non-numeric, the function
 *      defaults to LENGTH_DEFAULT or PIN_DEFAULT based on the flags-pin.state,
 *      displays an error message, and returns 0. If the provided value is greater
 *      than an upper limit, it displays an error message, defaults to LENGTH_DEFAULT
 *      or PIN_DEFAULT based on the flags-pin.state and returns 0. Otherwise, if the
 *      provided value is a valid numeric length, it assigns it to the flags->length.value
 *      member and returns 0.
 *
 * Parameters:
 *      (argc)  -> The number of command line arguments.
 *      (argv)  -> An array of command line argument strings.
 *      (flags) -> A pointer to a [FLAGS] struct that holds flag states and values.
 *
 * Return:
 *      [int] 0
 */
void get_length(FLAGS *flags)
{
    if (!flags->length.state)
    {
        flags->length.value = ((flags->pin.state == 1) * PIN_DEFAULT) + ((flags->pin.state == 0) * LENGTH_DEFAULT);

        return;
    }

    if (flags->prompt.state == 1)
    {
        size_t length_size = 0;
        int characters_read = 0;

        printf("Length: ");

        characters_read = getline(&flags->length.text, &length_size, stdin);
        if (characters_read == -1)
        {
            printf("Failed to retrieve the length.\n");

            free_allocated(flags);
            exit(1);
        }

        flags->length.allocated++;
        flags->length.text[characters_read - 1] = '\0';
    }


    // Check if the user provided an invalid non-numeric value as the password length
    if (check_string(flags->length.text) != 1)
    {
        printf("Invalid value for length.\n");

        free_allocated(flags);
        exit(1);
    }

    // If the user requested a very large password length...
    if (strlen(flags->length.text) > 30)
    {
        printf("Max value for length exceeded.\nMax value for length = 1 * 10^(30) - If you have enough memory - "
                "before possible memory failures.\n");

        free_allocated(flags);
        exit(1);
    }

    flags->length.value = atol(flags->length.text);
}

/**
 * Function: get_count
 *
 * Description:
 *      Retrieves and validates the password count from command line arguments.
 *
 *      This function retrieves the desired password count from the command line
 *      arguments based on the specified value. It checks for both valid and invalid
 *      values for the password count. If the provided value is invalid or contains
 *      non-numeric characters, the function defaults the count to COUNT_DEFAULT,
 *      displays an error message, and returns 0. If the provided value is greater than
 *      an upper limit, it displays an error message, sets the count to COUNT_DEFAULT,
 *      and returns 0. Otherwise, if the provided value is a valid numeric count, it
 *      assigns it to the flags->count.value member and returns 0.
 *
 * Parameters:
 *      (argc)  -> The number of command line arguments.
 *      (argv)  -> An array of command line argument strings.
 *      (flags) -> A pointer to a [FLAGS] struct that holds flag states and values.
 *
 * Return:
 *      [int] 0
 */
void get_count(FLAGS *flags)
{
    if (flags->prompt.state == 1)
    {
        size_t count_size = 0;
        int characters_read = 0;

        printf("Count: ");

        characters_read = getline(&flags->count.text, &count_size, stdin);
        if (characters_read == -1)
        {
            printf("Failed to retrieve the count.\n");

            free_allocated(flags);
            exit(1);
        }

        flags->count.allocated++;
        flags->count.text[characters_read - 1] = '\0';
    }

    // Check if the user provided an invalid non-numeric value as the password length
    if (check_string(flags->count.text) != 1)
    {
        printf("Invalid value for count.\n");

        free_allocated(flags);
        exit(1);
    }

    // If the user requested a very large password length...
    if (strlen(flags->count.text) > 30)
    {
        printf("Max value for count exceeded.\nMax value for count = 1 * 10^(30) - If you have enough memory - "
                "before possible memory failures.\n");

        free_allocated(flags);
        exit(1);
    }

    // User provided a valid value for count
    flags->count.value = atol(flags->count.text);
}

/**
 * Function: get_seed
 *
 * Description:
 *      Retrieves and validates the random number generator seed from command line arguments.
 *
 *      This function is responsible for retrieving and validating the random number
 *      generator seed from the command line arguments. If the user has provided a seed,
 *      it checks for both invalid and valid values for the seed. If the provided value
 *      is invalid or contains non-numeric characters, the function displays an error
 *      message and sets the seed state to 0 (indicating no custom seed). If the provided
 *      value is greater than an upper limit, it displays an error message and reverts to
 *      the default seed. Otherwise, if the provided value is a valid numeric seed, it
 *      sets the random number generator seed using srand() and the provided value.
 *
 * Parameters:
 *      (argc)  -> The number of command line arguments.
 *      (argv)  -> An array of command line argument strings.
 *      (flags) -> A pointer to a [FLAGS] struct that holds flag states and values.
 *
 * Return:
 *      [int] 0
 */
void get_seed(FLAGS *flags)
{
    if (flags->prompt.state == 1)
    {
        size_t seed_size = 0;
        int characters_read = 0;

        printf("Seed: ");

        characters_read = getline(&flags->head.text, &seed_size, stdin);
        if (characters_read == -1)
        {
            printf("Failed to retrieve the seed.\n");

            free_allocated(flags);
            exit(1);
        }

        flags->head.allocated++;
        flags->head.text[characters_read - 1] = '\0';
    }

    // Check if the user provided an invalid non-numeric value as the seed
    if (check_string(flags->head.text) == 0)
    {
        printf("Invalid seed.\n");

        free_allocated(flags);
        exit(1);
    }

    // If the user requested a very large seed...
    if (strlen(flags->head.text) > SEED_MAX)
    {
        printf("Max value for seed exceeded.\nMax value for seed = 1,000,000 characters.\n");

        free_allocated(flags);
        exit(1);
    }

    // User provided a valid value for the seed
    srand(hash(flags->head.text)); // Set the random number generator seed
}

void get_set(FLAGS *flags)
{
    int set_choice = 0;
    if (flags->charset.state > 0)
    {
        // Monoset and charset options are mutually exclusive
        printf(
            "You cannot use the monoset option alongside the charset option "
            "due to how unpredictable user-defined charsets can be.\n");

            free_allocated(flags);
            exit(1);
    }

    else if (flags->pronounce.state == 1)
    {
        // For monoset and pronounce, choose between uppercase and lowercase
        set_choice = get_random(2);

        flags->upper.state = (set_choice == 0);
        flags->lower.state = (set_choice == 1);
    }

    else
    {
        // For monoset without pronounce, choose among uppercase, lowercase, numbers, and special characters
        set_choice = get_random(4);

        flags->upper.state = (set_choice == 0);
        flags->lower.state = (set_choice == 1);
        flags->number.state = (set_choice == 2);
        flags->special.state = (set_choice == 3);
    }
}

/**
 * Function: parse_include
 *
 * Description:
 *      Parses and validates the include string provided by the user in command line arguments.
 *
 *      This function is responsible for parsing and validating the include string provided
 *      by the user in the command line arguments. It first checks if the user has provided
 *      a valid string, and if so, it proceeds to check the length of the string. If the
 *      provided string is longer than the maximum allowable length, an error message is
 *      displayed. If the user has specified options like "include-by" or specific formats,
 *      those options are validated. Finally, the include string is processed to cure any
 *      invalid characters and then stored in the [FLAGS] struct.
 *
 * Parameters:
 *      (argc)  -> The number of command line arguments.
 *      (argv)  -> An array of command line argument strings.
 *      (flags) -> A pointer to a [FLAGS] struct that holds flag states and values.
 *
 * Return:
 *      [int] 0 on successful parsing and validation of the include string.
 *      [int] 1 on error during parsing or validation.
 */

void parse_include(FLAGS *flags)
{
    if (flags->prompt.state == 1)
    {
        size_t include_size = 0;
        int characters_read = 0;

        printf("Include string: ");

        characters_read = getline(&flags->include.text, &include_size, stdin);
        if (characters_read == -1)
        {
            printf("Failed to retrieve the include string.\n");

            free_allocated(flags);
            exit(1);
        }

        flags->include.allocated++;
        flags->include.text[characters_read - 1] = '\0';
    }

    // Check if the user provided a valid string
    if (check_string(flags->include.text) == 0)
    {
        printf("Invalid include string.\n");

        free_allocated(flags);
        exit(1);
    }

    // Check if the user provided a very long include string
    else if (strlen(flags->include.text) > 1000000)
    {
        printf(
            "Max size for include string exceeded.\n"
            "Max size for include string = 1,000,000 letters.\n");

        free_allocated(flags);
        exit(1);
    }

    // Cure the include string and store it
    if (cure_string(flags->include.text, 1) != 0)
    {
        printf("Failed to cure the include string.\n");

        free_allocated(flags);
        exit(1);
    }

    if (flags->include_by.state == 1 && flags->prompt.state == 1)
    {
        flags->include_by.value = getchar();
    }

    else if (flags->include_by.state == 1 && flags->include_by.text != NULL)
    {
        flags->include_by.value = flags->include_by.text[0];
    }

    else
    {
        flags->include_by.value = ';';
    }
}

/**
 * Function: parse_charset
 *
 * Description:
 *      Parses and validates the charset provided by the user in command line arguments.
 *
 *      This function is responsible for parsing and validating the charset provided
 *      by the user in the command line arguments. It checks if the user has provided
 *      a valid charset string and validates its length. If the provided charset string
 *      is longer than the maximum allowable length, an error message is displayed.
 *      The function categorizes the characters in the charset and allocates memory
 *      for individual arrays for each character type (uppercase, lowercase, numbers,
 *      and special characters). If the user has not provided a custom charset, default
 *      values are used for each category.
 *
 * Parameters:
 *      (argc)  -> The number of command line arguments.
 *      (argv)  -> An array of command line argument strings.
 *      (flags) -> A pointer to a [FLAGS] struct that holds flag states and values.
 *
 * Return:
 *      [int] 0 on successful parsing and validation of the charset.
 *      [int] 1 on error during parsing or validation.
 */

// Function helpers
void set_default_charset(FLAGS *flags)
{
    // Set default values
    char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
    char *lower = "abcdefghijklmnopqrstuvwxyz\0";
    char *number = "0123456789\0";
    char *special = "!\"#$%%&'()*+,-./:;<=>?@[\\]^_`{|}~\0";

    // Get the length of each string
    flags->upper.value = strlen(upper);
    flags->lower.value = strlen(lower);
    flags->number.value = strlen(number);
    flags->special.value = strlen(special);

    /**
     * Allocate memory for the arrays based on the number of characters
     * and free previously allocated memory to avoid leaks on error.
    */

    size_t upper_size = flags->upper.value + 1;
    flags->upper.text = malloc(upper_size * sizeof(char));
    if (flags->upper.text == NULL)
    {
        printf("Failed to allocate memory for the uppercase charset.\n");

        free_allocated(flags);
        exit(1);
    }

    size_t lower_size = flags->lower.value + 1;
    flags->lower.text = malloc(lower_size * sizeof(char));
    if (flags->lower.text == NULL)
    {
        printf("Failed to allocate memory for the lowercase charset.\n");

        free(flags->upper.text);

        exit(1);
    }

    size_t number_size = flags->number.value + 1;
    flags->number.text = malloc(number_size * sizeof(char));
    if (flags->number.text == NULL)
    {
        printf("Failed to allocate memory for the numbers charset.\n");

        free(flags->upper.text);
        free(flags->lower.text);

        exit(1);
    }

    size_t special_size = flags->special.value + 1;
    flags->special.text = malloc(special_size * sizeof(char));
    if (flags->special.text == NULL)
    {
        printf("Failed to allocate memory for the special charset.\n");

        free(flags->upper.text);
        free(flags->lower.text);
        free(flags->number.text);
        free(flags->special.text);

        exit(1);
    }

    flags->upper.allocated++;
    flags->lower.allocated++;
    flags->number.allocated++;
    flags->special.allocated++;

    // Copy with strcpy to avoid pointer assignment
    strcpy(flags->upper.text, upper);
    strcpy(flags->lower.text, lower);
    strcpy(flags->number.text, number);
    strcpy(flags->special.text, special);
}

void parse_charset(FLAGS *flags)
{
    if (flags->charset.state == 0)
    {
        return set_default_charset(flags);
    }

    if (flags->prompt.state == 1)
    {
        size_t charset_size = 0;
        int characters_read = 0;

        printf("Charset: ");

        characters_read = getline(&flags->charset.text, &charset_size, stdin);
        if (characters_read == -1)
        {
            printf("Invalid charset.\n");

            free_allocated(flags);
            exit(1);
        }

        else
        {
            flags->charset.allocated++;
            flags->charset.text[characters_read - 1] = '\0';
        }
    }

    if (check_string(flags->charset.text) == 0)
    {
        printf("Invalid charset.\n");

        free_allocated(flags);
        exit(1);
    }

    if (strlen(flags->charset.text) > 1000000)
    {
        printf("Max size for charset exceeded. Max size for charset = 1,000,000 letters.\n");

        free_allocated(flags);
        exit(1);
    }

    // The user provided a valid charset for the password generation
    flags->charset.value = strlen(flags->charset.text);

    // Initialize the values inside the flags struct to zero (NULL)
    flags->upper.value = 0;
    flags->lower.value = 0;
    flags->number.value = 0;
    flags->special.value = 0;

    /**
     * Iterate over the charset and categorize the letters and increment the value inside each flag
     * in the flags struct to act as the indexing value
     */

    for (int i = 0; flags->charset.text[i] != '\0'; i++)
    {
        // Character is uppercase if it is bigger than ASCII 'A' and smaller than ASCII 'Z'
        if (flags->charset.text[i] >= 'A' && flags->charset.text[i] <= 'Z')
        {
            flags->upper.value++;
        }

        // Character is lowercase if it is bigger than ASCII 'a' and smaller than ASCII 'z'
        else if (flags->charset.text[i] >= 'a' && flags->charset.text[i] <= 'z')
        {
            flags->lower.value++;
        }

        // Character is a number if it is bigger than ASCII '0' and smaller than ASCII '9'
        else if (flags->charset.text[i] >= '0' && flags->charset.text[i] <= '9')
        {
            flags->number.value++;
        }

        // Character is special if all the above are untrue
        else
        {
            flags->special.value++;
        }
    }

    /**
     * Allocate memory for the arrays based on the number of characters
        * and free previously allocated memory to avoid leaks on error.
    */

    size_t upper_size = flags->upper.value + 1;
    flags->upper.text = malloc(upper_size * sizeof(char));
    if (flags->upper.text == NULL)
    {
        printf("Failed to allocate memory for the uppercase charset.\n");

        exit(1);
    }

    size_t lower_size = flags->lower.value + 1;
    flags->lower.text = malloc(lower_size * sizeof(char));
    if (flags->lower.text == NULL)
    {
        printf("Failed to allocate memory for the lowercase charset.\n");

        free(flags->upper.text);

        exit(1);
    }

    size_t number_size = flags->number.value + 1;
    flags->number.text = malloc(number_size * sizeof(char));
    if (flags->number.text == NULL)
    {
        printf("Failed to allocate memory for the numbers charset.\n");

        free(flags->upper.text);
        free(flags->lower.text);

        exit(1);
    }

    size_t special_size = flags->special.value + 1;
    flags->special.text = malloc(special_size * sizeof(char));
    if (flags->special.text == NULL)
    {
        printf("Failed to allocate memory for the special charset.\n");

        free(flags->upper.text);
        free(flags->lower.text);
        free(flags->number.text);
        free(flags->special.text);

        exit(1);
    }

    flags->upper.allocated++;
    flags->lower.allocated++;
    flags->number.allocated++;
    flags->special.allocated++;

    if (flags->upper.value == 0)
    {
        flags->upper.state = -1;
    }

    if (flags->lower.value == 0)
    {
        flags->lower.state = -1;
    }

    if (flags->number.value == 0)
    {
        flags->number.state = -1;
    }

    if (flags->special.value == 0)
    {
        flags->special.state = -1;
    }

    // Reset the counters
    flags->upper.value = 0;
    flags->lower.value = 0;
    flags->number.value = 0;
    flags->special.value = 0;

    // Iterate over the charset and populate the arrays
    for (int i = 0; flags->charset.text[i] != '\0'; i++)
    {
        // Character is uppercase if it is bigger than ASCII 'A' and smaller than ASCII 'Z'
        if (flags->charset.text[i] >= 'A' && flags->charset.text[i] <= 'Z')
        {
            flags->upper.text[flags->upper.value++] = flags->charset.text[i];
        }

        // Character is lowercase if it is bigger than ASCII 'a' and smaller than ASCII 'z'
        else if (flags->charset.text[i] >= 'a' && flags->charset.text[i] <= 'z')
        {
            flags->lower.text[flags->lower.value++] = flags->charset.text[i];
        }

        // Character is a number if it is bigger than ASCII '0' and smaller than ASCII '9'
        else if (flags->charset.text[i] >= '0' && flags->charset.text[i] <= '9')
        {
            flags->number.text[flags->number.value++] = flags->charset.text[i];
        }

        // Character is special if all the above are untrue
        else
        {
            flags->special.text[flags->special.value++] = flags->charset.text[i];
        }
    }
}

/**
 * Function: get_password
 *
 * Description:
 *      Generates a password based on the provided flags and includes, if any.
 *
 *      This function is responsible for generating passwords based on the provided
 *      [FLAGS] struct, taking into account any include options. It first checks if
 *      there are any include options specified, and if so, it obtains words based
 *      on the specified inclusion method. Then, based on the count of passwords
 *      specified in the flags, it generates either a single password or multiple
 *      passwords. If generating a single password, it calls the 'generate_password'
 *      function and handles any errors. If generating multiple passwords, it iterates
 *      over the count, generating each password and displaying them if the 'raw'
 *      flag is not set. If the 'choose' flag is set, it prompts the user to choose
 *      one of the generated passwords. After generating passwords and handling any
 *      errors, it frees the memory allocated for words and generated passwords.
 *
 * Parameters:
 *      (flags) -> A pointer to a [FLAGS] struct containing the password generation parameters.
 *
 * Return:
 *      [char *] A pointer to the generated password on success.
 *      [char *] (NULL) on error.
 */
char *get_password(FLAGS *flags)
{
    char **words = NULL;
    int word_count = 0;

    // Array to store passwords
    char *passwords[flags->count.value];

    int choice = 1;

    // Determine inclusion method and get words accordingly
    if (flags->include.state != 0 && flags->include.state != 3)
    {
        words = split(flags->include_by.value, flags->include.text, &word_count);
    }

    // Generate and process multiple passwords
    for (int i = 0; i < flags->count.value; i++)
    {
        // Generate the password and handle errors
        passwords[i] = generate_password(flags, words, word_count);
        if (passwords[i] == NULL)
        {
            printf("Error generating password.\n");
            for (int j = 0; j < i; j++)
            {
                free(passwords[j]);
            }

                // Free memory for words
            for (int i = 0; i < word_count; i++)
            {
                printf("%s\n", words[i]);
                free(words[i]);
            }

            free(words);

            return NULL;
        }

        // Display generated passwords
        if (flags->raw.state == 0 && flags->count.value > 1)
        {
            printf("[%d]: %s\n", i + 1, passwords[i]);
        }

        else if (flags->count.value > 1)
        {
            printf("%s\n", passwords[i]);
        }
    }

    // Choose a password if needed
    if (flags->choose.state == 1)
    {
        do
        {
            printf("Which password would you choose? [1 - %ld] ", flags->count.value);
            rc = scanf("%d", &choice);

            // Clean the input buffer
            scanf("%*[^\n]");
            scanf("%*c");

        } while (rc != 1 || choice < 1 || choice > flags->count.value);
    }

    choice--;

    // Free memory for generated passwords
    for (int i = 0; i < flags->count.value; i++)
    {
        if (i == choice)
        {
            continue;
        }

        free(passwords[i]);
    }

    // Free memory for words
    for (int i = 0; i < word_count; i++)
    {
        free(words[i]);
    }

    free(words);

    return passwords[choice];
}

void free_allocated(FLAGS *flags)
{
    FLAG *flag_ptr = &flags->head;

    // Deallocate resources and free memory in case of an error
    for (int i = 0; i < FLAGS_COUNT; i++)
    {
        if (flag_ptr->allocated > 0)
        {
            free(flag_ptr->text);
            flag_ptr->allocated--;
        }

        flag_ptr++;
    }
}

/**
 * Function: recurse
 *
 * Description:
 *      Recursively generates an include string based on the provided arguments.
 *
 *      This function is responsible for recursively generating an include string
 *      based on the provided arguments string. It initializes a local [FLAGS] struct
 *      and a [ROUTE] array to define the valid options. It then parses
 *      the provided arguments into a 2D array of strings using the 'split' function,
 *      and processes them to activate the appropriate flags in the [FLAGS] struct.
 *      After that, it calls the 'get_password' function to generate the include
 *      string based on the activated flags, particularly using the --genclude option.
 *      If successful, it returns the generated include string. If any errors occur
 *      during initialization, argument parsing, include string generation, or memory
 *      management, the function returns NULL after freeing any allocated resources.
 *
 * Parameters:
 *      (arguments) -> The arguments string containing options for generating an include string.
 *
 * Return:
 *      [char*] A pointer to the generated include string on success.
 *      [char*] (NULL) on error.
 */

char *recurse(const char *arguments)
{
    FLAGS r_flags;
    ROUTE r_route[] = {
        {.option = "--seed",         .flag = &r_flags.head,         .active =  1,   .takes_args = 1,   .retrieval_function = &get_seed     },
        {.option = ".",              .flag = &r_flags.head,         .active =  1,   .takes_args = 1,   .retrieval_function = &get_seed     },
        {.option = "--length",       .flag = &r_flags.length,       .active =  1,   .takes_args = 1,   .retrieval_function = &get_length   },
        {.option = "-len",           .flag = &r_flags.length,       .active =  1,   .takes_args = 1,   .retrieval_function = &get_length   },
        {.option = "--count",        .flag = &r_flags.count,        .active =  1,   .takes_args = 1,   .retrieval_function = &get_count    },
        {.option = "-c",             .flag = &r_flags.count,        .active =  1,   .takes_args = 1,   .retrieval_function = &get_count    },
        {.option = "--monoset",      .flag = &r_flags.monoset,      .active =  1,   .takes_args = 0,   .retrieval_function = &get_set      },
        {.option = "-mono",          .flag = &r_flags.monoset,      .active =  1,   .takes_args = 0,   .retrieval_function = &get_set      },
        {.option = "--upper",        .flag = &r_flags.upper,        .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-u",             .flag = &r_flags.upper,        .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--no-upper",     .flag = &r_flags.upper,        .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-nu",            .flag = &r_flags.upper,        .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--lower",        .flag = &r_flags.lower,        .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-l",             .flag = &r_flags.lower,        .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--no-lower",     .flag = &r_flags.lower,        .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-nl",            .flag = &r_flags.lower,        .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--number",       .flag = &r_flags.number,       .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-n",             .flag = &r_flags.number,       .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--no-number",    .flag = &r_flags.number,       .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-nn",            .flag = &r_flags.number,       .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--symbol",       .flag = &r_flags.special,      .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-s",             .flag = &r_flags.special,      .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--no-symbol",    .flag = &r_flags.special,      .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-ns",            .flag = &r_flags.special,      .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--pronounce",    .flag = &r_flags.pronounce,    .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-word",          .flag = &r_flags.pronounce,    .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--pin",          .flag = &r_flags.pin,          .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-p",             .flag = &r_flags.pin,          .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--include",      .flag = &r_flags.include,      .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-inc",           .flag = &r_flags.include,      .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-i",             .flag = &r_flags.include,      .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "--finclude",     .flag = &r_flags.include,      .active =  2,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-finc",          .flag = &r_flags.include,      .active =  2,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-f",             .flag = &r_flags.include,      .active =  2,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "--genclude",     .flag = &r_flags.include,      .active =  3,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-genc",          .flag = &r_flags.include,      .active =  3,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-g",             .flag = &r_flags.include,      .active =  3,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "--separator",    .flag = &r_flags.include_by,   .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-sep",           .flag = &r_flags.include_by,   .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "--charset",      .flag = &r_flags.charset,      .active =  1,   .takes_args = 1,   .retrieval_function = NULL          },
        {.option = "-set",           .flag = &r_flags.charset,      .active =  1,   .takes_args = 1,   .retrieval_function = NULL          },
        {.option = "--prompt",       .flag = &r_flags.prompt,       .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--",             .flag = &r_flags.prompt,       .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = NULL,             .flag = NULL,                .active =  0,   .takes_args = 0,   .retrieval_function = NULL          }
    };

    /**
     *  Initialize the FLAGS struct members (int state, int value, int index, int allocated, int deallocated, char *text)
     *  to zeros for int and NULL for pointers and check for errors
    */
    _init_(&r_flags);

    // Parse the arguments into a 2D array of string using split
    int r_argc = 0;
    char **r_argv = split(' ', arguments, &r_argc);
    if (r_argv == NULL)
    {
        printf("Failed to get the argv.\n");
        return NULL;
    }

    // Parse the command line arguments and activate flags based on route info
    rc = parse_args(r_argc, r_argv, &r_flags, r_route);
    if (rc != 0)
    {
        printf("Error parsing arguments.\n");

        free_allocated(&r_flags);
        return NULL;
    }

    // Generate the password based on user preferences
    char *r_password = get_password(&r_flags);
    if (r_password == NULL)
    {
        free_allocated(&r_flags);
        free(r_password);

        return NULL;
    }

    // Free allocated memory and exit
    free_allocated(&r_flags);

    return r_password;
}
