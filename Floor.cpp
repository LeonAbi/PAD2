/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Floor.cpp
 * Author: stud
 * 
 * Created on 14. Mai 2017, 17:00
 */

#include "Floor.h"

Floor::Floor()
{
    setChar('.');
    m_item = nullptr;
    m_active = nullptr;
    m_passive = nullptr;
}

Floor::Floor(Item* item) : Tile()
{
    m_item = item;
    setChar('*');
    m_active = nullptr;
    m_passive = nullptr;
}

void Floor::onEnter(Character* c, Tile* fromTile)
{
    setFigure(c);
    if (m_item != nullptr)
    {
        c->addItem(m_item);
        setChar('.');
    }
    
}

void Floor::onLeave(Tile* toTile)
{
    if (!toTile->hasCharacter())
    {
        Character* tmp = getFigure();
        setFigure(nullptr);
        toTile->onEnter(tmp, this);

    }
}

void Floor::setItem(Item* item)
{
    m_item = item;
    setChar('*');
}

void Floor::setActive(Active* active){
    m_active = active;
    setChar(active->getChar());
}

void Floor::setPassive(Passive* passive){
    m_passive = passive;
    setChar(passive->getChar());
}

