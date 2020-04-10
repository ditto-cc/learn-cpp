
#ifndef _TRIE_H
#define _TRIE_H

#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;

class Trie {
private:
    class Node {
    public:
        unordered_map<char, Node*> map;
        bool isWord;
        Node(): isWord(false) {
            map = unordered_map<char, Node*>{};
        }
        ~Node() = default;
    };

    int size;
    Node *root;

public:
    Trie(): size(0) { root = new Node(); }
    ~Trie() { delete root; }

    void add(const string& word) {
        Node *p = root;
        for (char i : word) {
            if (p->map.find(i) == p->map.end()) {
                p->map[i] = new Node();
            }
            p = p->map[i];
        }
        p->isWord = true;
    }

    bool search(const string &word) {
        Node *p = root;
        for (char i : word) {
            if (p->map.find(i) == p->map.end()) {
                return false;
            }
            p = p->map[i];
        }
        return p->isWord;
    }

    bool isPrefix(const string &prefix) {
        Node *p = root;
        for (char i : prefix) {
            if (p->map.find(i) == p->map.end()) {
                return false;
            }
            p = p->map[i];
        }
        return true;
    }
};

#endif
