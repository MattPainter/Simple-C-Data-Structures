Node** initialise_hash_table();
void hashAddString(Node**, char*); 
void hashRemoveString(Node**, char*);
int hashIsHashed(Node**, char*);
void hashRemoveHash(Node**, unsigned long);
int hashClearTable(Node** table);
unsigned long hashString(unsigned char*);
unsigned long hashGetHashModK(unsigned char*, long);			
void testPrintRandomStringAndHash(); 
void testPrintRandomHashedStrings();