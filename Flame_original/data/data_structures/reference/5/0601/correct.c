#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char temp[10000];
long long a1[10000],x1[10000],a2[10000],x2[10000],res[100][2];
int cmp(const void *_a,const void *_b){
    long long *a = (long long*)_a;
    long long *b = (long long*)_b;
    if(b[1] == a[1]){
        return b[0] - a[0];
    }else{
        return b[1] - a[1];
    }
}

int main(){

    gets(temp);
    int l = strlen(temp),tab = 0,c = 0,tab2 = 0;//输入a;
    int c1 = 0,c2 = 0,c0 = 0;
    long long buf = 0;
    for(int i = 0;i <= l;i ++){
        if(temp[i] == '-'){
            tab2 = 1;
            continue;
        }
        if(temp[i] == ' ' || i == l){
            if(tab == 0){
                if(tab2 == 1){
                    a1[c1] = -buf;
                }else{
                    a1[c1] = buf;
                }
                tab2 = 0;
                tab = 1;
                buf = 0;
            }else{
                if(tab2 == 1){
                    x1[c1 ++] = -buf;
                }else{
                    x1[c1 ++] = buf;
                }
                tab2 = 0;
                tab = 0;
                buf = 0;
            }
            continue;
        }
        buf = buf * 10 + temp[i] - '0';
    }
    gets(temp);
    l = strlen(temp),tab = 0;
    tab2 = 0;
    for(int i = 0;i <= l;i ++){
        if(temp[i] == '-'){
            tab2 = 1;
            continue;
        }
        if(temp[i] == ' ' || i == l){
            if(tab == 0){
                if(tab2 == 1){
                    a2[c2] = -buf;
                }else{
                    a2[c2] = buf;
                }
                tab2 = 0;
                tab = 1;
                buf = 0;
            }else{
                if(tab2 == 1){
                    x2[c2 ++] = -buf;
                }else{
                    x2[c2 ++] = buf;
                }
                tab = 0;
                buf = 0;
            }
            continue;
        }
        buf = buf * 10 + temp[i] - '0';
    }
    for(int i = 0;i < c1;i ++){
        for(int j = 0;j < c2;j ++){
            res[c][0] = a1[i] * a2[j];
            res[c][1] = x1[i] + x2[j];
            for(int t = 0;t < c;t ++){
                if(res[t][1] == res[c][1]){
                    c0 --;
                    res[c][0] += res[t][0];
                    res[t][0] = -10000000000;
                    res[t][1] = -10000000000;
                }
            }
            c ++;
            c0 ++;
        }
    }
    qsort(res,c,sizeof(res[0]),cmp);
    for(int i = 0;i < c0;i ++){
        printf("%lld %lld ",res[i][0],res[i][1]);
    }
    puts("");
}
