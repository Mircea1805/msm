#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <pthread.h>
#include "modules.h"

node *modules_list = NULL; // List of modules
void *(*func)(void *); // dynamic library start routine

// adds and runs modules
int add_modules(const char *name)
{
    // Get dl name
    char dl_path[256], wd[200];
    getcwd(wd, sizeof(wd));
    sprintf(dl_path, "%s%c%s", wd, '/', name);

    // Loads dl and gets start routine
    void *dl = dlopen(dl_path, RTLD_NOW);
    if (!dl) // Checks if dl loaded
    {
        puts("add_modules: Failed to load dl");
        return 1;
    }

    func = dlsym(dl, name);
    if (!func) // Checks if func exists
    {
        puts("add_modules: Failed to find func");
        return -1;
    }

    // Creates new thread and executes func
    pthread_t thread;
    pthread_create(&thread, NULL, func, NULL);

    // adds module to list
    if (modules_list == NULL)
    {
        modules_list = malloc(sizeof(node));
        if (!modules_list)
        {
            puts("add_modules: failed to allocate memory");
            return -2;
        }
    }
    else
    {
        node *new = malloc(sizeof(node));
        if (!new)
        {
            puts("add_modules: failed to allocate memory");
            return -2;
        }
        new->next = modules_list;
        modules_list = new;
    }
    strncpy(modules_list->module_name, name, 64);

    return 0;
}

// Lists modules by iterating through the list
void list_modules()
{
    node *it = modules_list;
    while (it)
    {
        puts(it->module_name);
        it = it->next;
    }
}