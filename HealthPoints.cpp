//
// Created by baraa on 27/05/2022.
//
#include "HealthPoints.h"

HealthPoints::HealthPoints(int hp)
{
    if(hp==0 || hp<0)
    {
        throw InvalidArgument();
    }
    HP=hp;
    max_HP=HP;
}

HealthPoints& HealthPoints:: operator+=(const HealthPoints& p1){
    int temp= HP+p1.HP;
    if(temp > max_HP)
    {
        HP=max_HP;
        return(*this);
    }
    else if (temp<=0){
        this->HP=0;
        return (*this);
    }
    else{
        this->HP=temp;
        return (*this);
    }
}

HealthPoints& HealthPoints:: operator-=(const HealthPoints& p1)
{
    int temp= HP-p1.HP;
    if(temp > max_HP)
    {
        HP=max_HP;
        return(*this);
    }
    else if (temp<=0){
        this->HP=0;
        return (*this);
    }
    else{
        this->HP=temp;
        return (*this);
    }
}


bool operator==(const HealthPoints& p1,const HealthPoints& p2){
    return p1.HP==p2.HP;
}
bool operator!=(const HealthPoints& p1,const HealthPoints& p2){
    return !(p1==p2);
}
bool operator<=(const HealthPoints& p1,const HealthPoints& p2){
    return p1<p2 || p1==p2;
}
bool operator>=(const HealthPoints& p1,const HealthPoints& p2){
    return p1>p2 || p1==p2;
}

bool operator>(const HealthPoints& p1,const HealthPoints& p2){
    return p1.HP>p2.HP;
}
bool operator<(const HealthPoints& p1,const HealthPoints& p2){
    return p2>p1;
}
std::ostream& operator<<(std::ostream& os, const HealthPoints& Points){
    return os<<Points.HP<<"("<<Points.max_HP<<")";
}

HealthPoints& operator+(const int& p1,const HealthPoints& p2)
{
    HealthPoints p3=p2;
    return p3+=p1;
}
HealthPoints& operator+(const HealthPoints& p2,const int& p1)
{
    HealthPoints p3=p2;
    return p3+=p1;
}
HealthPoints& operator-(const int& p1,const HealthPoints& p2)
{
    HealthPoints p3=p2;
    return p3-=p1;
}
HealthPoints& operator-(const HealthPoints& p2,const int& p1)
{
    HealthPoints p3=p2;
    return p3-=p1;
}