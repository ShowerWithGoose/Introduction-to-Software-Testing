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
    a[0].n=0; // @@ [This initialization is unnecessary and misleading; a[0] may not be used if file is empty, and it interferes with correct counting logic.]
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
    r[0]=a[0]; // @@ [If the input file is empty (j == 0), this accesses a[0] which was never properly initialized as a valid word, leading to undefined behavior or incorrect output.]
    for(i=1;i<j;i++){
        if(strcmp(a[i].str,r[k].str)==0){
            r[k].n++;
        }
        else{
            r[k+1]=a[i];
            k++;
        }
    }
    for(i=0;i<k;i++){ // @@ [Loop runs from 0 to k-1, but the last unique word stored at index k is never printed. Should be i<=k.]
        printf("%s %d\n",r[i].str,r[i].n);
    }
}