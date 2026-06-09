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
            int j=2; // @@ [This line initializes j=2, but if the number has only one non-zero digit after leading zeros (e.g., "0.005"), then ss[1] may never be set to '.', and ss may not be null-terminated. Also, logic for computing e is incorrect—it decrements e only for each '0', but should count position of first non-zero digit.]
            ss[0]=s[-e+1]; // @@ [If e is negative (which it is), -e+1 may be out of bounds. For example, if input is "0.001", the loop sets e = -2 (after two zeros), so -e+1 = 3, but s[3] is '1'—this seems okay, but if there are more zeros than digits, this leads to undefined behavior. Also, e is initialized to -1 and only decremented for zeros, which doesn't correctly compute exponent.]
            if(l>-e+2){ // @@ [This condition uses -e+2, but e was computed incorrectly. The logic does not correctly locate the first significant digit after leading zeros.]
                ss[1]='.';
                for(int i=-e+3;i<l;i++){
                    ss[j++]=s[i];
            }
            }
        }
    }
    printf("%s",ss); // @@ [ss is not null-terminated anywhere in the code, leading to undefined behavior when printed with %s.]
    printf("e%d\n",e);
}
int main(){
    SciNo();
    return 0;
}