
#ifndef SINGLETON_SINGLETON3_H
#define SINGLETON_SINGLETON3_H

#include <mutex>

using namespace std;


class Singleton3 {
private:
    static mutex m;
    static Singleton3 *instance;

    Singleton3() = default;


public:
    Singleton3(const Singleton3 &) = delete;

    ~Singleton3() = default;

    static Singleton3 *getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> guard(m);
            if (instance == nullptr) {
                instance = new Singleton3();
            }
        }
        return instance;
    }
};

mutex Singleton3::m;
Singleton3 *Singleton3::instance;
#endif
