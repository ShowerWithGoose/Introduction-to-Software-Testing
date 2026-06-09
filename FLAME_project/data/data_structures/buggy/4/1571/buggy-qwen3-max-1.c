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
    return strcmp(a->word+1,b->word +1); // @@ [The comparison skips the first character of each word by using `word+1`, but words are stored starting at index 1, so this is inconsistent with how words are printed and compared. However, the real issue is that words should be compared from index 0 if stored from index 0, or consistently from index 1. But the bigger problem is in reading logic.]
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ // @@ [Operator precedence error: `=` has lower precedence than `!=`, so this is equivalent to `while(c = (fgetc(in) != EOF))`, which assigns 0 or 1 to `c`, not the actual character. This causes all characters to be lost and replaced by 0/1. Should be `while((c = fgetc(in)) != EOF)`]
        s[++len]=c;
    }
    s[len+1]='\0';
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a')); // @@ [This converts uppercase to lowercase correctly, but note: `s[i]` might be non-alphabetic here due to loop condition, but actually the loop condition ensures it's alphabetic. However, the bigger issue is that `i` is incremented in the `do-while` condition, which may go out of bounds. Also, the initial `i` starts at 1, but `s` was filled starting at index 1, which is okay only if `len` is correctly set — but `len` starts uninitialized!]
            a[cnt].word[++a[cnt].sum]=c;
            a[cnt].word[a[cnt].sum+1]='\0';
        }while(isalpha(s[++i])); // @@ [This increments `i` before checking, which may skip characters or go beyond `len`. Also, if `i` reaches `len+1`, `s[i]` is `\0`, which is not alpha, so loop stops — but the logic is fragile. More critically, `len` was never initialized to 0, so it starts with garbage value.]
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
    printf("%s %d\n",a[cnt].word +1,ans); // @@ [If there are no words (cnt=0), this prints garbage. Also, the entire counting logic assumes at least one word. Moreover, the frequency counting is flawed: `ans` counts consecutive duplicates after sorting, but the initial word's count is never printed if there's only one unique word. Also, the structure member `time` is unused; instead, a local `ans` is used incorrectly.]

    return 0;
}