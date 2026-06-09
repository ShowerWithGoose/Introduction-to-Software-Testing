#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>                    

int cmp(const void *a, const void*b);

struct line {
    char s[100];
    int flag;

}p[100+5];  

int main()
{
	int i,k=0;
	char c;
    char str[10000+5];
    int cnt = 0;
    FILE* fp = fopen("article.txt", "r");
    while ((c = fgetc(fp)) != EOF) str[cnt++] = c;  
	cnt=0;    
	        
    for (i = 0; i < strlen(str); i++)
    {
         if (isalpha(str[i])) p[cnt].s[k++] = tolower(str[i]);
         else{
         	cnt++;
         	k=0;
		 }
    }  

    for (i = 0; i < cnt; i++)
        if(strlen(p[i].s)) p[i].flag = 1; 
		
	qsort(p, cnt, sizeof(p[0]), cmp); 
	
	int j;  
        
    for (i = 0; i < cnt; i++){
    	j=i;
    	while(strcmp(p[j].s, p[i+1].s)==0){
    		i++;
    		p[j].flag++;
		}
		if (p[j].flag)
		if(strlen(p[j].s))
            printf("%s %d\n", p[j].s, p[j].flag);
	}
	
    return 0;
}

int cmp(const void *a, const void*b)             
{
    struct line * c = (struct line *)a;
    struct line * d = (struct line *)b;
    return strcmp(c->s, d->s);
}



