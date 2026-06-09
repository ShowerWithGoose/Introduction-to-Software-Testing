#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct pair
{
    char word[50];
    int time;
} dic[50];

struct pair *pdic[50];

int main()
{
    FILE *fin = fopen("article.txt", "r");
    int all = 0;
    char buf[50], *pbuf, c;
    int flag = 0;
    pbuf = (char *)malloc(sizeof(char) * 50);
    for (;;)
    {
        memset(pbuf, 0, 50 * sizeof(char));
        flag=0;
		int p = 0;
        for (;;)
        {
            c = fgetc(fin);
            if (isalpha(c))
            {
                pbuf[p] = tolower(c);
                p++;
            }
            else
            {
            	if(p>0) break;
            	if(p==0&&c==EOF) goto A; 
			}
        }

        for (int i = 0; i < all; i++)
        {
            if (strcmp(pbuf, pdic[i]->word) == 0)
            {
                flag = 1;
                pdic[i]->time++;
                break;
            }
        }
        if (!flag)
        {
            strcpy(dic[all].word, pbuf);
            dic[all].time++;
            int it;
            for (it = 0; it < all; it++)
            {
                if (strcmp(pbuf, pdic[it]->word) < 0)
                    break;
            }
            for (int re = all; re > it; re--)
            {
                pdic[re] = pdic[re - 1];
            }
            pdic[it] = &dic[all];
            all++;
        }
        
        A:if (c == EOF)
            break;
    }
    for (int i = 0; i < all; i++)
    {
        printf("%s %d\n", pdic[i]->word, pdic[i]->time);
    }
    fclose(fin);
    free(pbuf);
    return 0;
}



