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
	char str[100];
}word,*wordptr;
int cmp(const void *a,const void *b){
	wordptr *x=(wordptr*)a;
	wordptr *y=(wordptr*)b;
	return strcmp((*x)->str,(*y)->str);
}
wordptr num[100000];
char str[4000],tmp[4000];
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
    int j=0,k=0;
    ch=fgetc(fp);
	while(ch!=EOF)
	{
		tmp[j]=ch;
        if(isalpha(tmp[j])) tmp[j]=tolower(tmp[j]);
		ch=fgetc(fp);
        j++;
	}
    for(int p=0;p<strlen(tmp);p++){
        int j;
        if(isalpha(tmp[p])){
            for(j=p;j<strlen(tmp);j++)
            {
                if(!isalpha(tmp[j])) break; 
            }
            memset(str,0,sizeof(str));
            for(j=0;j<j-p;j++)
                str[j]=tmp[p+j];
            p=j;
            for(j=0;j<=k;j++){
			if(j==k){
				num[k]=(wordptr)malloc(sizeof(word));
				num[k]->num=1;
				strcpy(num[k]->str,str);
				k++;
				break;
			}
			if(strcmp(str,num[j]->str)==0){
				num[j]->num++;
				break; 
			}
		}
        }
    }
    qsort(num,k,sizeof(wordptr),cmp);
    for(int p=0;p<k;p++) printf("%s %d\n",num[p]->str,num[p]->num);
    fclose(fp);
    return 0;
}
