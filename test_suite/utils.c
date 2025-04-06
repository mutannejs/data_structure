#include "./utils.h"

void initSetupTerm () {
  setupterm(NULL, STDOUT_FILENO, NULL);
  putp(exit_attribute_mode);
}

void printColored (char* message, int fg, int bg) {
  if (bg >= 0)
    putp(tparm(set_a_background, bg));
  if (fg >= 0)
    putp(tparm(set_a_foreground, fg));

  printf(message);

  putp(exit_attribute_mode);
  fflush(stdout);
}

void printInBold (char* message, int fg, int bg) {
  putp(enter_bold_mode);

  printColored(message, fg, bg);
}
