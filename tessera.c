#include "backend.h"
#include "string_manipulation.h"

int main(int argc, char **argv)
{
    // Declare a FLAGS struct to hold user preferences and settings
    FLAGS flags;

    // Define an array of route information for command line options
    ROUTE route[] = {
        // Define each option along with its corresponding FLAG struct, activation status, and argument info
        {.option = "--seed",         .flag = &flags.head,         .active =  1,   .takes_args = 1,   .retrieval_function = &get_seed     },
        {.option = ".",              .flag = &flags.head,         .active =  1,   .takes_args = 1,   .retrieval_function = &get_seed     },

        {.option = "--help",         .flag = &flags.help,         .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-h",             .flag = &flags.help,         .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "?",              .flag = &flags.help,         .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--version",      .flag = &flags.version,      .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-v",             .flag = &flags.version,      .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "!",              .flag = &flags.version,      .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--raw",          .flag = &flags.raw,          .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--length",       .flag = &flags.length,       .active =  1,   .takes_args = 1,   .retrieval_function = &get_length   },
        {.option = "-len",           .flag = &flags.length,       .active =  1,   .takes_args = 1,   .retrieval_function = &get_length   },

        {.option = "--count",        .flag = &flags.count,        .active =  1,   .takes_args = 1,   .retrieval_function = &get_count    },
        {.option = "-c",             .flag = &flags.count,        .active =  1,   .takes_args = 1,   .retrieval_function = &get_count    },

        {.option = "--choose",       .flag = &flags.choose,       .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--monoset",      .flag = &flags.monoset,      .active =  1,   .takes_args = 0,   .retrieval_function = &get_set      },
        {.option = "-mono",          .flag = &flags.monoset,      .active =  1,   .takes_args = 0,   .retrieval_function = &get_set      },

        {.option = "--upper",        .flag = &flags.upper,        .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-u",             .flag = &flags.upper,        .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--no-upper",     .flag = &flags.upper,        .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-nu",            .flag = &flags.upper,        .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--lower",        .flag = &flags.lower,        .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-l",             .flag = &flags.lower,        .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--no-lower",     .flag = &flags.lower,        .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-nl",            .flag = &flags.lower,        .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--number",       .flag = &flags.number,       .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-n",             .flag = &flags.number,       .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--no-number",    .flag = &flags.number,       .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-nn",            .flag = &flags.number,       .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--symbol",       .flag = &flags.special,      .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-s",             .flag = &flags.special,      .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--no-symbol",    .flag = &flags.special,      .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-ns",            .flag = &flags.special,      .active = -1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--pronounce",    .flag = &flags.pronounce,    .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-word",          .flag = &flags.pronounce,    .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--pin",          .flag = &flags.pin,          .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "-p",             .flag = &flags.pin,          .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },

        {.option = "--include",      .flag = &flags.include,      .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-inc",           .flag = &flags.include,      .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-i",             .flag = &flags.include,      .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},

        {.option = "--finclude",     .flag = &flags.include,      .active =  2,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-finc",          .flag = &flags.include,      .active =  2,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-f",             .flag = &flags.include,      .active =  2,   .takes_args = 1,   .retrieval_function = &parse_include},

        {.option = "--genclude",     .flag = &flags.include,      .active =  3,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-genc",          .flag = &flags.include,      .active =  3,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-g",             .flag = &flags.include,      .active =  3,   .takes_args = 1,   .retrieval_function = &parse_include},

        {.option = "--separator",    .flag = &flags.include_by,   .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},
        {.option = "-sep",           .flag = &flags.include_by,   .active =  1,   .takes_args = 1,   .retrieval_function = &parse_include},

        {.option = "--charset",      .flag = &flags.charset,      .active =  1,   .takes_args = 1,   .retrieval_function = NULL          },
        {.option = "-set",           .flag = &flags.charset,      .active =  1,   .takes_args = 1,   .retrieval_function = NULL          },

        {.option = "--prompt",       .flag = &flags.prompt,       .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = "--",             .flag = &flags.prompt,       .active =  1,   .takes_args = 0,   .retrieval_function = NULL          },
        {.option = NULL,             .flag = NULL,                .active =  0,   .takes_args = 0,   .retrieval_function = NULL          }
    };


    // Initialize the FLAGS struct members to default values
    _init_(&flags);

    // Parse the command line arguments and activate flags based on route info
    rc = parse_args(argc, argv, &flags, route);
    if (rc != 0)
    {
        printf("Error parsing arguments.\n");

        free_allocated(&flags);
        return rc;
    }

    // Check if the user is requesting help or version information and exit early
    if (flags.help.state == 1)
    {
        help();
    }

    if (flags.version.state == 1)
    {
        version();
    }

    // Generate the password based on user preferences
    char *password = get_password(&flags);
    if (password == NULL)
    {
        free_allocated(&flags);
        free(password);

        return 1;
    }


    // Check and handle password count and choose options
    if (flags.count.value > 1 && flags.choose.state == 0)
    {
        free_allocated(&flags);
        free(password);

        return 0;
    }

    printf("%s\n", password);

    // Free allocated memory and exit
    free_allocated(&flags);
    free(password);

    return 0;
}