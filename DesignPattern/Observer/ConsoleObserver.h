
#ifndef OBSERVER_CONSOLEOBSERVER_H
#define OBSERVER_CONSOLEOBSERVER_H

#include <iostream>
#include "FileProcessProgress.h"

using namespace std;

class ConsoleObserver : public FileProcessProgress {

public:
    void doProgress(double progress) override {
        printf("Console: %.2lf%\n", progress * 100);
    }
};

#endif