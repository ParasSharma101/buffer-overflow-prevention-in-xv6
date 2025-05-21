#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void vulnerable() {
    char buffer[16];
    printf("Enter something:\n");

    // Deliberately unsafe input
    gets(buffer, 64); // reading more than buffer size

    printf("You entered: %s\n\n", buffer);
}

int main() {
    printf("1. BUFFER OVERFLOW ATTACK SIMULATION\n");

    vulnerable();

    printf("4. BUFFER OVERFLOW TACKLED (Due to ASLR, control hijack is unpredictable)\n");

    exit(0);
}

