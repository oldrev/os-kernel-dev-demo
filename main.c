#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

#include "kernel/kernel.h"


static int usart_init(const Device* dev)
{
	printf("usart!\n");
	return 0;
}

DEVICE_DEFINE(usart, "usart", usart_init, NULL, NULL, NULL, 0);


static int i2c_init(const Device* dev)
{
	printf("i2c init!\n");
	return 0;
}

DEVICE_DEFINE(i2c, "i2c", i2c_init, NULL, NULL, NULL, 0);

int main()
{
	int retval = init();

	const Device *devices;
	size_t n_device = device_get_all_static(&devices);
	printf("Device count = %lu\n", n_device);

	const Device *usart = device_find_static("usart");
	printf("Found usart device: %s\n", usart->name);

	return 0;
}
