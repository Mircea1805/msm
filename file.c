#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "modules.h"

void parse_main_conf()
{
    FILE *main_config = fopen("main.conf", "r"); // Open main.conf
    char module_name[64]; // Module names can have a max of 63 chars

    // Reads conf file line-by-line for module names
    while (fscanf(main_config, "%s ", module_name) > 0)
    {
        add_modules(module_name);
    }

    fclose(main_config);
}