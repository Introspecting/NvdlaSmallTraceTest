from opendla import registers as modules

declaration_file = open("nvdla_registers.h", "w+")

initialization_file = open("nvdla_registers.c", "w+")

declaration_file.write('#ifndef NVDLA_REGISTERS_HEADER \n#define NVDLA_REGISTERS_HEADER \n')

declaration_file.write('#include "common_defines.h"\n\n')


declaration_file.write("#define pri_mem (1) \n")
declaration_file.write("#define PDP_0 (0) \n")
declaration_file.write("#define sync_id_0 (0) \n\n")

declaration_file.write("// NVDLA 各个模块的寄存器地址声明\n")


initialization_file.write('#include "nvdla_registers.h"\n\n')

for module in modules:
    regs_content = ""
    
    for reg in (modules[module]):
        if (reg == "register_list"):
            continue
        regs_content += \
            f'    volatile unsigned int * const {reg}; \n'
    module_template = \
        f'struct {module}_MODULE \n' \
        f'{{ \n' \
        f'{regs_content}' \
        f'}}; \n\n'
    declaration_file.write(module_template)

declaration_file.write("\n// NVDLA 各个模块\n") 

for module in modules:
    declaration_file.write(f'extern struct {module}_MODULE {module}; \n\n');

declaration_file.write("#endif\n")

declaration_file.close()

for module in modules:
    regs_content = ""
    
    for reg in (modules[module]):
        if (reg == "register_list"):
            continue
        regs_content += \
            f'    .{reg} = (unsigned int *)({modules[module][reg]["addr"]:#x} + NVDLA_CSB_BASE_ADDR), \n'
    module_template = \
        f'struct {module}_MODULE {module}  = \n' \
        f'{{ \n' \
        f'{regs_content}' \
        f'}}; \n\n'
    initialization_file.write(module_template)

initialization_file.close()
