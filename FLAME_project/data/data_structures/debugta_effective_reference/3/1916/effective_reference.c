#include <stdio.h>
#include <string.h>
int main()
{
    char ori[105],alt[105];
    gets(ori);
    int i,sign,cnt,cntn0=2;
    if(ori[0]=='0'){
        sign=-1;
        for(i=2;!(ori[i]-48);i++);
        ori[0]=ori[i];
        for(cntn0=2;ori[i+1];i++,cntn0++){
            ori[cntn0]=ori[i+1];
        }
        cnt=i+1-cntn0;
        ori[cntn0]='\0';
        if(ori[cntn0-1]=='.'){
            ori[cntn0-1]='\0';
        }
    }else{
        sign=1;
        for(i=0;ori[i];i++){
            if(ori[i]=='.'){
                cnt=i-1;
                for(cntn0=i;cntn0>1;cntn0--){
                    ori[cntn0]=ori[cntn0-1];
                }
                ori[1]='.';
                break;
            }
        }
    }
    fputs(ori,stdout);
    printf("e%d",sign*cnt);
    return 0;
}
