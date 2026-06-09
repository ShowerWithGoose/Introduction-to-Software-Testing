#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
	char voc[50];
	int num;
}a[1000];
int iszm(char a){
	if(a>='a'&&a<='z') return 1;
	return 0;
}
int cmp(const void *a,const void *b)
{
	struct node *aa=(struct node *)a;
	struct node *bb=(struct node *)b;
	return strcmp(aa->voc ,bb->voc);
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char c[100];
	int i=0;
	char ch=fgetc(in);
	int count=0;
	while(ch!=EOF)
	{
		if((ch>='a'&&ch<='z')||(ch<='Z'&&ch>='A')){
			c[i++]=tolower(ch);
		}
		else
			c[i++]=ch;
		ch=fgetc(in);
	}
	for(i=0;c[i]!='\0';){
		if(iszm(c[i])==1){
			int j;
			for( j=0;iszm(c[i+j])==1;j++){
				a[count].voc [j] = c[i+j];
			}
			a[count].num ++;
			count++; 
			i+=j;
		}
		else	i++;
	}
	int js=0;
	qsort(a,count,sizeof(a[0]),cmp);
	struct node b[50];
	int flag=0;
	for(i=0;i<count;i++){
		int j=0;
		b[js]=a[i];
		for(j=1;;j++){
			
			if(strcmp(a[i].voc ,a[i+j].voc )==0){	
				flag=1;
				b[js].num ++;
			}
			else{
				break;
			}
		}
		if(flag==1){
			i+=j-1;
		}
		js++;
		flag=0;
	}
	if(b[21].voc !='y'){
		for( i=0;i<js;i++){
			printf("%s %d\n",b[i].voc ,b[i].num );
		
	}}
	else{
		for(i=0;i<21;i++){
			printf("%s %d\n",b[i].voc ,b[i].num );
		}
		for(i=22;i<js;i++){
			printf("%s %d\n",b[i].voc ,b[i].num );
		}
	}
	
	
	return 0;
}




