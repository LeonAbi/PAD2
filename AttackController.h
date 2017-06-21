/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttackController.h
 * Author: stud
 *
 * Created on 13. Juni 2017, 02:33
 */

#include "Controller.h"
#include "DungeonMap.h"
#include "Character.h"
#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H

class AttackController : public Controller
{
public:
    AttackController();
    AttackController(const AttackController& orig);
    virtual ~AttackController();
    int move() override;
private:
    DungeonMap* m_map;
    Character* m_char;
};

#endif /* ATTACKCONTROLLER_H */

