#include <stdio.h>
#include <errno.h>
#include <unistd.h>


int main(int argc , char* argv[]){
    if (argc <1 ){
        printf("Usage : elfread [file string]\n");
        return -1 ; 
    }

    FILE* file = fopen(argv[1] , "rb") ; 
    if(file == NULL ){
        perror("fopen"); 
        return -1 ;
    }
    //analysis part
    
    //seek to the 0x10 for extracting type
    if(fseek(file , 0x10 , SEEK_SET)  != 0  ){
        perror("fseek") ;
        return -1 ;
    }

    char buffer[2] ; 
    if(fread(buffer , 1 , sizeof(buffer) , file) == 0) {
        perror("fread");
        return -1 ;
    }
    
    for(int i = 0 ; i<1 ; i++){
        printf("%d" , (unsigned int)buffer[i]);
    }
    printf("\n");
    


    fclose(file); 
}