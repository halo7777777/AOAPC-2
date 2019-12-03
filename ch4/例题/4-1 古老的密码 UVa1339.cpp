/*
P73  Uva1339
本题顺序字母都可以改变
**只需要判断排序后的次数数组是否相同**
即可以判断是否可变换
*/
#include<bits/stdc++.h>
using namespace std;
char a[100001], b[100001];
int cnt1[26], cnt2[26];
int main()
{
    while(scanf("%s %s",a,b) != EOF)
    {
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        int length = strlen(a);
        for(int i = 0; i < length; i++)
        {
            cnt1[a[i] - 'A']++;
            cnt2[b[i] - 'A']++;
        }
        sort(cnt1,cnt1+26);
        sort(cnt2,cnt2+26);
        int flag = 0;
        for(int i = 0; i < 26; i++)
        {
            if(cnt1[i] != cnt2[i])
            {
                flag = 1;

            }
        }
        if(flag == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
