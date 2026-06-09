//
//  main.c
//  表达式计算
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>
int main() {
    char s[10001], x[10001], t[10001];
    int i, j=0, k=0, k1=1, len, len1, a[10001]={0}, ans=0;
    gets(s);
    len = strlen(s);
    for(i=0;i<len;i++){
        if(s[i]!=' ')
            x[k++]=s[i];
    }
    len1 = strlen(x);
    for(i=0;i<len1-1;i++){
        if(x[i]>='0'&&x[i]<='9')
            a[j] = 10*a[j] + x[i]-'0';
        else{
            t[j]=x[i];
            j++;
        }
    }
    ans += a[0];
    for(i=0;i<j;i++){
        if(t[i]=='*'){
            if(i==0){
                ans = ans - a[i] + a[i]*a[i+1];
                a[i+1] = a[i] * a[i+1];
            }
            else{
                if(t[i-k1]=='+'){
                    ans = ans - a[i] + a[i]*a[i+1];
                    a[i+1] = a[i] * a[i+1];
                    k1++;
                }
                else if(t[i-k1]=='-'){
                    ans = ans + a[i] - a[i]*a[i+1];
                    a[i+1] = a[i] * a[i+1];
                    k1++;
                }
                else if(t[i-k1]=='*'){
                    ans *= a[i+1];
                    k1++;
                }
                else if(t[i-k1]=='/'){
                    ans *= a[i+1];
                    k1++;
                }
            }
        }
        else if(t[i]=='/'){
            if(i==0){
                ans = ans - a[i] + a[i]/a[i+1];
                a[i+1] = a[i] / a[i+1];
            }
            else{
                if(t[i-k1]=='+'){
                    ans = ans - a[i] + a[i]/a[i+1];
                    a[i+1] = a[i] / a[i+1];
                    k1++;
                }
                else if(t[i-k1]=='-'){
                    ans = ans + a[i] - a[i]/a[i+1];
                    a[i+1] = a[i] / a[i+1];
                    k1++;
                }
                else if(t[i-k1]=='*'){
                    ans /= a[i+1];
                    k1++;
                }
                else if(t[i-k1]=='/'){
                    ans /= a[i+1];
                    k1++;
                }
            }
        }
        else if(t[i]=='+'){
            ans += a[i+1];
            k1=1;
        }
        else if(t[i]=='-'){
            ans -= a[i+1];
            k1=1;
        }
    }
    printf("%d\n", ans);
    return 0;
}



