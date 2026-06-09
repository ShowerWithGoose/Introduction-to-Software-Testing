#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int cacu(char a[],int begin,int end);
int ischa(char);
int chatonum(char a[],int begin,int end);
int main(){
    int i = 0,j = 0,j1 = 0,ans = 0,len1,len2,temb,numm[100]={0};
    char ori[10000]={0},expr[10000]={0},chh[100]={0};
    gets(ori);
    len1 = strlen(ori);
    for(i = 0;i < len1;i++){
        if(ori[i] != ' '){
            expr[j] = ori[i];
            j++;
        }
    }
    j = 1;
    len2 = strlen(expr);
    temb = 0;
    for(i = 0;i < len2;i++){
        if(ischa(expr[i])==2||ischa(expr[i])==1){
            numm[j1]=cacu(expr,temb,i-1);
            
            if(i!=len2-1){
                chh[j]=expr[i];
                j++;
            }
            temb = i+1;
            j1++;
        }
    }
    ans = numm[0];
    for(i = 1;i<j;i++){
        switch (chh[i]){
            case '+':{
                ans += numm[i];
            }break;
            case '-':{
                ans -= numm[i];
            }break;
        }
    }
    printf("%d\n",ans);
}

int cacu(char a[],int begin,int end){
    int i = 0,j = 1,j1 = 0,res = 0,temb = begin;
    int num[100]={0};
    char ca[100]={0};
    for(i = begin;i <= end;i++){
        if(ischa(a[i]) == 3||i == end){
            if(i!=end){
                ca[j] = a[i];
                j++;
            }
            num[j1] = chatonum(a,temb,i==end?end:i-1);
            j1++;
            temb = i+1;
        }
    }
    res = num[0];
    for(i = 1;i < j;i++){
        switch (ca[i]){
            case '*':{
                res *= num[i];
            }break;
            case '/':{
                res /= num[i];
            }break;
        }
    }
    return res;
}

int ischa(char c){
    if(c == '*'||c == '/') return 3;
    else if(c == '+'||c == '-') return 2;
    else if(c == '=') return 1;
    else return 0; 
}

int chatonum(char a[],int begin,int end){
    char tem[100]={0};
    int i = 0,j = 0;
    for(i = begin;i <= end;i++){
        tem[i-begin] = a[i];
    }
    return atoi(tem);
}
