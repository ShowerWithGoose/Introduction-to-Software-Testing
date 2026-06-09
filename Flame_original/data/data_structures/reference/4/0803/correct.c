#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char s[1000];
struct NODE
{
    int n;
    char a[1000];
}node[1000];

int Comp ( const void *p1 , const void *p2 )
{
		struct NODE*x=(struct NODE*)p1;
		struct NODE*y=(struct NODE*)p2;
		return strcmp(x->a,y->a);
}

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
	char op;
	int i=0,len=0,b;
	while((op=fgetc(in))!=EOF)
	{
		if(op>='A'&&op<='Z'){
			s[i++]=tolower(op);
		}
		else if(op>='a'&&op<='z'){
			s[i++]=op;
		}		
		else{
			if(s!=NULL)
			for(int j=0;j<len;j++){
				if(!strcmp(s,node[j].a)){
					node[j].n++;
					b=1;break;
				}
				else b=0;
			}
			if(!b){
				strcpy(node[len].a,s);
				node[len++].n=1;
			}
			for(int k=0;k<10;k++){
				s[k]='\0';
			}
			i=0;	                   
		}	
	} 
	qsort(node, len, sizeof(struct NODE), Comp);
	for(i=1;i<len;i++){
	        printf("%s %d\n",node[i].a,node[i].n);
	    }
	fclose(in);	 
    return 0;
}

