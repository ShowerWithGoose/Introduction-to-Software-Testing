#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct l{
	char s[50];
	int num;
}list;
list t[2000];
int end=0;
char word[50];
char line[1000];
int cmp(const void*,const void*);
int cmp2(char [],char []);
int bisearch(char []);
int main()
{
	FILE *in;
	int flag=0,i,tail=0;
	in = fopen("article.txt","r");
	while(fgets(line,999,in)!=NULL){
		for(i=0;i<strlen(line);i++){
			if(isalpha(line[i])!=0){
				word[tail] = tolower(line[i]);//获取单词新思路 
				tail++;
				if(isalpha(line[i+1])==0){
					word[tail] = '\0';//注意自己抠出来的单词最后要加'\0' 
					flag = bisearch(word);
					if(flag==0){
						qsort(&t[1],end,sizeof(list),cmp); 
					}
					memset(word,0,49);
					tail = 0;
				}
	        }
		}
		memset(line,0,999);
	}
	for(i=1;i<=end;i++){
		printf("%s %d\n",t[i].s,t[i].num);
	}
	return 0;
}
int cmp2(char p1[],char p2[])
{
	int k;
	k = strcmp(p1,p2);
	return k;
}
int cmp(const void* p1,const void* p2)
{
	list *a1;
	list *a2;
	int flag=0;
	a1 = (list*)p1;
	a2 = (list*)p2;
	flag = strcmp(a1->s,a2->s);
	if(flag<0){
		return -1;
	}
	else{
		return 1;
	}
	
}
int bisearch(char p[])
{
	int low,high,mid,flag=-1;
	low = 0;
	high = end;
	while(low<=high){
		mid = (low+high)/2;
		flag = cmp2(word,t[mid].s);
		if(flag<0){
			high = mid-1;
		}
		else if(flag>0){
			low = mid+1;
		}
		else if(flag==0){
			t[mid].num++;
			break;
		}
	}
	if(flag==0)
	return 1;
	else {
		end++;//注意end初值为0的情况下入队的第一个位置为1，end的大小等于数组内元素数量 
		t[end].num = 1;
		strcpy(t[end].s,p);
		return 0;
	}
	
}


















