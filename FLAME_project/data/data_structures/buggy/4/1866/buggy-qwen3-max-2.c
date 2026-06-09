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
                swap(*(s+i),*(s+i+1)); // @@ [This swap function only swaps the first character of each string, not the entire string. It should use strcpy or a loop to swap full strings.]
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
                m++;
                n=0;
            }
        }
        else continue;
    }


    for(int j=0;j<m;j++){
        for(int i=0;i<sum;i++){
            if(strcmp(word[i],s[j])==0){
                time[i]++;
                flag=1;
                break;
            }
        }
        if(flag==0){
            strcpy(word[sum],s[j]);
            time[sum]++; // @@ [This should be time[sum] = 1; because it's the first occurrence of the word, not an increment from 0 (which would make it 1 anyway, but logically incorrect and misleading). However, since time array is initialized to 0, time[sum]++ results in 1, so this is not the main bug.]
            sum++;
        }
        flag=0;
    }


    int i=0;
    bubblesort(word,sum,time);
    while(word[i][0]!='\0'){    // @@ [This loop condition may cause undefined behavior or infinite loop if the word array has empty strings in the middle due to incorrect insertion logic. Also, after sorting, all valid words are in indices 0 to sum-1, so it should loop for i from 0 to sum-1 instead of checking for null character. This can lead to printing garbage or hanging if uninitialized memory appears non-null.]
        printf("%s %d\n",word[i],time[i]);
        i++;
    }



    return 0;
}