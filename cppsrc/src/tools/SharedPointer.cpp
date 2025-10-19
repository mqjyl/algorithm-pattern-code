//
// Created by mqjyl on 2020/10/9.
//

#include "../../include/tools/SharedPointer.h"
#include <iostream>

using namespace std;

void testSharedPointer(){
    SharedPointer<int> p1(new int(10));
    cout << "ֵ��" << *(p1.get()) << " ���ü�����" << p1.use_count() << endl;
    *p1 = 100;
    cout << "ֵ��" << *p1 << " ���ü�����" << p1.use_count() << endl;

    {
        SharedPointer<int> p2(p1);
        *p2 = 3;
        cout << "ֵ��" << *p2 << " ���ü�����" << p1.use_count() << endl;

        SharedPointer<int> p3 = p2;
        *p3 = 55;
        cout << "ֵ��" << *p3 << " ���ü�����" << p1.use_count() << endl;

        cout << "ֵ��" << *p2 << " ���ü�����" << p1.use_count() << endl;
    }

    cout << "ֵ��" << *p1 << " ���ü�����" << p1.use_count() << endl;

    if(p1){
        cout << "True" << endl;
    }

    SharedPointer<string> q1(new string("����string1"));
    cout << "ֵ��" << (*(q1)).c_str() << " size��" << q1->size() << endl;
}