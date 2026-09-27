#include <iostream>
using namespace std;
typedef int Elemtype;
typedef long long ll;
typedef struct LinkNode {
    Elemtype data;
    LinkNode* next;
}*LinkList;

bool Init(LinkList& L, LinkList& R) {
    L = new LinkNode;
    R = new LinkNode;
    L->data = 0;
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
ll Length(LinkList& L) {
    ll tmp = 0;
    LinkList p = L;
    while (p->next != nullptr) {
        tmp++;
        p = p->next;
    }
    return tmp;
}
bool Traverse(LinkList& L, LinkList& R) {
    LinkList p = L;
    while (p->next != nullptr) {
        p = p->next;
        cout << p->data << " ";
    }
    R = p;
    cout << '\n';
    return true;
}
bool IsEmpty(LinkList& L) {
    return (L->next == nullptr);
}
Elemtype GetElem(LinkList& L, int pos) {
    if (pos < 1 || IsEmpty(L))return -100000000;
    LinkList p = L->next;
    pos--;
    bool flag = false;
    while (pos--) {
        if (!p) { flag = true; break; }
        p = p->next;
    }
    if (flag)return -100000000;
    else return p->data;
}
int LocateElem(LinkList& L, Elemtype val) {
    if (IsEmpty(L))return -100000000;
    LinkList p = L->next;
    int j = 1;
    while (p) {
        if (p->data == val)return j;
        j++;
        p = p->next;
    }
    return -1000000000;
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
bool Delete(LinkList& L, int pos) {
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
    LinkList tmp = p->next;
    p->next = tmp->next;
    delete tmp;
    return true;
}
bool Destroy(const LinkList L, LinkList& R) {
    LinkList p = L;
    LinkList tmp;
    while (p != nullptr) {
        tmp = p;
        p = p->next;
        delete tmp;
    }
    return true;
}
bool Clear(LinkList& L, LinkList& R) {
    LinkList p = L->next;
    LinkList tmp;
    while (p != nullptr) {
        tmp = p;
        p = p->next;
        delete tmp;
    }
    L->next = nullptr;
    R = L;
    return true;
    }
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LinkList L, R;
    Init(L, R);
    for (int i = 1; i <= 5; i++)CreateList_H(L, i);
    Traverse(L, R);
    cout << Length(L) << '\n';
    Insert(L, 6, 6);
    cout << LocateElem(L, 5) << " " << LocateElem(L, 6) << " " << LocateElem(L, 2) << '\n';
    for (int i = 7; i <= 11; i++)Insert(L, 2, i);
    Traverse(L, R);
    for (int i = 0; i < 2; i++) {
        cout << GetElem(L, 1) << '\n';
        Delete(L, 1);
    }
    Traverse(L, R);
    cout << GetElem(L, 9) << '\n';
    Delete(L, 9);
    Traverse(L, R);
    cout << Length(L) << '\n';
    Clear(L, R);
    cout << Length(L) << '\n';
    cout << (Insert(L, 2, 10) ? "成功插入\n" : "插入不成功\n");
    for (int i = 1; i <= 5; i++)CreateList_R(R, i);
    Traverse(L, R);
    Destroy(L, R);
    LinkList B, BR;
    Init(B, BR);
    for (int i = 1; i <= 5; i++)CreateList_R(BR, i);
    Traverse(B, BR);
    cout << Length(B) << '\n';
    Destroy(B, BR);
    return 0;
}