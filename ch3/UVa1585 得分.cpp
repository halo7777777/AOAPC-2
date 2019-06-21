#include<cstdio>
#include<cstring>
#define MAXN 85

int main()
{
    char s[MAXN];
    int T = 0;
    scanf("%d",&T);
    while(T--)
    {
        int score = 0, len = 0, add = 1;
        scanf("%s",s);
        len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'O')
            {
                score += add;
                add++;
            }
            else
                add = 1;
        }
        printf("%d\n",score);
    }
    return 0;
}
