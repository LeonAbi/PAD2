/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.h
 * Author: stud
 *
 * Created on 16. Mai 2017, 21:17
 */

#include <iostream>
#ifndef CONTROLLER_H
#define CONTROLLER_H

class Character;
class Controller
{
public:
    Controller();
    virtual ~Controller();
    virtual int move() =0;
    void setCharacter(Character* character);
private:
    Character* m_char;
};

#endif /* CONTROLLER_H */

