#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int>  vi;
typedef long double ld;
typedef long long ll;
const char *fi ="TAMGIAC.INP";
const char *fo ="";
const int  MAXN = 10000;
const double EPS = 1e-9;
fstream f;

int n,l[MAXN],truoc[MAXN];

struct tamgiac
{
  int x1,y1,x2,y2,x3,y3;
  double s,d1,d2,d3,p;
};
tamgiac a[MAXN];



bool kt ( tamgiac x, tamgiac y){

    // tinh dien tich cac tam giac
    double  temp_d1,temp_d2,temp_d3;

    temp_d1 = sqrt( pow( x.x1 - y.x1 , 2 ) + pow ( x.y1 - y.y1 , 2) );
    temp_d2 = sqrt( pow( x.x1 - y.x2 , 2 ) + pow ( x.y1 - y.y2 , 2) );
    temp_d3 = sqrt( pow( x.x1 - y.x3 , 2 ) + pow ( x.y1 - y.y3 , 2) );

    double  temp_p1,temp_p2,temp_p3,
            temp_s1,temp_s2,temp_s3;

    temp_p1   =  ( temp_d1+temp_d2+y.d1 )/2;
    temp_s1   =  sqrt(temp_p1*( temp_p1 - temp_d1 ) * (temp_p1- temp_d2) *(temp_p1-y.d1));

    temp_p2   =  ( temp_d2+temp_d3+y.d2 )/2;
    temp_s2   =  sqrt(temp_p2*( temp_p2 - temp_d2 ) * (temp_p2- temp_d3) *(temp_p2-y.d2));


    temp_p3   =  ( temp_d1+temp_d3+y.d3 )/2;
    temp_s3   =  sqrt(temp_p3*( temp_p3 - temp_d1 ) * (temp_p3- temp_d3) *(temp_p3-y.d3));

    /*------------------------------------------------------------------------------------*/
    double  temp_d1_1,temp_d2_1,temp_d3_1;

    temp_d1_1 = sqrt( pow( x.x2 - y.x1 , 2 ) + pow ( x.y2 - y.y1 , 2) );
    temp_d2_1 = sqrt( pow( x.x2 - y.x2 , 2 ) + pow ( x.y2 - y.y2 , 2) );
    temp_d3_1 = sqrt( pow( x.x2 - y.x3 , 2 ) + pow ( x.y2 - y.y3 , 2) );



    double  temp_p1_1,temp_p2_1,temp_p3_1,
            temp_s1_1,temp_s2_1,temp_s3_1;

    temp_p1_1   =  ( temp_d1_1+temp_d2_1+y.d1 )/2;
    temp_s1_1   =  sqrt(temp_p1_1*( temp_p1_1 - temp_d1_1 ) * (temp_p1_1- temp_d2_1) *(temp_p1_1-y.d1));

    temp_p2_1   =  ( temp_d2_1+temp_d3_1+y.d2 )/2;
    temp_s2_1   =  sqrt(temp_p2_1*( temp_p2_1 - temp_d2_1 ) * (temp_p2_1- temp_d3_1) *(temp_p2_1-y.d2));


    temp_p3_1   =  ( temp_d1_1+temp_d3_1+y.d3 )/2;
    temp_s3_1   =  sqrt(temp_p3_1*( temp_p3_1 - temp_d1_1 ) * (temp_p3_1- temp_d3_1) *(temp_p3_1-y.d3));


    /*------------------------------------------------------------------------------------*/
    double  temp_d1_2,temp_d2_2,temp_d3_2;

    temp_d1_2 = sqrt( pow( x.x3 - y.x1 , 2 ) + pow ( x.y3 - y.y1 , 2) );
    temp_d2_2 = sqrt( pow( x.x3 - y.x2 , 2 ) + pow ( x.y3 - y.y2 , 2) );
    temp_d3_2 = sqrt( pow( x.x3 - y.x3 , 2 ) + pow ( x.y3 - y.y3 , 2) );



    double  temp_p1_2,temp_p2_2,temp_p3_2,
            temp_s1_2,temp_s2_2,temp_s3_2;

    temp_p1_2   =  ( temp_d1_2+temp_d2_2+y.d1 )/2;
    temp_s1_2   =  sqrt(temp_p1_2*( temp_p1_2 - temp_d1_2 ) * (temp_p1_2- temp_d2_2) *(temp_p1_2-y.d1));

    temp_p2_2   =  ( temp_d2_2+temp_d3_2+y.d2 )/2;
    temp_s2_2   =  sqrt(temp_p2_2*( temp_p2_2 - temp_d2_2 ) * (temp_p2_2- temp_d3_2) *(temp_p2_2-y.d2));

    temp_p3_2   =  ( temp_d1_2+temp_d3_2+y.d3 )/2;
    temp_s3_2   =  sqrt(temp_p3_2*( temp_p3_2 - temp_d1_2 ) * (temp_p3_2- temp_d3_2) *(temp_p3_2-y.d3));

    if ( ( fabs(y.s -( temp_s1+temp_s2+temp_s3)) <EPS ) &&
            ( fabs (y.s -( temp_s1_1+temp_s2_1+temp_s3_1)) <EPS ) &&
                ( fabs(y.s -( temp_s1_2+temp_s2_2+temp_s3_2)) <EPS)  )
                {
                    return true;
                }
        else return false;


}

