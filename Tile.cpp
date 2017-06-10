/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.cpp
 * Author: stud
 * 
 * Created on 2. Mai 2017, 11:10
 */

#include "Tile.h"

Tile::Tile(){

   figure = nullptr; 
}

Tile::~Tile(){
    
}

Character* Tile::getFigure() const
{
    return figure;
}

Tile::Kacheltyp Tile::getTile() const
{
    return kachel;
}

void Tile::setFigure(Character* fig){
    figure = fig;
}

bool Tile::hasCharacter(){
    if(figure == nullptr) return false;
    else return true;
}

char Tile::getChar()
{
    return m_char;
}

void Tile::setChar(char chara)
{
    m_char = chara;
}

bool Tile::isTransparent(){
    return true;
}