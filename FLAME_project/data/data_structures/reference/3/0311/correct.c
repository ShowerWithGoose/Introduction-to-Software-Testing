#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char a[105],b[105];
    gets(a);
    int i,cot=0;
    if(a[0]!='0'){
        int j=2;
        for(i=0;a[i]!='\0';i++){
            if(a[i]!='.')
                cot++;
            else
                break;
        }
        b[0]=a[0];
        b[1]='.';
        for(i=1;a[i]!='\0';i++){
            if(a[i]!='.'){
                b[j]=a[i];
                j++;
            }
        }
        printf("%se%d",b,cot-1);
    }
    else{
        for(i=2;a[i]!='\0';i++){
            if(a[i]=='0')
                cot++;
            else
                break;
        }
        b[0]=a[2+cot];
        if(a[3+cot]=='\0')
            printf("%ce-%d",b[0],cot+1);
        else{
            int j=2;
            b[1]='.';
            for(i=3+cot;a[i]!='\0';i++){
                b[j]=a[i];
                j++;
            }
            printf("%se-%d",b,cot+1);
        }
    }
    return 0;
}



