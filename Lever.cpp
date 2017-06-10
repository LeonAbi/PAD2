/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lever.cpp
 * Author: stud
 * 
 * Created on 30. Mai 2017, 18:11
 */

#include "Lever.h"
#include "Active.h"

Lever::Lever(char c) : Active()
{
    setChar(c);

    if (getChar() == '?') setActivated(false);
    else setActivated(true);
}

Lever::~Lever()
{
}

void Lever::onEnter(Character* c, Tile* fromTile)
{
    setFigure(c);
    if (getActivated()==true)
    {
        setActivated(false);
        setChar('?');
    }
    else {
        setActivated(true);
        setChar('!');
    }


}

void Lever::onLeave(Tile* toTile)
{
    //    if(!toTile->hasCharacter())
    //    {
    Character* tmp = getFigure();
    setFigure(nullptr);
    toTile->onEnter(tmp, this);

    //}

}

