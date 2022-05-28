//
// Created by baraa on 27/05/2022.
//

#ifndef HW3_HEALTHPOINTS_H
#define HW3_HEALTHPOINTS_H
#include <exception>
#include "iostream"

class HealthPoints {
    int max_HP=100;
    int HP;
public:

    class InvalidArgument : public std::exception{};
    HealthPoints(int hp=100);
    ~HealthPoints()=default;

    HealthPoints& operator+=(const HealthPoints& p1);
    HealthPoints& operator-=(const HealthPoints& p1);
    friend bool operator==(const HealthPoints&,const HealthPoints&);
    friend bool operator>(const HealthPoints&,const HealthPoints&);
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& Points);


};

HealthPoints& operator+(const int& p1,const HealthPoints& p2);
HealthPoints& operator+(const HealthPoints& p2,const int& p1);
HealthPoints& operator-(const int& p1,const HealthPoints& p2);
HealthPoints& operator-(const HealthPoints& p2,const int& p1);

bool operator!=(const HealthPoints& p1,const HealthPoints& p2);
bool operator<(const HealthPoints& p1,const HealthPoints& p2);
bool operator<=(const HealthPoints& p1,const HealthPoints& p2);
bool operator>=(const HealthPoints& p1,const HealthPoints& p2);

#endif //HW3_HEALTHPOINTS_H
