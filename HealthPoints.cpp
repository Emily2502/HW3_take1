//
// Created by baraa on 27/05/2022.
//
#include "HealthPoints.h"
const int MINIMUM_HP = 0;

HealthPoints::HealthPoints(int hp)
{
    if(hp <= 0)
    {
        throw InvalidArgument();
    }
    m_HP = hp;
    m_maxHP = m_HP;
}


HealthPoints& HealthPoints::operator+=(int hp)
{
    m_HP += hp;
    if (m_HP < MINIMUM_HP)
    {
        m_HP = MINIMUM_HP;
    }
    if (m_HP > m_maxHP)
    {
        m_HP = m_maxHP;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(int hp)
{
    m_HP -= hp;
    if (m_HP < MINIMUM_HP)
    {
        m_HP = MINIMUM_HP;
    }
    if (m_HP > m_maxHP)
    {
        m_HP = m_maxHP;
    }
    return *this;
}


HealthPoints operator+(const int& hp, const HealthPoints& healthPoints)
{
    HealthPoints result(healthPoints);
    return result += hp;
}

HealthPoints operator+(const HealthPoints& healthPoints, const int& hp)
{
    HealthPoints result(healthPoints);
    return result += hp;
}

HealthPoints operator-(const int& hp, const HealthPoints& healthPoints)
{
    HealthPoints result(healthPoints);
    return result -= hp;
}

HealthPoints operator-(const HealthPoints& healthPoints, const int& hp)
{
    HealthPoints result(healthPoints);
    return result -= hp;
}


bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1.m_HP == healthPoints2.m_HP;
}

bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !(healthPoints1==healthPoints2);
}

bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1.m_HP > healthPoints2.m_HP;
}

bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1<healthPoints2 || healthPoints1==healthPoints2;
}

bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints1>healthPoints2 || healthPoints1==healthPoints2;
}

bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return healthPoints2>healthPoints1;
}


std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints)
{
    return os << healthPoints.m_HP << "(" << healthPoints.m_maxHP << ")";
}

