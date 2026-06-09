#include<stdio.h>
#include<ctype.h>
#define L 10009
char str[L];
int cal[L],l=0;

int reaDigit(char *p) {
    int ret = 0;
    while(isdigit(*p)) {
        ret = ret*10 + *p-'0';
        p++;
    }
    return ret;
}

int main() {
    gets(str);
    for(char *p=str, las = 0;*p!='\0';p++) {
        if(isblank(*p)) {
            continue;
        }else if(isdigit(*p)) {
            int t=reaDigit(p);
            if(las == '+') {
                cal[++l] = t;
            }else if(las == '-') {
                cal[++l] = -(t);
            }else if(las == '*') {
                cal[l] *= t;
            }else if(las == '/') {
                
                cal[l] /= t;
            }else cal[l] = t;
            while(isdigit(*p)) p++;
            p--;
        }else {
            las = *p;
        }
    }
    long long ans = 0;
    for(int i=0;i<=l;i++) {
        ans += cal[i];
    }
    printf("%lld\n",ans);
    return 0;
}
