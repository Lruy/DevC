#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
    int t;cin >> t;
    while(t--) {
        double w;cin >> w;
        double x1,x2,yc,v,u;cin >> x1 >> x2 >> yc >> u >> v;
        double tt;tt = (w - yc) / v;
        if (x1 > 0 && u > 0 || x2 < 0 && v < 0 || x1 < 0 && u > 0 && (yc / v >= (-1 * x1)/u) 
        || x2 > 0 && u < 0 && yc / v >= (x2) / (-1.0 * u)) {
            double ans = yc / v + tt;
            cout << ans << '\n';
        }
        else {
            if (u > 0) {
                double del = 4.0*x1*x1*u*u + 4.0*(x1*x1+yc*yc)*(v*v-u*u);
            double ttt = (-1.0 * 2.0*(x1)*u+sqrt(del)) / (2.0*(u*u - v*v));
            if(ttt<0)   ttt = (-1.0 * 2.0*(x1)*u-sqrt(del)) / (2.0*(u*u - v*v));
            else ttt = min(ttt,(2.0*(x1)*u-sqrt(del)) / (2.0*(u*u - v * v)));
            double ans;
            if (ttt > 0)   ans = ttt + tt;
            double del2 = 4.0*x2*x2*u*u + 4.0*(x2*x2+yc*yc)*(v*v-u*u);
            double ttt2 = (-1.0*2.0*x2*u+sqrt(del2)) / (2.0*(u*u - v*v));
            if (ttt2 < 0)   ttt2 = (-1.0*2.0*x2*u-sqrt(del2)) / (2.0*(u*u-v*v));
            else ttt2 = min(ttt2,(-1.0*2.0*x2*u-sqrt(del2)) / (2.0*(u*u-v*v)));
            if (ttt2 > 0)  ans = min(ttt2 + tt,ans);
            cout << ans << '\n';
            }
            else {
                u = -1.0 * u;
                double del = 4.0*x2*x2*u*u + 4.0*(x2*x2+yc*yc)*(v*v-u*u);
            double ttt = (-1.0 * 2.0*(x2)*u+sqrt(del)) / (2.0*(u*u - v*v));
            if(ttt<0)   ttt = (-1.0 * 2.0*(x2)*u-sqrt(del)) / (2.0*(u*u - v*v));
            else ttt = min(ttt,(2.0*(x2)*u-sqrt(del)) / (2.0*(u*u - v * v)));
            double ans;
            if (ttt > 0)   ans = ttt + tt;
            double del2 = 4.0*x1*x1*u*u + 4.0*(x1*x1+yc*yc)*(v*v-u*u);
            double ttt2 = (2.0*x1*u+sqrt(del2)) / (2.0*(u*u - v*v));
            if (ttt2 < 0)   ttt2 = (2.0*x1*u-sqrt(del2)) / (2.0*(u*u-v*v));
            else ttt2 = min(ttt2,(2.0*x1*u-sqrt(del2)) / (2.0*(u*u-v*v)));
            if (ttt2 > 0)  ans = min(ttt2 + tt,ans);
            cout << ans << '\n';
            }
        }
    }
    return 0;
}