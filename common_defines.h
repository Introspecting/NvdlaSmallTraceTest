#ifndef COMMON_DEFINES_HEADER
#define COMMON_DEFINES_HEADER

#define ret_err return -1;

#define ret_ok return 0;

/**
 * NVDLA CSB配置寄存器的起始地址。
 **/
#define NVDLA_CSB_BASE_ADDR (0x44a00000)

/**
 * 如果0x80000000并非DDR所属的区间，可以在这里加个偏移。必须保证写入数据的地址在空闲的DDR内存里，而不要覆盖了程序本身或其它的数据！
 * 如果内存地址不同于0x80000000，那么偏移需要出现在mem_init、mem_load、check_crc和write_reg写入基地址寄存器时。
 **/
#define NVDLA_DDR_BASE_OFFSET (0x20000000)

#endif
