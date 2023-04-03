//
// Created by gels on 2023/4/3.
//

#include <stdio.h>
#include <stdlib.h>

class Base {
public:
    virtual void Say() = 0;

    void Say2();
};

void Base::Say() {
    printf("Base::Say!\n");
}

void Base::Say2() {
    printf("Base::Say2\n");
}

class Son : public Base {
public:
    virtual void Say() override; //override加上, 覆盖检查
    void Say2();
};

void Son::Say() {
    printf("Son::Say!\n");
}

void Son::Say2() {
    printf("Son::Say2!\n");
}

int main() {
    printf("== testmain ==\n");

    Base *p = new Son();
    Base *p2 = p;
    p2->Say();   //
    p2->Say2();  //错误，本应该调用Son::Say2，结果是Base::Say2，使用override关键字解决该问题

    return 0;
}
