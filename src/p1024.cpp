#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef double ll;

ll a,b,c,d;
ll aa,bb,cc;
ll a1,a2,a3;
ll calc(ll x){
    return a*x*x*x+b*x*x+c*x+d;
}
signed main() {
    cin>>a>>b>>c>>d;
    ll l=-101,r=101,mid=0;
    while(fabs(l-r)>1e-8){
        mid=(l+r)/2;
        if(calc(l)*calc(mid)<0)r=mid;
        else l=mid;
        //cout<<mid<<'\n';
    }
    a1=mid;
    aa=a;
    bb=b+aa*l;
    cc=c+bb*l;
    ll delta=bb*bb-4.0*aa*cc;
    a2=(-bb-sqrt(delta))/aa/2.0;
    a3=(-bb+sqrt(delta))/aa/2.0;
    if(a2>a3)swap(a2,a3);
    if(a1>a2)swap(a1,a2);
    if(a2>a3)swap(a2,a3);
    printf("%.2lf %.2lf %.2lf",a1,a2,a3);
    return 0;
}