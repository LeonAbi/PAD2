/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Active.h
 * Author: stud
 *
 * Created on 16. Mai 2017, 19:31
 */
#include "Tile.h"
#include "Passive.h"
#include <vector>
#ifndef ACTIVE_H
#define ACTIVE_H

class Active : public Tile
{
public:
    Active();
    virtual ~Active();
    void setActivated(bool activated);
    bool getActivated();
    void setpPassive(Passive* pPassive);
    bool isTransparent() override;
private:
    bool m_activated;
    Passive* m_pPassive;
};

#endif /* ACTIVE_H */

