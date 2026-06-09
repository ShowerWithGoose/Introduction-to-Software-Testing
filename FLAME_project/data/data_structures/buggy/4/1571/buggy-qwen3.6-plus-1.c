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
int cnt,i,len;//存储的单词个数，，字符串的长度 @@ [Variable 'i' is redeclared here, conflicting with the global declaration and the local usage in main. Variable 'len' is used without initialization.]

int cmp(const void *p,const void *q){
    struct WORD *a=(struct WORD *)p;
    struct WORD *b=(struct WORD *)q;
    return strcmp(a->word+1,b->word +1); @@ [The words are stored starting at index 1, so comparing from index 1 is correct for the custom storage, but standard practice is 0-indexed. However, the main issue is that `qsort` is called on `a+1`, so the pointers passed to cmp point to `a[1]`, `a[2]` etc. Inside cmp, `a` points to `a[1]`. `a->word` is `a[1].word`. Accessing `a->word+1` skips the first character of the word. The word is built starting at `word[1]`. So `word[0]` is uninitialized/garbage. Comparing `word+1` is actually correct given the construction logic below, BUT the sorting logic relies on `cnt` which might be wrong due to previous errors.]
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ @@ [Operator precedence error: `!=` has higher precedence than `=`. This assigns the result of the comparison (0 or 1) to `c`, not the character read. It should be `(c=fgetc(in))!=EOF`. Also, `c` is `char`, `EOF` is `int`, should use `int` for `c`.]
        s[++len]=c;
    }
    s[len+1]='\0'; @@ [Should be `s[len]='\0'` if `len` was incremented correctly after the last char, but since `c` is wrong, this whole block is flawed. Also `len` is uninitialized global int (defaults to 0), so `s[1]` is first char. String should end at `s[len]`. Here it ends at `s[len+1]`, leaving `s[len]` potentially uninitialized if loop condition fails immediately or logic is off.]
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a'));
            a[cnt].word[++a[cnt].sum]=c; @@ [`a[cnt].sum` is not initialized to 0 before use. It contains garbage value. Should initialize `a[cnt].sum = 0` before the do-while loop or when `cnt` is incremented.]
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