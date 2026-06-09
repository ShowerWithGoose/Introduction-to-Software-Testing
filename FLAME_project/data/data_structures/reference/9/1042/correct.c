#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct coo
{
    int orgin[2];   //orgin[0] xo;orgin[1] yo
    int dest[2];    //destination[0] xd;destination[1] yd
};
struct coo line[101];
void choose_rise(int );
int main()
{
    int line_num=0,i=0,j=0,k=0,num=0,max=0,mid[2],max_coo[2];
    scanf("%d",&line_num);
    for(i=0;i<line_num;i++)
        scanf("%d%d%d%d",&line[i].orgin[0],&line[i].orgin[1],&line[i].dest[0],&line[i].dest[1]);
    choose_rise(line_num);
    for(i=0;i<line_num;i++)//to delect
    for(k=0;k<line_num;k++){
        i=k; num=0;
        for(i;i<line_num;i++){
        	num=0;
            for(j=0;j<line_num;j++){
                if(line[i].dest[0]==line[j].orgin[0]){
                    if(line[i].dest[1]==line[j].orgin[1]){
                        if(num==0){
                            mid[0]=line[i].orgin[0]; mid[1]=line[i].orgin[1];
                        }
                        num++;
                        i=j;
                    }
                }
            }
        }
        if(num>=max)
        {
            max=num;
            max_coo[0]=mid[0]; max_coo[1]=mid[1];
        }
    }
    printf("%d %d %d",max+1,max_coo[0],max_coo[1]);
    return 0;
}
void choose_rise(int n)
{
    struct coo buf;
    int i=0,j=0,min=0;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(line[min].orgin[0]>line[j].orgin[0])
                min=j;
        if(min!=i)
        {
            buf=line[min];
            line[min]=line[i];
            line[i]=buf;
        }
    }
}
