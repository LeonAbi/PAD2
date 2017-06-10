/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passive.cpp
 * Author: stud
 * 
 * Created on 16. Mai 2017, 19:30
 */

#include "Passive.h"

Passive::Passive() : Tile()
{
    m_status = false;
}


Passive::~Passive()
{
}

void Passive::setStatus(bool status)
{
    m_status = status;

    
}

bool Passive::getStatus()
{
    return m_status;
}

