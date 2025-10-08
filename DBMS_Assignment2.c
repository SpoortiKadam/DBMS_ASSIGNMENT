
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    int roll;
    char name[20];
};

struct index{
    int roll;
    long pos;
};

int main()
{
    FILE *datafile,*indexfile;
    struct Student s;
    struct index idx;

    datafile=fopen("Student.dat","wb+");
    indexfile=fopen("index.dat","wb+");

    if(!datafile||!indexfile){
        perror("File open failed");
        exit(-1);
    }

    int num;
    printf("Enter the number of enteries: ");
    scanf("%d",&num);

    for(int i=0;i<num;i++){
        printf("Enter Roll number and Name : ");
        scanf("%d %s",&s.roll,s.name);
        long pos=ftell(datafile);
        fwrite(&s,sizeof(s),1,datafile);
        idx.roll=s.roll;
        idx.pos=pos;
        fwrite(&idx,sizeof(idx),1,indexfile);
    }

    fclose(datafile);
    fclose(indexfile);

    datafile=fopen("Stdent.dat","rb");
    indexfile=fopen("index.dat","rb");

    int searchroll;
    printf("\nEnter the roll number to search: ");
    scanf("%d",&searchroll);

    while(fread(&idx,sizeof(idx),1,indexfile)){
        if(idx.roll==searchroll){
            fseek(datafile,idx.pos,SEEK_SET);
            fread(&s,sizeof(s),1,datafile);
            printf("Record found:\n Roll number=%d\n Name=%s\n",s.roll,s.name);
            fclose(datafile);
            fclose(indexfile);
            return 0;
        }
    }

    printf("Records not found!....");
    fclose(datafile);
    fclose(indexfile);
    return 0;
}