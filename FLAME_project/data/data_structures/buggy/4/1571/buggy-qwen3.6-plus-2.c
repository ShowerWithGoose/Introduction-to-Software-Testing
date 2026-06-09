#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define maxn 100005
#define m 105

int num,i;//单词个数 @@ [Variable 'i' is declared globally and also locally in main, causing shadowing and potential logic errors. Variable 'num' is unused.]
struct WORD{
    int time,sum;//词频，长度 
    char word[105];
}a[maxn];
char s[maxn],c;//c：从文件中读取的字符 
int cnt,i,len;//存储的单词个数，，字符串的长度 @@ [Variable 'i' is redeclared here, conflicting with the global declaration. Variable 'len' is used without initialization.]

int cmp(const void *p,const void *q){
    struct WORD *a=(struct WORD *)p;
    struct WORD *b=(struct WORD *)q;
    return strcmp(a->word+1,b->word +1); @@ [The words are stored starting at index 1, so comparing from index 1 is correct for the custom storage, but standard practice is 0-indexed. However, the main issue is that 'sum' is used as length/index but initialized to 0 by default global init, which is fine. The logic relies on 1-based indexing for strings.]
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ @@ [Operator precedence error: '!=' has higher precedence than '='. This assigns the result of comparison (0 or 1) to c, not the character. Should be (c=fgetc(in))!=EOF.]
        s[++len]=c;
    }
    s[len+1]='\0';
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a'));
            a[cnt].word[++a[cnt].sum]=c; @@ ['sum' is used as the current length/index. It starts at 0 (global init). Pre-increment makes it 1. This matches the 1-based string storage.]
            a[cnt].word[a[cnt].sum+1]='\0';
        }while(isalpha(s[++i]));
    }
    
    qsort(a+1,cnt,sizeof(a[0]),cmp);
    
    int ans=0;
    for(i=1;i<=cnt;i++){
        if(i==1||strcmp(a[i].word +1,a[i-1].word +1)!=0){
            if(i!=1)
                printf("%s %d\n",a[i-1].word +1,ans);
            ans=1;
        }else if(strcmp(a[i].word+1,a[i-1].word +1)==0) ans++;
    }
    printf("%s %d\n",a[cnt].word +1,ans);

    return 0;
}