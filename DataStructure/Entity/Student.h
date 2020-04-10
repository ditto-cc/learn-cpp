#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>
#include <iostream>
#include <utility>
using std::string;
using std::ostream;

class Student {
private:
    string m_name;
    double m_score;

public:
    Student(string name, const double &score): m_name(std::move(name)), m_score(score) {}
    Student(const char *name, const double &score): m_score(score) {
        m_name = string(name);
    }

    string name() const {
        return m_name;
    }

    double score() const {
        return m_score;
    }

    void name(const string& newName) {
        m_name = newName;
    }

    void score(double newScore) {
        m_score = newScore;
    }

    friend ostream &operator<<(ostream &os, const Student &s) {
        os << "(";
        os << s.m_name << ", " << s.m_score;
        return os << ")";
    }
};
#endif