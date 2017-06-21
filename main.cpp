/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stud
 *
 * Created on 2. Mai 2017, 11:09
 */

#include <cstdlib>
#include "GameEngine.h"
#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <fstream>
#include "Tile.h"
using namespace std;

/*
 * 
 */
void loadFromFile(string filename, vector<string>& map,vector<string>& specialTiles, int& hoehe, int& breite){
    ifstream spiel;
    string line;
    spiel.open(filename, ios::in);

        
        spiel >> breite;
        spiel >> hoehe;
        getline(spiel, line);
        for(int i=0;i<hoehe;i++){
            getline(spiel, line);
            map.push_back(line);
        }
        
        while(!spiel.eof()){
            getline(spiel, line);
            specialTiles.push_back(line);
        }

    spiel.close();
       

        
    }


int main(int argc, char** argv)
{
    int hoehe, breite;
    vector<string> map;
    vector<string> specialTiles;
    loadFromFile("level1.txt", map, specialTiles, hoehe, breite);
    GameEngine ge(hoehe, breite, map, specialTiles);
    ge.run();
//vector<string> data{
//"##########",
//"####.....#",
//"###......#",
//"##......t#",
//"#XL.XL...#",
//"#........#",
//"#........#",
//"#........#",
//"#........#",
//"##########",};
//
//
//vector<string> specialTiles{
//"Character @ 5 5 ConsoleController 5 5",
////"Character % 2 3 StationaryController 3 4",
//"Item Greatsword 2 4",
//"Door 4 1 Lever 4 2",
//"Trap 3 8",
//"Door 4 4 Lever 4 5"
//};
//
//GameEngine ge(10,10,data, specialTiles);
//ge.run();

    return 0;
}



