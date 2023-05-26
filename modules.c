#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <pthread.h>
#include "modules.h"

node *modules_list = NULL;
void *(*func)(void *);

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

    char dl_path[256], wd[200];
    getcwd(wd, sizeof(wd));
    sprintf(dl_path, "%s%c%s", wd, '/', name);

    void *dl = dlopen(dl_path, RTLD_NOW);
    func = dlsym(dl, name);

    pthread_t thread;
    pthread_create(&thread, NULL, func, NULL);
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