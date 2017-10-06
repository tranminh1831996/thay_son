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
const ll oo = 1e9;
const ld EPS = 1e-9;

bool a[20]={false};
list<int>::iterator it,it1,it2;
list<int> l;
ll n,m;

ll gt(int k){
    ll temp =1;
    for (int i=1;i<=k;i++) {temp*=i;}
    return temp;
}

void init(){
    for (int i=1;i<=n;i++) l.push_back(i);
}

void show (){
    for (it2=l.begin();it2!=l.end();++it2){
        cout<< *it2 <<" ";
    }
}

int main()
{
	freopen("t.txt","r",stdin);
    /*
4 1
4 2
4 3
4 4
4 5
4 6
4 7
4 8
4 9
4 10
4 11
4 12

    */
    while (cin>>n>>m)
    {
    l.clear();
    init();
    while (n>0){

        int r,d;
        ll temp_gt;
        temp_gt = gt(n-1);
        r= m%temp_gt;
        d= m/temp_gt;


        if (r==0){

            it = l.begin();
            advance(it,d-1);

            cout<<*it<<" ";
            l.erase(it);

            l.reverse();
            show();

            break;
        }
        else{

            it = l.begin();
            advance(it,d);
            cout<<*it<<" ";
            l.erase(it);
            n--;
            m = r;


         }

        }
        cout<<endl;
    }

	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
