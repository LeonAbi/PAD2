/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.cpp
 * Author: stud
 * 
 * Created on 14. Mai 2017, 16:59
 */

#include "Wall.h"

Wall::Wall() : Tile()
{
    setChar('#');
}

void Wall::onLeave(Tile* toTile)
{
        
}

void Wall::onEnter(Character* c, Tile* fromTile)
{
    fromTile->setFigure(c);
}

bool Wall::isTransparent(){
    return false;
}

void Wall::print(){
    cout << '#';
}
