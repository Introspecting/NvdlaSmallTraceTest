#ifndef NVDLA_VERIF_HEADER
#define NVDLA_VERIF_HEADER

struct mem_payload
{
	unsigned int offset;
	unsigned int size;
	unsigned char payload[8];
};

enum MEM_FILL_TYPE
{
    ALL_ZERO
};

int reg_write(unsigned int *reg_addr, unsigned int value);

int intr_notify(int module, int sync_id);

int check_crc(int sync_id, int mem_type, unsigned int base_addr, unsigned int size, unsigned int expected);

int mem_init(int mem_type, unsigned int base_addr, unsigned int size, enum MEM_FILL_TYPE fill_type);

int mem_load(int mem_type, unsigned int base_addr, const char *dat_key);

int poll_reg_equal(unsigned int *reg_addr,unsigned int expected_value);


#endif
