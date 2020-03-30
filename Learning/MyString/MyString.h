

#ifndef _MYSTRING_
#define _MYSTRING_

#include <cstring>

class String {
private:
    char *m_data;

public:
    String(const char *cstr = nullptr);

    String(const String &str);

    String &operator=(const String &str);

    ~String() { delete[] m_data; }

    char *get_c_str() const { return m_data; }
};

inline
String::String(const char *cstr) {
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    } else {
        m_data = new char[1];
        m_data[0] = '\0';
    }
}

inline
String::String(const String &str) {
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline
String &String::operator=(const String &str) {
    if (this == &str)
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const String &str) {
    return os << str.get_c_str();
}

#endif
