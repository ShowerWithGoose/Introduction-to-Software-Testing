#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct S
{
    int a;
    int b;
    int c;
    int d;
    int mark;
};

int main()
{
     int n,i,k,count,max=0,x = 100000,y,x1,y1,a1,b1,c1,d1;
     struct S line[100];
     scanf("%d",&n);
     for(int i = 0;i<n;i++)
     {
         scanf("%d%d%d%d",&line[i].a,&line[i].b,&line[i].c,&line[i].d);
         line[i].mark = 0;
     }

     for(k = 0;k<n;k++)
     {
             count = 0;
             x1 = line[k].a;
             y1 = line[k].b;
             a1 = x1;
             b1 = y1;
             c1 = line[k].c;
             d1 = line[k].d;
            A:for(i = 0;i<n;i++)
             {
                if(line[i].mark == 1)
                {
                    continue;
                }
                 if(((a1==line[i].a)&&(b1==line[i].b))||((c1==line[i].c)&&(d1==line[i].d))||((a1==line[i].c)&&(b1==line[i].d))||((c1==line[i].a)&&(d1==line[i].b)))
                 {
           //          printf("here! k is %d\n and a1 is %d,b1 is %d,i.a is %d,i.b is %d\n",k,a1,b1,line[i].a,line[i].b);
                     count++;
                     line[i].mark = 1;
                     if(line[i].a<a1)
                     {
                         x1 = line[i].a;
                         y1 = line[i].b;
                     }
                     a1 = line[i].a;
                     b1 = line[i].b;
                     c1 = line[i].c;
                     d1 = line[i].d;
                     goto A;
                 }
             }
   //          printf("count is %d and max is %d and  x is %d and y is %d\n\n",count,max,x,y);
             if(count>max)
             {
                 max = count;
                 x = x1;
                 y = y1;
             }
         for(int i = 0;i<n;i++)
        {
           line[i].mark = 0;
        }
     }
     printf("%d %d %d",max,x,y);
     return 0;
}

