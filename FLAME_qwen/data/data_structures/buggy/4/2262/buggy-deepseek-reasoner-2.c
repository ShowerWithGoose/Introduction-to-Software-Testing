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
    char mid[1000]= {}; // @@ [Empty initializer braces are not standard C; use `= {0}` or skip initialization.]
    while(~fscanf(in,"%s",mid)) {
        int len=strlen(mid);
        int pos=0;
        for(int i=0; i<len; i++) {
            mid[i]=tolower(mid[i]);
            if(mid[i]<='z'&&mid[i]>='a')
                s[cnt].ss[pos++]=mid[i];
            else{
                pos=0;cnt++;
            }
        }
        cnt++;
    }
    /*for(int i=0;i<cnt;i++){
        puts(s[i].ss);
    }*/
    qsort(s,cnt,sizeof(struct stu),cmp); // @@ [Missing #include <stdlib.h> for qsort function.]
    for(int i=0; i<cnt; i++) {
        if(s[i].ss[0]==' ') continue;
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