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
                swap(*(s+i),*(s+i+1)); // @@ [swap function expects pointers to single characters, but *(s+i) is a char array (char*). This causes undefined behavior as it swaps only the first character of each string.]
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
    while((c=fgetc(file))!=EOF){ // @@ [c should be declared as int, not char, because EOF is outside the range of char. Comparing a char to EOF can cause infinite loops or incorrect behavior on systems where char is unsigned.]
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
            time[sum]++; // @@ [time[sum] is uninitialized; it should be set to 1 for a new word, not incremented from 0.]
            sum++;
        }
        flag=0;
    }


    int i=0;
    bubblesort(word,sum,time);
    while(word[i][0]!='\0'){    // @@ [Loop condition assumes word array is null-terminated beyond valid entries, but word entries beyond 'sum' may contain garbage or zeroed data due to initialization. Should loop only up to 'sum'.]
        printf("%s %d\n",word[i],time[i]);
        i++;
    }



    return 0;
}