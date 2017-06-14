/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.h
 * Author: stud
 *
 * Created on 16. Mai 2017, 19:42
 */
#include "Passive.h"
#ifndef DOOR_H
#define DOOR_H

class Door : public Passive
{
public:
    Door(char c);
    virtual ~Door();
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
    bool isTransparent() override;
    void print() override;
private:

};

#endif /* DOOR_H */

