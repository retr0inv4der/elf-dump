#ifndef ELF_FILE_H 
#define ELF_FILE_H 

#include <stdio.h>
#include <stdbool.h>

FILE* elf_file_open(const char* path);
bool elf_file_read_at(FILE* file , long offset , void * buffer , size_t size ) ;
bool elf_file_close(FILE* file);



#endif