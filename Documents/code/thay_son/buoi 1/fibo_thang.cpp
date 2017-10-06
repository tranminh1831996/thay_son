#include<bits/stdc++.h>
using namespace std;
fstream f;
const char *fi ="fibonaci.inp";
const char *fo ="fibonaci.out";
const int nmax=10000;
int x,F[nmax],m,L[nmax][nmax];
void nhap()
{
    f.open(fi,ios::in);
    cin>>x;
    f.close();
}
void taoday()
{
    F[1]=1;
    F[2]=2;
    m=3;
    while(1)
    {
        F[m]=F[m-1]+F[m-2];
        if(F[m]>x) {m--;break;}
        m++;
    }
    sort(F+1,F+1+m,greater<int>());
}
void QHD()
{
  int i,j;
  L[0][0]=1;for(i=1;i<=x;i++) L[0][i]=0;
  for(i=1;i<=m;i++)
        for(j=0;j<=x;j++)
  {
      L[i][j]=L[i-1][j];
      if(j>=F[i])
      {
          if(L[i-1][j-F[i]]) L[i][j]=1;
      }
  }
}
void inkq()
{
    int i;
    f.open(fo,ios::out);

    for(int j=1;j<=m;j++) cout<<F[j]<<" ";
    cout << endl;
    if(L[m][x])
    {
        for(i=m;i>=1;i--)
      {
        if(L[i-1][x-F[i]])
        {

            cout<<F[i]<<"+";
            x-=F[i];
        }

        if(x==0) break;
      }
    }
    else
    {
        cout<<"NO";
    }
    f.close();

}
int main()
{
 nhap();
 taoday();
 QHD();
 inkq();



}

