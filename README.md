# Tessera

# Tessera is a command-line tool developed as versatile string manipulation project. It allows users to generate customizable passwords with various options to suit their preferences. The program is written in C and leverages custom-defined structs and efficient algorithms to provide a robust string generation experience.

## Table of Contents
- [Installation](#installation)
- [Files and Functionality](#files-and-functionality)
  - [Windows](#windows)
  - [MacOS](#macos)
  - [Linux](#linux)
- [Structs and Data Organization](#structs-and-data-organization)
- [Design Choices](#design-choices)
- [Usage](#usage)
- [Usage examples](#usage-examples)

### [Installation](#installation)
### [Windows](#windows)

    1. **Download the Source Code**
       - Navigate to the GitHub repository.
       - Download the source code by running:
       
         git clone https://github.com/adamtawfikcode/tessera.git
         
       - Alternatively, download the ZIP file from the repository and extract it.

    2. **Install a C Compiler**
       - Download and install MinGW or Cygwin to use GCC for compiling the code.
       - Follow the installation guide on the respective website to set it up properly.

    3. **Compile Tessera**
       - Open Command Prompt or PowerShell as an administrator.
       - Change to the directory where you have Tessera, then compile it:
         
         gcc -o tessera.exe tessera.c backend.c string_manipulation.c
         
       - This command creates `tessera.exe`, the executable file.

    4. **Add Tessera to System PATH**
       - Access "Environment Variables" through system settings.
       - Add the directory containing `tessera.exe` to the `PATH` variable.
       - This allows you to run Tessera from any command prompt or PowerShell window.

    5. **Running Tessera**
       - Open a new Command Prompt or PowerShell window.
       - Type `tessera` and press Enter to run the program.

### [MacOS](#macos)

    1. **Download the Source Code**
       - Navigate to the GitHub repository.
       - Download the source code by running:
       
         git clone https://github.com/adamtawfikcode/tessera.git
         
       - Alternatively, download the ZIP file from the repository and extract it.

    2. **Install Xcode Command Line Tools**
       - If not already installed, open Terminal and install Xcode Command Line Tools with:
     
     xcode-select --install

    3. **Compile Tessera**
       -  In Terminal, navigate to the Tessera directory and compile:
     
         gcc -o tessera tessera.c backend.c string_manipulation.c

    4. **Add Tessera to PATH**
       - Edit your shell profile (`.bash_profile`, `.bashrc`, or `.zshrc`) with:
       
         export PATH="$PATH:/path/to/tessera"
         
       - Replace `/path/to/tessera` with the actual path to the Tessera directory.
    
    5. **Running Tessera**
       - Open a new Terminal window.
       - Type `tessera` and press Enter to run the program.

### [Linux](#linux)

     1. **Download the Source Code**
       - Navigate to the GitHub repository.
       - Download the source code by running:
       
         git clone https://github.com/adamtawfikcode/tessera.git
         
       - Alternatively, download the ZIP file from the repository and extract it.

    2. **Ensure GCC is Installed**
       - Verify GCC installation with `gcc --version`.
       - If GCC is not installed, use your distribution's package manager to install it (e.g., `sudo apt-get install gcc`).

    3. **Compile Tessera**
       - Navigate to the Tessera directory.
       - Compile with:
         gcc -o tessera tessera.c backend.c string_manipulation.c

    4. **Make Tessera Globally Accessible**
       - Add the Tessera directory to your PATH by editing your shell profile (`.bashrc`, `.bash_profile`, or `.zshrc`).

    5. **Running Tessera**
       - Open a new terminal window.
       - Type `tessera` and press Enter to run the program.

    If you encounter any issues or have questions during the installation process, please reach out for assistance.

### [Files and Functionality](#files-and-functionality)

    The project consists of the following key files, each serving specific functionalities:
        1. `backend.h`:
           - Contains the custom-defined structs `FLAG`, `FLAGS` and `ROUTES`.
           - Provides function declarations for functions like
                - `help()` and `version()` for retrieving the usage guide and version information.
                - `_init_()` for program initialization.
                - `get_x()` for retrieving all the user defined data like the length, count, seed, etc.. where x is the value that needs retrieval.
                - `parse_x()` for parsing user provided arguments and strings for inclusion, argument string generation and user-defined charset where
                x could be include, charset or arguments.
                - `get_password()` for generating and retrieving all the generated passwords after validating user input.
                - `recurse()` for generating and include string if the user requested.

        2. `backend.c`:
           - Provides function implementations for `help()`, `version()`, `get_x()` functions, `parse_x()` functions, `get_password()` and `recurse()`.

        3. `string_manipulation.h`:
           - Contains function declarations for various string manipulation tasks.

        4. `string_manipulation.c`:
           - Implements functions for string manipulation such as checking the validity of strings, extracting words from strings,
           inserting strings into target strings, etc..
           - Includes the `generate_password()` core function for password generation based on user-selected options.

        5. `tessera.c`:
           - The main program file responsible for handling FLAGS struct definition and route array initilization,
           handling user input, initializing the password generator, and displaying the generated passwords.

### [Structs and Data Organization](#structs-and-data-organization)

    Tessera defines three custom-defined structs,`FLAG`, `FLAGS` and `ROUTES`, to efficiently organize user options and corresponding data:
        1. `FLAG` struct:
            - Serves as the building block for the `FLAGS` struct and hosts the core varibles for the flag state [1 => Active | 0 => Neutral (active if needed) | -1 => Inactive].
            - Hosts the varibles for the necessary values for the flags such as long for the length, count, and text for include and charset flag.
            - Hosts the varibale for storing the index where the flag was found in the command line 2D array vector.

        2. `FLAGS` struct:
           - Serves as the central data structure for storing user-defined options and their associated properties.
           - Contains members representing various flag options (e.g. length, count) and their corresponding states [Active | Neutral | Inactive].
           - Tracks values provided with certain flags (e.g., password length, custom strings).
           - Enables efficient handling of user inputs, simplifying conditional checks for flag combinations.

        3. `ROUTES` struct:
           - Facilitates mapping command-line options to their corresponding flag members in the `FLAGS` struct.
           - Pairs each option with its associated flag, optimizing retrieval and modification of relevant flag data during command-line argument processing.

    Together, these custom structs optimize the organization and management of user options, ensuring a clean and well-structured codebase for Tessera.

### [Design Choices](#design-choices)

    During the development of Tessera, several design choices were made to ensure a user-friendly and robust experience:
        1. **Modular Code Structure**: The program is organized into separate files for better maintainability and readability.
        Each file handles specific functionalities, making it easier to locate and update code blocks as needed.

        2. **Custom Structs for Data Management**: The use of custom `FLAG`, `FLAGS` and `ROUTES` structs allows for efficient handling
        and storage of user options and their associated data, resulting in streamlined command-line argument processing.

### [Usage](#usage)

    The Tessera Password Generator supports the following command-line options:
        +------------------------+--------------------------------------------------------------------+------------+
        | Option                 | Description                                                        | Takes Args |
        +------------------------+--------------------------------------------------------------------+------------+
        | --seed                 | Set custom seed.                                                   | Yes        |
        | --help, -h, ?          | Display program usage and help info.                               | No         |
        | --version, -v          | Display program version details.                                   | No         |
        | --raw                  | Enable raw output (no extra messages).                             | No         |
        | --length, -len         | Set password length.                                               | Yes        |
        | --count, -c            | Set number of passwords to generate.                               | Yes        |
        | --choose               | Pick from predefined passwords.                                    | No         |
        | --monoset, -mono       | Use one character set.                                             | No         |
        | --upper, -u            | Include uppercase letters.                                         | No         |
        | --no-upper, -nu        | Exclude uppercase letters.                                         | No         |
        | --lower, -l            | Include lowercase letters.                                         | No         |
        | --no-lower, -nl        | Exclude lowercase letters.                                         | No         |
        | --number, -n           | Include numbers.                                                   | No         |
        | --no-number, -nn       | Exclude numbers.                                                   | No         |
        | --symbol, -s           | Include special symbols.                                           | No         |
        | --no-symbol, -ns       | Exclude special symbols.                                           | No         |
        | --pronounce, -word     | Generate readable passwords.                                       | No         |
        | --pin, -p              | Create 4 digit PIN.                                                | No         |
        | --include, -inc        | Insert one or choose one of multiple strings into passwords.       | Yes        |
        | --finclude, -finc      | Fuzzy include, same as --include but replace * with                | ---------. |
        | '--------------------> | random letter from the available charset.                          | Yes        |
        | --genclude [ARGUMENTS] | Generate an include string from arguments.                         | Yes        |
        | --include-by, -by      | Separate the include string by a custom separator.                 | Yes        |
        | --charset, -set        | Customize character set for generation.                            | Yes        |
        | --prompt, --           | Prompt for input after certain flags.                              | No         |
        +------------------------+--------------------------------------------------------------------+------------+
    Each flag allows users to customize the generated password to meet their specific security requirements and preferences.

### [Usage examples](#usage-examples)

    - Generate a single password with a length of 12 characters:
      '------> $ tessera --length 12
      |
      '------> JnWsL6M6Nq9

    - Generate 5 passwords with a length of 8 characters, excluding special characters:
      '------> $ tessera --length 8 --count 5 --no-special
      |
      '------> JnWsL6M6Nq9

    - Generate a single password using the seed "Tessera":
      '------> $ tessera --seed "Tessera"
      |
      '------> 31NENT48KBv/

    - Generate 20 passwords with a length of 16 characters, excluding uppercase letters and choose one of them to be displayed:
      '------> $ tessera --length 8 --count 5 --no-number --choose
      |
      '------> [1]: Co.FNk0S
               [2]: %^vUlr5%
               [3]: 9JUI=ZJ/
               [4]: 67?59I60
               [5]: ql~y.V'7

    - Generate a PIN code:
      '------> $ tessera --pin
      |
      '------> 2285

    - Generate a PIN code with the length of 12 numbers:
      '------> $ tessera --pin --length 12
      |
      '------> 691131983989

    - Generate 3 passwords with a length of 16 characters, including uppercase and lowe rcase letters:
      '------> $ tessera --length 16 --count 3 --upper --lower
      |
      '------> [1]: IVQlRGeKfgdulxsR
               [2]: bMcZbESEhcxqBGpM
               [3]: mekQLMdXGYicseZU

    - Generate two 16 letter pronounceable password (or just a word):
      '------> $ tessera --pronounce --count 2 --length 16
      |
      '------> [1]: qukolekukixukaqu
               [2]: zufaxaruyunebeji

    - Generate 10 passwords with a length of 10 characters, including uppercase letters and special characters and choose one of them to be displayed:
      '------> $ tessera --length 10 --count 10 --upper --special --choose
      |
      '------> [1]: %W~P!>ZI'T
               [2]: G!HXL@%X:T
               [3]: ?_/Z%JY))$
               [4]: UANOA\A=?!
               [5]: T&'G='@HI>
               [6]: J~I[_KZ=A.
               [7]: =KW%]ACQG%
               [8]: M<;S%,JQ-Q
               [9]: GF"$]+Q"=K
               [10]: ?_F^NG?KE&

    - Generate a single password with a custom character set:
      '------> $ tessera --length 12 --charset "aleph10"
      |
      '------> l10h11lael0a

    - Generate a single password that includes the word "Secret" as part of it:
      '------> $ tessera --include "Secret"
      |
      '------> o5Secret47i"

    - Generate a single password around the word "Pass*ord" and the asterisk (*) is replaced by a random character:
      '------> $ tessera --finclude "Pass*ord"
      |
      '------> :5Passtord'7

    - Generate 5 passwords with a length of 12 characters, including only numbers and special characters, and replace the asterisk (*) with a random character:
      '------> $ tessera --length 12 --count 5 --number --special --finclude "*0123;45*7;89*^&*()_+-="
      |
      '------> [1]: 759-57?336989:^&)()_+-=6
               [2]: &4/%&2?^{%-\45&7*=:6\1}2
               [3]: 01550\%7)89:^&)()_+-=$/^
               [4]: <73"20123"9"9&~=?%?(22}$
               [5]: _1|8]289:^&)()_+-=8]7\::

    - Generate 5 passwords with a length of 16 consisting of only numbers, and then generate a string with a default length of 12 that is only special characters and insert it into the generated password:
      '------> $ tessera --length 16 --count 5 --number --genclude "--special"
      |
      '------> [1]: 289`(]=%?#&~<`\4
               [2]: 4;|<*(]<~*><<061
               [3]: '[)<.$:@(_)_6155
               [4]: 33->$('~<~';+;55
               [5]: 548-$>}_^>?*%-!4

    - Generate a password but generate the include string and use a custom charset and prompt for each one of these options to be entered separately:
      '------> $ tessera --prompt --genclude "" --charset ""
      |-> Include string: --upper
      |-> Charset: ABCabc123
      |
      '------> CAc2TBLTAHFPAYIL2A1b2Caa

    =--.
    |  | -> As you can see, the only limit is you imagination, and the flags..
    '--=

    For detailed information on available command-line options and usage examples, refer to the help documentation provided by the program.

============================================================================================
# Feel free to reach out to the project maintainer @adamtawfikcode (me :D) with any questions or feedback!             #
============================================================================================
