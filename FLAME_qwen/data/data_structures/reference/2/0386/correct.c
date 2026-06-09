#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
#define FOR(X,Y,Z)  for(int X = Y;X<Z;X++)  
char s[100],a[100];

int main(){
    //freopen(".in","r",stdin);
    gets(s);
    int k = 0;
    for(int i = 0;i<=strlen(s);i++){
        if(s[i]!=' ')
        a[k++] = s[i];
    }
   
    int ans = 0,num1=0,num2=0,jj = 1,cc = 1;
    for(int i = 0;i<=strlen(a);i++){
        if(isdigit(a[i])){
            num1 *= 10;
            num1 += a[i]-'0';
        }
        else{
            if(a[i]=='+'||a[i]=='-'){
                if(jj==1){
                    ans+=num1;
                    
                }
                else{
                    ans -= num1;
                }     
                num1 = 0;  
                if(a[i]=='+')
                jj=1;
                if(a[i]=='-')
                jj=2; 
               
                
            }
            if(a[i]=='*'||a[i]=='/'){
                if(a[i]=='*')
                cc = 1;
                else
                cc = 2;
                i++;
                num2 = 0;
                for(;isdigit(a[i]);i++){
                    num2 *= 10;
                    num2 += a[i]-'0';
                }
                if(cc == 1){
                    num1 *= num2;
                }
                else{
                    num1 /=num2;
                }
                i--;
                
            }
            if(a[i]=='='){
                if(jj==1){
                    ans+=num1;
                    
                }
                else{
                    ans -= num1;
                }    
            }

           
        }
       
    }
     printf("%d",ans);
    return 0;
}

