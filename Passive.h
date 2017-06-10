/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passive.h
 * Author: stud
 *
 * Created on 16. Mai 2017, 19:30
 */

#include "Tile.h"
#ifndef PASSIVE_H
#define PASSIVE_H

class Passive : public Tile
{
public:
    Passive();
    virtual ~Passive();
    void setStatus(bool status);
    bool getStatus();
//protected:
    bool m_status;
};

#endif /* PASSIVE_H */

