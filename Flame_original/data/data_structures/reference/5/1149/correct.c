#include <stdio.h>
#include <string.h>
struct ELE
{
    int xi;
    int zhi;
};
int main()
{
    int i,j,k=0,l,m,len,lenf,lens,len1,len2,ff1[100],ff2[100],lenff1=0,lenff2=0,ten=1;
    struct ELE f1[100],f2[100],fop[10000];
    char fir[100],sec[100];
    for(i=0;i<100;i++)
    {
        ff1[i]=0;
        ff2[i]=0;
        fir[i]=0;
        sec[i]=0;
    }
    gets(fir);
    gets(sec);
    lenf=strlen(fir);
    lens=strlen(sec);
    for(i=0;i<=lenf;i++)
    {
        if(fir[i]==32 || i==lenf)
        {
            ten=1;
            for(j=1;j<=k;j++)
            {
                ff1[lenff1]+=(fir[i-j]-'0')*ten;
                ten=ten*10;
            }
            k=0;
            lenff1++;
        }
        else
        {
            k=k+1;
        }
    }
    k=0;
    for(i=0;i<=lens;i++)
    {
        if(sec[i]==32 || i==lens)
        {
            ten=1;
            for(j=1;j<=k;j++)
            {
                ff2[lenff2]+=(sec[i-j]-'0')*ten;
                ten=ten*10;
            }
            k=0;
            lenff2++;
        }
        else
        {
            k=k+1;
        }
    }
    j=0;
    for(i=0;i<(lenff1/2);i=i+1)
    {
        f1[i].xi=ff1[j];
        f1[i].zhi=ff1[j+1];
        j=j+2;
    }
    j=0;
    for(i=0;i<(lenff2/2);i=i+1)
    {
        f2[i].xi=ff2[j];
        f2[i].zhi=ff2[j+1];
        j=j+2;
    }
    len1=lenff1/2;
    len2=lenff2/2;
    k=0;
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            fop[k].xi=f1[i].xi*f2[j].xi;
            fop[k].zhi=f1[i].zhi+f2[j].zhi;
            k++;
        }
    }
    len=len1*len2;
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(fop[j].zhi>=0)
            {
                if(fop[i].zhi==fop[j].zhi)
                {
                    fop[i].xi+=fop[j].xi;
                    fop[j].zhi=-1;
                }
            }
        }
    }
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-1;j++)
        {
            if(fop[j].zhi<fop[j+1].zhi)
            {
                l=fop[j].zhi;
                fop[j].zhi=fop[j+1].zhi;
                fop[j+1].zhi=l;
                l=fop[j].xi;
                fop[j].xi=fop[j+1].xi;
                fop[j+1].xi=l;
            }
            if(fop[j].zhi==fop[j+1].zhi && fop[j].xi<fop[j+1].xi)
            {
                l=fop[j].zhi;
                fop[j].zhi=fop[j+1].zhi;
                fop[j+1].zhi=l;
                l=fop[j].xi;
                fop[j].xi=fop[j+1].xi;
                fop[j+1].xi=l;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        if(fop[i].zhi>=0 && fop[i].xi != 0)
        {
            printf("%d %d ",fop[i].xi,fop[i].zhi);
        }
        if(fop[i].zhi==0)
        {
            break;
        }
    }
}

