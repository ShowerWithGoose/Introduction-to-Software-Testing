#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char words[105][20];
struct node
{
    char c[100];
    int cnt;
   
}array[105];
void sortbyName(struct node array[], int len_a);//按名字排序
int main()
{
   FILE *inf;
    inf = fopen("article.txt", "r");
    
    char ch;
    int i = 0, j = 0, len_a = 0;
    ch = fgetc(inf); //输入
    while (ch != EOF)
    {
        if (isalpha(ch))
        {
            words[i][j] = ch;
            j++;
        }

        else if (ispunct(ch) || isspace(ch) /*ch == ' ' || ch == '.' || ch == ';' || ch == ',' || ch == ':' */)
        {
            words[i][j] = '\0';
            j = 0;
            i++;
        }

        ch = fgetc(inf);
    }
    len_a = i;
    for ( i = 0; i < len_a; i++) //全变成小写
    {
        for ( j = 0; j < strlen(words[i]); j++)
        {
            words[i][j] = tolower(words[i][j]);
        }
    }
    for ( i = 0; i < len_a; i++) 
    {
        strcpy(array[i].c,words[i]);
    
    }
    for(i=0;i<len_a;i++)
    {
    	array[i].cnt=1;
        if(array[i].c[0]=='\0')
        continue;
        for(j=i+1;j<len_a;j++)
        {
            if(strcmp(array[i].c,array[j].c)==0)
            {
                array[j].c[0]='\0';
                
				array[i].cnt++;
            }
            
        }
    }
    sortbyName(array,len_a);
    for(i=0;i<len_a;i++)
    {
        if(array[i].c[0]!='\0')
        printf("%s %d\n",array[i].c,array[i].cnt);
    }
  
    fclose(inf);
    return 0;
}
void sortbyName(struct node array[], int len_a)
{
    int i, j;
    struct node tmp;
    for(i=0; i<len_a; i++)
        for(j=i; j<len_a; j++){//冒泡排序
            if(strcmp(array[i].c,array[j].c)>0){ //如果i的名字比j的字典序大那就交换位置
              tmp = array[i];
	          array[i] = array[j];
              array[j] = tmp;
            }
        }
}

