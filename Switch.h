/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.h
 * Author: stud
 *
 * Created on 16. Mai 2017, 19:41
 */
#include "Active.h"

#ifndef SWITCH_H
#define SWITCH_H

class Switch : public Active
{
public:
    Switch(char c);
    virtual ~Switch();
    void onEnter(Character* c, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
private:

};

#endif /* SWITCH_H */

