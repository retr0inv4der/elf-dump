#include "elf_parser.h"
#include "elf_file.h"

#include <string.h>



bool load_header(const char* path , void* buffer ){
    Elf32_Ehdr Elf32_header ; 
    Elf64_Ehdr Elf64_header ;
    uint8_t arch ;

    //open file 
    FILE* file = elf_file_open(path) ; 

    //load program arch 
    load_EI_CLASS(file , &arch) ;


    // 1 -> 32   2 -> 64
    if(arch == 1 ){
        Elf32_header.e_ident[EI_CLASS] = arch; 
        memcpy(buffer , &Elf32_header , sizeof(Elf32_header) );
    }
    else if(arch == 2 ){
        Elf64_header.e_ident[EI_CLASS] = arch; 
        memcpy(buffer , &Elf64_header , sizeof(Elf64_header) );
    }


} 




bool load_EI_CLASS(FILE* file , uint8_t* out){
    if(elf_file_read_at(file , 0x04 , out , 1)==false) return false ;
    return true;
}


bool load_e_type(FILE* file , uint16_t* out) {
    if(elf_file_read_at(file , 0x10 , out , 2)==false) return false ; 
    return true;
}


bool load_e_machine(FILE* file , uint16_t *out){
    if(elf_file_read_at(file , 0x12 , out , 2)==false) return false ;
    return true;
}

