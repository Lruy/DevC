#include <iostream>
using namespace std;
typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    LinkNode* next;
    LinkNode(ElemType aa=0,LinkNode* bb=nullptr):data(aa),next(bb){}
}*LinkList;

void InitLinkList(LinkList& L){
    L=new LinkNode;
    L->next=nullptr;
}

signed Traverse(LinkList& L,LinkList& R){
    int cnt=0;
    LinkList p=L->next;
    while(p!=nullptr){
        cnt++;
        R->next=p;
        p=p->next;
    }
    return cnt;
}

void CreatHead(LinkList& L){
    ElemType tmp;
    while(cin>>tmp){
        LinkList s=new LinkNode;
        s->data=tmp;
        s->next=L->next;
        L->next=s;
    }
    return;
}

void CreatRear(LinkList& R){
    ElemType tmp;
    while(cin>>tmp){
        LinkList s=new LinkNode;
        R->next->next=s;
        s->data=tmp;
        s->next=nullptr;
        R->next=s;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LinkList a;
    InitLinkList(a);
    CreatHead(a);
    LinkList r;
    cout<<Traverse(a,r);
    return 0;
}