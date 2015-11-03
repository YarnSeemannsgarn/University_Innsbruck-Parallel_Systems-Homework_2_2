How to run the programme/s
==========================

First of all build all programmes:

    $ make
    
Afterwards you have to increase the stack size, otherwise there will be a segmentation fault:

    $ ulimit -s 65536

Now you can run the programmes (e.g. aligned_arrays):
    
    $ ./aligned_arrays
    
If you want to clean up just do:

    $ make clean

Tasks
=====

Host machine: 4 CPUs (per cpu: 4 cores, 800Mhz, cache size: 512KB, cache alignment: 64)
getconf -a | grep CACHE output:

LEVEL1_ICACHE_SIZE                 65536
LEVEL1_ICACHE_ASSOC                2
LEVEL1_ICACHE_LINESIZE             64
LEVEL1_DCACHE_SIZE                 65536
LEVEL1_DCACHE_ASSOC                2
LEVEL1_DCACHE_LINESIZE             64
LEVEL2_CACHE_SIZE                  524288
LEVEL2_CACHE_ASSOC                 16
LEVEL2_CACHE_LINESIZE              64
LEVEL3_CACHE_SIZE                  6291456
LEVEL3_CACHE_ASSOC                 48
LEVEL3_CACHE_LINESIZE              64
LEVEL4_CACHE_SIZE                  0
LEVEL4_CACHE_ASSOC                 0
LEVEL4_CACHE_LINESIZE              0

Task 1 & 2
----------

Valgrind options: --tool=cachegrind --L2=8388608,2,128 --main-stacksize=33554432

Programme                | Runtime (in s) | cache misses
:------------------------|---------------:|-------------------------------------------------------:
aligned_arrays           | 0.26           | I1 misses: 897, D1 misses: 4196187, LLd misses: 4195358
aligned_arrays_optimized | 0.33           | I1 misses: 898, D1 misses:  264021, LLd misses:  132122

The stacksize of the main programme needed to be adapted, otherwise there will be a segmentation fault within valgrind. The number 33554432 is just the initial main stacksize number doubled.

The L1 and L2 data cache misses of the initial programme are nearly 1024*1024*4 (4194304), which means that nearly every access to the arrays are cache misses.

The cache misses of the optimized programme are much less than in the cache misses in the initial programme (Explanation in the programme). The runtime on the other hand is a little bit bigger, probably due to the multiplication for accessing the array (e.g. a[i*3]).

Task 3
------

Programme                | Runtime (in s) | 
:------------------------|---------------:|
aligned_arrays           | 0.029          |
aligned_arrays_optimized | 0.037          |

The runtime is much less for both programmes, whereby the runtime of the initial programme is still less than the optimized programme. The lesser time is due to the omitted valgrind simulation overhead.