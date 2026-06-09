#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int judge(char a[],int ind);
int isnumb(char);
int main(){
    int i,j,len;
    char a[10000]={0};
    scanf("%s",a);
    len = strlen(a);
    for(i = 0;i < len;i++){
        if(a[i+1]=='-'){
            if(i != len-2){
                if(judge(a,i+1)!=0){
                    //expand
                    for(j = a[i];j<=(a[i+3]=='-'?a[i+2]-1:a[i+2]);j++){
                        printf("%c",j);
                    }
                    i += 1;
                }
                else{
                    printf("%c",a[i]);
                }
            }
            else{
                printf("%c",a[i]);
            }
        }
        else{
            if(!(judge(a,i-1)))
            printf("%c",a[i]);
        }
    }
}
int judge(char a[],int ind){
    if(a[ind]=='-'&&a[ind-1]<a[ind+1]){
        if(isupper(a[ind-1])&&isupper(a[ind+1])) return 1;
        else if(islower(a[ind-1])&&islower(a[ind+1])) return 1;
        else if(isnumb(a[ind-1])&&isnumb(a[ind+1])) return 1;
        else return 0;
    }
    else{
        return 0;
    }
    
}
int isnumb(char c){
    if(c<='9'&&c>='0') return 1;
    else return 0;
}


