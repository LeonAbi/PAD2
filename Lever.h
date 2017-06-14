/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lever.h
 * Author: stud
 *
 * Created on 30. Mai 2017, 18:11
 */

#include "Active.h"

#ifndef LEVER_H
#define LEVER_H

class Lever : public Active
{
public:
    Lever(char c);
    virtual ~Lever();
    void onEnter(Character* c, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    void print() override;
private:

};

#endif /* LEVER_H */

