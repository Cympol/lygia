#include <stdio.h>
#include <stdlib.h>

typedef enum { // TokenType: lygia lexemes;
    // Arithmetic: + - * / %;
    PLUS_TOKEN,
    MINUS_TOKEN,
    TIMES_TOKEN,
    DIVIDE_TOKEN,
    MODULO_TOKEN,
    // Assignment: = += -= *= /= %=;
    ASSIGN_TOKEN,
    PLUS_ASSIGN_TOKEN,
    MINUS_ASSIGN_TOKEN,
    TIMES_ASSIGN_TOKEN,
    DIVIDE_ASSIGN_TOKEN,
    MODULO_ASSIGN_TOKEN,
    // Comparison: == != > < >= <=;
    EQUALS_TOKEN,
    NOT_EQUALS_TOKEN,
    GREATER_THAN_TOKEN,
    LESSER_THAN_TOKEN,
    GREATER_EQUALS_TOKEN,
    LESSER_EQUALS_TOKEN,
    // Logical: and or not;
    AND_TOKEN,
    OR_TOKEN,
    NOT_TOKEN,
    // Integer Literals: 1231618;
    INTEGER_LITERAL_TOKEN,
    // Float Literals: 0.0451 9044200.01;
    FLOAT_LITERAL_TOKEN,
    // Boolean Literals: true false;
    TRUE_LITERAL_TOKEN,
    FALSE_LITERAL_TOKEN,
    // String Literals:  "some string";
    STRING_LITERAL_TOKEN,
} TokenType;

typedef struct { // Token:
    TokenType type;  // Type of the token;
    int       start; // Index of the start of the token;
    int       end;   // Index of the end of the token;
} Token;

int main(int argc, char *argv[]) {
    // CLI input handler:
    printf("argc = %d\n", argc);
    switch (argc) {
    case 1: // If there are no arguments, it should open the REPL;
        printf("Boot Repl\n");
        exit(0); //not impl yet
        break;
    case 2: // If there is one argument, interpret it as a file path and attempt to run the file.
        printf("Run %s\n", argv[1]);
        break;
    default: // If there are more than one arguments, attempt to interpret the commands
        printf("Error: Invalid input!\n");
        exit(0); //not impl yet
    }

    // Lexer:
    // 1. Load a .lygia file;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: File failed to open!");
        exit(0);
    }
    // 2. Scan the file for tokens and print them;
    while (!feof(file)) {
        int ch = fgetc(file);
        printf("%c", ch);
        
        // switch (ch) {

        // }
    }
    // 3. Report ortography errors;
    // 4. Print the tokens in the terminal;
    // 5. Close .lygia file;
    fclose(file);
    
    return 0;
}