#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
#define maxn 100005
char s[maxn];

int n,cnt_num,cnt_pic,num[maxn];
char pic[maxn];

int main(){
    /*double st=clock();*/
    gets(s+1);
    int i,j;
    for(i=j=1;s[i]!='\0';i++)
     if(s[i]!=' ') s[j++]=s[i];
    s[j]='\0';
    n=strlen(s+1);
    int now_num=0;
    for(i=1;i<=n;i++)
     if(isdigit(s[i])) now_num=now_num*10+s[i]-'0';
     else {
         pic[++cnt_pic]=s[i];
         num[++cnt_num]=now_num;
         now_num=0;
     }
    cnt_pic--;//  '='
    //for(i=1;i<=cnt_num;i++) printf("%d ",num[i]);
    for(int i=1;i<=cnt_pic;i++)
     if(pic[i]=='*'){
         num[i+1]*=num[i];
         num[i]=-1;
         pic[i]='@';
     }
     else if(pic[i]=='/'){
         num[i+1]=num[i]/num[i+1];
         num[i]=-1;
         pic[i]='@';
     }
    for(int i=j=1;i<=cnt_num;i++)
     if(num[i]!=-1) num[j++]=num[i];
    cnt_num=j-1;
    for(int i=j=1;i<=cnt_pic;i++)
     if(pic[i]!='@') pic[j++]=pic[i];
    cnt_pic=j-1;
    //for(int i=1;i<=cnt_pic;i++) printf("%c ",pic[i]);
    int ans=num[1];
    for(i=1,j=2;i<=cnt_pic;i++,j++)
     if(pic[i]=='+') ans+=num[j];
     else ans-=num[j];
    printf("%d",ans);
    /*double ed=clock();
    printf("Time:%lf ms",ed-st);*/
    return 0;
}


