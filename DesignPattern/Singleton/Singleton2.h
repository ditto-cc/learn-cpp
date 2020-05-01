
#ifndef SINGLETON_SINGLETON2_H
#define SINGLETON_SINGLETON2_H

#include <mutex>

using namespace std;

class Singleton2 {
private:
    static Singleton2 *instance;
    static mutex m;

    Singleton2() = default;

public:
    Singleton2(const Singleton2 &) = delete;
    Singleton2 & operator=(const Singleton2 &) = delete;

    ~Singleton2() = default;

    static Singleton2 *getInstance() {
        lock_guard<mutex> guard(m);
        if (instance == nullptr) {
            instance = new Singleton2();
        }
        return instance;
    }
};

mutex Singleton2::m;
Singleton2 *Singleton2::instance;
#endif
