#pragma once

typedef struct
{
    int (*init)(const Device *device);
    const Device *device;
} InitEntry;

#define __INIT_SECTION __attribute__((section("._init")))

#define INIT_ENTRY_DEFINE(entry_name_, init_fn_, device_)                              \
    static const InitEntry CONCAT(_init_entry_, entry_name_) __USED __INIT_SECTION = { \
        .init = (&init_fn_),                                                           \
        .device = (device_)};

int init();
