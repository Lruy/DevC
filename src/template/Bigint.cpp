#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=10005;
struct Bigint{
    int* a;
    int len;
    Bigint(){
        a=new int[N];
        memset(a,0,sizeof(int)*N);
        len=0;
    }
    Bigint(ll aa,int bb):len(bb){
        a=new int[N];
        memset(a,0,sizeof(int)*N);
        for(int i=0;i<bb;i++){
            this->a[i]=aa%10;
            aa/=10;
        }
    }
    Bigint(const Bigint& other){
        a=new int[N];
        memcpy(a,other.a,sizeof(int)*N);
        len=other.len;
    }
    ~Bigint(){delete[] a;}
    Bigint& operator=(const Bigint& other){
        if(this==&other)return *this;
        memcpy(a,other.a,sizeof(int)*N);
        len=other.len;
        return *this;
    }
    Bigint operator+(const Bigint &other){
        Bigint ans(0,1);
        int add=0;
        int len=max(this->len,other.len);
        for(int i=0;i<len;i++){
            int tmp=this->a[i]+other.a[i]+add;
            ans.a[i]=tmp%10;
            add=tmp/10;
        }
        if(add){
            ans.a[len]=add;
            len++;
        }
        ans.len=len;
        return ans;
    }
    Bigint operator*(const Bigint& other){
        Bigint ans(0,1);
        for(int i=0;i<other.len;i++){
            Bigint tmp(*this);
            int add=0;
            for(int j=0;j<tmp.len;j++){
                tmp.a[j]*=other.a[i];
                tmp.a[j]+=add;
                add=tmp.a[j]/10;
                tmp.a[j]%=10;
            }
            if(add){
                tmp.a[tmp.len]=add;
                tmp.len++;
            }
            tmp.len+=i;
            if(i){
                for(int j=tmp.len-1;j>=i;j--){
                    tmp.a[j]=tmp.a[j-i];
                }
                for(int j=0;j<i;j++){
                    tmp.a[j]=0;
                }
            }
            ans=ans+tmp;
        }
        return ans;
    }
    void in(){
        string sa;
        cin>>sa;
        for(int i=0;i<sa.size();i++){
            this->a[i]=sa[sa.size()-1-i]-'0';
        }
        this->len=sa.size();
    }
    void out(){
        if(this->len==0){
            cout<<0<<'\n';
            return;
        }
        bool pre0=true;
        for(int i=this->len-1;i>=0;i--){
            if(this->a[i])pre0=false;
            if(!pre0)cout<<this->a[i];
        }
        if(pre0)cout<<0<<'\n';
        return;
    }
};

signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    return 0;
}