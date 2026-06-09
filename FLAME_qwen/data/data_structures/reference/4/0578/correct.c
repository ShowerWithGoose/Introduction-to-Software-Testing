#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct word{
	char name[35];
	int count;
};
struct word list[1000];
int getword(char s[],FILE *fp){
	int c,i=0;
	c=fgetc(fp);
	if(c==-1) return -1;
	while(c>'z'||c<'A'){
		c=fgetc(fp);
		if(c==-1) return -1;
	}
	while(c>='A'&&c<='z'){
		s[i++]=tolower(c);
		c=fgetc(fp);
	}
	s[i]='\0';
	return 1;
}
int cmp(const void *p1,const void *p2){
	return (strcmp((*(struct word *)p1).name,(*(struct word *)p2).name)>0)?1:-1;
}

int main(){
	FILE *in;
	int n=0;
	in=fopen("article.txt","r");
	if((in=fopen("article.txt","r"))==NULL){
		printf("Cannot Open file article.txt!\n");
		return 1;
	}
	if(getword(list[0].name,in)!=EOF){
	        list[0].count=1;
	        n=1;
	}
	while(getword(list[n].name,in)!=EOF){
			int k=0,flag=0;
			while(k<n){
				if(strcmp(list[n].name,list[k].name)==0){
					list[k].count++;
					flag=1;
					break;
				}
				else{
		        	k++;
				}
			}
			if(flag==0){
				list[n].count=1;
				n++;
			}
		}
    qsort(list,n,sizeof(list[0]),cmp);
	int i=0;
	while(i<n){
		printf("%s %d\n",list[i].name,list[i].count);
		i++;
	}
    return 0;
}








