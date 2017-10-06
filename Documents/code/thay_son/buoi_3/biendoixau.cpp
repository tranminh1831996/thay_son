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

int min_3(int x,int y,int z){
    return min (min(x,y),z);
}



int main()
{
	//freopen("t.txt","r",stdin);
	string x= " PBBCEFATZ";
	string y= " QABCDABEFA";
	int f[100][100];
    int n= x.length();
    int m= y.length();
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (i==0||j==0){
                f[0][j]=j;
                f[i][0]=i;
            }
            else {
                if (x[i]==y[j]){
                    f[i][j]=f[i-1][j-1];
                }
                else{
                    f[i][j]=min_3 (f[i-1][j],f[i-1][j-1],f[i][j-1])+1;
                }
            }
        }
    }

    cout<<f[n][m]<<endl;

    while (m!=0 || n!=0){

        if (x[n]==y[m]) {n--;m--;}
        else{
            cout<<x<<"  ->   ";
            // phep chen
            if (f[n][m]==f[n]  [m-1]+1){
                cout<<" Insert"<<"("<<n<<","<<y[m]<<")";
                string temp(1,y[m]);
                x.insert(n+1,temp);
                m--;

            }
            // phep thay the
           else if (f[n][m]==f[m-1][n-1]+1){
                cout<<" Replace"<<"("<<n<<","<<y[m]<<")";
                x[n]=y[m];
                n--;m--;
            }
             // phep xoa
            else //(f[n][m]==f[n-1][m]  +1)
            {
                cout<<" Delete"<<"("<<n<<")";
                x.erase(n,1);

                n--;
            }
            cout<<"  ->  "<<x<<endl;
        }


    }

	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
