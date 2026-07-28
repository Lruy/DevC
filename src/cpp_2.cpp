#include <iostream>
#include <string>
using namespace std;

// ---------------- 抽象 ----------------
// 抽象类：定义武器的通用接口，不实现具体方法
class Weapon {
public:
    // 纯虚函数，体现抽象：只定义行为规范，不提供实现
    virtual void attack() = 0;
    virtual ~Weapon() {} // 虚析构函数，保证多态时正确释放资源
};

// ---------------- 封装 ----------------
// 具体武器类：将属性和方法封装在类内部，通过public接口访问
class Gun : public Weapon {
private:
    // 私有属性：封装数据，外部无法直接访问
    string name;
    int ammo;

public:
    // 构造函数：初始化封装的属性
    Gun(string n, int a) : name(n), ammo(a) {}

    // 公共方法：提供访问和修改私有属性的接口
    string getName() const { return name; }
    int getAmmo() const { return ammo; }
    void setAmmo(int a) { ammo = a > 0 ? a : 0; }

    // 实现抽象类的纯虚函数
    void attack() override {
        if (ammo > 0) {
            cout << name << " 开火！剩余弹药：" << --ammo << endl;
        } else {
            cout << name << " 没有弹药了！" << endl;
        }
    }
};

// ---------------- 继承 ----------------
// 子类Sniper继承父类Gun，复用父类的属性和方法
class Sniper : public Gun {
private:
    // 子类特有属性
    double scopeZoom;

public:
    // 子类构造函数：调用父类构造函数初始化继承的属性
    Sniper(string n, int a, double zoom) : Gun(n, a), scopeZoom(zoom) {}

    // 子类特有方法
    void aim() {
        cout << getName() << " 开启" << scopeZoom << "倍镜瞄准！" << endl;
    }

    // ---------------- 多态（重写） ----------------
    // 重写父类的attack方法，实现不同的行为
    void attack() override {
        cout << "[狙击枪] ";
        Gun::attack(); // 复用父类的基础攻击逻辑
    }
};

// 另一个子类MachineGun，继承Gun，体现多态的另一种实现
class MachineGun : public Gun {
public:
    MachineGun(string n, int a) : Gun(n, a) {}

    // 重写attack方法
    void attack() override {
        cout << "[机枪] ";
        for (int i = 0; i < 3; ++i) { // 机枪连射3发
            Gun::attack();
        }
    }
};

int main() {
    // 多态使用：父类指针指向子类对象
    Weapon* w1 = new Sniper("AWM", 5, 8.0);
    Weapon* w2 = new MachineGun("M249", 30);

    // 调用同一个attack方法，表现出不同的行为（多态）
    w1->attack();
    w2->attack();

    // 子类特有方法调用
    Sniper* s = dynamic_cast<Sniper*>(w1);
    if (s) s->aim();

    // 释放资源
    delete w1;
    delete w2;

    return 0;
}