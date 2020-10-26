#include "kernel/kernel.h"

#include <stdio.h>
#include <string.h>

extern const InitEntry __init_begin[];
extern const InitEntry __init_end[];

int init()
{
    for (const InitEntry *entry_ptr = __init_begin;
         entry_ptr < __init_end;
         entry_ptr++)
    {
        fprintf(stderr, "Init device: %s\n", entry_ptr->device->name);
        if (entry_ptr != NULL && entry_ptr->init != NULL)
        {
            int retval = entry_ptr->init(entry_ptr->device);
            if (retval != 0)
            {
                return -1;
            }
        }
    }

    return 0;
}

extern const Device __device_begin[];
extern const Device __device_end[];

size_t device_get_all_static(const Device **devices)
{
    *devices = __device_begin;
    return __device_end - __device_begin;
}

const Device *device_find_static(const char *name)
{
    const Device *devices;
    size_t n = device_get_all_static(&devices);

    // Fast search
    for (size_t i = 0; i < n; i++)
    {
        if (name == devices[i].name)
        {
            return &devices[i];
        }
    }

    // Slow search
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(name, devices[i].name) == 0)
        {
            return &devices[i];
        }
    }

    return NULL;
}