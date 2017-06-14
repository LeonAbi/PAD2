/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.cpp
 * Author: stud
 * 
 * Created on 16. Mai 2017, 19:41
 */

#include "Switch.h"

Switch::Switch(char c) : Active()
{
    setChar(c);
    
    if(getChar() == '?') setActivated(false);
    else setActivated(true);
}


Switch::~Switch()
{
}

void Switch::onEnter(Character* c, Tile* fromTile)
{
       setFigure(c);
       setActivated(true);
       setChar('!');
}

void Switch::onLeave(Tile* toTile)
{
//    if(!toTile->hasCharacter())
//    {
        Character* tmp = getFigure();
        setFigure(nullptr);
        toTile->onEnter(tmp, this);

    //}

}

void Switch::print(){
    if(getActivated() == true){
        cout << "!";
    }
    
    else{
        cout << "?";
    }
}
