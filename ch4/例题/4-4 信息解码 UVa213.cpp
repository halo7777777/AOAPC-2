/*测试数据

输入
$#**\
0100000101101100011100101000
输出
##*\$

*/
#include<bits/stdc++.h>
using namespace std;
int readchar()        //跨行读字符
{
    for(;;)
    {
        int ch = getchar();
        if(ch != '\n' && ch != '\r')
            return ch;
    }
}
int readint(int c)   //读取c位二进制字符并转化为十进制
{
    int v = 0;
    while(c--)
        v = v * 2 + readchar() -'0';
    return v;
}
int code[8][1<<8];
int readcodes()      //用于读取编码
{
    memset(code, 0, sizeof(code));
    code[1][0] = readchar();
    for(int len = 2; len < 8; len++)
    {
        for(int i = 0; i < (1 << len) - 1; i++)
        {
            int ch = getchar();
            if(ch == EOF)
                return 0;
            if(ch == '\n' || ch == '\r')
                return 1;
            code[len][i] = ch;
        }
    }
    return 1;
}
void printcodes()
{
    for(int len = 1; len < 8; len++)
    {
        for(int i = 0; i < (1<<len)-1; i++)
        {
            if(code[len][i] == 0)
                return;
           printf("code[%d][%d] = %c\n", len, i, code[len][i]);
        }
    }
}
int main()
{
    while(readcodes())
    {
       printcodes();
        for(;;)
        {
            int len = readint(3);         //每个小节的前3个数字代表小节中每个编码的长度
            if(len == 0)
                break;
        printf("len = %d\n", len);
            for(;;)
            {
            int v = readint(len);
   //          printf("v = %d\n",v);
                if(v == (1 << len) - 1)
                    break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}

