/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.h
 * Author: stud
 *
 * Created on 2. Mai 2017, 11:10
 */

#ifndef TILE_H
#define TILE_H
#include "Character.h"

using namespace std;

class Tile
{
public:
    enum Kacheltyp{
        Floor, Wall
    };
    Tile();
    virtual ~Tile();
    Kacheltyp getTile() const;
    Character* getFigure() const;
    void setFigure(Character* fig);
    virtual void onLeave(Tile* toTile)=0;
    virtual void onEnter(Character* c, Tile* fromTile)=0;
    bool hasCharacter();
    void setChar(char chara);
    char getChar();
    virtual bool isTransparent()=0;
    virtual void print()=0;
private:
    Kacheltyp kachel;
    Character* figure;
    char m_char;
};


#endif /* TILE_H */

