/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.cpp
 * Author: stud
 * 
 * Created on 2. Mai 2017, 11:11
 */

#include "Character.h"
#include "Controller.h"
#include "ConsoleController.h"

Character::Character()
{
    m_controller = new ConsoleController();
    m_controller->setCharacter(this);
}

Character::Character(char sign, int strength, int stamina, Controller* controller)
{
    m_sign = sign;
    m_controller = controller;
    m_controller->setCharacter(this);
    m_strength = strength;
    m_stamina = stamina;
    m_hitpoints = getMaxHP();
}

Character::~Character(){
    m_items.clear();
    delete m_controller;
}

char Character::getSign() const
{
    return m_sign;
}

int Character::move()
{
   return m_controller->move();
}

int Character::getMaxHP(){
    return 20+(getStamina() * 5);
}

void Character::showInfo(){
    cout<< "Character: " << m_sign << endl;
    cout<< "Strength: "<< m_strength<< endl;
    cout<< "Stamina: "<< m_stamina<< endl;
    cout<< "HP: "<< m_hitpoints<< endl << endl;
}

void Character::addItem(Item* item){
    m_items.push_back(item);
}

int Character::getStamina(){
    int sum=m_stamina;
    for(int i=0;i<m_items.size();i++){
        sum = sum + m_items.at(i)->modifyStamina(m_stamina);
    }
    return sum;
}

int Character::getStrength(){
    int sum=m_strength;
    for(int i=0;i<m_items.size();i++){
        sum = sum + m_items.at(i)->modifyStrength(m_stamina);
    }
    return sum;
}

void Character::setHP(int hp){
    m_hitpoints = m_hitpoints + hp;
}

int Character::getHp(){
    return m_hitpoints;
}

//ostream& Character::operator<<(ostream& output, const Character& character){
//    
//    return output;
//}