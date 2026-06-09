#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char in[105][20];
struct node
{
    char c[100];
    int cnt;
   
}danci[105];
void sortbyName(struct node array[], int n);//按名字排序
int main()
{
   FILE *inf;
    inf = fopen("article.txt", "r");
    
    char ch;
    int i = 0, j = 0, n = 0;
    ch = fgetc(inf); //输入
    while (ch != EOF)
    {
        if (isalpha(ch))
        {
            in[i][j] = ch;
            j++;
        }

        else if (ispunct(ch) || isspace(ch) /*ch == ' ' || ch == '.' || ch == ';' || ch == ',' || ch == ':' */)
        {
            in[i][j] = '\0';
            j = 0;
            i++;
        }

        ch = fgetc(inf);
    }
    n = i;
    for ( i = 0; i < n; i++) //全变成小写
    {
        for ( j = 0; j < strlen(in[i]); j++)
        {
            in[i][j] = tolower(in[i][j]);
        }
    }
    for ( i = 0; i < n; i++) 
    {
        strcpy(danci[i].c,in[i]);
    
    }
    for(i=0;i<n;i++)
    {
    	danci[i].cnt=1;
        if(danci[i].c[0]=='\0')
        continue;
        for(j=i+1;j<n;j++)
        {
            if(strcmp(danci[i].c,danci[j].c)==0)
            {
                danci[j].c[0]='\0';
                
				danci[i].cnt++;
            }
            
        }
    }
    sortbyName(danci,n);
    for(i=0;i<n;i++)
    {
        if(danci[i].c[0]!='\0')
        printf("%s %d\n",danci[i].c,danci[i].cnt);
    }
  
    fclose(inf);
    return 0;
}
void sortbyName(struct node array[], int n)
{
    int i, j;
    struct node tmp;
    for(i=0; i<n; i++)
        for(j=i; j<n; j++){//冒泡排序
            if(strcmp(array[i].c,array[j].c)>0){ //如果i的名字比j的字典序大那就交换位置
              tmp = array[i];
	          array[i] = array[j];
              array[j] = tmp;
            }
        }
}

