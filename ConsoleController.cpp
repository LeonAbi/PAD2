/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConsoleController.cpp
 * Author: stud
 * 
 * Created on 16. Mai 2017, 21:18
 */

#include "ConsoleController.h"

ConsoleController::ConsoleController() : Controller()
{

}

ConsoleController::~ConsoleController()
{
    
}



int ConsoleController::move()
{
    int eingabe;
    cout << "Wähle eine Richtung: (8 - oben / 4 - links / 6 - rechts / 2 - runter / 5 - stehen bleiben)" << endl;
    cin >> eingabe;
    return eingabe;
}

