#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
typedef char ElemType;
struct tree{
    ElemType data;
    tree* l;
    tree* r;
    bool ld;
    tree(){ld=false;l=nullptr;r=nullptr;}
    tree(char a):data(a){ld=false;l=nullptr;r=nullptr;}
};
void pre(tree* t){
    stack<tree*> s;
    s.push(t);
    while(!s.empty()){
        tree* tmp=s.top();
        s.pop();
        if(tmp==nullptr)continue;
        cout<<tmp->data<<" ";
        s.push(tmp->r);
        s.push(tmp->l);
    }
    cout<<'\n';
}
void mid(tree* t){
    stack<tree*> s;
    s.push(t);
    while(!s.empty()){
        tree* tmp=s.top();
        if(tmp==nullptr){s.pop();continue;}
        if(tmp->ld){cout<<tmp->data<<" ";s.pop();}
        else{
            s.pop();
            tmp->ld=true;
            s.push(tmp->r);
            s.push(tmp);
            s.push(tmp->l);
        }
    }
    cout<<'\n';
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    tree* a=new tree;
    a->data='D';a->l=new tree;a->l->data='B';a->l->l=new tree;a->l->l->data='U';a->l->l->r=new tree;a->l->l->r->data='G';
    a->r=new tree;a->r->data='C';a->r->r=new tree;a->r->r->data='E';a->r->r->l=new tree;a->r->r->r=new tree;a->r->r->l->data='F';a->r->r->r->data='I';
    pre(a);mid(a);
    return 0;
}