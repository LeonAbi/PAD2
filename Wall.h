/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.h
 * Author: stud
 *
 * Created on 14. Mai 2017, 16:59
 */

#include "Tile.h"
#ifndef WALL_H
#define WALL_H

class Wall : public Tile
{
public:
    Wall();
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
    bool isTransparent();
private:
    Tile* frTile;
};

#endif /* WALL_H */

