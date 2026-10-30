#include "elf_file.h"
#include <errno.h>
FILE* elf_file_open(const char* path){
    FILE * file = fopen(path , "rb") ; 
    if(file == NULL){
        perror("fopen") ; 
        return NULL ;
        
    }
    return file ; 
}


bool elf_file_read_at(FILE* file , long offset , void * buffer , size_t size ) {
    if(fseek(file , offset ,size  ) != 0){
        perror("fseek");
        return false; 
    }
    size_t ret = fread(buffer ,1 , size , file)  ;
    if(ret != size){
        if(ferror(file)){
            perror("fopen") ;
        }else if(feof(file)){
            fprintf(stderr , "unexpected end of file.\n"); 
        }
        return false ;
    }

    return true; 


}

bool elf_file_close(FILE* file){
    if(fclose(file)!= 0){
        perror("fclose");
        return false; 
    } 
    return true; 
}