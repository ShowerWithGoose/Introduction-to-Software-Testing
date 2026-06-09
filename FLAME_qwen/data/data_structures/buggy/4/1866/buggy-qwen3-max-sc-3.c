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
                swap(*(s+i),*(s+i+1)); // @@ [The swap function expects two char pointers, but *(s+i) and *(s+i+1) are arrays (char[20]), which decay to char*, so this is actually okay syntactically. However, the real issue is that 'swap' swaps only the first character of each string, not the entire string. This leads to incorrect sorting.]
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
    while((c=fgetc(file))!=EOF){ // @@ [The variable 'c' is declared as char, but fgetc returns int. When EOF (which is -1) is stored in a char, it may become indistinguishable from a valid character (e.g., 0xFF on systems where char is signed). This can cause premature termination or infinite loops.]
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
            time[sum]++; // @@ [time[sum] is uninitialized; it should be set to 1, not incremented. Since time array is initialized to zero globally/statically, this might work by accident, but logically it's wrong: it should be time[sum] = 1;]
            sum++;
        }
        flag=0;
    }


    int i=0;
    bubblesort(word,sum,time);
    while(word[i][0]!='\0'){    // @@ [This loop assumes that all entries up to the first empty string are valid, but after sorting, empty strings (if any) might appear in the middle or beginning. Also, 'sum' is the actual count, so loop should be for(i=0; i<sum; i++). This may print garbage or stop early.]
        printf("%s %d\n",word[i],time[i]);
        i++;
    }



    return 0;
}