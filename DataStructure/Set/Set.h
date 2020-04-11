#ifndef _SET_H
#define _SET_H

template <class T>
class Set {
public:
    virtual void add(const T&) = 0;
    virtual bool remove(const T&) = 0;
    virtual bool contains(const T&) = 0;
    virtual int size() = 0;
    virtual bool empty() = 0;
};

#endif
