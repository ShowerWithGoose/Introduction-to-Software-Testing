#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void pl(int n);
int main()
{
    int n;
    scanf("%d",&n);
    pl(n);
    return 0;
}

void pl(int n)
{
    int x,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
    rusg:for(i1=1;i1<=n;i1++)
    {
        if(n==1)
        {
            printf("%d\n",i1);
            continue;
        }
        for(i2=1;i2<=n;i2++)
        {
            if(i2==i1)
            {
                continue;
            }
            if(n==2)
            {
                printf("%d %d\n",i1,i2);
                continue;
            }
            for(i3=1;i3<=n;i3++)
            {
                if(i3==i1||i3==i2)
                {
                    continue;
                }
                if(n==3)
                {
                    printf("%d %d %d\n",i1,i2,i3);
                    continue;
                }
                    for(i4=1;i4<=n;i4++)
                    {
                        if(i4==i1||i4==i2||i4==i3)
                        {
                            continue;
                        }
                        if(n==4)
                        {
                            printf("%d %d %d %d\n",i1,i2,i3,i4);
                            continue;
                        }
                            for(i5=1;i5<=n;i5++)
                            {
                                if(i5==i1||i5==i2||i5==i3||i5==i4)
                                {
                                    continue;
                                }
                                if(n==5)
                                {
                                    printf("%d %d %d %d %d\n",i1,i2,i3,i4,i5);
                                    continue;
                                }
                                for(i6=1;i6<=n;i6++)
                                {
                                    if(i6==i1||i6==i2||i6==i3||i6==i4||i6==i5)
                                    {
                                        continue;
                                    }
                                    if(n==6)
                                    {
                                        printf("%d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i6);
                                        continue;
                                    }
                                    for(i7=1;i7<=n;i7++)
                                    {
                                        if(i7==i1||i7==i2||i7==i3||i7==i4||i7==i5||i7==i6)
                                        {
                                            continue;
                                        }
                                        if(n==7)
                                        {
                                            printf("%d %d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i6,i7);
                                            continue;
                                        }
                                        for(i8=1;i8<=n;i8++)
                                        {
                                            if(i8==i1||i8==i2||i8==i3||i8==i4||i8==i5||i8==i6||i8==i7)
                                            {
                                                continue;
                                            }
                                            if(n==8)
                                            {
                                                printf("%d %d %d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i6,i7,i8);
                                                continue;
                                            }
                                            for(i9=1;i9<=n;i9++)
                                            {
                                                if(i9==i1||i9==i2||i9==i3||i9==i4||i9==i5||i9==i6||i9==i7||i9==i8)
                                                {
                                                    continue;
                                                }
                                                if(n==9)
                                                {
                                                    printf("%d %d %d %d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i6,i7,i8,i9);
                                                    continue;
                                                }
                                                for(i10=1;i10<=n;i10++)
                                                {
                                                    if(i10==i1||i10==i2||i10==i3||i10==i4||i10==i5||i10==i6||i10==i7||i10==i8)
                                                    {
                                                        continue;
                                                    }
                                                    else
                                                    {
                                                        printf("%d %d %d %d %d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i6,i7,i8,i9,i10);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                    }
            }
        }
    }
    fin:x=0;
}


