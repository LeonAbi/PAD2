/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trap.h
 * Author: stud
 *
 * Created on 30. Mai 2017, 18:18
 */

#include "Passive.h"

#ifndef TRAP_H
#define TRAP_H

class Trap : public Passive
{
public:
    Trap(char c);
    virtual ~Trap();
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
private:

};

#endif /* TRAP_H */

