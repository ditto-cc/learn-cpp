#include <iostream>
#include "MyString.h"

int main() {
    String str("Hello, World!");
    String a = str;
    str = "aaa";
    char *b = "Love you!";
    char d[] = {'a','c','d','\0'};
    String c(b);
    String e(d);
    std::cout << str << std::endl;
    std::cout << a << std::endl;
    std::cout << c << std::endl;
    std::cout << e << std::endl;
    return 0;

}
