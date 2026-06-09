#include<stdio.h>
#include<string.h>

char num[1000];
int i,l,flag=0,l2,l3;

int main(){
    l2=0,l3=1;
    gets(num);
    l=strlen(num);
    for(i=0;i<l;i++){
        if(flag==0){
            if(num[i]!='.'){
                l2++;
            }
            else flag=1;
        }
        else{
            if(num[0]=='0'){
                if(num[i]=='0')l3++;
                else {
                    printf("%c",num[i]);
                    if(i+1<l)printf(".");
                    for(i++;i<l;i++){
                        printf("%c",num[i]);
                    }
                    printf("e-%d",l3);
                    return 0;
                }
            }
            else if(i==l-1){
                printf("%c",num[0]);
                printf(".");
                i=1;
                while(i<l2){
                    printf("%c",num[i]);
                    i++;
                }
                
                for(i++;i<l;i++){
                    printf("%c",num[i]);
                }
                printf("e%d\n",l2-1);
                return 0;
            }
        }
    }
    return 0;
}
