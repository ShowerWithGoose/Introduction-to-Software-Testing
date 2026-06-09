#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000

int i,j,k=0;

typedef struct word{
    char str[20];
    int n;
}word;


int main(){
    word a[max];
    a[0].n=0;
    FILE *fp=fopen("article.txt","r");
    
    char c;
    char s[20]="\0";
    j=0;
    
    while(fscanf(fp,"%c",&c)!=EOF){
        if(c>='A'&&c<='Z')
            c+=32;
        if(c>='a'&&c<='z'){
            s[k]=c;
            k++;
        }
        else if(k==0)
            continue;
        else {
            for(i=0;i<k;i++){
                a[j].str[i]=s[i];
            }
            a[j].n=1;
            a[j].str[k]='\0';
            j++;
            k=0;
        }
    }
    
    for(i=0;i<j-1;i++){
        for(k=0;k<j-i-1;k++){
            if(strcmp(a[k].str,a[k+1].str)>0){
                word temp=a[k];
                a[k]=a[k+1];
                a[k+1]=temp;
            }
        }
    }
    
    word r[max];
    k=0;
    r[0]=a[0];
    for(i=1;i<j;i++){
        if(strcmp(a[i].str,r[k].str)==0){
            r[k].n++;
        }
        else{
            r[k+1]=a[i];
            k++;
        }
    }
    for(i=0;i<k;i++){ // @@ 输出循环边界错误，应改为 i <= k 以打印最后一个单词
        printf("%s %d\n",r[i].str,r[i].n);
    }
}