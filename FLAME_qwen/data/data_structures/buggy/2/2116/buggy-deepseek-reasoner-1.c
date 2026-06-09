#include<stdio.h>
int main()
{
    int numstk[1000] = { 0 };
    char fomu[1000] = "", opstk[1000] = "";
    gets(fomu); // @@ gets is unsafe and deprecated; may cause buffer overflow in some environments

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
            numstk[x] = numstk[x] * numstk[x - 1]; // @@ This approach does not correctly handle operator precedence; multiplies left-to-right but mixes with pending additions/subtractions
        }

        else if (opstk[i] == '/') {
            x++;
            numstk[x] = numstk[x - 1] / numstk[x]; // @@ Similar issue: division performed left-to-right without respecting precedence of pending +/-
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
                numstk[x] += t; // @@ Incorrectly adds accumulated t to the current number; should instead keep a running sum
                x++;
                t = numstk[x - 1];
            }
            else if (flag == 2)
            {
                numstk[x] = t-numstk[x]; // @@ Should be adding the opposite; logic for subtraction and addition is flawed
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
                numstk[x] = t-numstk[x]; // @@ Should subtract from running total; current logic leads to incorrect results for consecutive subtractions
                x++;
                t = numstk[x - 1];
            }
            else if (flag == 1)
            {
                numstk[x] += t; // @@ Adds the previous sum instead of starting a new subtraction sequence
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