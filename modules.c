#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "modules.h"

node *modules_list = NULL;

int add_modules(const char *name)
{
    if (modules_list == NULL)
    {
        modules_list = malloc(sizeof(node));
    }
    else
    {
        node *new = malloc(sizeof(node));
        new->next = modules_list;
        modules_list = new;
    }

    strncpy(modules_list->module_name, name, 64);
}

void list_modules()
{
    node *it = modules_list;
    while (it)
    {
        puts(it->module_name);
        it = it->next;
    }
}