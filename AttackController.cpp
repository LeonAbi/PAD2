/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttackController.cpp
 * Author: stud
 * 
 * Created on 13. Juni 2017, 02:33
 */

#include "AttackController.h"

AttackController::AttackController()
{
}

AttackController::AttackController(const AttackController& orig)
{
}

AttackController::~AttackController()
{
}

int AttackController::move(){
    
    Position thisContr;
    thisContr = m_map->findCharacter(m_char);
    
    vector<Position> vec = m_map->getPathTo(thisContr, m_map->findChar('@') );
    if(vec[1].reihe == (thisContr.reihe + 1) && vec[1].spalte == thisContr.spalte ) return 4;
    if(vec[1].reihe == (thisContr.reihe - 1) && vec[1].spalte == thisContr.spalte ) return 6;
    if(vec[1].reihe == (thisContr.reihe + 1) && vec[1].spalte == (thisContr.spalte +1) ) return 7;
    if(vec[1].reihe == (thisContr.reihe + 1) && vec[1].spalte == (thisContr.spalte -1) ) return 1;
    if(vec[1].reihe == thisContr.reihe && vec[1].spalte == (thisContr.spalte +1) ) return 8;
     if(vec[1].reihe == thisContr.reihe && vec[1].spalte == (thisContr.spalte -1) ) return 2;
    if(vec[1].reihe == (thisContr.reihe - 1) && vec[1].spalte == (thisContr.spalte +1) ) return 9;
    if(vec[1].reihe == (thisContr.reihe - 1) && vec[1].spalte == (thisContr.spalte -1) ) return 3;
    
}

