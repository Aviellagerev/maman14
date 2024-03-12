#include <stdio.h>
#include <stdlib.h>
#include "preambley.h"
#include "test.c"
#include "table.c"
#define SRC_FILE_EXTENTION ".as"

int handle_terminal_input(int argc,char *argv[]);
void handle_file(char *arg);
int main(int argc,char *argv[]) {
    printf("hello pre assmble test \n");

    handle_terminal_input(argc,argv);
        /*
         *
         * need to make states for stuff inside the hash table(macro for starters and what is insize said macro)
         *
         * need to add hash table to figure out how to store the macros
         * efines (A R E all the r1,r2 exc)
         * after that finish the pre proccesor
         * add error and library file
         * preplan the project
         * ask gemini ai and preplan the project better
         * kill me
         * */
    return 0;
}
int handle_terminal_input(int argc,char *argv[]){
    int file_counter = argc-1;
    int i=1;
    if(file_counter<1){
        fprintf(stderr,"need a file to start mny guy");      /*random msg that will change */
        exit(1);
    }
    while(--argc){
        handle_file(argv[i]);
        i++;
    }

}
void handle_file(char *arg){
    FILE  *src = NULL,*target = NULL;
    char *file_name = (char *)calloc(strlen(arg)+4,sizeof(char *));
    strncpy( file_name , arg , strlen(arg));
    strcat(file_name,SRC_FILE_EXTENTION);
    if((src = fopen(file_name,"r"))==NULL){
        fprintf(stderr,"EL PROBLEM SIR IN SRC");
        free(file_name);
        return;
    }
    file_name[strlen(file_name)-1]='m';/*change file extention to am*/
    if((target = fopen(file_name,"w+"))==NULL){
        fprintf(stderr,"EL PROBLEM SIR IN TARGET");
        free(file_name);
        return;
    }
    else{
        initTables();

    }





}