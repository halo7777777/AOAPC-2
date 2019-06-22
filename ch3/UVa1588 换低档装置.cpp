
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000
char a[MAXN] = {0};
char b[MAXN] = {0};
int main()
{
    while(scanf("%s %s",a,b) != EOF)
    {
        int alen = strlen(a), blen = strlen(b);
        int t1 = 0,t2 = 0;
        for(t1 = 0; t1 < alen; t1++)
        {
            int i = 0, j = 0;
            for(i = 0, j = 0; i+t1 < alen && j < blen; i++, j++)
            {
                if(a[t1+i]-'0'+b[j]-'0' > 3)
                {
                    break;
                }
            }
            if(j == blen||i+t1 == alen)
                break;

        }
        t1 = max(t1+blen,alen);
        for(t2 = 0; t2 < blen; t2++)
        {
            int i = 0, j = 0;
            for(i = 0, j = 0; i < alen && j+t2 < blen; i++, j++)
            {
                if(a[i]-'0'+b[t2+j]-'0' > 3)
                {
                    break;
                }
            }
            if(i == alen || j+t2 == blen)
                break;

        }
        t2 = max(t2+alen,blen);

        printf("%d\n",min(t1,t2));
    }
    return 0;
}

/*
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[105], t[105];
    int len1, len2, len;
    while(cin>>s>>t)
    {
        int i, j, x, y;
        int len1 = strlen(s), len2 = strlen(t);
        for( i=0; i<len1; i++ )
        {
            bool flag = true;
            for( j=0; j<len2 && j+i<len1 ; j++ )
                if(s[i+j]=='2'&&t[j]=='2')
                  {flag = false; break;}
            if(flag)
                break;

        }
        x = max(len1, len2+i);
        i = j = 0;
        for( i=0; i<len2; i++ )
        {
            bool flag = true;
            for( j=0; j<len1 && j+i<len2; j++ )
                if(t[i+j]=='2'&&s[j]=='2')
                  {flag = false; break ;}
            if(flag)
                break;
        }
        y = max(len2, len1+i);
    cout<<min(x,y)<<endl;
    }
    return 0;
}
*/
