#ifndef ELF_PARSER_H
#define ELF_PARSER_H

#include <elf.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool load_header(const char* path , void* buffer ); 
bool load_EI_CLASS(FILE* file , uint8_t* out);
bool load_e_type(FILE* file , uint16_t *out) ; // the two extracted bytes will be stored in out. the called must allocated it 
bool load_e_machine(FILE* file , uint16_t *out); 
bool load_e_entry(FILE* file , uint64_t *out, uint8_t machine_arch ); // machine arch must be specified for the function to be able to choose between 64bit or 32bit address mode

#endif