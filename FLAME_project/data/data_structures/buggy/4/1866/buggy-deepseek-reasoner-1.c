#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *s,char *c){
    char temp;
    temp=*s;
    *s=*c;
    *c=temp;
}
void swapint(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(char s[][20],int sum,int *time){
    int flag=1;
    while(flag){
        flag=0;
        for(int i=0;i<sum-1;i++){   
            if(strcmp(*(s+i),*(s+i+1))>0){
                flag=1;
                swap(*(s+i),*(s+i+1)); // @@ Only swaps the first character of each string, not the entire string. Use strcpy with a temporary array to swap whole strings.
                swapint(time+i,time+i+1);
            }
        }
    }
}

int main(){
    FILE *file=fopen("article.txt","r");
    char word[114][20]={'\0'};
    char s[114][20]={'\0'};
    char c;
    int time[114]={0};
    int sum=0,flag=0,m=0,n=0;
    while((c=fgetc(file))!=EOF){
        if(c>=97&&c<=122) s[m][n++]=c;
        else if(c>=65&&c<=90) s[m][n++]=c+32;
        else if(n!=0){
            if(s[m][n-1]>=97&&s[m][n-1]<=122){
                m++; // @@ Missing null terminator for the just‑completed word. Write s[m][n] = '\0' before this line.
                n=0;
            }
        }
        else continue;
    }
    // Missing handling of the last word if the file ends with a letter. Should null‑terminate s[m] and increment m.

    for(int j=0;j<m;j++){ // @@ m may be undercounted because the last word was not added. See missing handling above.
        for(int i=0;i<sum;i++){
            if(strcmp(word[i],s[j])==0){
                time[i]++;
                flag=1;
                break;
            }
        }
        if(flag==0){
            strcpy(word[sum],s[j]);
            time[sum]++;
            sum++;
        }
        flag=0;
    }

    int i=0;
    bubblesort(word,sum,time);
    while(word[i][0]!='\0'){    
        printf("%s %d\n",word[i],time[i]);
        i++;
    }

    return 0;
}