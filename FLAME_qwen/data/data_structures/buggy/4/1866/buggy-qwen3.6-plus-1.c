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
        for(int i=0;i<sum-1;i++){   // @@ C89 standard does not allow variable declaration inside for-loop initialization; causes compilation error in strict C89 mode.
            if(strcmp(*(s+i),*(s+i+1))>0){
                flag=1;
                swap(*(s+i),*(s+i+1)); // @@ Logical error: swap function only exchanges the first character of the two strings, not the entire strings. Need to swap full arrays or use strcpy.
                swapint(time+i,time+i+1);
            }
        }
    }
}


int main(){
    FILE *file=fopen("article.txt","r");
    char word[114][20]={'\0'};
    char s[114][20]={'\0'};
    char c; // @@ Semantic error: fgetc returns int and EOF is typically -1. Using char may cause infinite loop if char is unsigned. Should be int c.
    int time[114]={0};
    int sum=0,flag=0,m=0,n=0;
    while((c=fgetc(file))!=EOF){
        if(c>=97&&c<=122) s[m][n++]=c;
        else if(c>=65&&c<=90) s[m][n++]=c+32;
        else if(n!=0){
            if(s[m][n-1]>=97&&s[m][n-1]<=122){
                m++;
                n=0;
            }
        }
        else continue;
    }


    for(int j=0;j<m;j++){ // @@ C89 standard does not allow variable declaration inside for-loop initialization.
        for(int i=0;i<sum;i++){ // @@ C89 standard does not allow variable declaration inside for-loop initialization.
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