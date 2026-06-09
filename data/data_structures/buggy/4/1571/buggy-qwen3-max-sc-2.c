#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define maxn 100005
#define m 105

int num,i;//单词个数
struct WORD{
    int time,sum;//词频，长度 
    char word[105];
}a[maxn];
char s[maxn],c;//c：从文件中读取的字符 
int cnt,i,len;//存储的单词个数，，字符串的长度 

int cmp(const void *p,const void *q){
    struct WORD *a=(struct WORD *)p;
    struct WORD *b=(struct WORD *)q;
    return strcmp(a->word+1,b->word +1); // @@ [The comparison skips the first character of each word by using `word+1`, but words are stored starting at index 1, so this is inconsistent with standard string handling and may cause undefined behavior or incorrect sorting. Also, if a word is empty, this leads to invalid access.]
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ // @@ [Operator precedence error: `!=` has higher precedence than `=`, so this assigns the result of `(fgetc(in) != EOF)` (which is 0 or 1) to `c`, not the character itself. This causes incorrect character reading and likely infinite loop or premature termination.]
        s[++len]=c;
    }
    s[len+1]='\0';
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a')); // @@ [Incorrect case conversion: uses 'A' and 'a' but should use `tolower()`; also, if `s[i]` is uppercase, subtracting 'A' and adding 'a' works only for ASCII, but more critically, this expression is safe only if `s[i]` is alphabetic — which it is due to the outer `if`, but the logic is fragile. However, the bigger issue is that `s[i]` might be non-ASCII, but the main bug is elsewhere.]
            a[cnt].word[++a[cnt].sum]=c;
            a[cnt].word[a[cnt].sum+1]='\0';
        }while(isalpha(s[++i])); // @@ [This increments `i` inside the loop condition, which may cause out-of-bounds access when `i` reaches `len` and then `s[++i]` accesses `s[len+1]` or beyond. Also, after the last word, `i` may exceed `len`, leading to undefined behavior.]
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
    printf("%s %d\n",a[cnt].word +1,ans); // @@ [If `cnt` is 0 (no words), this accesses `a[0].word+1`, which is invalid. Also, the final count `ans` may not correspond to the last group if the loop ends without printing the last group correctly. Additionally, the program prints an extra newline even if there's no output, but the bigger issue is potential crash on empty input.]

    return 0;
}