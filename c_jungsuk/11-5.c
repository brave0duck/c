#include <stdio.h>

typedef struct student{
    int no;
    char name[10];
    int kor;
    int math;
    int eng;
    int totalScore;
    float average;
} Student;

int main(void){
    FILE* fp;
    char* fname = "score.txt";
    int i;
    Student* sp;

    char* format = "%2d %-10s %3d %3d %3d\n";

    Student sArr[]={
        {1,"ABC",100,100,100},
        {2,"ABCD",90,90,90},
        {3,"JKL",80,80,80},
        {4,"AAAA",70,70,70},
    };
    const int LEN =  sizeof(sArr) / sizeof(Student);

    if((fp = fopen(fname,"w")) ==NULL){
        printf("can't open file[%s]\n", fname);
        return 1;
    }

    for(i=0; i<LEN; i++){
        sp = &sArr[i];

        fprintf(fp, format, sp->no, sp->name, sp->kor, sp->math, sp->eng);
        fprintf(stdout, format, sp->no, sp->name, sp->kor, sp->math, sp->eng);
    }

    fclose(fp);

    return 0;
}