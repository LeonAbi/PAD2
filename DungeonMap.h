/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DungeonMap.h
 * Author: stud
 *
 * Created on 2. Mai 2017, 11:11
 */

#ifndef DUNGEONMAP_H
#define DUNGEONMAP_H

#include "Door.h"
#include "Switch.h"
#include <string>
#include "Tile.h"
#include <vector>
#include "Floor.h"
#include "Wall.h"
#include "Passive.h"
#include "Active.h"
#include "Lever.h"

using namespace std;

struct Position{
    int reihe;
    int spalte;
};

class DungeonMap
{
public:
    DungeonMap();
    DungeonMap(int height, int width);
    DungeonMap(int height, int width, const vector<string>& data);
    virtual ~DungeonMap();
    void place(Position pos, Character* c);
    Position findTile(Tile* t);
    Tile* findTile(Position pos);
    Position findCharacter(Character* c);
    void print(Position from);
    bool hasLineOfSight(Position from, Position to);
private:
    DungeonMap(const DungeonMap& orig);
    const int breite;
    const int hoehe;
    Tile*** playground;
};

#endif /* DUNGEONMAP_H */

