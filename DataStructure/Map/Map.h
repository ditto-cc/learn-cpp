#ifndef _MAP_
#define _MAP_

template <class K, class V>
class Map {
public:
    virtual void put(const K &key, V &val) = 0;
    virtual bool contains(const K &key) = 0;
    virtual V &remove(const K &key) = 0;
    virtual V &get(const K &key) = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
};

#endif
