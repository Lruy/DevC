#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n,m;
struct pipe{
    int to,rate;
    pipe(int x,int y){
        to=x;rate=y;
    }
};
vector<vector<pipe> > mp(405);
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    return 0;
}