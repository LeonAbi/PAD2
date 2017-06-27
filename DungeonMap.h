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
#include <iostream>
#include "Switch.h"
#include <string>
#include "Tile.h"
#include <vector>
#include "Floor.h"
#include "Wall.h"
#include "Passive.h"
#include "Active.h"
#include "Lever.h"
#include <cmath>
#include "Item.h"
#include <set>

using namespace std;

struct Position{
    int reihe;
    int spalte;
    
    friend ostream& operator<<(ostream& outputstream, const Position& pos){
        outputstream << "(" << pos.reihe << "/" << pos.spalte << ")";
    }
    friend istream& operator>>(istream& inputstream, Position& pos){
        inputstream >> pos.reihe >> pos.spalte;
    }
};

struct Kante{
    Position knoten1;
    Position knoten2;
};

struct comp{
    bool operator()(const Position& left,const Position& right){
        if(left.reihe == right.reihe) return left.spalte<right.spalte;
        else return left.reihe < right.reihe;
    }
};

struct compKante{
    bool operator()(const Kante& left,const Kante& right){
        if(left.knoten1.reihe == right.knoten1.reihe && left.knoten1.spalte == right.knoten1.spalte){
            if(left.knoten2.reihe == right.knoten2.reihe) return left.knoten2.spalte < right.knoten2.spalte;
            else return left.knoten2.reihe < right.knoten2.reihe;
        }
        else{
            if(left.knoten1.reihe == right.knoten1.reihe) return left.knoten1.spalte < right.knoten1.spalte;
            else return left.knoten1.reihe < right.knoten1.reihe;
        }
    }
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
    vector<Position> getPathTo(Position from, Position to);
    Position findChar(char c);
    double round(double x);
    void setTile(int x, int y, string tile);
    vector<Kante> Dijkstra(set<Kante, compKante> gegeben, vector<Kante> gelaufen, Position start, Position ziel);
    int posAbstand(Position p1, Position p2);
    bool samePos(Position p1, Position p2);

private:
    DungeonMap(const DungeonMap& orig);
    const int breite;
    const int hoehe;
    Tile*** playground;
};

#endif /* DUNGEONMAP_H */

