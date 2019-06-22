//***************注意定义变量的范围****************
//尽量不要改变循环自变量
//注意函数的正确返回值，非0不一定返回的是1
#include<cstdio>
#include<cstring>
#include<cctype>
#define MAXN 100

int main()
{
    int T;
    char s[MAXN] = {0};
    scanf("%d",&T);
    while(T--)
    {
        int a[MAXN] = {0};
        double weight;
        scanf("%s",s);
        int len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            if(isalpha(s[i]) == 1)
            {
                int omit = 1;
                int m = 0;
                char flag = s[i];
                a[s[i]]++;
                i++;
                for(;i < len && isdigit(s[i]) != 0;i++)
                {
                    omit = 0;
                    m = 10*m + (s[i]-'0');
                }
                if(omit == 0)
                    a[flag] += (m-1);
                i--;
            }
        }
        weight = 12.01*a['C'] + 1.008*a['H'] + 16.00*a['O'] + 14.01*a['N'];
        printf("%.3f\n",weight);
    }
    return 0;
}

//正确答案
/*
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char * argv[])
{
    double weight;//计数器，记录当前原子的原子量
    int count;//计数器，记录当前原子的多少
    double ans;//计数器，记录分子式总重量
    bool flag;//计数器，记录是否是字母后读到的第一个数字
    char formula[85];//记录一条分子式
    int n;//数据条数
    scanf("%d\n",&n);//之后需要读入整行，这里要把\n一起读了，特别是用cin的时候小心这个问题
    for (int i = 0; i < n; ++i)//对每一个分子式
    {
        //每次要根据计数器的意义，进行初始化
        ans = 0.0;
        count = 0;//初值为设0就可以直接开始循环，想想为什么
        flag = false;
        scanf("%s",formula);//如果有空格，就用cin.getline(formula, 85)
        for (int i = 0; i < strlen(formula); ++i)
        {
            switch (formula[i])
            {
                case 'C':
                    ans += (weight * count);//读到了新的原子，就可以把上一个原子的总重量加上去了
                    weight = 12.01;//只需要记录当前分子的重量
                    count = 1, flag = false;//count设置为1，若下一个仍是字母，就可以直接输入啦
                    break;
                case 'H':
                    ans += (weight * count);
                    weight = 1.008;
                    count = 1, flag = false;
                    break;
                case 'O':
                    ans += (weight * count);
                    weight = 16.00;
                    count = 1, flag = false;
                    break;
                case 'N':
                    ans += (weight * count);
                    weight = 14.01;
                    count = 1, flag = false;
                    break;
                default://剩下的就是读到数字的情况
                    if(!flag) count = formula[i] - '0';//如果是字母后读到的第一个数字
                    else count = count * 10 + (formula[i] - '0');
                    flag = true;
            }
        }
        ans += (weight * count);//别忘了最后一组还没算呢
        printf("%.3f\n",ans);
    }
    return 0;
}
*/
