
#ifndef _TEMPLATEMETHOD_H
#define _TEMPLATEMETHOD_H

#include <iostream>
using namespace std;

class TemplateMethod {
protected:
    virtual bool step2() = 0;
    virtual void step4() = 0;

    void step1() {
        cout << "START processing" << endl << "step1" << endl;
    }

    void step3() {
        cout << "step3" << endl;
    }

    void step5() {
        cout << "step5" << endl << "END processing";
    }

public:

    virtual ~TemplateMethod() = default;
    void run() {
        step1();

        if (step2()) { // virtual
            cout << "step2 return true, ";
            step3();
        }

        step4(); // virtual

        step5();
    }
};


#endif
