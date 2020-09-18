CONFIG_MODULE_SIG=n
CONFIG_MODULE_SIG_ALL=n
CC=gcc

obj-m:=tcp_swiftest.o
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:     modules

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o *~ core .depend *.symvers .*.cmd *.ko *.mod.c .tmp_versions

install:
	insmod tcp_swiftest.ko


