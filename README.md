# LINIX DEVICE DRIVERS

## dryinit_module
Sample module which allows to see if you are able to load and unload module.

* Build, install and boot kernel from kernel.org -> tested on 6.9.3
* ```cd dryinit_module && make```
* ```sudo insmod dryinit-module.ko```
* ```sudo rmsmod dryinit-module.ko```
* ```sudo dmesg```

Shall see
```
[  119.001055] Hello, world
[  200.727763] Goodbye, cruel world
```

## sample_program
User space running programs