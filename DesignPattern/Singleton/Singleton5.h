
#ifndef SINGLETON_SINGLETON5_H
#define SINGLETON_SINGLETON5_H

#include <memory>
#include <mutex>

using namespace std;

class Singleton5 {
private:
    static unique_ptr<Singleton5> instance;
    static once_flag flag;

    Singleton5() = default;


public:
    Singleton5(const Singleton5 &) = delete;

    ~Singleton5() = default;

    static Singleton5 *getInstance() {
        call_once(flag, [] { instance.reset(new Singleton5()); });
        return instance.get();
    }

};

unique_ptr<Singleton5> Singleton5::instance;
once_flag Singleton5::flag;

#endif
