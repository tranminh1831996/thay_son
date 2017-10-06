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

struct matrix{
    int x,y,z;
};

int main()
{
	freopen("t.txt","r",stdin);
    int n; cin>>n;
    int a[100],pos=0,neg=0;
    for (int i=1;i<=n;i++) {cin>>a[i];pos+=a[i],neg-=a[i];}
    ii p;

    int l[100][100];
    memset(l,0,sizeof l);
    l[1][a[1]+pos+1]=1;


    //cout<<neg<<endl<<pos;
    //for (int i=1;i<=n;i++) cout<<a[i]<<" ";


    for (int i=1;i<=n;i++){

        for (int j=neg;j<=pos;j++){

            if (j<0){
                if ( l[i-1][j+pos+1+a[i]]==1 )
                    l[i][j+pos+1]=l[i-1][j+pos+1+a[i]];

            }
            if (j>=0){
                if ( l[i-1][j+pos+1-a[i]]==1 )
                l[i][j+pos+1]=l[i-1][j+pos+1-a[i]];

            }

        }


    }
    /*
    for (int i=1;i<=n;i++){

        for (int j=neg;j<=pos;j++){
            cout<<l[i][j+pos+1]<<" ";
        }
       cout<<endl;
    }
    */
    int x; cin>>x;
    if (!l[n][x+pos+1])
    {
        cout<<"NO"; return 0;
    }
    while (n>=0){
        if ( x<0 ){
            if (l[n][x+pos+1]==1){
                cout<<"-"<<a[n]<<" ";
                x+=a[n];
            }
            //x-pos-1
        }
        if (x>=0){
            if (l[n][x+pos+1]==1){
                cout<<" +"<<a[n]<<" ";
                x-=a[n];
            }
        }
        n--;

    }



	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
