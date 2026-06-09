#include<stdio.h>
#include<string.h>
char in[10000];
char inn[10000];

int main(void){
    gets(in);
    char * point=NULL;
    int j=0;
    for(int i=0;in[i];i++){
        if(in[i]=='.')point=&in[i];
        else inn[j++]=in[i];
    }
    while(inn[--j]=='0');
    inn[j+1]=0;
    int n=point-in-1;
    if(in[0]=='0'){
        for(int i=0;inn[i];i++){
            if(inn[i]!='0'){
                n=&inn[i]-inn;
                point=&inn[i];
                break;
            }
        }
        putchar(point[0]);
        if(point[1])putchar('.');
        for(int i=1;point[i];i++)putchar(point[i]);
        printf("e-%d",n);
        return 0;
    }
    if(n==0){
        printf("%se0",in);
        return 0;
    }
    printf("%c.%se%d",inn[0],inn+1,n);
    return 0;
    
}


