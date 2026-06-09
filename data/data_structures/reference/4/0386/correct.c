#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
#define FOR(X,Y,Z)  for(int X = Y;X<Z;X++) 
struct word{
    char ch[30];
    int t;
} a[100];
char s[1000];
char buffer[100];
int cnt = 0;
int cmp(const void*a,const void *b){
    struct word p1 = *(struct word*) a;
    struct word p2 = *(struct word*) b;
    return strcmp(p1.ch,p2.ch);
}
int main(){
    freopen("article.txt","r",stdin);
    int i = 0;
    int flag = -1;
    while(~(s[i] =  getchar())){
            if(isupper(s[i])) s[i]+='a'-'A';
            if(islower(s[i])&&flag == -1)
                flag = i;
            if(!islower(s[i])&&flag!=-1){
                int p = 0;
                for(int j = flag;j < i;j++){
                    buffer[p++] = s[j];
                }
                buffer[p] = '\0';
                flag = -1;
                int find = -1;
                for(int j = 0;j < cnt;j++){
                    if(strcmp(a[j].ch,buffer)==0)
                    find = j;
                }
                if(find == -1){
                strcpy(a[cnt].ch,buffer);
                a[cnt++].t = 1;
                }
                else
                a[find].t++;
            }
            i++;
        }      
    
    qsort(a,cnt,sizeof(a[0]),cmp);
    for(int j = 0;j < cnt;j++)
    printf("%s %d\n",a[j].ch,a[j].t);
    return 0;
}



