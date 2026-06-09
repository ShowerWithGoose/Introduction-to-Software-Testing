#include<stdio.h>
int main()
{
    int numstk[1000] = { 0 };
    char fomu[1000] = "", opstk[1000] = "";
    gets(fomu); // @@ gets() has been removed from the C11 standard and causes compilation errors in modern compilers; replace with fgets(fomu, sizeof(fomu), stdin)

    //24 / 4 / 3 / 2 + 100 - 50 - 40 + 10*20*30*40 / 40 / 30 =
    int j = 0, k = 0;
    for (int i = 0; fomu[i] != '='; i++)
    {
        if ((fomu[i] == '+') || (fomu[i] == '-') || (fomu[i] == '*') || (fomu[i] == '/'))
            opstk[j++] = fomu[i];
        else if (fomu[i] <= '9' && fomu[i] >= '0')
        {
            numstk[k] = fomu[i] - '0';
            while (fomu[i + 1] <= '9' && fomu[i + 1] >= '0')
            {
                numstk[k] = numstk[k] * 10 + (fomu[i + 1] - '0');
                i++;
            }
            k++;
        }
    }//简化式子
    opstk[j] = '='; k--;
    /// / / +--+***/ / =
    //    24 4 3 2 100 50 40 10 20 30 40 40 30
    int x = 0;
    int flag = 0; int t = -999;
    for (int i = 0;opstk[i]!='=';i++ )
    {
        if (opstk[i] == '*') {
            x++;
            numstk[x] = numstk[x] * numstk[x - 1];
        }

        else if (opstk[i] == '/') {
            x++;
            numstk[x] = numstk[x - 1] / numstk[x];
        }
        else if (opstk[i] == '+')
        {
            if(flag == 0)
            {    
                flag = 1;
                t = numstk[x];
                x++;
            }
            else if (flag == 1)
            {
                numstk[x] += t;
                x++;
                t = numstk[x - 1];
            }
            else if (flag == 2)
            {
                numstk[x] = t-numstk[x];
                x++;
                t = numstk[x - 1];
                flag = 1;
            }
        }
        else if (opstk[i] == '-')
        {
            if (flag == 0)
            {
                flag = 2;
                t = numstk[x];
                x++;
            }
            else if (flag == 2)
            {
                numstk[x] = t-numstk[x];
                x++;
                t = numstk[x - 1];
            }
            else if (flag == 1)
            {
                numstk[x] += t; 
                ++x;
                t = numstk[x - 1];
                flag = 2;
            }
        }
    }
    if (flag == 1)printf("%d", numstk[x] + t);
    if (flag == 2)printf("%d",  t - numstk[x]);
    if (!flag)printf("%d", numstk[x]);
    return 0;
}