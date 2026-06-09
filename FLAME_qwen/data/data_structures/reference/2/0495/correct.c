#include <stdio.h>

typedef struct adder {
    int sign; // sign, 1 or -1
    int start; // starting position & length of the adder
    int len;
} Adder;
typedef struct timer {
    int type; // type, 0 for times, 1 for divided by
    int start; // starting position & length of the timer
    int len;
} Timer;

int calc_adder(char*, int);

int main()
{

    char str[10005]; int i, j;
    char ch;

    Adder addr[10005];
    int addr_idx, addr_len;

    Timer tmr[10005];
    int tmr_idx, tmr_len;

    int sum, timesup;

    char cvrt_str[10005];
    int cvrt_num;

    // input

    gets(str);

    // remove spaces

    for (i = j = 0; str[i]; i++)
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    // init the 1st adder

    addr_idx = 0;
    addr[addr_idx].sign = 1;
    addr[addr_idx].start = 0;

    // scan adders

    for (i = 0; str[i]; i++)
    {
        ch = str[i];
        if (ch == '=' || str[i] == 0) // met '=', finish
        {
            addr[addr_idx].len = (int)(i - addr[addr_idx].start); // finish the prev adder
            break;
        }
        if (ch == '+' || ch == '-') // met '+' / '-', start a new adder
        {
            addr[addr_idx].len = (int)(i - addr[addr_idx].start); // finish the prev adder
            addr_idx++; // move to a new adder
            addr[addr_idx].sign = (ch == '+') ? 1 : -1;
            addr[addr_idx].start = i+1;
        }
    }
    addr_len = addr_idx + 1;

    // calculate adders & sum up

    sum = 0;
    for (addr_idx = 0; addr_idx < addr_len; addr_idx++)
    {

        // init the 1st timer
            
        tmr_idx = 0;
        tmr[tmr_idx].type = 0;
        tmr[tmr_idx].start = addr[addr_idx].start;

        for (i = addr[addr_idx].start; i - addr[addr_idx].start < addr[addr_idx].len; i++)
        {
            ch = str[i];
            if (ch == '*' || ch == '/') // met '*' / '/', start a new timer
            {
                tmr[tmr_idx].len = (int)(i - tmr[tmr_idx].start); // finish the prev timer
                tmr_idx++; // move to a new timer
                tmr[tmr_idx].type = (ch == '*') ? 0 : 1;
                tmr[tmr_idx].start = i+1;
            }
        }
        tmr[tmr_idx].len = (int)(i - tmr[tmr_idx].start); // finish the last timer
        tmr_len = tmr_idx + 1;

        // time up the timers

        timesup = 1;
        for (tmr_idx = 0; tmr_idx < tmr_len; tmr_idx++)
        {
            tmr[tmr_idx] = tmr[tmr_idx];
            // scanf the num
            for (j = tmr[tmr_idx].start; j - tmr[tmr_idx].start < tmr[tmr_idx].len; j++)
            {
                cvrt_str[j - tmr[tmr_idx].start] = str[j];
            }
            cvrt_str[j - tmr[tmr_idx].start] = '\0';
            if (cvrt_str[0]=='\0')
            {
                cvrt_num = 1;
            }
            else
            {
                sscanf(cvrt_str, "%d", &cvrt_num);
            }
            // time up
            if (tmr[tmr_idx].type == 0)
                timesup *= cvrt_num;
            else if (tmr[tmr_idx].type == 1)
            {
                timesup /= cvrt_num;
            }
        }

        // sum up

        sum += addr[addr_idx].sign * timesup;

    }

    printf("%d", sum);

    return 0;
}



