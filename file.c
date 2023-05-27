#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "modules.h"

int parse_main_conf()
{
    FILE *main_config = fopen("main.conf", "r"); // Open main.conf

    if (!main_config)
    {
        puts("parse_main_conf: main.conf failed to open");
        return 1;
    }

    char module_name[64]; // Module names can have a max of 63 chars

    // Reads conf file line-by-line for module names
    while (fscanf(main_config, "%s ", module_name) > 0)
    {
        if (add_modules(module_name))
        {
            printf("add_module: %s failed to load\n", module_name);
        }
    }

    fclose(main_config);
    return 0;
}