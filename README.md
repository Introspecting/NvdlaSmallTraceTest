# NvdlaSmallTraceTest
NVDLA small版本的踪迹测试，用于在裸机环境下运行。

## 使用
1. 按照NVDLA官方文档生成hw vmod，从outdir/拷贝opendla.py到data目录。
2. 从hw的verif/拷贝到
3. 运行scripts\convert_dat_2_arrays.py生成数据数组相关代码。
4. 运行scripts\nvdla_registers.py生成寄存器定义相关代码。
5. 将所有.h和.c以及nv_small目录拷贝到工程目录，编译运行。
