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
    return strcmp(a->word+1,b->word +1); // @@ [The comparison skips the first character of each word by using `word+1`, but words are stored starting at index 1, so this is inconsistent with how words are printed and compared elsewhere. However, the main issue is that `word` is never null-terminated properly at index 0, and using `word+1` assumes a dummy character at index 0, which is not guaranteed to be consistent.]
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ // @@ [Operator precedence error: `!=` has higher precedence than `=`, so this assigns the result of `(fgetc(in) != EOF)` (which is 0 or 1) to `c`, not the actual character. This causes incorrect character reading and likely infinite loop or premature termination. Should be `while((c = fgetc(in)) != EOF)`]
        s[++len]=c;
    }
    s[len+1]='\0';
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a')); // @@ [Incorrect case conversion: `s[i]-'A'+'a'` only works if `s[i]` is uppercase. But if `s[i]` is non-alphabetic (though guarded by `isalpha` above), it's safe, but more critically, if `s[i]` is already lowercase, this is fine. However, the real issue is that `s[i]` might be uppercase, but `'A'` and `'a'` are not guaranteed to be contiguous in all character sets (though they are in ASCII). The bigger problem is logic flow below.]
            a[cnt].word[++a[cnt].sum]=c;
            a[cnt].word[a[cnt].sum+1]='\0';
        }while(isalpha(s[++i])); // @@ [This increments `i` inside the condition, which may cause skipping characters or out-of-bound access. Also, after the last word, `i` may exceed `len`, leading to undefined behavior when accessing `s[i]`.]
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
    printf("%s %d\n",a[cnt].word +1,ans); // @@ [If `cnt` is 0 (no words), this accesses `a[0].word+1` which is uninitialized, causing undefined behavior. Also, the final count `ans` may not correspond to the last group if the loop ends without printing the last group correctly.]

    return 0;
}