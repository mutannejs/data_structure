#include <term.h>
#include <stdio.h>
#include <unistd.h>

#define COLOR_ERROR 9
#define COLOR_SUCCESS 2
#define COLOR_INFO 208

void initSetupTerm ();

void printColored (char* message, int fg, int bg);

void printInBold (char* message, int fg, int bg);
