#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct stu{
    char ss[1000];
    int num;
};
int cmp(const void*a,const void *b){
    struct stu*p1=(struct stu*)a;
    struct stu*p2=(struct stu*)b;
    return (strcmp(p1->ss,p2->ss));
}
int main()
{
    struct stu s[1000];
    FILE*in;
    in=fopen("article.txt","r");
    int cnt=0;
    char mid[1000]= {};
    while(~fscanf(in,"%s",mid)) {
        int len=strlen(mid);
        int pos=0;
        for(int i=0; i<len; i++) {
            mid[i]=tolower(mid[i]);
            if(mid[i]<='z'&&mid[i]>='a')
                s[cnt].ss[pos++]=mid[i]; // @@ 没有添加字符串终止符，导致后续单词比较时可能越界
            else{
                pos=0;cnt++; // @@ 遇到非字母时直接增加cnt，应在增加前先给当前单词添加'\0'；而且循环结束后还会再增加一次，导致产生空单词
            }
        }
        cnt++; // @@ 每次读取一个字符串后都增加cnt，但对于包含非字母的字符串，循环内已增加过，导致多增加一次，形成空单词
    }
    /*for(int i=0;i<cnt;i++){
        puts(s[i].ss);
    }*/
    qsort(s,cnt,sizeof(struct stu),cmp);
    for(int i=0; i<cnt; i++) {
        if(s[i].ss[0]==' ') continue; // @@ 只过滤了空格字符，但空字符串（ss[0]=='\0'）未被过滤，导致空单词被输出
        int t=0;
        for(int j=i;j<cnt;j++){
            if(strcmp(s[i].ss,s[j].ss)!=0) break;
            else t++;
        }
        printf("%s %d\n",s[i].ss,t);
        i=i+t-1;
    }
    return 0;
}