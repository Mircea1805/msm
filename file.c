#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "modules.h"

void parse_main_conf()
{
    FILE *main_config = fopen("main.conf", "r");
    char module_name[64];

    if (fscanf(main_config, "%63s", module_name))
    {
        add_modules(module_name);
    }

    fclose(main_config);
}

int install_module()
{

}

int uninstall_module()
{
    
}