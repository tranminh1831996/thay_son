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
//fstream f;


int main()
{
	//freopen("t.txt","r",stdin);
	 int n,m;
   //

    cin>>n>>m;
     int w[100],v[100];

    for (int i=1; i<=n;i++){
        cin>>w[i]>>v[i];
    }

    long l[108][108]={0};
    for (int i=0;i<=n;i++) {l[0][i]=0;l[i][0]=0;}

    for (int i=1;i<=n;i++){

        for (int j=1;j<=m;j++){

            if (j>=w[i]){

                l[i][j]= max ( l[i-1][j] , (l[i-1][j-w[i]] +v[i]) );

            }

            else l[i][j] = l[i-1][j];

        }
    }

    cout<<l[n][m]<<endl;
    //truyvet(n,m);
    while (n>0){
        if (l[n][m]!=l[n-1][m]){
            cout<<n<<" ";
            m=m-w[n];
        }
        n--;
    }


	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
