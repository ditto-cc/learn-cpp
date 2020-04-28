
#ifndef _MYMETHOD_H
#define _MYMETHOD_H

#include "TemplateMethod.h"
#include <iostream>
using namespace std;

class MyMethod : public TemplateMethod {
public:
    ~MyMethod() override = default;

    bool step2() override {
        cout << "MyMethod step2" << endl;
        return true;
    }

    void step4() override {
        cout << "MyMethod step4" << endl;
    }
};

#endif
