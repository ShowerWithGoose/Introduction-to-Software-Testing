#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long

char str[1000000];

struct node{
    int typ;//0=dig 1=add 2=mul
    int num;
    char cal;
    int l;
    int r;
}n[10000];

int main(){
//    freopen("r.txt","r",stdin);
//    freopen("w.txt","w",stdout);
    gets(str+1);
    int len = strlen(str+1),i,j;
    int cnt1=0,cnt2=0;
    for(i = j = 1; i <= len-1; ++i){
        char c = str[i];
        if(c == ' ')continue;
        if(c >= '0' && c <= '9'){
            n[j].typ = 0;
            n[j].num = c-'0';
            while(str[i+1] >= '0' && str[i+1] <= '9'){
                ++i;
                n[j].num = n[j].num * 10 + str[i] - '0';
            }
            n[j].l = j-1;
            n[j].r = j+1;
            ++j;
        }else if(c == '+' || c == '-'){
            n[j].typ = 1;
            n[j].cal = c;
            n[j].l = j-1;
            n[j].r = j+1;
            ++j;
            ++cnt1;
        }else{
            n[j].typ = 2;
            n[j].cal = c;
            n[j].l = j-1;
            n[j].r = j+1;
            ++j;
            ++cnt2;
        }
    }
    --j;
    for(i = 1; i <= j; ++i){
        if(n[i].typ == 2){
            int l=n[i].l,r=n[i].r;
            int ans;
            switch(n[i].cal){
                case '*':
                ans = n[l].num*n[r].num;
                break;
                case '/':
                ans = n[l].num/n[r].num;
                break;
            }
            n[i].typ = 0;
            n[i].num = ans;
            n[i].l = n[l].l;
            n[n[l].l].r = i;
            n[i].r = n[r].r;
            n[n[r].r].l = i;
            --cnt2;
        }
        if(cnt1 == 0 && cnt2 == 0){
            printf("%d",n[i].num);
            return 0;
        }
    }
    for(i = 1; i <= j; ++i){
        if(n[i].typ == 1){
            int l=n[i].l,r=n[i].r;
            int ans;
            switch(n[i].cal){
                case '+':
                ans = n[l].num+n[r].num;
                break;
                case '-':
                ans = n[l].num-n[r].num;
                break;
            }
            n[i].typ = 0;
            n[i].num = ans;
            n[i].l = n[l].l;
            n[n[l].l].r = i;
            n[i].r = n[r].r;
            n[n[r].r].l = i;
            --cnt1;
        }
        if(cnt1 == 0){
            printf("%d",n[i].num);
            return 0;
        }
    }
    return 0;
}
