/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Floor.h
 * Author: stud
 *
 * Created on 14. Mai 2017, 17:00
 */

#include "Tile.h"
#include "Item.h"
#include "Active.h"
#include "Passive.h"
#include "Door.h"
#include "Lever.h"
#include "Switch.h"
#include "Trap.h"

#ifndef FLOOR_H
#define FLOOR_H

class Floor : public Tile
{
public:
    Floor();
    Floor(Item* item);
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
    void setItem(Item* item);
    void setActive(Active* active);
    void setPassive(Passive* passive);
    bool isTransparent() override;
    void print() override;

private:
   Item* m_item; 
   Active* m_active;
   Passive* m_passive;
    
};

#endif /* FLOOR_H */

