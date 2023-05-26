#include <stdio.h>
#include <string.h>
#include "modules.h"
#include "file.h"

#define VERSION "0.0.1"
#define HELP_STR ""

int main()
{
    parse_main_conf();

    char cli_buffer[256];
    for (;;)
    {
        fputs("> ", stdout);
        fgets(cli_buffer, sizeof(cli_buffer) - 1, stdin);

        if (strncmp(cli_buffer, "version", 7) == 0)
        {
            puts(VERSION);
        }

        if (strncmp(cli_buffer, "help", 4) == 0)
        {
            puts(HELP_STR);
        }

        if (strncmp(cli_buffer, "exit", 4) == 0)
        {
            return 0;
        }

        if (strncmp(cli_buffer, "modules", 7) == 0) //list modules
        {
            list_modules();
        }

        if (strncmp(cli_buffer, "install", 7) == 0) //install modules
        {
            install_module();
        }

        if (strncmp(cli_buffer, "uninstall", 9) == 0) //uninstall modules
        {
            uninstall_module();
        }
    } 
}