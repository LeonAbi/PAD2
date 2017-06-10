/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConsoleController.h
 * Author: stud
 *
 * Created on 16. Mai 2017, 21:18
 */

#include "Controller.h"

#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

using namespace std;


class ConsoleController : public Controller
{
public:
    ConsoleController();
    virtual ~ConsoleController();
    int move() override;
private:

};

#endif /* CONSOLECONTROLLER_H */

