#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n,m;
int a[1000005];
struct Node{
    int l,r,val;
    Node(){}
    Node(int a,int b,int c):l(a),r(b),val(c){}
};
vector<Node> tree;

int clone(int pos){
    tree.push_back(tree[pos]);
    return tree.size()-1;
}
int build(int l,int r){
    int pos=tree.size();
    tree.push_back(Node(0,0,0));
    if(l==r)tree[pos].val=a[l];
    else{
        int mid=(l+r)>>1;
        tree[pos].l=build(l,mid);
        tree[pos].r=build(mid+1,r);
    }
    return pos;
}
int update(int pos,int l,int r,int tar,int valu){
    pos=clone(pos);
    if(l==r)tree[pos].val=valu;
    else{
        int mid=(l+r)>>1;
        if(tar<=mid)tree[pos].l=update(tree[pos].l,l,mid,tar,valu);
        else tree[pos].r=update(tree[pos].r,mid+1,r,tar,valu);
    }
    return pos;
}
int query(int pos,int l,int r,int tar){
    if(l==r)return tree[pos].val;
    int mid=(l+r)>>1;
    if(tar<=mid)return query(tree[pos].l,l,mid,tar);
    else return query(tree[pos].r,mid+1,r,tar);
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    tree.reserve(23000000);
    tree.push_back(Node(0,0,0)); // 0 号节点占位
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int> root(m+1);
    root[0]=build(1,n);
    for(int i=1;i<=m;i++){
        int x1,x2,x3;
        cin>>x1>>x2>>x3;
        if(x2==1){
            int x4;cin>>x4;
            root[i]=update(root[x1],1,n,x3,x4);
        }else{
            cout<<query(root[x1],1,n,x3)<<'\n';
            root[i]=root[x1];
        }
    }
    return 0;
}