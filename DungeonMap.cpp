/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DungeonMap.cpp
 * Author: stud
 * 
 * Created on 2. Mai 2017, 11:11
 */

#include "DungeonMap.h"

DungeonMap::DungeonMap() :
breite(0),
hoehe(0)
{
}

DungeonMap::DungeonMap(const DungeonMap& orig) :
breite(0), hoehe(0)
{
}

DungeonMap::~DungeonMap()
{
    for (int i = 0; i < hoehe; i++)
    {
        for (int j = 0; j < breite; j++)
        {
            delete playground[i][j];
        }
        delete[] playground[i];
    }
    delete[] playground;

}

DungeonMap::DungeonMap(int height, int width) :
breite(width), hoehe(height)
{
    playground = new Tile**[hoehe];
    for (int x = 0; x < hoehe; x++)
    {
        playground[x] = new Tile*[breite];
    }

    for (int i = 0; i < hoehe; i++)
    {
        for (int j = 0; j < breite; j++)
        {
            playground[i][j] = nullptr;
        }
    }


}

DungeonMap::DungeonMap(int height, int width, const vector<string>& data) :
breite(width), hoehe(height)
{


    playground = new Tile**[hoehe];
    for (int x = 0; x < hoehe; x++)
    {
        playground[x] = new Tile*[breite];
    }


    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            switch (data[i].at(j))
            {
            case '.':
                playground[i][j] = new Floor();
                break;
            case '#':
                playground[i][j] = new Wall();
                break;
            case 'X':
                playground[i][j] = new Door('X');
                break;
            case '/':
                playground[i][j] = new Door('/');

                break;
            case 'S':
                playground[i][j] = new Switch('?');
                break;
            case 's':
                playground[i][j] = new Switch('!');

                break;
            case 'L':
                playground[i][j] = new Lever('?');
                break;
            case 'l':
                playground[i][j] = new Lever('!');

                break;
            case 't':
                playground[i][j] = new Trap('.');
                break;
            case 'T':
                playground[i][j] = new Trap('T');
                break;
            default:
                throw std::runtime_error("invalid Tile Type requested");
            }
        }
    }
}

void DungeonMap::place(Position pos, Character* c)
{
    if (playground[pos.spalte][pos.reihe]->getTile() == Tile::Floor)
    {
        playground[pos.spalte][pos.reihe]->setFigure(c);

    }
}

Position DungeonMap::findTile(Tile* t)
{
    Position p;
    for (int i = 0; i < hoehe; i++)
    {
        for (int j = 0; j < breite; j++)
        {
            if (playground[i][j] == t)
            {

                p.reihe = j;
                p.spalte = i;

            }
        }
    }
    return p;
}

Tile* DungeonMap::findTile(Position pos)
{
    Tile* t;
    if (pos.reihe <= breite && pos.spalte <= hoehe)
    {
        t = playground[pos.spalte][pos.reihe];
    }
    return t;
}

Position DungeonMap::findCharacter(Character* c)
{

    Position p;
    for (int i = 0; i < hoehe; i++)
    {
        for (int j = 0; j < breite; j++)
        {
            if (playground[i][j]->getFigure() == c)
            {
                p.spalte = i;
                p.reihe = j;

            }

        }
    }
    return p;
}

void DungeonMap::print(Position from)
{

//    for (int i = 0; i < hoehe; i++)
//    {
//        for (int j = 0; j < breite; j++)
//        {
//            Position p;
//            p.reihe = i;
//            p.spalte = j;
//            if (hasLineOfSight(from, p))
//            {
//                if (playground[i][j]->hasCharacter())
//                {
//                    cout << playground[i][j]->getFigure()->getSign();
//                }
//
//                else {
//                    cout << playground[i][j]->getChar();
//                   
//                }
//            }
//            else cout << '^';
//            
//        }
//        cout << endl;
//    }




        for(int i=0;i<hoehe;i++){
            for(int j=0;j<breite;j++){
    
                    if(playground[i][j]->hasCharacter()){
                        cout << playground[i][j]->getFigure()->getSign();
                    }
                    else cout << playground[i][j]->getChar();
    
                
            }
            cout << endl;
}
        }

bool DungeonMap::hasLineOfSight(Position from, Position to)
{
    unsigned int rdeltax;
    unsigned int rdeltay;
    double deltax = (to.reihe - from.reihe);
    if(deltax > 0) rdeltax = deltax + 0.5;
    else rdeltax = deltax - 0.5;
    
    double deltay = (to.spalte - from.spalte);
    if(deltay > 0) rdeltay = deltay + 0.5;
    else rdeltay = deltay - 0.5;
    
    double m = deltay / deltax;
    double y;
    int round;

    if (rdeltax <= rdeltay)
    {
            int i=from.reihe;
            
            while(i<to.reihe){
                y = (m * (i - from.reihe)) + from.spalte;
                round = y + 0.5;
            if (playground[round][i]->getChar() == 'X' || playground[round][i]->getChar() == '#')
               return false;
                
                i++;
            }
            
            while(i>from.reihe){
                y = (m * (i - from.reihe)) + from.spalte;
                round = y + 0.5;
            if (playground[round][i]->getChar() == 'X' || playground[round][i]->getChar() == '#')
               return false;
                
                i--;
            }
            
            //        for (int i = from.reihe; i < to.reihe; i++)
//        {
//            int z=i;
//            if(deltax < 0){
//                
//                z = from.reihe - 2* (i - from.reihe);
//            }
//            
//            y = (m * (z - from.reihe)) + from.spalte;
//            round = y + 0.5;
//            if (playground[round][z]->getChar() == 'X' || playground[round][z]->getChar() == '#')
//                return false;
        }
    return true;
}

//        else{
//            for()
//        }
//    }
//
//    else
//    {
//        for(int i = from.spalte; i < to.spalte; i++)
//        {
//            int z=i;
//            if(deltay <0){
//                z = from.spalte - 2* (i - from.spalte);
//            }
//            y = (m * (z - from.spalte)) + from.reihe;
//            round = y + 0.5;
//            if (playground[round][z]->getChar() == 'X' || playground[round][z]->getChar() == '#')
//                return false;
//        }
//
//    }
//
//    return true;
//
//
//}

