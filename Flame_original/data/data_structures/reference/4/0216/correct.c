#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
typedef struct _dc{
	char ch[60];
	int num;
	struct _dc *link;
} dc; 
typedef dc *dcp;

int main(){
    char a[60],b[60];FILE *in;dcp list=NULL,p;int flag,len,h=1;
    in=fopen("article.txt","r");
    list=(dcp)malloc(sizeof(dc));
    list->link=NULL; 
    while(fscanf(in,"%s",b)!=EOF){
    	int f=0;
    	len=strlen(b);
    	int i,j;
    	for(i=0,j=0;i<len;i++){
    		if(isalpha(b[i])) {
    			if(b[i]>='A'&&b[i]<='Z') b[i]=b[i]+32;
    			f=1,a[j]=b[i],j++;
			}
    		else if(f==0) continue;
    		if(i==len-1||!isalpha(b[i])&&f==1) {
    			a[j]='\0';f=0;j=0;
    			p=(dcp)malloc(sizeof(dc));
    	    p->link=NULL;
    	    p->num=1;
		    strcpy(p->ch,a);
		    if(h){
			    list->link=p;h=0;
		    }
		    else{
		    	dcp m,n;
			    for(m=list,n=list->link;n!=NULL;m=m->link,n=n->link){
				    flag=strcmp(p->ch,n->ch);
				    if(flag<0) {
				        m->link=p,p->link=n;break;
				    }
				    else if(flag==0){
					    n->num=n->num+1;break;
				    } 
				    else if(n->link==NULL) n->link=p,n=p; 
				    else continue;
			   }
		    }
			}
		}		
	}
	dcp n;
	for(n=list->link;n!=NULL;n=n->link){
		printf("%s %d\n",n->ch,n->num);
	}
	fclose(in);
	return 0;
}

