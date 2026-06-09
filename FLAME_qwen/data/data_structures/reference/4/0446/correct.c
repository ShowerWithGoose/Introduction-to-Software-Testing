#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    FILE*fin;
    fin=fopen("article.txt","r");
    int i,n=0,k,n1=0,j=0,l,cishu[200],flag[200],n2=0,temp1,cishu2[200];
    char c,zidian[200][20],zidian2[200][20],temp[20];
    c=fgetc(fin);
    for(i=0;i<200;i++){
        flag[i]=1;
        cishu[i]=1;
        cishu2[i]=1;
    }
    while(c!=EOF){
        if(isalpha(c)){
            zidian[n][n1]=c;
            n1++;
        }
        else if(ispunct(c) || isspace(c)){
                zidian[n][n1]='\0';
            n1=0;
            n++;
        }
        c=fgetc(fin);

    }
    for(i=0;i<n;i++){
        for(j=0;j<strlen(zidian[i]);j++){
            zidian[i][j]=tolower(zidian[i][j]);
        }
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(!strcmp(zidian[i],zidian[j])&&flag[j]==1){
                cishu[i]+=1;
                flag[j]=0;
            }
        }
    }

    for(i=0;i<n;i++){
        if(flag[i]==1){
            for(j=0;j<strlen(zidian[i]);j++){
                zidian2[n2][j]=zidian[i][j];
                cishu2[n2]=cishu[i];
            }
            n2++;
        }}

    for(i=0;i<n2;i++){
        for(j=i+1;j<n2;j++){
            if(strcmp(zidian2[i],zidian2[j])>0){
                strcpy(temp,zidian2[j]);
                strcpy(zidian2[j],zidian2[i]);
                strcpy(zidian2[i],temp);
                temp1=cishu2[i];
                cishu2[i]=cishu2[j];
                cishu2[j]=temp1;
            }
        }
    }
        for(i=1;i<n2;i++){
        printf("%s %d\n",zidian2[i],cishu2[i]);
    }






  fclose(fin);


return 0;}



