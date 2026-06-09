#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    char x1[10];
    char y1[10];

    char x2[10];
    char y2[10];

    char a[105];
    char b[105];//coordinate of line end

    int num;

}line[105];

int main()
{
    int n=0;
    scanf("%d",&n);//total number of lines

    int i=0;
    for(i=0;i<n;i++)//get lines' coordinates
    {
        scanf("%s",line[i].x1);
        scanf("%s",line[i].y1);
        sprintf(line[i].a,"%s %s",line[i].x1,line[i].y1);

        scanf("%s",line[i].x2);
        scanf("%s",line[i].y2);
        sprintf(line[i].b,"%s %s",line[i].x2,line[i].y2);
    }

    int j=0;
    for(i=0;i<n;i++)//select a line, update line[j].a/b, line[j].num=line[i].num+1
    {
        if(strcmp(line[i].a,"0")!=0&&strcmp(line[i].b,"0")!=0)
        {
            for(j=0;j<n;j++)
            {
                if(strcmp(line[i].b,line[j].a)==0)
                {
                    strcpy(line[i].x2,line[j].x2);
                    strcpy(line[i].y2,line[j].y2);
                    strcpy(line[j].a,"0");
                    strcpy(line[j].b,"0");
                    sprintf(line[i].b,"%s %s",line[i].x2,line[i].y2);
                    line[i].num=line[i].num+line[j].num+1;
                }

                else if(strcmp(line[i].a,line[j].b)==0)
                {
                    strcpy(line[i].x1,line[j].x1);
                    strcpy(line[i].y1,line[j].y1);
                    strcpy(line[j].a,"0");
                    strcpy(line[j].b,"0");
                    sprintf(line[i].a,"%s %s",line[i].x1,line[i].y1);
                    line[i].num=line[i].num+line[j].num+1;
                }
            }
        }
    }

    int maxnum=0;

    for(i=0;i<n;i++)
    {
        if(line[i].num>maxnum)
        {
            maxnum=line[i].num;
            j=i;
        }
    }

    printf("%d %s",maxnum+1,line[j].a);

    return 0;
}

















