#include "string_manipulation.h"

/**
 * Function: check_string
 *
 * Description:
 *      Checks if the provided string is valid and categorizes its content.
 *
 *      This function is responsible for validating a given string and categorizing
 *      its content. It iterates over the characters in the provided string and
 *      performs checks to determine whether the string is valid and to identify
 *      whether it contains numeric characters or non-numeric characters - [int] or [char*] -.
 *      The function returns a code based on the categorization of the string:
 *
 * Parameters:
 *      (string) -> The string to be checked for validity and categorization.
 *
 * Return:
 *      [int] 0 if the string is invalid (contains characters with ASCII value < 32),
 *      [int] 1 if the string is numeric,
 *      [int] (n > 1) the number of non-numeric characters in the string.
 */
int check_string(const char *string)
{
    // If the user provided a NULL string, return 0 for invalid string
    if (string == NULL) return 0;

    // Initialize counters
    int number = 0;         // Counter for numeric characters
    int character = 0;      // Counter for non-numeric characters

    // Iterate over the string
    for (int i = 0; string[i] != '\0'; i++)
    {
        // If the character is between '0' and '9', add 1 to the number variable only if the number variable is uninitialized
        if (string[i] >= '0' && string[i] <= '9') number += (number == 0);

        // If the above conditions are not true, add 1 to the character variable
        else character++;
    }

    /*
        Codes:
        ---> 0  -> Invalid string && Invalid character (ASCII < 32)
        ---> 1  -> Numeric
        ---> 2+ -> String (Number of non-numeric characters)
    */
    return character + number;
}

/**
 * Function: split
 *
 * Description:
 *      Splits a string into words based on a separator and returns a 2D array of words.
 *
 *      This function takes a string and a separator character and splits the string
 *      into individual words based on the separator. It counts the number of words
 *      and allocates memory for a 2D array of words. It then copies each word into
 *      the array and returns the array. The word count is also updated accordingly.
 *      It handles cases where invalid placements of separators are detected.
 *
 * Parameters:
 *      (separator)  -> The character that separates words in the string.
 *      (string)     -> The input string to be split into words.
 *      (word_count) -> A pointer to an integer to store the number of words found.
 *
 * Return:
 *      [char**] A 2D array of strings containing the individual words.
 *      [void*] NULL for errors
 */
char **split(char separator, const char *string, int *word_count)
{
    *word_count = 1;

    // Initialize variables
    int index = 0;          // Current word index in the 2D array
    int word_start = 0;     // Starting index of the current word found in the string
    int word_end = 0;       // Ending index of the current word found in the string
    int index_iterator = 0; // Iterator for copying characters to the word array

    // Count the number of words by counting the separators
    for (; string[word_end] != '\0'; word_end++)
    {
        if (string[word_end] == separator && word_start != word_end && string[word_end + 1] != ' ')
        {
            (*word_count)++;
            word_start = word_end + 1;
        }
    }

    word_start = 0;
    word_end = 0;

    // Calculate the size needed for the array of words
    size_t array_size = (*word_count) * sizeof(char*);

    // Allocate memory for the array of words and check for allocation errors
    char **words = calloc(array_size, sizeof(char*));
    if (words == NULL)
    {
        printf("Error allocating memory for the separated words array.\n");

        exit(1);
    }

    // Start analyzing the string
    for (; string[word_end] != '\0'; word_end++)
    {
        // Check for invalid placement of separators or if there's a space after a separator
        if (string[word_end] != separator || word_start == word_end || string[word_end + 1] == ' ')
        {
            continue;
        }

        // Calculate the size needed for the word
        size_t word_size = (word_end - word_start + 1) * sizeof(char);

        // Allocate memory for the word and check for errors
        words[index] = calloc(word_size, sizeof(char));
        if (words[index] == NULL)
        {
            printf("Error allocating memory for the separated words array.\n");

            // Free all the allocated memory
            for (int i = 0; i < (*word_count); i++)
            {
                free(words[i]);
            }

            // Free the 2D array pointer
            free(words);

            // Return no words because of an allocation error
            *word_count = 0;

            exit(1);
        }

        // Reset the index iterator
        index_iterator = 0;

        // Copy the string to the array
        for (; word_start < word_end; word_start++)
        {
            // Copy letter by letter, excluding spaces
            words[index][index_iterator] = string[word_start];
            index_iterator++;
        }

        // Move to the next word
        index++;

        // Move to the next word in the string (word_end + 1 to skip the separator)
        word_start = word_end + 1;
    }

    // Calculate the size needed for the last word
    size_t word_size = (word_end - word_start + 1) * sizeof(char);

    // Allocate memory for the last word and check for errors
    words[index] = calloc(word_size, sizeof(char));
    if (words[index] == NULL)
    {
        printf("Error allocating memory for the separated words array.\n");

        // Free all the allocated memory
        for (int i = 0; i < *word_count; i++)
        {
            free(words[i]);
        }

        // Free the 2D array pointer
        free(words);

        // Return no words because of an allocation error
        *word_count = 0;

        exit(1);
    }

    // Reset the index iterator
    index_iterator = 0;

    // Copy the last word to the array
    for (; word_start <= word_end; word_start++)
    {
        // Copy letter by letter, excluding spaces
        words[index][index_iterator] = string[word_start];
        index_iterator++;
    }

    return words;
}

