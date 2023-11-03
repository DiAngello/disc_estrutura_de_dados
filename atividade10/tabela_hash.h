typedef struct {
    char* chave;
    char* dado;
} Registro;

void initialize_hash_table();
void hash_table_put(char* chave, char* dado);
Registro* hash_table_get(char* chave);
int hash_table_contains(char* chave);
void hash_table_remove(char* chave);
void print_hash_table();
void destroy_hash_table();
