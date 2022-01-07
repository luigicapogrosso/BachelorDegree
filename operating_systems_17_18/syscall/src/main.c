#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "padre.h"
#include "toolbox.h"
// =============================================================================
int main(int argc, char *argv[]) {
    // Controllo dei parametri inseriti da lina di comando
    if (argc != 3) {
        my_println("Esecuzione: key_finder <plain_text> <encoded_text>");
        return 1;
    }

    // Iniziamo!
    padre(argv[1], argv[2]);
}
// =============================================================================
