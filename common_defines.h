#ifndef COMMON_DEFINES_HEADER
#define COMMON_DEFINES_HEADER

#define ret_err return -1;

#define ret_ok return 0;

#define pri_mem (1)

// 顺序就是模块在nvdla_glb_s_intr_status_0_out寄存器中对应中断位的序号。
// 寄存器在glb/NV_NVDLA_GLB_ic.v被写入。
// assign nvdla_glb_s_intr_status_0_out[31:0] = { 10'b0, cacc_done_status1, cacc_done_status0, cdma_wt_done_status1, cdma_wt_done_status0, cdma_dat_done_status1, cdma_dat_done_status0, 6'b0, rubik_done_status1, rubik_done_status0, bdma_done_status1, bdma_done_status0, pdp_done_status1, pdp_done_status0, cdp_done_status1, cdp_done_status0, sdp_done_status1, sdp_done_status0 };

#define SDP_0 (0)
#define SDP_1 (1)
#define CDP_0 (2)
#define CDP_1 (3)
#define PDP_0 (4)
#define PDP_1 (5)

#define CDMA_DAT_0 (10)
#define CDMA_DAT_1 (11)
#define CDMA_WT_0 (12)
#define CDMA_WT_1 (13)
#define CACC_0 (14)
#define CACC_1 (15)

#define sync_id_0 (0)

/**
 * NVDLA CSB配置寄存器的起始地址。
 **/
#define NVDLA_CSB_BASE_ADDR (0xa0000000)

/**
 * 如果0x80000000并非DDR所属的区间，可以在这里加个偏移。必须保证写入数据的地址在空闲的DDR内存里，而不要覆盖了程序本身或其它的数据！
 * 如果内存地址不同于0x80000000，那么偏移需要出现在mem_init、mem_load、check_crc和write_reg写入基地址寄存器时。
 **/
#define NVDLA_DDR_BASE_OFFSET (0xC0000000)

#endif
