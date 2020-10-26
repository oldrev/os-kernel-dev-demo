#pragma once

typedef struct
{
    /** Initialization function for the init entry which will take
	 * the dev attribute as parameter. See below.
	 */
    int (*init)(const Device *device);
    /** Pointer to a device driver instance structure. Can be NULL
	 * if the init entry is not used for a device driver but a services.
	 */
    const Device *device;
} InitEntry;

#define __INIT_SECTION __attribute__((section("._init")))

#define INIT_ENTRY_DEFINE(entry_name_, init_fn_, device_)                              \
    static const InitEntry CONCAT(_init_entry_, entry_name_) __USED __INIT_SECTION = { \
        .init = (&init_fn_),                                                           \
        .device = (device_)};

int init();