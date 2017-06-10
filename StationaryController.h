/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StationaryController.h
 * Author: stud
 *
 * Created on 30. Mai 2017, 18:38
 */

#include "Controller.h"

#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H

class StationaryController : public Controller
{
public:
    StationaryController();
    virtual ~StationaryController();
    int move() override;
private:

};

#endif /* STATIONARYCONTROLLER_H */

