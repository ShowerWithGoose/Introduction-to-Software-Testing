#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
char str[10000000];
int judge(char c){
    if(c >= '0' && c <= '9')return 0;
    if(c >= 'a' && c <= 'z')return 1;
    if(c >= 'A' && c <= 'Z')return 2;
}

int main(){
//    freopen("r.txt","r",stdin);
//    freopen("w.txt","w",stdout);
    
    scanf("%s",str);
    ll len = strlen(str);
    putchar(str[0]);
    for(int i = 1; i < len; ++i){
        if(str[i] == '-'){
            char _c=str[i-1],c_=str[i+1];//get char
            if(judge(_c) == judge(c_) && c_ != '\0'){//is legal than fill from _c+1 to c_-1
                if(_c+1 >= c_){
                    putchar(str[i]);
                    continue;
                }
                for(char j = _c+1; j < c_; ++j)
                    putchar(j);
            }else putchar(str[i]);
        }else{
            putchar(str[i]);
        }
    }
    return 0;
}
