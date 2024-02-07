#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

bool is_init();
void init();
void config(int num,char* input[]);
void printf_file_config(char type[],FILE *file_config,char input[]);
void add(char[]);


int main(int argc,char* argv[]){

    if(strcmp(argv[1],"init")==0){init();}
    if(strcmp(argv[1],"config")==0){config(argc,argv);}
    if(strcmp(argv[1],"add")==0){add(argv[2]);}

}

void init(){
    if(is_init()){
        printf("repo exist");
        return ;
    }
    system("init.bat");

    //inser config
    FILE* file_config=fopen(".pey/config.txt","w");
    fprintf(file_config,"####################################\n");
    fclose(file_config);

    //insert config global
    FILE* file_config_global=fopen("C:\\Users\\hossein\\Documents\\GIt_Project\\project\\config_global.txt","w");
    fprintf(file_config_global,"####################################\n");
    fclose(file_config_global);
}

void config(int num,char* input[]){

    if(strcmp(input[2],"-global")==0){
        FILE* file_config_global=fopen("C:\\Users\\hossein\\Documents\\GIt_Project\\project\\config_global.txt","r+");
        printf_file_config(input[3],file_config_global,input[4]);
        fclose(file_config_global);
    }
    else {
        FILE* file_config=fopen(".pey/config.txt","r+");
        printf_file_config(input[2],file_config,input[3]);
        fclose(file_config);
    }

}

void printf_file_config(char type[],FILE *file_config,char input[]){

        if(strcmp(type,"user.name")==0){

            fseek(file_config,0,SEEK_SET);
             fprintf(file_config,"name:%s\0",input);

        }
        else if(strcmp(type,"user.email")==0){
            fseek(file_config,0,SEEK_END);
            fprintf(file_config,"email:%s\0",input);
        }

//    fprintf(file_config_write,"user: %s\nemail: %s",config->user,config->email);
}

void add (char input[]){

    char text[1000]="copy ";
    strcat (text,input);
    strcat (text , " .pey\\stage");
    system(text);
}

bool is_init(){

    DIR *dir;
    struct dirent* ent;

    const char * path ="C:\\Users\\hossein\\Documents\\GIt_Project\\project";

    dir = opendir(path);
    while((ent=readdir(dir))!=NULL){

        if(strcmp(ent->d_name,".pey")==0){
            return true;
        }

    }
    return false;
}

