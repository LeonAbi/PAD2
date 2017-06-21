/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameEngine.h
 * Author: stud
 *
 * Created on 2. Mai 2017, 11:11
 */

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "DungeonMap.h"
#include <vector>
#include "Character.h"
#include "Tile.h"
#include <sstream>
#include "Controller.h"
#include "ConsoleController.h"
#include "StationaryController.h"
#include "Lever.h"
#include "Switch.h"
#include "Door.h"
#include "Trap.h"

using namespace std;

struct Links{
    Position p1;
    Position p2;
};
class GameEngine
{
public:
    GameEngine();
    GameEngine(int height, int width, const vector<string>& data, vector<string>& specialTiles);
    virtual ~GameEngine();
    bool finished();
    void turn();
    void run();
    void help(vector<string> doors);
    void parser(vector<string>& specialTiles);
    void helpDoor(istringstream& stream, string s);
    void helpCharacter(istringstream& stream);
    void helpItem(istringstream& stream);
    void menue();
 
private:
    DungeonMap dm;
    vector<Character*> m_chars;
    Character* chara;
    vector<Links> m_pos;
};

#endif /* GAMEENGINE_H */

