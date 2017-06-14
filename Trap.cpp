/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trap.cpp
 * Author: stud
 * 
 * Created on 30. Mai 2017, 18:18
 */

#include "Trap.h"

Trap::Trap(char c)
{
    
    if(getChar() == 'T') setStatus(true);
    else setStatus(false);
    setChar('.');
}

Trap::~Trap()
{
}

void Trap::onLeave(Tile* toTile)
{
    if (!toTile->hasCharacter())
    {
        Character* tmp = getFigure();
        setFigure(nullptr);
        toTile->onEnter(tmp, this);

    }
}

void Trap::onEnter(Character* c, Tile* fromTile)
{
    if (getChar() == '.')
    {
        setFigure(c);
        c->setHP(-20);
        setChar('T');
    }
}

bool Trap::isTransparent(){
    return true;
}

void Trap::print(){
    if(getStatus() == true){
        cout << "T";
    }
    
    else{
        cout << ".";
    }
}


