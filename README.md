# os-kernel-dev-demo
A simple demo to implements a Linux or Zephyr-OS like device driver management architecture.


## Getting Started

```bash
$ gcc -T default.lds  main.c init.c -o demo
$ ./demo
```

To test it in your own STM32 project, **do not** use the `default.lds` file that included in this repository, instead you may add the following to your STM32 linker script (`*.ld/*.lds`):

```lds
  ._init :
  {
    PROVIDE_HIDDEN (__init_begin = .);
    KEEP (*(SORT(._init.*)))
    KEEP (*(._init*))
    PROVIDE_HIDDEN (__init_end = .);
  } >FLASH

  .devices :
  {
    PROVIDE_HIDDEN (__device_begin = .);
    KEEP (*(SORT(.device_.*)))
    KEEP (*(.device_*))
    PROVIDE_HIDDEN (__device_end = .);
  } >FLASH
```
