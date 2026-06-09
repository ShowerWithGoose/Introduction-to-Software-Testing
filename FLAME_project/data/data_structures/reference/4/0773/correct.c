#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long
#define For(a, b, c) for (int a = b; a < c;a++)
#define FOR(a, b, c) for (int a = c - 1; a >= b;a--)
#define ull unsigned long long
#define MAXN 1000000
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define swap(a,b)   do{a^=b;b^=a;a^=b;}while(0)
typedef struct In{
	int num;
	char str1[100];
}word,*wordptr;
int cmp(const void *a,const void *b){
	wordptr *x=(wordptr*)a;
	wordptr *y=(wordptr*)b;
	return strcmp((*x)->str1,(*y)->str1);
}
wordptr list[100000];
char str[4000],s[4000];
/*Nodeptr createList(int n){
    Nodeptr list=NULL;
    for(int i=1;i<=n;i++){
        q=(Nodeptr)malloc(sizeof(Node));
        q->data=i;
        q->link=NULL;
        if(list==NULL)
            list=p=q;
        else p->link=q;
        p=q;132 744 132 731 165 711 506 710 744 47 120 36 744 34 150 16 460 15 2852 13 110 5
    }
    p->link=list;
    return list;
}*/
int main()
{
    FILE *fp=fopen("article.txt","r");
    char ch;
    int k=0,count=0;
    ch=fgetc(fp);
	while(ch!=EOF)
	{
		s[k]=ch;
        if(isalpha(s[k])) s[k]=tolower(s[k]);
		ch=fgetc(fp);
        k++;
	}
    for(int i=0;i<strlen(s);i++){
        int j;
        if(isalpha(s[i])){
            for(j=i;j<strlen(s);j++)
            {
                if(!isalpha(s[j])) break; 
            }
            memset(str,0,sizeof(str));
            for(k=0;k<j-i;k++)
                str[k]=s[i+k];
            i=j;
            for(k=0;k<=count;k++){
			if(k==count){
				list[count]=(wordptr)malloc(sizeof(word));
				list[count]->num=1;
				strcpy(list[count]->str1,str);
				count++;
				break;
			}
			if(strcmp(str,list[k]->str1)==0){
				list[k]->num++;
				break; 
			}
		}
        }
    }
    qsort(list,count,sizeof(wordptr),cmp);
    for(int i=0;i<count;i++) printf("%s %d\n",list[i]->str1,list[i]->num);
    fclose(fp);
    return 0;
}
