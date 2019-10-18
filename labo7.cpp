#include <iostream>
#include <string>

using namespace std;

int memoizedCutRodAux(int p[],int n,int r[]){
    r[0]=0;
    for(int j=1;j<n+1;j++){
        int q=p[j-1];
        for(int i=1;i<j;i++){
            q=max(q,r[i]+r[j-i]);
        }
        r[j]=q;
    }
    return r[n];
}

int memoizedCutRod(int p[],int n){
    int r[n];
    for(int i=0;i<n;i++){
        r[i] = -1;
    }
    return memoizedCutRodAux(p,n,r);
}

int main()
{
  int p[10]={1,5,8,9,10,17,17,20,24,30};
  cout<<memoizedCutRod(p,5);
}
