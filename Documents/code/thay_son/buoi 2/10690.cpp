#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
const char *fi ="";
const char *fo ="";
const int  MAXN = 10000;
const ld EPS = 1e-9;
fstream f;




int main()
{
	//freopen("t.txt","r",stdin);
	int n,m;
	while (cin>>n>>m){
        int a[n+m+1];
        int sum=0;
        for (int i=1;i<=n+m;i++)
        { cin>>a[i];sum+=a[i]; a[i]+=50; }

        bool dp[105][10005]={false};

        dp[0][0]=true;

        for (int i=1;i<=n+m;++i)
            for (int k= min (i,n); k>=1;--k )
                for (int j=0;j<=10000;++j)
                    if (dp[k-1][j])
                        dp[k][j+a[i]]=true;


        int maximum = -5000;
        int minimum = 5000;

        for (int i=0;i<=10000;++i){
            if (dp[n][i])
            {
                int t_sum= i- 50*n;
                maximum = max (maximum, t_sum * (sum-t_sum));
                minimum = min (minimum, t_sum * (sum-t_sum));



            }
        }
        cout<< maximum<<" "<<minimum<<endl;


	}


	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
