#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]){

    FILE *inFilePtr;
    FILE *outFilePtr;
    char c;

    if(argc != 3){
        puts("Usage: mycopy infile outfile");
    } else{
        if((inFilePtr = fopen(argv[1], "r")) != NULL){
            if((outFilePtr = fopen(argv[2], "w")) != NULL){
                while ((c = fgetc(inFilePtr))!=EOF){
                    fputc(toupper(c), outFilePtr);
                }
                fclose(outFilePtr);
            } else{
                printf("File cannot be opened");
            }
            fclose(inFilePtr);
        } else{
            printf("File cannot be opened");
        }
    }

}