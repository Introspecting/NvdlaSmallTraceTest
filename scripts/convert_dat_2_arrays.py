import os
import re

# 需要的参数
# nvdla_version
# 数据文件的目录

def brace_payload(matched):
    return "payload:{ " + matched.group(1).replace(' ', ',') + " }"

file_list = []

nvdla_version = "nv_small_256"

print("Current Directory: "+ os.path.abspath("."))

# 当前目录(指项目目录，VS Code打开时会用此目录作为当前目录)下data应该存在nvdla的踪迹测试
for current, dirs, files in os.walk(os.path.join("data", nvdla_version)):
    file_list.extend([*map(lambda name: os.path.join(current, name), files)])

assert len(file_list) > 0, "文件列表为空，当前目录应该存在nvdla的踪迹测试！"

generated_c_file = open("mem_dat.generated.c", "w+")

for name in file_list:
    if (name.endswith(".dat")):
        # 获取上一级目录和文件不带后缀的名称
        parent_dir,base_name = os.path.split(name)
        parent_base_name = os.path.basename(parent_dir)
        name_without_suffix,suffix = os.path.splitext(base_name)

        file = open(name, 'r+')
        content = file.read()
        file.close();
        
        write_file = open(name + ".c.generated", "w+")
        replace_content=re.sub(r'payload:((?:0[xX][0-9a-fA-F]{2}\s?)+(?=}))', brace_payload, content)
        
        write_file.write(f'static const struct mem_payload {parent_base_name}_{name_without_suffix}[] = \n' + replace_content + ';\n')
        write_file.close();
    
        generated_c_file.write(
        f'#ifdef {parent_base_name} \n\n'
        f'#include "./{nvdla_version}/{parent_base_name}/{base_name}.c.generated" \n\n'

        f'    if (strcmp(dat_key, "{base_name}") == 0)\n'
        f'    {{\n'
        f'        length  = sizeof({parent_base_name}_{name_without_suffix}) / sizeof(struct mem_payload); \n'
        f'        mem_bulk = {parent_base_name}_{name_without_suffix}; \n'
        f'    }} \n'
        f'#endif\n\n'
        )

generated_c_file.close()
