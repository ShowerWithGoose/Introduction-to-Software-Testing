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
    a[0].n=0; // @@ [This line is unnecessary and potentially misleading, but not the cause of compilation error. However, the real issue is that the file may be empty or contain no valid words, leading to j=0, which causes out-of-bound access later. But more critically, the program does not handle the case when the last word in file is not followed by a non-letter character, so it may miss the final word. However, the reported error is "gcc: not found", which is NOT a compilation error in the code but an environment issue. But assuming the actual runtime/logic errors are to be marked as per problem context...]
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
    
    for(i=0;i<j-1;i++){ // @@ [If j is 0 (no words read), then j-1 is -1, and loop condition becomes i < -1, which for unsigned comparison may cause issues, but more critically, if j==0, the following loops access a[0] which was never properly initialized as a word (only a[0].n=0 was set, but str is uninitialized). Also, if the file ends without a non-letter after the last word, that word is never added to array a.]
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
    r[0]=a[0]; // @@ [If j == 0 (no words processed), then a[0] is used but was never filled with a valid word (only a[0].n was set to 0 at start, and str is uninitialized). This leads to undefined behavior. Also, if j >= 1, this is okay, but if j==0, this is invalid. Additionally, the final word in the file might be missing if not terminated by non-letter.]
    for(i=1;i<j;i++){
        if(strcmp(a[i].str,r[k].str)==0){
            r[k].n++;
        }
        else{
            r[k+1]=a[i];
            k++;
        }
    }
    for(i=0;i<k;i++){ // @@ [Loop runs from 0 to k-1, but there are k+1 unique words (indices 0..k). So the last word (at index k) is never printed. Should be i<=k or loop condition i <= k. This causes missing output for the last unique word.]
        printf("%s %d\n",r[i].str,r[i].n);
    }
}