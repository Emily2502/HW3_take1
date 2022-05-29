//
// Created by baraa on 27/05/2022.
//

#ifndef HW3_HEALTH_POINTS_H
#define HW3_HEALTH_POINTS_H
#include <exception>
#include "iostream"
const int DEFAULT_MAX_HP = 100;

class HealthPoints
{
public:

    /**
     * C'tor of HealthPoints class
     *
     * @param hp& - initial hp.
     * @return
     *      A new instance of HealthPoints.
    */
    explicit HealthPoints(int hp = DEFAULT_MAX_HP);

    /**
     * Assignment operator of HealthPoints class
     *
     * @param HealthPoints& - Reference to a given HealthPoints.
     * @return
     *      A new instance of HealthPoints.
    */
    HealthPoints& operator=(const HealthPoints&) = default;

    /**
     * Copy c'tor of HealthPoints class
     *
     * @param HealthPoints& - Reference to HealthPoints to copy.
     * @return
     *      A new instance of HealthPoints.
    */
    HealthPoints(const HealthPoints&) = default;

    /**
     * D'tor of HealthPoints class
     *
     * @return
     *      void
    */
    ~HealthPoints() = default;

    /**
     * Adds hp to a given HealthPoints variable
     *
     * @param hp& - hp to add.
     * @return
     *      reference to the member that called the function.
    */
    HealthPoints& operator+=(int hp);

    /**
     * Subtracts hp from a given HealthPoints variable
     *
     * @return
     *      reference to the member that called the function.
    */
    HealthPoints& operator-=(int hp);

    /**
     * Checks if two HealthPoints instances are equal by comparing their HPs
     *
     * @param healthPoints1 -  first HealthPoints instance
     * @param healthPoints2 -  second HealthPoints instance
     * @return
     *      true if the two are equal and false otherwise.
    */
    friend bool operator==(const HealthPoints&, const HealthPoints&);

    /**
     * Checks if one HealthPoints instance is greater than the other by comparing their HPs
     *
     * @param healthPoints1 -  first HealthPoints instance
     * @param healthPoints2 -  second HealthPoints instance
     * @return
     *      true if the first is greater than the second and false otherwise.
    */
    friend bool operator>(const HealthPoints&, const HealthPoints&);

    /**
     * Printing operator
    */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints);

    class InvalidArgument : public std::exception{};

private:
    int m_maxHP;
    int m_HP;
};

/**
     * Creates new HealthPoints instance with HP equals to a given
     * HealthPoints instance plus integer hp given as a parameter
     *
     * @param healthPoints -  given HealthPoints
     * @param hp - health points to add
     * @return
     *      A new instance of HealthPoints.
    */
HealthPoints operator+(const int& hp, const HealthPoints& healthPoints);
HealthPoints operator+(const HealthPoints& healthPoints, const int& hp);

/**
     * Creates new HealthPoints instance with HP equals to a given
     * HealthPoints instance minus integer hp given as a parameter
     *
     * @param healthPoints -  given HealthPoints
     * @param hp - health points to subtract
     * @return
     *      A new instance of HealthPoints.
    */
HealthPoints operator-(const int& hp, const HealthPoints& healthPoints);
HealthPoints operator-(const HealthPoints& healthPoints, const int& hp);

/**
     * Checks if two HealthPoints instances are not equal by comparing their HPs
     *
     * @param healthPoints1 -  first HealthPoints instance
     * @param healthPoints2 -  second HealthPoints instance
     * @return
     *      true if the two are not equal and false otherwise.
    */
bool operator!=(const HealthPoints& p1,const HealthPoints& p2);

/**
     * Checks if one HealthPoints instance is greater than the other by comparing their HPs
     *
     * @param healthPoints1 -  first HealthPoints instance
     * @param healthPoints2 -  second HealthPoints instance
     * @return
     *      true if the second is greater than the first and false otherwise.
    */
bool operator<(const HealthPoints& p1,const HealthPoints& p2);

/**
     * Checks if one HealthPoints instance is greater than or equal to the other by comparing their HPs
     *
     * @param healthPoints1 -  first HealthPoints instance
     * @param healthPoints2 -  second HealthPoints instance
     * @return
     *      true if the second is greater or equal to than the first and false otherwise.
    */
bool operator<=(const HealthPoints& p1,const HealthPoints& p2);

/**
     * Checks if one HealthPoints instance is greater than or equal to the other by comparing their HPs
     *
     * @param healthPoints1 -  first HealthPoints instance
     * @param healthPoints2 -  second HealthPoints instance
     * @return
     *      true if the first is greater or equal to than the second and false otherwise.
    */
bool operator>=(const HealthPoints& p1,const HealthPoints& p2);

#endif //HW3_HEALTH_POINTS_H
