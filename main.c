#include "nvdla_verif.h"
#include "nvdla_registers.h"
#include <stdio.h>

int main(void)
{
#include "pdp_8x9x19_3x3_ave_int8_0.cfg"

    fprintf(stderr, "test passed");
    
    return 0;
}
