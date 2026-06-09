#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
    char s[500];
    char b[1000][500],c[1000][50];
    int n=0,x=0,i,j;
    FILE *in;
    in=fopen("article.txt","r");
    while(fgets(s,500,in)!=NULL){
        strcpy(b[n],s);
        n++;
    }
    /*while(gets(s)!=NULL){
        strcpy(b[n],s);
        n++;
    }*/
    for(i=0;i<n;i++){
        for(j=0;b[i][j]!='\0';j++){
            if('a'<=tolower(b[i][j])&&tolower(b[i][j])<='z'){
                c[x][strlen(c[x])]=tolower(b[i][j]);
                if('a'>tolower(b[i][j+1])||tolower(b[i][j+1])>'z'){
                    x++;
                }
            }
        }
    }
    //printf("%d %d",x,n);
    int a[1000];
    for(i=0;i<x;i++){
        a[i]=1;
    }
    for(i=0;i<x-1;i++){
        for(j=i+1;j<x;j++){
            if(strcmp(c[i],c[j])>0){
                strcpy(s,c[i]);
                strcpy(c[i],c[j]);
                strcpy(c[j],s);
                n=a[i];
                a[i]=a[j];
                a[j]=n;
            }
            if(strcmp(c[i],c[j])==0){
                a[i]+=a[j];
                a[j]=0;
            }
        }
    }
    for(i=0;i<x;i++){
        if(a[i]==0){
            continue;
        }
        else{
            printf("%s %d\n",c[i],a[i]);
        }
    }
	return 0;
}

