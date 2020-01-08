
#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>

template<typename T>
class Complex {
private:
    T re, im;

    template<typename _T>
    friend Complex<_T> &__doapl(Complex<_T> *, const Complex<_T> &);

public:
    Complex(const T &r = 0, const T &i = 0) : re(r), im(i) {}

    Complex<T> &operator+=(const Complex<T> &);

    T real() const { return re; }

    T imag() const { return im; }

    void real(T r) { re = r; }

    void imag(T i) { im = i; }

};

/**
 * 求复数实部
 * @tparam T
 * @param c
 * @return
 */
template<typename T>
T real(const Complex<T> &c) {
    return c.real();
}

/**
 * 求复数虚部
 * @tparam T
 * @param c
 * @return
 */
template<typename T>
T imag(const Complex<T> &c) {
    return c.imag();
}

/**
 * 求共轭复数
 * @tparam T
 * @param c
 * @return
 */
template <typename T>
Complex<T> conj(const Complex<T> &c) {
    return Complex<T>(real(c), - imag(c));
}

template<typename T>
inline Complex<T> &
Complex<T>::operator+=(const Complex<T> &r) {
    return __doapl(this, r);
}

template<typename T>
inline Complex<T> &__doapl(Complex<T> *ths, const Complex<T> &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}


template<typename T>
inline std::ostream &operator<<(std::ostream &os, const Complex<T> &x) {
    return os << "(" << real(x) << ", " << imag(x) << ")";
}

template<typename T>
inline Complex<T> operator+(const Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>(real(c1) + real(c2), imag(c1) + imag(c2));
}

template<typename T>
inline Complex<T> operator+(const T &val, const Complex<T> &c) {
    return Complex<T>(val + real(c), imag(c));
}

template<typename _T>
inline Complex<_T> operator+(const Complex<_T> &c, const _T &val) {
    return Complex<_T>(val + real(c), imag(c));;
}

template<typename T>
inline Complex<T> operator-(const Complex<T> &c1, const Complex<T> &c2) {
    return Complex<T>(real(c1) - real(c2), imag(c1) - imag(c2));
}

template<typename T>
inline Complex<T> operator-(const T &val, const Complex<T> &c) {
    return Complex<T>(val - real(c), 0 - imag(c));
}

template<typename T>
inline Complex<T> operator-(const Complex<T> &c, const T &val) {
    return Complex<T>(real(c) - val, imag(c));
}


#endif
