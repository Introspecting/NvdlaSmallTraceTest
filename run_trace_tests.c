#include "nvdla_verif.h"
#include "nvdla_registers.h"
#include <stdio.h>
#include <xil_cache.h>
/**
 * 启用某个测试，如pdp_8x9x19_3x3_ave_int8_0。
 * 在nvdla_verif.c定义#define pdp_8x9x19_3x3_ave_int8_0 1
 * 在run_trace_tests中加上#include "nv_small/{test}/{test}.cfg"
 * 
 * 
 **/

#define pdp_8x9x19_3x3_ave_int8_0 1

int run_trace_tests(void)
{
	Xil_DCacheDisable();


#include "data/nv_small/pdp_8x9x19_3x3_ave_int8_0/pdp_8x9x19_3x3_ave_int8_0.cfg"

    fprintf(stderr, "test passed");
    
    return 0;
}

