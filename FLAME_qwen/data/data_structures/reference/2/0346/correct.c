#include<stdio.h>
#include<string.h>
long long a[20001];
char s[20001];
int main(){
    int i;
    for (i = 0;;i++){
        scanf("%lld %c", &a[i], &s[i]);
        
        if(s[i]=='=')
            break;
    }
    long long ans = 0;
    int l = strlen(s);
    if(s[0]=='*'){
        a[1] = (a[0] * a[1]);
        s[0] = '+';
        a[0] = 0;
    }else if(s[0]=='/'){
        a[1] = (a[0] / a[1]);
        s[0] = '+';
        a[0] = 0;
    }
    for (i = 1; i < l-1;i++){
        if(s[i]=='*'){
            a[i + 1] = (a[i] * a[i + 1]);
            if(s[i-1]=='-')
                s[i] = '-';
            else
                s[i] = '+';
            a[i] = 0;
        }else if(s[i]=='/'){
            a[i + 1] = (a[i] / a[i + 1]);
            if(s[i-1]=='-')
                s[i] = '-';
            else
                s[i] = '+';
            a[i] = 0;
        }
    }
    ans = a[0];
    for (i = 0; i < l-1;i++){
        if(s[i]=='+')
            ans += a[i + 1];
        else if(s[i]=='-')
            ans -= a[i + 1];
    }
    printf("%lld", ans);
    return 0;
}


