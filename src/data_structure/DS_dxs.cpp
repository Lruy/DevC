#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
struct Elemtype{
    int mi;
    int xi;
    Elemtype(){}
    Elemtype(int a,int b):xi(a),mi(b){}
};
typedef struct LinkNode{
    Elemtype data;
    LinkNode* next;
}* LinkList;
bool Init(LinkList& L, LinkList& R) {
    L = new LinkNode;
    L->data.xi = 0;
    L->data.mi = 0;
    L->next = nullptr;
    R = L;
    return true;
}
bool CreateList_H(LinkList& L, Elemtype e) {
    LinkList p = new LinkNode;
    p->data = e;
    p->next = L->next;
    L->next = p;
    return true;
}
bool CreateList_R(LinkList& R, Elemtype e) {
    LinkList p = new LinkNode;
    R->next = p;
    p->data = e;
    p->next = nullptr;
    R = p;
    return true;
}
bool Insert(LinkList& L, int pos, Elemtype e) {
    if (pos < 1)return false;
    LinkList p = L;
    int j = 0;
    bool flag = false;
    while (p && p->next != nullptr) {
        p = p->next;
        j++;
        if (j == pos - 1) { flag = true; break; }
    }
    if (!flag)return false;
    LinkList n = new LinkNode;
    n->data = e;
    n->next = p->next;
    p->next = n;
    return true;
}
bool Create(LinkList &L,Elemtype e){
    if(L->next==nullptr){
        LinkList p=new LinkNode;
        p->data.mi=e.mi;
        p->data.xi=e.xi;
        p->next=nullptr;
        L->next=p;
        return true;
    }
    LinkList p=L->next;
    LinkList last=L;
    while(p!=nullptr&& p->data.mi<e.mi){last=p;p=p->next;}
    if(p==nullptr){
        LinkList t=new LinkNode;
        t->data.mi=e.mi;
        t->data.xi=e.xi;
        t->next=nullptr;
        last->next=t;
        return true;
    }
    if(p->data.mi!=e.mi){
        LinkList t=new LinkNode;
        t->next=last->next;
        t->data=e;
        last->next=t;
    }
    else if(p->data.xi!=-e.xi){
        p->data.xi+=e.xi;
    }
    else{
        last->next=p->next;
        delete p;
    }
    return true;
}
bool Add(LinkList &a,LinkList& b){
    LinkList pa=a->next;
    LinkList pb=b->next;
    LinkList last=a;
    while(pa!=nullptr&&pb!=nullptr){
        if(pa->data.mi<pb->data.mi){
            last=pa;pa=pa->next;
        }
        else if(pa->data.mi==pb->data.mi){
            if(pa->data.xi!=-pb->data.xi){
                pa->data.xi+=pb->data.xi;
                last=pa;
                pa=pa->next;
                LinkList tmp=pb;
                pb=pb->next;
                delete tmp;
            }
            else{
                LinkList tmp=pa;
                pa=pa->next;
                delete tmp;
                last->next=pa;
                LinkList tmpp=pb;
                pb=pb->next;
                delete tmpp;
            }
        }
        else{
            LinkList tmp=pb->next;
            pb->next=pa;
            last->next=pb;
            last=pb;
            pb=tmp;
        }
    }
    if(pa==nullptr){
        last->next=pb;
    }
    delete b;
    return true;
}
bool Sub(LinkList &a,LinkList& b){
    LinkList p=b->next;
    while(p){p->data.xi=-p->data.xi;p=p->next;}
    return Add(a,b);
}
bool Traverse(LinkList &L){
    bool flag=true;
    LinkList p=L->next;
    while(p!=nullptr){
        if(p->data.xi==0){p=p->next;continue;}
        flag=false;
        if(p!=L->next&&p->data.xi>=0){cout<<"+";}
        if(p->data.xi<0){cout<<"-";}
        if(p->data.mi==0){
            cout<<abs(p->data.xi);
        }
        else{
            if(abs(p->data.xi)!=1)cout<<abs(p->data.xi);
            if(p->data.mi!=1){
                cout<<"x^";
                cout<<p->data.mi;
            }
            else cout<<"x";
        }
        p=p->next;
    }
    if(flag){cout<<"0\n";return false;}
    cout<<'\n';
    return true;
}
stack<LinkList> s;
bool Reverse(LinkList &L){
    LinkList p=L->next;
    while(p!=nullptr){
        s.push(p);
        p=p->next;
    }
    LinkList last=L;
    while(!s.empty()){
        last->next=s.top();
        last=last->next;
        s.pop();
    }
    last->next=nullptr;
    return true;
}
ll Evaluate(LinkList &L,int x){
    ll sum=0;ll tx=x;ll mul=1;
    LinkList p=L->next;
    while(p!=nullptr){
        ll tmp=1;
        if(p->data.mi==0)tmp=p->data.xi;
        else if(mul==p->data.mi)tmp=p->data.xi*tx;
        else{
            ll cnt=p->data.mi-mul;
            ll ttx=x;
            while(cnt){
                if(cnt&1)tmp*=ttx;
                cnt>>=1;
                ttx*=ttx;
            }
            tmp*=tx;
            tx=tmp;
            mul=p->data.mi;
            tmp*=p->data.xi;
        }
        sum+=tmp;
        p=p->next;
    }
    return sum;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LinkList r;
    LinkList a,b,c,d,e;
    Init(a,r);Create(a,Elemtype(7,0));Create(a,Elemtype(3,1));Create(a,Elemtype(9,8));Create(a,Elemtype(5,17));
    Init(b,r);Create(b,Elemtype(8,1));Create(b,Elemtype(22,7));Create(b,Elemtype(-9,8));
    Add(a,b);
    Traverse(a);
    Init(c,r);Create(c,Elemtype(1,0));Create(c,Elemtype(1,1));Create(c,Elemtype(1,2));
    Init(d,r);Create(d,Elemtype(1,2));Create(d,Elemtype(-5,3));
    Sub(c,d);
    Traverse(c);
    Init(e,r);Create(e,Elemtype(-5,0));Create(e,Elemtype(2,1));Create(e,Elemtype(4,6));Create(e,Elemtype(-10,9));
    cout<<Evaluate(e,2)<<'\n';
    return 0;
}