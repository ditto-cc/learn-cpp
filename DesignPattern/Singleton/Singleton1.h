
#ifndef SINGLETON_SINGLETON1_H
#define SINGLETON_SINGLETON1_H


class Singleton1 {
private:
    static Singleton1 *instance;

    Singleton1() = default;

public:
    Singleton1(const Singleton1 &) = delete;

    ~Singleton1() = default;

    static Singleton1 *getInstance() {
        if (instance == nullptr) {
            instance = new Singleton1();
        }
        return instance;
    }

};

Singleton1 *Singleton1::instance;
#endif
