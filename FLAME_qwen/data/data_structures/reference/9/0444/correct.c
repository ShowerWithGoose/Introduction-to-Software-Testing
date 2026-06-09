#include<stdio.h>
struct line
{
    int startx;
    int starty;
    int endx;
    int endy;
    int number;
}line[200];
int main(){
    int a;
    int shu1[200],shu2[200];
    int b,c,d,e,f,g,h,k;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d%d%d%d",&line[i].startx,&line[i].starty,&line[i].endx,&line[i].endy);
        line[i].number=1;
    }
    for(int i=0;i<a-1;i++)
        for(int j=0;j<a-1-i;j++)
            if(line[j].startx>line[j+1].startx)
        {
            b=line[j].startx;
            line[j].startx=line[j+1].startx;
            line[j+1].startx=b;
            c=line[j].starty;
            line[j].starty=line[j+1].starty;
            line[j+1].starty=c;
            d=line[j].endx;
            line[j].endx=line[j+1].endx;
            line[j+1].endx=d;
            e=line[j].endy;
            line[j].endy=line[j+1].endy;
            line[j+1].endy=e;
        }
     for(int i=0;i<a;i++)
     {
        f=i;
        for(int j=i+1;j<a;j++)
        {
           if(line[i].endx==line[j].startx&&line[i].endy==line[j].starty)
           {
               line[f].number++;
               i=j;
           }
        }
        i=f;
     }
     for(int i=0;i<a;i++)
     {
         shu1[i]=line[i].number;
         shu2[i]=i;
     }
     for(int i=0;i<a-1;i++)
        for(int j=0;j<a-1-i;j++)

         if(shu1[j]>shu1[j+1])
        {
                g=shu1[j];
            shu1[j]=shu1[j+1];
            shu1[j+1]=g;
            h=shu2[j];
            shu2[j]=shu2[j+1];
            shu2[j+1]=h;
        }
     k=shu2[a-1];
     printf("%d %d %d",shu1[a-1],line[k].startx,line[k].starty);
    return 0;
}



