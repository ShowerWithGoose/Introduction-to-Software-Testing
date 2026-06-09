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
    return strcmp(a->word+1,b->word +1); // @@ [The comparison skips the first character of each word by using `word+1`, but words are stored starting at index 1, so this is inconsistent with how words are printed and compared elsewhere. However, the main issue is that the program has multiple semantic and logical errors leading to undefined behavior, but the reported error is a compilation error due to missing initialization and incorrect file reading logic causing potential undefined behavior that some compilers may reject or that leads to runtime issues misreported as compilation errors in the test environment.]
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ // @@ [Operator precedence error: `!=` has higher precedence than `=`, so this assigns the result of `(fgetc(in) != EOF)` (which is 0 or 1) to `c`, not the character. This causes incorrect input reading and may lead to undefined behavior when `in` is NULL (if file doesn't exist), which could manifest as a compilation or runtime error depending on environment. Also, `c` is declared as `char`, but `fgetc` returns `int` to properly handle EOF. Using `char` can cause EOF comparison to fail on systems where `char` is unsigned.]
        s[++len]=c;
    }
    s[len+1]='\0';
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a')); // @@ [If `s[i]` is not alphabetic, this branch shouldn't execute, but the loop condition ensures it is; however, subtracting 'A' and adding 'a' assumes uppercase, but if non-alphabetic somehow enters, it's undefined. More critically, `c` is `char`, but used in arithmetic that may overflow or behave unexpectedly. Also, the ternary condition uses `islower`, but if `s[i]` is uppercase, the conversion is correct, but the code doesn't handle non-ASCII safely. However, the primary bug is earlier with `c`'s type and assignment.]
            a[cnt].word[++a[cnt].sum]=c;
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