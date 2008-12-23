ULimit Addon for Io
===================

Building:

    cd io
    git clone git://github.com/quag/ulimit.git addons/ULimit
    make ULimit
    make install

ULimit Object
-------------

    Io> ULimit
    ==>  ULimit_0x3304f0:
     setCPUTimeLimit  = ULimit_setCPUTimeLimit()
     setDataMemoryLimit = ULimit_setDataMemoryLimit()
     setVirtualMemoryLimit = ULimit_setVirtualMemoryLimit()

    Io> 

