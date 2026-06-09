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
    a[0].n=0; // @@ [This line is unnecessary and misleading; a[0].n will be overwritten later, but more critically, the array 'a' is not initialized properly for all elements, though this alone may not cause compilation error. However, the real issue lies elsewhere.]
    FILE *fp=fopen("article.txt","r");
    
    char c;
    char s[20]="\0";
    j=0;
    
    while(fscanf(fp,"%c",&c)!=EOF){ // @@ [fscanf returns the number of successfully read items, not EOF directly in the way used here. When fscanf fails (e.g., at EOF), it returns EOF, but comparing !=EOF is technically okay. However, the bigger issue: 'c' is declared as char, but fgetc/fscanf with %c reads into char, yet EOF is an int outside char range. This can cause infinite loop or undefined behavior, but not a compilation error. Still, not the cause of compilation failure.]
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
    r[0]=a[0]; // @@ [If the input file is empty or no words were read, j remains 0, so accessing a[0] is invalid. But again, this is runtime, not compilation.]
    for(i=1;i<j;i++){
        if(strcmp(a[i].str,r[k].str)==0){
            r[k].n++;
        }
        else{
            r[k+1]=a[i];
            k++;
        }
    }
    for(i=0;i<k;i++){ // @@ [Loop runs from 0 to k-1, but after processing, the last group is stored at index k, so it should be i<=k. This causes missing last word in output, but not compilation error.]
        printf("%s %d\n",r[i].str,r[i].n);
    }
}