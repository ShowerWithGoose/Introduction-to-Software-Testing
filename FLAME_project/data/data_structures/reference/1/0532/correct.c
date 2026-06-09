#include <stdio.h>
#include <string.h>
int main(){
int n;
scanf("%d",&n);
switch(n)
{
    case 1:printf("1");break;
    case 2:for(int n1=1;n1<=n;n1++)
    {
        printf("%d ",n1);
        for(int n2=1;n2<=n;n2++)
            if(n2!=n1)
            printf("%d\n",n2);
    }break;
    case 3:for(int n1=1;n1<=n;n1++)
    {
        for(int n2=1;n2<=n;n2++)
        if(n2!=n1)
            {   printf("%d ",n1);
                printf("%d ",n2);
        for(int n3=1;n3<=n;n3++)
            if(n3!=n2&&n3!=n1)
            printf("%d\n",n3);
        }
    }break;
    case 4:for(int n1=1;n1<=n;n1++)
    {
        for(int n2=1;n2<=n;n2++)
        if(n2!=n1)
            {
        for(int n3=1;n3<=n;n3++)
            if(n3!=n2&&n3!=n1)
            {  printf("%d ",n1);
                printf("%d ",n2);
                printf("%d ",n3);
            for(int n4=1;n4<=n;n4++)
                if(n4!=n3&&n4!=n2&&n4!=n1)
                printf("%d\n",n4);

            }
        }
    }break;
    case 5:for(int n1=1;n1<=n;n1++)
    {
        for(int n2=1;n2<=n;n2++)
        if(n2!=n1)
           {
        for(int n3=1;n3<=n;n3++)
            if(n3!=n2&&n3!=n1)
            {
            for(int n4=1;n4<=n;n4++)
                if(n4!=n3&&n4!=n2&&n4!=n1)
             {  printf("%d ",n1);
                printf("%d ",n2);
                printf("%d ",n3);
                printf("%d ",n4);
                for(int n5=1;n5<=n;n5++)
                if(n5!=n4&&n5!=n3&&n5!=n2&&n5!=n1)
                printf("%d\n",n5);
               }

            }
        }
    }break;
    case 6:for(int n1=1;n1<=n;n1++)
    {
        for(int n2=1;n2<=n;n2++)
        if(n2!=n1)
        {for(int n3=1;n3<=n;n3++)
            if(n3!=n2&&n3!=n1)
            {for(int n4=1;n4<=n;n4++)
                if(n4!=n3&&n4!=n2&&n4!=n1)
                {for(int n5=1;n5<=n;n5++)
                if(n5!=n4&&n5!=n3&&n5!=n2&&n5!=n1)
                {printf("%d ",n1);
                printf("%d ",n2);
                printf("%d ",n3);
                printf("%d ",n4);
                printf("%d ",n5);
                for(int n6=1;n6<=n;n6++)
                if(n6!=n5&&n6!=n4&&n6!=n3&&n6!=n2&&n6!=n1)
                printf("%d\n",n6);
               }
               }

            }
        }
    }break;
    case 7:for(int n1=1;n1<=n;n1++)
    {
        for(int n2=1;n2<=n;n2++)
        if(n2!=n1)
        {for(int n3=1;n3<=n;n3++)
            if(n3!=n2&&n3!=n1)
            {for(int n4=1;n4<=n;n4++)
                if(n4!=n3&&n4!=n2&&n4!=n1)
                {for(int n5=1;n5<=n;n5++)
                if(n5!=n4&&n5!=n3&&n5!=n2&&n5!=n1)
                {for(int n6=1;n6<=n;n6++)
                if(n6!=n5&&n6!=n4&&n6!=n3&&n6!=n2&&n6!=n1)
                {printf("%d ",n1);
                printf("%d ",n2);
                printf("%d ",n3);
                printf("%d ",n4);
                printf("%d ",n5);
                printf("%d ",n6);
                for(int n7=1;n7<=n;n7++)
                if(n7!=n6&&n7!=n5&&n7!=n4&&n7!=n3&&n7!=n2&&n7!=n1)
                printf("%d\n",n7);
                }
               }
               }

            }
        }
    }break;
    case 8:for(int n1=1;n1<=n;n1++)
    {
        for(int n2=1;n2<=n;n2++)
        if(n2!=n1)
        {for(int n3=1;n3<=n;n3++)
            if(n3!=n2&&n3!=n1)
            {for(int n4=1;n4<=n;n4++)
                if(n4!=n3&&n4!=n2&&n4!=n1)
                {for(int n5=1;n5<=n;n5++)
                if(n5!=n4&&n5!=n3&&n5!=n2&&n5!=n1)
                {for(int n6=1;n6<=n;n6++)
                if(n6!=n5&&n6!=n4&&n6!=n3&&n6!=n2&&n6!=n1)
                {for(int n7=1;n7<=n;n7++)
                if(n7!=n6&&n7!=n5&&n7!=n4&&n7!=n3&&n7!=n2&&n7!=n1)
                {printf("%d ",n1);
                printf("%d ",n2);
                printf("%d ",n3);
                printf("%d ",n4);
                printf("%d ",n5);
                printf("%d ",n6);
                printf("%d ",n7);
                for(int n8=1;n8<=n;n8++)
                if(n8!=n7&&n8!=n6&&n8!=n5&&n8!=n4&&n8!=n3&&n8!=n2&&n8!=n1)
                printf("%d\n",n8);
                }
                }
               }
               }

            }
        }
    }break;
    case 9:for(int n1=1;n1<=n;n1++)
    {
        for(int n2=1;n2<=n;n2++)
        if(n2!=n1)
        {for(int n3=1;n3<=n;n3++)
            if(n3!=n2&&n3!=n1)
            {for(int n4=1;n4<=n;n4++)
                if(n4!=n3&&n4!=n2&&n4!=n1)
                {for(int n5=1;n5<=n;n5++)
                if(n5!=n4&&n5!=n3&&n5!=n2&&n5!=n1)
                {for(int n6=1;n6<=n;n6++)
                if(n6!=n5&&n6!=n4&&n6!=n3&&n6!=n2&&n6!=n1)
                {for(int n7=1;n7<=n;n7++)
                if(n7!=n6&&n7!=n5&&n7!=n4&&n7!=n3&&n7!=n2&&n7!=n1)
                {for(int n8=1;n8<=n;n8++)
                if(n8!=n7&&n8!=n6&&n8!=n5&&n8!=n4&&n8!=n3&&n8!=n2&&n8!=n1)
                {printf("%d ",n1);
                printf("%d ",n2);
                printf("%d ",n3);
                printf("%d ",n4);
                printf("%d ",n5);
                printf("%d ",n6);
                printf("%d ",n7);
                printf("%d ",n8);
                for(int n9=1;n9<=n;n9++)
                if(n9!=n8&&n9!=n7&&n9!=n6&&n9!=n5&&n9!=n4&&n9!=n3&&n9!=n2&&n9!=n1)
                printf("%d\n",n9);
                }
                }
                }
               }
               }

            }
        }
    }break;
        case 10:for(int n1=1;n1<=n;n1++)
    {
        for(int n2=1;n2<=n;n2++)
        if(n2!=n1)
        {for(int n3=1;n3<=n;n3++)
            if(n3!=n2&&n3!=n1)
            {for(int n4=1;n4<=n;n4++)
                if(n4!=n3&&n4!=n2&&n4!=n1)
                {for(int n5=1;n5<=n;n5++)
                if(n5!=n4&&n5!=n3&&n5!=n2&&n5!=n1)
                {for(int n6=1;n6<=n;n6++)
                if(n6!=n5&&n6!=n4&&n6!=n3&&n6!=n2&&n6!=n1)
                {for(int n7=1;n7<=n;n7++)
                if(n7!=n6&&n7!=n5&&n7!=n4&&n7!=n3&&n7!=n2&&n7!=n1)
                {for(int n8=1;n8<=n;n8++)
                if(n8!=n7&&n8!=n6&&n8!=n5&&n8!=n4&&n8!=n3&&n8!=n2&&n8!=n1)
                {for(int n9=1;n9<=n;n9++)
                if(n9!=n8&&n9!=n7&&n9!=n6&&n9!=n5&&n9!=n4&&n9!=n3&&n9!=n2&&n9!=n1)
                {printf("%d ",n1);
                printf("%d ",n2);
                printf("%d ",n3);
                printf("%d ",n4);
                printf("%d ",n5);
                printf("%d ",n6);
                printf("%d ",n7);
                printf("%d ",n8);
                printf("%d ",n9);
                for(int n10=1;n10<=n;n10++)
                if(n10!=n9&&n10!=n8&&n10!=n7&&n10!=n6&&n10!=n5&&n10!=n4&&n10!=n3&&n10!=n2&&n10!=n1)
                printf("%d\n",n10);
                }
                }
                }
                }
               }
               }

            }
        }
    }break;
}

return 0;
}