/**
 * Function: insert_string
 *
 * Description:
 *      Inserts a string into another at the specified index.
 *
 *      This function takes a target string, an insertion string, and an index.
 *      It first checks if both the target and insertion strings are valid.
 *      If either of them is invalid, it prints an error message and returns.
 *      The index is then validated to ensure it's within the bounds of the target string.
 *      Finally, the function inserts the insertion string into the target string at the specified index.
 *
 * Parameters:
 *      (target_string)    -> The string where the insertion will take place.
 *      (insertion_string) -> The string to be inserted into the target string.
 *      (index)            -> The index in the target string where the insertion will occur.
 *
 * Return:
 *      [int] 0 on successful insertion,
 *      [int] (rc) on failure.
 */
int insert_string(char *target_string, const char *insertion_string, int index)
{
    // Validate the target and insertion strings
    int rc = check_string(target_string) + check_string(insertion_string);
    if (rc == 0)
    {
        printf("Invalid string.");
        return rc;
    }

    // Validate and adjust the index based on the target string's length
    index *= ((int)strlen(target_string) >= index); // If true will evaluate to 1, else 0

    // Insert the insertion string into the target string at the specified index
    for (int i = 0; target_string[index] != '\0' && insertion_string[i] != '\0'; i++, index++)
    {
        target_string[index] = insertion_string[i];
    }

    return 0;
}

/** **CORE FUNCTION**
 *
 * Function: generate_password
 *
 * Description:
 *      Generates a customized password based on the provided user flags, optional word list and include string.
 *
 * Functionality:
 *      - Initializes variables and structures for password generation.
 *      - Validates character set conditions and inclusion flags.
 *      - Handles scenarios for including custom strings in the password:
 *          - Recursive custom string extraction or random selection from word list.
 *          - Handling special character insertions.
 *          - Dynamically adjusts password length.
 *      - Generates pronounceable passwords if requested, alternating between consonants and vowels.
 *      - Generates passwords based on selected character sets.
 *      - Handles password generation with underscores.
 *      - Inserts custom strings into the generated password as specified by inclusion flags.
 *      - Returns the generated password as a dynamically allocated string on success, or NULL on failure.
 *
 * Parameters:
 *      (flags)       -> A pointer to the FLAGS struct containing user preferences and settings.
 *      (words)       -> An array of words that can be used for insertion in the password.
 *      (word_count)  -> The number of words in the words array.
 *
 * Return:
 *      [char*] A dynamically allocated string containing the generated password on success,
 *             or NULL on failure during the password generation process.
 */
