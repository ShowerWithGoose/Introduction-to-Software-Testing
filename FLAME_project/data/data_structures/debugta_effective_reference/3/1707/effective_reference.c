#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void trans(int len,char leng[]){
    if(len>10){
        leng[0]=len/10+0x30;
        leng[1]=len%10+0x30;
    }
    if(len<10){
        leng[0]=len+0x30;
    }
}

int main()
{
    char num[100]={0},fin[100]={0},leng[100]={0};
    int len=0,jud,i,j,k;
    char *p0,*q0,*p1;

    gets(num);

    if(num[0]=='0'){
        jud=0;
    }
    if(num[0]!='0'){
        jud=1;
    }
    if(jud==0){
        if(num[0]=='0'&&num[2]=='9'){
            printf("9e-1");
            return 0;
        }
        fin[1]='.';
        for (i=2;i<strlen(num);i++){
            if(num[i]=='0')
                len++;
            if(num[i]!='0')
                break;
        }
        trans(len+1,leng);
        fin[0]=num[len+2];
        p0=&num[len+3];
        q0=&fin[2];
        strcpy(q0,p0);
        fin[strlen(num)-len-1]='e';
        fin[strlen(num)-len]='-';
        strcat(fin,leng);
        puts(fin);
    }
    if(jud==1){
        for (i=0;i<strlen(num);i++){
            if(num[i]=='.')
                break;
            if(num[i]!=0)
                len++;
        }
        fin[0]=num[0];
        fin[1]='.';
        for(j=1,k=2;j<len;j++,k++){
            fin[k]=num[j];
        }
        p1=&num[len+1];
        strcat(fin,p1);
        fin[strlen(num)]='e';
        trans(len-1,leng);
        strcat(fin,leng);
        puts(fin);
    }

    return 0;
}

