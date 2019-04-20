
#CROSS_COMPILE = arm-none-linux-gnueabi-
CROSS_COMPILE = 

AS			= $(CROSS_COMPILE)as
LD			= $(CROSS_COMPILE)ld
CC			= $(CROSS_COMPILE)gcc
CJJ			= $(CROSS_COMPILE)g++
CPP			= $(CC) -E
AR			= $(CROSS_COMPILE)ar
NM			= $(CROSS_COMPILE)nm
STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump	

# export导出的变量是给子目录下的Makefile使用的
export AS LD CC CPP AR NM STRIP OBJCOPY OBJDUMP CJJ

# 编译器在编译时的参数设置
CFLAGS := -Wall -O2 -g
#CFLAGS := 
# 添加头文件路径，不添加的话include目录下的头文件编译时找不到
CFLAGS += -I$(shell pwd)/common
CFLAGS += -I$(shell pwd)/listArray 
CFLAGS += -I$(shell pwd)/single_linklist 
CFLAGS += -I$(shell pwd)/static_linklist
CFLAGS += -I$(shell pwd)/double_linklist
CFLAGS += -I$(shell pwd)/listArray_stack
CFLAGS += -I$(shell pwd)/slinklist_stack
CFLAGS += -I$(shell pwd)/main/test

# 链接器的链接参数设置
LDFLAGS :=  
#-Wl,--hash-style=sysv

export CFLAGS LDFLAGS

TOPDIR := $(shell pwd)
export TOPDIR

# 定义将来编译生成的可执行程序的名字
TARGET := dataStructure

# 添加项目中所有用到的源文件，有顶层目录下的.c文件，和子文件夹
# 添加顶层目录下的.c文件
# TOP = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
# $(info $(TOP))
# main.c通过传参指定  main.c的路径main/xxx/main.c
ifeq ("$(origin D)", "command line")
	COMPILE_DIR = $(D)
ifneq (main.c, $(wildcard main.c))
#do something here
$(shell ln -s ./main/$(COMPILE_DIR)/main.c main.c)
endif
endif



obj-y += main.o

# 添加顶层目录下的子文件夹（注意目录名后面加一个/）
obj-y += listArray/
obj-y += single_linklist/
obj-y += static_linklist/
obj-y += double_linklist/
obj-y += listArray_stack/
obj-y += slinklist_stack/

all: 
	make -C ./ -f $(TOPDIR)/Makefile.build
	$(CC) $(LDFLAGS) -o $(TARGET) built-in.o

help:
	@echo  '编译:'
	@echo  '  make D=test 	- test是main.c的目录，一次只能添加一个main.c'
	@echo  '  		  		- main.c的相对路径 ./main/test/main.c'
	@echo  ''
	@echo  '清除:'
	@echo  '  clean		  	- 只清楚.o文件'
	@echo  '  distclean	  	- 全部清除'
	@echo  ''

clean:
	rm -f main.c
	rm -f $(shell find -name "*.o")
	rm -f $(TARGET)

distclean:
	rm -f main.c
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.d")
	rm -f $(TARGET)
	
