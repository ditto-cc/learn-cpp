
#ifndef SINGLETON_SINGLETON4_H
#define SINGLETON_SINGLETON4_H

#include <mutex>
#include <atomic>

using namespace std;

class Singleton4 {
private:
    static atomic<Singleton4 *> instance;
    static mutex m;

    Singleton4() = default;

public:
    Singleton4(const Singleton4 &) = delete;
    Singleton4 & operator=(const Singleton4 &) = delete;

    ~Singleton4() = default;

    static Singleton4 *getInstance() {
        Singleton4 *tmp = instance.load(memory_order_relaxed);
        atomic_thread_fence(memory_order_acquire);
        if (tmp == nullptr) {
            lock_guard<mutex> lock(m);
            tmp = instance.load(memory_order_relaxed);
            if (instance == nullptr) {
                instance = new Singleton4();
                atomic_thread_fence(memory_order_release);
                instance.store(tmp, memory_order_relaxed);
            }
        }
        return tmp;
    }
};

atomic<Singleton4 *> Singleton4::instance;
mutex Singleton4::m;

#endif
