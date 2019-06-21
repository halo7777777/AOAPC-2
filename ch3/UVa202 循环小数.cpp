#include <stdio.h>
#include <string.h>
char ans[10001];
int main()
{
    int a, b, j = 0, kase = 0;
    while(scanf("%d%d",&a,&b) != EOF)
    {
        int i, T, temp = a;
        j = 0;
        if(kase) printf("\n");
        kase++;
        memset(ans,0,sizeof(ans));
        int k = a/b;
        a %= b;
        //高精部分start
        while(j <= 10000)
        {
            a *= 10;
            ans[j++] = a/b+'0';
            a %= b;
        }
        //高精部分end
        //判断周期长度start
        for(T = 1; T <= 5000; T++)
        {
/**重要**/    for(i = 10000-2*T; i <= 10000-T; i++) //还未知道循环起始位置，需要倒着判断
            {
                if(ans[i] != ans[i+T])
                {
                    break;
                }
            }
            if(i == 10001-T)
            {
                break;  //找到最小的循环周期
            }
        }
        //判断周期长度end
        printf("%d/%d = ",temp,b);
        //判断循环起始位置start
        for(j = 10000; j >= T; j--)
        {
            if(ans[j] != ans[j-T])
            {
                break;
            }
        }
        if(j == T - 1)
        {
            j = 0;
        }
        else
        {
            j = j - T + 1;
        }
        //判断循环起始位置end
        printf("%d.",k);
        for(i = 0;i <= j-1 && i < 51; i++)
        {
            if(i == 50)
            {
                printf("...");
                break;
            }
            printf("%c",ans[i]);
        }
        printf("(");
        for(i = j; i < j+T && i < 51; i++)
        {
            if(i == 50)
            {
                printf("...");
                break;
            }
            printf("%c",ans[i]);
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n",T);
    }
    printf("\n");
    return 0;
}
