/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.h
 * Author: stud
 *
 * Created on 29. Mai 2017, 19:44
 */


#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;
class Item
{
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();
    virtual int modifyStrength(int strength) = 0;
    virtual int modifyStamina(int stamina) = 0;
    void print();
private:
    char m_symbol;
};

class ArmingSword : public Item
{
public:
    ArmingSword();
    virtual ~ArmingSword();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;

};

class Greatsword : public Item
{
public:
    Greatsword();
    virtual ~Greatsword();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Club : public Item
{
public:
    Club();
    virtual ~Club();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class RapierAndDagger : public Item
{
public:
    RapierAndDagger();
    virtual ~RapierAndDagger();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Gambeson : public Item
{
public:
    Gambeson();
    virtual ~Gambeson();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class MailArmour : public Item
{
public:
    MailArmour();
    virtual ~MailArmour();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class Shield : public Item
{
public:
    Shield();
    virtual ~Shield();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

class FullPlateArmour : public Item
{
public:
    FullPlateArmour();
    virtual ~FullPlateArmour();
    int modifyStrength(int strength) override;
    int modifyStamina(int stamina) override;
};

#endif /* ITEM_H */
