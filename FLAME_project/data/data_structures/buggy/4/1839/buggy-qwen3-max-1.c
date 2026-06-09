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
    
    if(k>0) { // @@ [After EOF, if there's still a word in buffer s (k>0), it needs to be added to array a. The original code misses the last word if file doesn't end with non-letter.]
        for(i=0;i<k;i++){
            a[j].str[i]=s[i];
        }
        a[j].n=1;
        a[j].str[k]='\0';
        j++;
        k=0;
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
            r[k].n++; // @@ [When merging duplicates, initial count in r[k] is 1 (from a[i]), so incrementing gives correct total. However, this logic assumes r[k] was initialized with count 1, which is true, but the loop below prints only up to index k-1, missing the last group.]
        }
        else{
            r[k+1]=a[i];
            k++;
        }
    }
    for(i=0;i<=k;i++){ // @@ [The loop condition should be i <= k because k is the index of the last valid element in r. Original condition i < k skips the last unique word group.]
        printf("%s %d\n",r[i].str,r[i].n);
    }
}