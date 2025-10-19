//
// Created by mqjyl on 2020/10/9.
//

#include "../../include/tools/SharedPointer.h"
#include <iostream>

using namespace std;

void testSharedPointer(){
    SharedPointer<int> p1(new int(10));
    cout << "值：" << *(p1.get()) << " 引用计数：" << p1.use_count() << endl;
    *p1 = 100;
    cout << "值：" << *p1 << " 引用计数：" << p1.use_count() << endl;

    {
        SharedPointer<int> p2(p1);
        *p2 = 3;
        cout << "值：" << *p2 << " 引用计数：" << p1.use_count() << endl;

        SharedPointer<int> p3 = p2;
        *p3 = 55;
        cout << "值：" << *p3 << " 引用计数：" << p1.use_count() << endl;

        cout << "值：" << *p2 << " 引用计数：" << p1.use_count() << endl;
    }

    cout << "值：" << *p1 << " 引用计数：" << p1.use_count() << endl;

    if(p1){
        cout << "True" << endl;
    }

    SharedPointer<string> q1(new string("我是string1"));
    cout << "值：" << (*(q1)).c_str() << " size：" << q1->size() << endl;
}