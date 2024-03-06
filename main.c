#include <stdio.h>
#include <stdlib.h>

int handle_terminal_input(int argc,char *argv[]);
void handle_file(char *arg);
int main(int argc,char *argv[]) {
    printf("hello pre assmble test ");
    handle_terminal_input(argc,argv);
        /*
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

}