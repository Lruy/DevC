#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Bigint{
    int a[2005];
    int strlen;
    Bigint(){
        strlen=0;
    }
    Bigint(ll aa,int bb):strlen(bb){
        memset(a,0,sizeof(a));
        for(int i=0;i<bb;i++){
            this->a[i]=aa%10;
            aa/=10;
        }
    }
    Bigint operator+(Bigint &other){
        Bigint ans(0,1);
        int add=0;
        int len=max(this->strlen,other.strlen);
        for(int i=0;i<len;i++){
            int tmp=this->a[i]+other.a[i]+add;
            ans.a[i]=tmp%10;
            add=tmp/10;
        }
        if(add){
            ans.a[len]=add;
            len++;
        }
        ans.strlen=len;
        return ans;
    }
    void out(){
        if(this->strlen!=0){
            for(int i=this->strlen-1;i>=0;i--){
                if(i!=this->strlen-1||this->a[i])cout<<this->a[i];
            }
        }   
        else{
            cout<<0;
        }
    }
};

signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    return 0;
}