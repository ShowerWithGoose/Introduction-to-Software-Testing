#include <stdio.h>
#include <string.h>
char s[100];

int op1(int i){
    int sum=0;
    for(;s[i]!='\0';i++){
        if(s[i]>='0'&&s[i]<='9'){
            sum+=s[i]-'0';
        }
    }
    return sum;
}

void op(void){
    int point=0,p2,sum,i,flag=0,flag1=0,l=strlen(s);
    if(s[1]=='.'&&s[0]!='0'){
        printf("%c.",s[0]);
        for(i=2;i<l;i++){
            if(s[i]>'0'&&s[i]<='9'){
                printf("%c",s[i]);
            }
            else if(s[i]=='0'){
                sum=op1(i);
                if (sum!=0){
                   printf("0");
                }
                else break;
            }
        }
        printf("e0");
        return ;
    }
    for(i=0;i<l;i++){
        if(s[i]=='.') {
            point=i;
            break;
        }
    }
    for(i=0;i<l;i++){
        if(!flag){
            if(s[i]>'0'&&s[i]<='9'){
            printf("%c",s[i]);
            p2=i;
            flag=1;
            }
        } 
        else {
            if(s[i]>'0'&&s[i]<='9'){
                if(flag1)
                printf("%c",s[i]);
                else {
                    printf(".%c",s[i]);
                    flag1=1;
                }
            }
            else if(s[i]=='0'){
                sum=op1(i);
                if(!flag1){
                    if(sum!=0)
                    {
                        printf(".0");
                        flag1=1;
                    }
                }
                else{
                    
                    if (sum!=0){
                        printf("0");
                    }
                    else break;
                }
            }
        }
    }
    if(s[1]!='.') printf("e%d",point-p2-1);
    else 
    printf("e%d",point-p2);
} 

int main()
{
    scanf("%s",s);
    op();
    return 0;
}
