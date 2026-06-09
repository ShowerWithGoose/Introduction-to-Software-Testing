#include<stdio.h>
char number[105];
int main(){
    gets(number);
    int i,interger,point,tailer,pow,sign,cnt=0;
    for(i=0;number[i];i++){
        if(number[i]=='.'){
            point=i;
            break;
        }
    }
    if(number[0]=='0'){
        pow=-1;
        sign=0;
        for(i=point+1;number[i];i++){
            sign+=number[i]-'0';
            if(sign){
                interger=number[i]-'0';
                tailer=i+1;
                i++;
                break;
            } else
            pow--;
        }
        for(i;number[i];i++){
            cnt++;
        }
    } else{
        interger=number[0]-'0';
        pow=0;
        sign=0;
        for (i=1;number[i];i++)
        {
            if(number[i]!='.')
                cnt++;
            else
                sign=1;
            if(!sign){
                pow++;
            }
        }
        if(cnt)
        tailer=1;
    }
    printf("%d",interger);
    if(cnt){
        printf(".");
        for(i=tailer;number[i];i++){
            if(number[i]!='.')
            printf("%c",number[i]);
        }
    }
    printf("e%d\n",pow);
    return 0;
}


