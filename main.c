#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct config{
    char user[100];
    char email[100];
}con;

void init();
void config(int num,char* input[]);

int main(int argc,char* argv[]){

    if(strcmp(argv[1],"init")==0){init();}
    if(strcmp(argv[1],"config")==0){config(argc,argv);}
    if(strcmp(argv[1],"add")==0){}

}

void init(){
    system("init.bat");
}

void config(int num,char* input[]){

    con* config=(con*)malloc(sizeof(con));
//    config->user[0]=0;
//    config->email[0]=0;

    printf("config: %s %s",config->user,config->email);

    FILE* file_config_read=fopen(".pey/config.txt","r");
    FILE* file_config_write=fopen(".pey/config.txt","w");

    if(num==4){
        if(strcmp(input[2],"user.name")==0){
            strcpy(config->user,input[3]);
        }
        else if(strcmp(input[2],"user.email")==0){
            strcpy(config->email,input[3]);
        }

    fprintf(file_config_write,"user: %s\nemail: %s",config->user,config->email);
    }
}

