/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Active.cpp
 * Author: stud
 * 
 * Created on 16. Mai 2017, 19:31
 */

#include <vector>

#include "Active.h"

Active::Active() : Tile()
{

}

Active::~Active()
{
}

bool Active::getActivated()
{
    return m_activated;
}

void Active::setActivated(bool activated)
{
    m_activated = activated;
    if(m_pPassive == nullptr)
        return;
    if (m_activated)
    {
        m_pPassive->setChar('/');
        m_pPassive->setStatus(true);
    }
    else {
        m_pPassive->setChar('X');
        m_pPassive->setStatus(false);
    }

}

void Active::setpPassive(Passive* pPassive)
{
    m_pPassive = pPassive;
}

bool Active::isTransparent(){
    return true;
}