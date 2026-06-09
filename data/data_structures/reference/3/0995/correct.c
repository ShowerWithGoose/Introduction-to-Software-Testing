#include <stdio.h>
#include <string.h>
int main()
{
    char ori[105],alt[105];
    gets(ori);
    int i,sign,exp,j=2;
    if(ori[0]=='0'){
        sign=-1;
        for(i=2;!(ori[i]-48);i++);
        ori[0]=ori[i];
        for(j=2;ori[i+1];i++,j++){
            ori[j]=ori[i+1];
        }
        exp=i+1-j;
        ori[j]='\0';
        if(ori[j-1]=='.'){
            ori[j-1]='\0';
        }
    }else{
        sign=1;
        for(i=0;ori[i];i++){
            if(ori[i]=='.'){
                exp=i-1;
                for(j=i;j>1;j--){
                    ori[j]=ori[j-1];
                }
                ori[1]='.';
                break;
            }
        }
    }
    fputs(ori,stdout);
    printf("e%d",sign*exp);
    return 0;
}
