#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
char s[200],ss[200];
bool dot(char *s){
    int l=strlen(s);
    for(int i=0;i<l;i++){
        if(s[i]=='.')return true;
    }
    return false;
}
void SciNo(){
    scanf("%s",s);
    int l=strlen(s);
    int e=-1;
    if(!dot(s)){
        if(l>=2){
            ss[0]=s[0];
            ss[1]='.';
            for(int i=2;i<l+1;i++){
                ss[i]=s[i-1];
            }
            e=l-1;
        }
        else{
            e=0;
            for(int i=0;i<l;i++)ss[i]=s[i];
        }
    }
    else if(dot(s)){
        if(s[0]!='0'){
            for(int i=0;i<l;i++){
                if(s[i]!='.')e++;
                else break;
            }
            ss[0]=s[0];
            ss[1]='.';
            int j=2;
            for(int i=1;i<l;i++){
                if(s[i]!='.'){
                    ss[j++]=s[i];
                }
            }
        }
        else{
            for(int i=2;i<l;i++){
                if(s[i]=='0'){
                    e--;
                }
            }
            int j=2;
            ss[0]=s[-e+1]; // @@ [-e may be out of bounds or logic error: e is decremented only for leading zeros after decimal, but loop doesn't break on first non-zero; also -e+1 may exceed string length]
            if(l>-e+2){
                ss[1]='.';
                for(int i=-e+3;i<l;i++){
                    ss[j++]=s[i];
            }
            }
        }
    }
    printf("%s",ss); // @@ [ss is not null-terminated, leading to undefined behavior when printed]
    printf("e%d\n",e);
}
int main(){
    SciNo();
    return 0;
}