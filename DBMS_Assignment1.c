#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int file;
    char buffer[100];
    ssize_t bytesRead;

    file=open("DBMS.txt",O_CREAT|O_RDWR,0644);
    if(file==-1)
    {
        perror("Error in opening the file !....");
        exit(-1);
    }
    printf("File opened successfully \n");

    const char *text="Hello, this is  UNIX system all example .\n";
    write(file,text,strlen(text));
    printf("Data is written in the file !...\n");

    lseek(file,0,SEEK_SET);

    bytesRead=read(file,buffer,sizeof(buffer)-1);
    buffer[bytesRead]='\0';
    printf("Data is read from the file : %s\n",buffer);

    close(file);
    printf("File closed successfully.\n");
    return 0;
}