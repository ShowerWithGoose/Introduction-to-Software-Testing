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
                s[cnt].ss[pos++]=mid[i];
            else{
                pos=0;cnt++; // @@ [When a non-letter character is encountered, the current word should be terminated and a new word started. However, resetting pos to 0 and incrementing cnt here discards any letters processed before the non-letter character, leading to incomplete or missing words. Also, it may create empty entries.]
            }
        }
        cnt++; // @@ [This unconditionally increments cnt after processing each input token, even if the last part of the token was non-letter and already triggered cnt++. This leads to extra empty or invalid entries in the array s, which appear as blank lines or incorrect counts.]
    }
    /*for(int i=0;i<cnt;i++){
        puts(s[i].ss);
    }*/
    qsort(s,cnt,sizeof(struct stu),cmp);
    for(int i=0; i<cnt; i++) {
        if(s[i].ss[0]==' ') continue; // @@ [This checks for space, but empty strings are represented by '\0', not space. It should check if s[i].ss[0] == '\0'. As a result, empty entries (from erroneous cnt increments) may not be skipped properly, though in this case they might print as blank lines. However, the main issue is the creation of those empty entries earlier.]
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