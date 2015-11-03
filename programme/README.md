How to run the programme/s
==========================

First of all build all programmes:

    $ make
    
Afterwards you have to increase the stack size, otherwise there will be a segmentation:

    $ ulimit -s 65536

Now you can run the programmes (e.g. aligned_arrays):
    
    $ ./aligned_arrays
    
If you want to clean up just do:

    $ make clean

Tasks
=====

Host machine: 4 CPUs (per cpu: 4 cores, 800Mhz, cache size: 512KB, cache alignment: 64)

Task 1
------

Valgrind options: --tool=cachegrind --L2=8388608,2,128

