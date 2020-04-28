
#ifndef OBSERVER_PROGRESSBAR_H
#define OBSERVER_PROGRESSBAR_H

#include <iostream>
using namespace std;

class ProgressBar {
private:
    int m_length = 20;
public:
    void setValue(double val) {
        int process = val * m_length;
        cout << "ProgressBar: <";
        for (int i = 0; i < m_length; i++, process--) {
            process > 0 ? cout << '*' : cout << '-';
        }
        cout << ">" << endl;
    }
};

#endif
