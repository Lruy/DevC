#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n,m;
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
int build_fa(int l,int r){
    int pos=tree.size();
    tree.push_back(Node(0,0,0));
    if(l==r)tree[pos].val=l;
    else{
        int mid=(l+r)>>1;
        tree[pos].l=build_fa(l,mid);
        tree[pos].r=build_fa(mid+1,r);
    }
    return pos;
}
int build_dep(int l,int r){
    int pos=tree.size();
    tree.push_back(Node(0,0,0));
    if(l==r)tree[pos].val=1;
    else{
        int mid=(l+r)>>1;
        tree[pos].l=build_dep(l,mid);
        tree[pos].r=build_dep(mid+1,r);
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
int find(int rt,int x){
    int fx=query(rt,1,n,x);
    if(fx==x)return x;
    return find(rt,fx);
}
int root_fa[200005],root_dep[200005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    tree.reserve(8000000);
    tree.push_back(Node(0,0,0));
    root_fa[0]=build_fa(1,n);
    root_dep[0]=build_dep(1,n);
    for(int i=1;i<=m;i++){
        int opt;cin>>opt;
        if(opt==1){
            int a,b;cin>>a>>b;
            int ra=find(root_fa[i-1],a);
            int rb=find(root_fa[i-1],b);
            if(ra==rb){
                root_fa[i]=root_fa[i-1];
                root_dep[i]=root_dep[i-1];
                continue;
            }
            int da=query(root_dep[i-1],1,n,ra);
            int db=query(root_dep[i-1],1,n,rb);
            if(da<db){
                root_fa[i]=update(root_fa[i-1],1,n,ra,rb);
                root_dep[i]=root_dep[i-1];
            }else if(da>db){
                root_fa[i]=update(root_fa[i-1],1,n,rb,ra);
                root_dep[i]=root_dep[i-1];
            }else{
                root_fa[i]=update(root_fa[i-1],1,n,ra,rb);
                root_dep[i]=update(root_dep[i-1],1,n,rb,db+1);
            }
        }else if(opt==2){
            int k;cin>>k;
            root_fa[i]=root_fa[k];
            root_dep[i]=root_dep[k];
        }else{
            int a,b;cin>>a>>b;
            cout<<(find(root_fa[i-1],a)==find(root_fa[i-1],b)?1:0)<<'\n';
            root_fa[i]=root_fa[i-1];
            root_dep[i]=root_dep[i-1];
        }
    }
    return 0;
}
