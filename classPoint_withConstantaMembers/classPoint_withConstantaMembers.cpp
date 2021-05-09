// classPoint_withConstantaMembers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
class CPoint {
    const T m_x;
    const T m_y;
public:
    CPoint()
        : m_x(0), m_y(0)
    {}
    CPoint(T a, T b)
        : m_x(a), m_y(b)
    {}
    CPoint(const CPoint& obj)
        : m_x(obj.m_x), m_y(obj.m_y)
    {}

    const CPoint& operator= (const CPoint& obj) const {
        const_cast<T&>(this->m_x) = obj.m_x;
        const_cast<T&>(this->m_y) = obj.m_y;
        return *this;
    }

    T GetX() const { return m_x; }
    T GetY() const { return m_y; }

    bool SetX(T a) {
        if (const_cast<T&>(this->m_x) = a)
            return true;
        return false;
    }
    bool SetY(T b) {
        if (const_cast<T&>(this->m_y) = b)
            return true;
        return false;
    }
};


int main()
{

    CPoint<double> point1(3.3, 4.4);
    CPoint<double> point2 = point1;

    std::cout << "X = " << point1.GetX() << " Y = " << point1.GetY() << "\n";

    std::cout << "X = " << point1.GetX() << " Y = " << point1.GetY() << "\n\n";

    point1.SetX(7.7);
    point2.SetY(12.12);
    std::cout << "X = " << point1.GetX() << " Y = " << point1.GetY() << "\n";
    std::cout << "X = " << point2.GetX() << " Y = " << point2.GetY() << "\n\n";

    CPoint<double> point3 = point2;
    point3 = point1;
    std::cout << "X = " << point3.GetX() << " Y = " << point3.GetY() << "\n";

    return EXIT_SUCCESS;
}