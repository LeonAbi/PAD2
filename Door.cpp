/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.cpp
 * Author: stud
 * 
 * Created on 16. Mai 2017, 19:42
 */

#include "Door.h"

Door::Door(char c) : Passive()
{
    setChar('X');
    
    if(c == '/') setStatus(true);
    else setStatus(false);
}




Door::~Door()
{
}

void Door::onLeave(Tile* toTile)
{
    if(!toTile->hasCharacter())
    {
        Character* tmp = getFigure();
        setFigure(nullptr);
        toTile->onEnter(tmp, this);

    }
}

void Door::onEnter(Character* c, Tile* fromTile)
{
    if(getChar() == '/')
    {
        setFigure(c);
    }
    else 
    {
        fromTile->setFigure(c);
    }
}

bool Door::isTransparent(){
    return getStatus();
}

void Door::print(){
    if(getStatus() == true){
        cout << "/";
    }
    
    else{
        cout << "X";
    }
}
