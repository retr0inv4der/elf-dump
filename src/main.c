#include "elf_file.h"
#include "elf_parser.h"

int main(int argc , char* argv[]){
    
    Elf32_Ehdr header32 ; 
    Elf64_Ehdr header64 ;

    load_header("testfile" , &header64) ;
    uint8_t arch = header64.e_ident[EI_CLASS] ; 
    if(arch == 1 ){
        printf("architecture:32-bit\n" ) ;
    }else if(arch ==2 ) { 
        printf("architecture:64-bit\n") ; 
    }
    
    return 0;
}