char *generate_password(FLAGS *flags, char **words, int word_count)
{
    /* Variable declarations */

    // Main password string
    char *password = NULL;

    // Character selection variables
    int index = 0;
    int letter = 0;

    // Include string variables
    int insertion_index = 0;
    char *word = NULL;

    // Charsets
    FLAG charset[4] = {
        flags->upper,
        flags->lower,
        flags->number,
        flags->special
    };

    // The user wants to generate an include string
    if (flags->include.state == 3)
    {
        word = recurse(flags->include.text);
        if (word == NULL)
        {
            printf("Invalid include string.\n");

            exit(1);
        }

        flags->include.value = strlen(word);

        // If the insertion word is bigger than the password itself, add the length of the word to the password length
        flags->length.value += (flags->include.value * (flags->include.value >= flags->length.value));

        // Assign the insertion index and make sure to avoid cutting the string at the end of the password
        insertion_index = get_random(flags->length.value - flags->include.value);

        // Allocate memory for the strng based on the flags->length.value and check for errors
        size_t password_size = (flags->length.value + 1) * sizeof(char);
        password = calloc(password_size, sizeof(char));
        if (password == NULL)
        {
            printf("Error allocating memory for the generated word.\n");

            exit(1);
        }
    }

    // The user have provided the string / the array of strings for inclusion
    else if (flags->include.state != 0)
    {
        // Choose a string from the array and assign it's length to the value member of the include member of the flags struct
        int chosen_word = get_random(word_count);
        word = words[chosen_word];

        flags->include.value = strlen(word);

        // If the insertion word is bigger than the password itself, add the length of the word to the password length
        flags->length.value += (flags->include.value * (flags->length.value <= flags->include.value));

        // Assign the insertion index and make sure to avoid cutting the string at the end of the password
        insertion_index = get_random(flags->length.value - flags->include.value);

        for (int i = 0; flags->include.state == 2 && word[i] != '\0'; i++)
        {
            if (word[i] != '*') continue;

            // Choose a random index from the charset and check if it is allowed
            index = get_random(4);
            if (((charset[index].state == -1) || (charset[index].text[0] == '\0')) && flags->charset.state != -1)
            {
                // Decrement i and restart the loop
                i--;
                continue;
            }

            // letter = charset_array.text_inside[random number from 0 to the value inside the flag]
            letter = charset[index].text[get_random(charset[index].value)];

            // Assign the letter to the password
            word[i] = letter;
        }

        // Allocate memory for the password and check for errors
        password = calloc((flags->length.value + 1) * sizeof(char), sizeof(char));
        if (password == NULL)
        {
            printf("Error allocating memory for the generated word.\n");

            exit(1);
        }
    }

    // The user does not want to include a string
    else
    {
        // Allocate memory for the password and check for errors
        password = calloc((flags->length.value + 1) * sizeof(char), sizeof(char));
        if (password == NULL)
        {
            printf("Error allocating memory for the generated word.\n");

            exit(1);
        }
    }

    // Check if the user wants a pronounceable password
    if (flags->pronounce.state)
    {
        char pronounce_charset[4][21] = {
            "BCDFGHJKLMNPQRSTVWXYZ",
            "bcdfghjklmnpqrstvwxyz",
            "AEIOU",
            "aeiou"
        };

        // Get the last index to make sure the oscillation between consonant and vowel is constant
        int last_index = 0;

        for (int i = 0; i < flags->length.value; i++)
        {
            // First index to be uppercase if the user wants and uppercase pronounceable password, else lowercase index
            index = (flags->lower.state != -1);

            // If consonant go to the vowels and if vowel go to consonants
            index += (index == last_index) * 2;

            // Update the last index to the current index
            last_index = index;

            // Choose a random letter based on the current index in the charset array
            letter = (get_random(21) * (index < 2)) + (get_random(5) * (index >= 2));

            // Assign the letter to the password
            password[i] = pronounce_charset[index][letter];
        }
    }

    else
    {
        for (int i = 0; i < flags->length.value; i++)
        {
            // Choose a random index from the charset and check if it is allowed
            index = get_random(4);
            if ((charset[index].state == -1) || (charset[index].text[0] == '\0'))
            {
                // Decrement i and restart the loop
                i--;
                continue;
            }

            // letter = charset_array.text_inside[random number from 0 to the value inside the flag]
            letter = charset[index].text[get_random(charset[index].value)];

            // Assign the letter to the password
            password[i] = letter;
        }
    }

    // Check if the include flag is still active and insert the string to the password
    if (flags->include.state > 0)
    {
        rc = insert_string(password, word, insertion_index);
        if (rc != 0)
        {
            printf("Failed to insert string %s to the generated word.\n", flags->include.text);

            exit(1);
        }

        if (flags->include.state == 3)
        {
            free(word);
        }
    }

    return password;
}

/**
 * Function: cure_string
 *
 * Description:
 *      Replaces non-printable characters in the given string with spaces to cure it.
 *      This function sanitizes a string by replacing any non-printable characters (ASCII < 32)
 *      with spaces, thus making the string printable and safe for display.
 *
 *      The function Validates if the provided string is NULL or empty, indicating an invalid string.
 *      If invalid, an error message is printed, and the function returns 1. It then counts the number
 *      of printable characters in the string by iterating through it replacing non-printable characters
 *      with spaces.
 *
 * Parameters:
 *      (string) -> A pointer to the string that needs to be cured.
 *
 * Return:
 *      [int] 0 on successful curing of the string, indicating success.
 *      [int] 1 if the provided string is NULL or empty, indicating an invalid string.
 */
int cure_string(char *string, int include_LF)
{
    // Check if the string is NULL or empty
    if (string == NULL || string[0] == '\0')
    {
        printf("Invalid string.\n");

        exit(1);
    }

    // Iterate through the string to replace non-printable characters with spaces
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] < 32 && (include_LF == 1 || string[i] != '\n'))
        {
            string[i] = ' ';
        }
    }

    return 0;
}

/**
 * Function: hash
 *
 * Description:
 *      Calculates a hash value for the given input string using a simple hashing algorithm.
 *      This function iterates through each character in the input string and updates the hash
 *      value using bitwise left shift and XOR operations. The resulting hash is then restricted
 *      to the range between 0 and 999,999 using modulo.
 *
 * Parameters:
 *      (string) -> A pointer to the input string for which the hash needs to be calculated.
 *
 * Return:
 *      [int] The calculated hash value for the input string, restricted to the range 0-999,999.
 */
int hash(const char *string)
{
    unsigned int hash = 0;  // Initialize the hash value

    // Iterate through each character in the string
    for (int i = 0; string[i] != '\0'; i++)
    {
        // Update the hash using bitwise left shift and XOR operations
        hash = (hash << 4) ^ (string[i]);
    }

    return hash; // Modulo to restrict to the range 0-999,999
}