#pragma once

typedef struct
{
    const char *name;
    const void *config;
    const void *api;
    void *const data;
} Device;

#define __DEVICE_SECTION(x) __attribute__((section(".device_" x)))

#define __DEVICE_MAKE_NAME(x) CONCAT(__device_, x)

#define DEVICE_DEFINE(dev_name_, drv_name_, init_, config_, api_, data_, prio_) \
    static const Device                                                         \
        __DEVICE_MAKE_NAME(dev_name_)                                           \
            __DEVICE_SECTION(STRINGIFY(dev_name_) "_" STRINGIFY(prio_)) = {     \
                .name = (drv_name_),                                            \
                .config = (config_),                                            \
                .api = (api_),                                                  \
                .data = (data_),                                                \
    };                                                                          \
    INIT_ENTRY_DEFINE(__DEVICE_MAKE_NAME(dev_name_), init_, &__DEVICE_MAKE_NAME(dev_name_));

size_t device_get_all_static(const Device **devices);

const Device *device_find_static(const char *name);
