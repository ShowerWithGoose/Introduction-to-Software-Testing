//
//  main.c
//  text  2
//
//  Created by  on 2021/11/5.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char *argv[])
{char s1[500],ans[100];
    struct node{
    char s[100];
    int n;
};
    int p=0,flag,hold;
  struct node a[100];
    FILE *f1;
    f1=fopen("article.txt","r");
    while(fgets(s1,500,f1)!=NULL){
        int i=0,k=0;
        while(s1[i]!='\0'){
            if((s1[i]>='A'&&s1[i]<='Z')||(s1[i]>='a'&&s1[i]<='z'))
                ans[k++]=islower(s1[i])?s1[i]:s1[i]-'A'+'a';
            else {
                if(k==0){i++;continue;}
                ans[k]='\0';k=0;
                hold=0;
                for(int j=0;j<p;j++){
                    flag=strcmp(a[j].s,ans);
                    if(flag==0){
                        a[j].n++;hold=1;break;}
                }
                if(hold==0){strcpy(a[p].s,ans);a[p].n=1;p++;}
            }
            i++;
        }
    }
    for(int j=0;j<p-1;j++){
        for( int k=0;k<p-1-j;k++ ){
            hold=strcmp(a[k].s,a[k+1].s);
            if(hold>0){
                strcpy(ans,a[k].s);strcpy(a[k].s,a[k+1].s);
                strcpy(a[k+1].s,ans);
                flag=a[k].n;a[k].n=a[k+1].n;a[k+1].n=flag;
            }
        }
    }
    for(int j=0;j<p;j++)
        printf("%s %d\n",a[j].s,a[j].n);
    
  return 0;
}


