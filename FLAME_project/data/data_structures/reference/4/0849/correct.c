#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 32
struct  node
{
    char s[MAXWORD];
    int num;
};
int getWord(FILE *fp,char *str);
int cmpfunc (const void * a, const void * b)
{
	struct node *p=(struct node*)a;
	struct node *q=(struct node*)b;
	return (strcmp(p->s,q->s));
//	return strcmp( (*(struct node *)a)->s , (*(struct node *)b)->s ); 
}
struct node nodes[500];
int main(){
    FILE *bfp; 
    int i=0,max=0;
    char word[MAXWORD];
    if((bfp=fopen("article.txt","r"))==NULL){
        fprintf(stderr,"%s can't open!\n","article.txt");
        return -1;
    }
     getWord(bfp,word);
//    while(getWord(bfp,word)!=-1){
//	}
    
    nodes[0].num=1;
    strcpy(nodes[0].s,word);
    max=1;
    int flag=1;
    while(getWord(bfp,word)!=-1){
    	flag=1;
        for(i=0;i<max;i++){
            if(strcmp(nodes[i].s,word)==0){
                nodes[i].num++;
//                printf("SAMESAME!!!!!!\n");
                flag=0;
                break;
            }
        }
        if(flag){
        	nodes[i].num=1;
        	strcpy(nodes[i].s,word);
        	max++;
        	flag=1;
		}
    }
//    printf("%d\n",max);
    qsort(&nodes[0],max,sizeof(struct node),cmpfunc); 
    for(i=0;i<max;i++){
        printf("%s %d\n",nodes[i].s,nodes[i].num);
    }
    return 0;

}
int getWord(FILE *fp,char *str)
{
	char c;
	int counter = 0;
	while((c = fgetc(fp)) != EOF){
		if( !((c>='a'&&c<='z')||(c>='A'&&c<='Z')) && (counter <= 0)){
			continue;
		}
		else if(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')) && (counter > 0)){
			break;
		}
		if(c>='a'&&c<='z'){
			str[counter++] = c;
		} 
		else if(c>='A'&&c<='Z'){
			str[counter++] = (c+'a'-'A');
		}
	}
	str[counter] = '\0';
//	puts(str);
	if(counter!=0){
		return 0;
	}
	else
	return -1;
}