void Nhap(){
    f.open(fi,ios::in);
    f>>n;
    for (int i=1;i<=n;i++)
    {
        f>>a[i].x1>>a[i].y1
         >>a[i].x2>>a[i].y2
         >>a[i].x3>>a[i].y3;

        a[i].d1=sqrt( pow( a[i].x1 - a[i].x2 , 2 ) + pow ( a[i].y1 - a[i].y2 , 2) ); // d1: 1 2

        a[i].d2=sqrt( pow( a[i].x2 - a[i].x3 , 2 ) + pow ( a[i].y2 - a[i].y3 , 2) ); // d2: 2 3

        a[i].d3=sqrt( pow( a[i].x3 - a[i].x1 , 2 ) + pow ( a[i].y1 - a[i].y3 , 2) ); // d3: 3 1

        a[i].p= ( a[i].d1+a[i].d2+a[i].d3 ) / 2;

        a[i].s= sqrt( a[i].p * ( a[i].p - a[i].d1 ) * ( a[i].p - a[i].d2 ) * ( a[i].p - a[i].d3 ) );
    }

}
bool compare(tamgiac x,tamgiac y)
{
    return x.s<y.s;
}

void qhd()
{
    l[1]=1;
    for (int i=2;i<=n;i++){
        l[i]=1;
        for (int j=1;j<i;j++){
            if (a[j].s<a[i].s){
                if ( kt(a[j],a[i]) )
                {
                    l[i]=max(l[i],l[j]+1);
                    truoc[i]=j;
                }
            }
        }
    }
}

void truyvet(int i)
{
    if (truoc[i]==0) {cout<<endl<<a[i].x1<<" "<<a[i].y1<<" "<<a[i].x2<<" "<<a[i].y2<<" "<<a[i].x3<<" "<<a[i].y3<<" "<<a[i].s; return;}
    else{
        truyvet(truoc[i]);
        cout<<endl<<a[i].x1<<" "<<a[i].y1<<" "<<a[i].x2<<" "<<a[i].y2<<" "<<a[i].x3<<" "<<a[i].y3<<" "<<a[i].s;
    }
}

int main()
{
	//freopen("t.txt","r",stdin);
	Nhap();
    sort (a+1,a+n+1,compare);
    qhd();
    int MAX=0,id=1;
    for (int i=1;i<=n;i++)
    {
        if (l[i] >MAX ) {MAX= l[i];id=i;}
        cout<<l[i]<<" ";
    }
    cout<<endl;
    truyvet(id);

    //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
