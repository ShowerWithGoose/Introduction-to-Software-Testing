#include<stdio.h>
int zhan[100];
int main()
{
    int a,b,i=0;
    while(scanf("%d",&a)!=EOF)
    {
        if(a==1)
        {
            scanf("%d",&b);
            if(i>=100)
            printf("error ");
            zhan[i]=b;
            i++;

        }
        else if(a==0)
        {
            i--;
            if(i<0){
            printf("error ");
            i++;}
           
           else
            printf("%d ",zhan[i]);
             
            
        }
        else 
        {
            break;
        }
    }
    
    return 0;
}
