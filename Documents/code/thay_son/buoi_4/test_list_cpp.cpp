#include<bits/stdc++.h>
#include <list>
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

list <int> l;
std::list <int>::iterator it,it1,it2;

void show(){

    for (it= l.begin();it!= l.end();++it){
        cout<<*it<<" ";
	}

}

int main()
{
	//freopen("t.txt","r",stdin);

	for (int i=1;i<=10;i++)
	l.push_back(i);

	it1= l.begin();
	it2= l.end();
	advance(it2,-6);

    l.erase(it1,it2);
    show();
	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
