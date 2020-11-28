#define READ 1
#define WRITE 2

void system_bus(int address, int *value, int control);
void dump_memory(int start_address, int num_bytes);
void load_memory(char *filename);
