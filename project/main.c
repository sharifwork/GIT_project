#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

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

    FILE* file_config_read=fopen(".pey/config.txt","r");
    FILE* file_config_write=fopen(".pey/config.txt","a");

    if(num==4){
        if(strcmp(input[2],"user.name")==0){
            char line[1000];
            while(fgets(line,sizeof(line),file_config_read)!=NULL){
                if(strstr(line,"user:")!=NULL)
                    fprintf(file_config_write," %s",input[3]);
            }
        }
        else if(strcmp(input[2],"user.email")==0){
            char line[1000];
            while(fgets(line,sizeof(line),file_config_read)!=NULL){
                if(strstr(line,"email:")!=NULL)
                    fprintf(file_config_write," %s",input[3]);
            }
        }
    }
}

