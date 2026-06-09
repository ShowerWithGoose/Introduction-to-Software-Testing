#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    gets(str); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in some environments like newer GCC, 'gets' is removed entirely causing compilation error]
    int len;
    len=strlen(str);
        int i=2;
    if(str[0]=='0'){
        while(1){
            if(str[i]!='0'){
                break;
            }    
            i++;    
        }
        if(i==(len-1)){
            printf("%c",str[i]);
        }
        else{
        printf("%c.",str[i]);
        for(int k=i+1;k<len;k++){
            printf("%c",str[k]);
        }
        }
        int m=i-1;
        printf("e-%d",m);    
    }
    else if(str[0]!=0){ // @@ [Incorrect condition: should compare with '0' character (i.e., '0') not integer 0; this causes logic error but not compilation error. However, the primary compilation error is due to 'gets']
        printf("%c.",str[0]);
        int a=1;
        while(1){
            if(str[a]!='.'){
                printf("%c",str[a]);
                a++; 
            }
            else if(str[a]=='.'){
                break;
            }
        }
        for(int b=a+1;b<len;b++){
            printf("%c",str[b]);
        }
        printf("e%d",a);
    }
     
return 0;
}