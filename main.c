#include <stdio.h>
#include <string.h>
#include "modules.h"
#include "file.h"

#define VERSION "0.0.1"
#define HELP_STR "Modular Server Manager\nUSAGE:\nmodules\tlist modules\nhelp\tprint this message\nversion\tversion information\nexit\tquit program"

int main()
{
    // Parse conf file
    if (parse_main_conf())
    {
        return 1;
    }

    // cli loop
    char cli_buffer[256];
    for (;;)
    {
        fputs("> ", stdout);
        fgets(cli_buffer, sizeof(cli_buffer) - 1, stdin);

        // version
        if (strncmp(cli_buffer, "version", 7) == 0)
        {
            puts(VERSION);
            continue;
        }

        // help
        if (strncmp(cli_buffer, "help", 4) == 0)
        {
            puts(HELP_STR);
            continue;
        }

        // exit
        if (strncmp(cli_buffer, "exit", 4) == 0)
        {
            break;
        }

        // modules
        if (strncmp(cli_buffer, "modules", 7) == 0)
        {
            list_modules();
            continue;
        }
    }

    return 0;
}