# NvdlaSmallTraceTest
NVDLA small版本的踪迹测试，用于在裸机环境下运行。

## 使用
/home/lvxu-cnu/Documents/Projects/hw/outdir/nv_small_256/spec/manual
1. 按照NVDLA官方文档生成hw vmod，从outdir/对应版本/spec/manual/拷贝opendla.py到script目录。
2. 从hw/verif/tests/trace_tests/拷贝nvdla对应版本的测试文件（拷贝整个目录）到data目录。
3. 运行scripts\convert_dat_2_arrays.py生成数据数组相关代码。
4. 运行scripts\nvdla_registers.py生成寄存器定义相关代码。
5. 将所有.h和.c以及nv_small目录拷贝到工程目录，编译运行。

## todo
将两个脚本参数化，接目录，版本
common_defines.h定义了两个重要变量：NVDLA_CSB_BASE_ADDR和NVDLA_DDR_BASE_OFFSET，需要根据Vivado中地址映射的具体情况修改。