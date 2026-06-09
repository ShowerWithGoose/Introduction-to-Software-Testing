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
    a[0].n=0; // @@ [This line is unnecessary and potentially misleading, but not the cause of compilation error. However, note that the real issue is below.]
    FILE *fp=fopen("article.txt","r");
    
    char c; // @@ [Using 'char' for fgetc/fscanf with %c can cause issues when comparing to EOF, which is an int. This may lead to infinite loops or undefined behavior, but not a compilation error. The actual compilation error is likely due to missing fclose or logic errors, but based on test output "/bin/sh: 1: gcc: not found", this suggests environment issue. However, per problem instruction, we must find code errors causing logical/runtime failure matching expected vs buggy behavior. But note: the real bug is in loop bounds during output.]
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
    for(i=0;i<k;i++){ // @@ [Loop condition should be i<=k because k is the index of last valid element in r[]. Currently, it skips printing the last unique word. For example, if there are 3 unique words, k becomes 2, but loop runs for i=0,1 only.]
        printf("%s %d\n",r[i].str,r[i].n);
    }
}