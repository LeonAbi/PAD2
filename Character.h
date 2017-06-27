/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: stud
 *
 * Created on 2. Mai 2017, 11:11
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "Controller.h"
#include "Item.h"
#include "vector"

using namespace std;


class Character
{
public:
    Character();
    Character(char sign, int strenght, int stamina, Controller* controller);
    virtual ~Character();
    char getSign() const;
    int move();
    int getMaxHP();
    void showInfo();
    void addItem(Item* item);
    int getStamina();
    int getStrength();
    void setHP(int hp);
    int getHP();
    
    //Operatorüberladung
    friend ostream& operator<<(ostream& outputstream, Character& character);
private:
    char m_sign;
    Controller* m_controller;
    int m_strength;
    int m_stamina;
    int m_hitpoints;
    vector<Item*> m_items;
};

#endif /* CHARACTER_H */
