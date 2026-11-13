#include "alfabeto.h"
#include <cctype>

char classificarCaractere(char c) {
    if (std::isdigit(c)) return 'D';
    if (std::isalpha(c)) return 'L';
    return c;
}
