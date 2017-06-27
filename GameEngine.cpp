/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameEngine.cpp
 * Author: stud
 * 
 * Created on 2. Mai 2017, 11:11
 */

#include "GameEngine.h"
#include "StationaryController.h"

GameEngine::GameEngine()
{

}

GameEngine::GameEngine(int height, int width, const vector<string>& data, vector<string>& specialTiles) :
dm(height, width, data)
{
    parser(specialTiles);
}

GameEngine::~GameEngine()
{
    delete chara;
}

bool GameEngine::finished()
{

    if (dm.findCharacter(m_chars[0]).reihe == 3 && dm.findCharacter(m_chars[0]).spalte == 6)
    {
        return true;
    }
    else
        return false;

}

void GameEngine::turn()
{
    Position p;
    Position p_old;
    Tile* t_old;
    Tile* t_new;
    int richtung;

    for (int i = 0; i < m_chars.size(); i++)
    {
        dm.print(dm.findCharacter(m_chars.at(i)));
        richtung = m_chars.at(i)->move();
        p = dm.findCharacter(m_chars.at(i));
        p_old = p;
        t_old = dm.findTile(p);

        switch (richtung)
        {
        case 0: menue();
        break;
        case 1: p.spalte++;
            p.reihe--;
            break;
        case 3: p.reihe++;
            p.spalte++;
            break;
        case 7: p.reihe--;
            p.spalte--;
            break;
        case 9: p.spalte--;
            p.reihe++;
            break;
        case 8: p.spalte--;
            break;
        case 4: p.reihe--;
            break;
        case 6: p.reihe++;
            break;
        case 2: p.spalte++;
            break;
        default: break;
        }

        //alte Variante funktioniert
        t_new = dm.findTile(p);
        t_old->onLeave(t_new);
        
        //neue Variante funktioniert noch nicht
        
//        if (t_new->getFigure() != nullptr)
//        {
//            t_new->getFigure()->setHP((t_new->getFigure()->getMaxHP() - t_old->getFigure()->getStrength()));
//            if (t_new->getFigure()->getHP() > 0)
//            {
//                t_old->getFigure()->setHP((t_old->getFigure()->getMaxHP() - t_new->getFigure()->getStrength()));
//            }
//            else t_old->onLeave(t_new);
//        }
//        
//        int humanChars = 0;
//        
//        for(int i =0; i< m_chars.size(); i++){
//            if(m_chars.at(i)->getSign() != 'q') humanChars++;
//        }
//        
//       // if(humanChars > 0) exit(0);

    }

}

void GameEngine::run()
{
    while (!finished())
    {
        turn();
    }
}

//void GameEngine::help(vector<string> doors)
//{
//
//
//    vector<int> v;
//    Position p1, p2;
//    Links l;
//    Active* aTile;
//    Passive* pTile;
//
//
//    for (int i = 0; i < doors.size(); i++)
//    {
//        istringstream iss(doors[i]);
//        for (int j = 0; j < 4; j++)
//        {
//            int val;
//            iss >> val;
//            v.push_back(val);
//        }
//    }
//
//    for (int i = 0; i < v.size(); i = i + 4)
//    {
//        p1.reihe = v[i + 1];
//        p1.spalte = v[i];
//        p2.reihe = v[i + 3];
//        p2.spalte = v[i + 2];
//        //        l.p1 = p1;
//        //        l.p2 = p2;
//        //        m_pos.push_back(l);
//        //if(dm.findTile(m_pos[i].p1) == Switch && dm.findTile(m_pos[i].p2 == Door)){
//
//        aTile = dynamic_cast<Active*> (dm.findTile(p1));
//        pTile = dynamic_cast<Passive*> (dm.findTile(p2));
//        aTile->setpPassive(pTile);
//        //        }
//    }
//}

void GameEngine::parser(vector<string>& specialTiles)
{

    for (int i = 0; i < specialTiles.size(); i++)
    {
        string word = "";
        //speichert den ersten String in sstream
        istringstream sstream(specialTiles.at(i));

        //übergibt Zeichenkette bis zum Leerzeichen
        sstream >> word;

        if (word == "Door")
        {
            helpDoor(sstream, word);
        }

        else if (word == "Character")
        {
            helpCharacter(sstream);
        }

        else if (word == "Trap")
        {
            helpTrap(sstream, word);
        }

        else if (word == "Item")
        {
            helpItem(sstream);
        }

        //else throw runtime_error("Falsches Objekt");
    }
}

void GameEngine::helpCharacter(istringstream& stream)
{
    string word;
    char symbol;
    int strength, stamina;
    Position p1;
    Controller* controller;

    stream >> symbol >> strength >> stamina >> word >> p1.spalte >> p1.reihe;

    if (word == "ConsoleController")
    {
        controller = new ConsoleController();
    }

    if (word == "StationaryController")
    {
        controller = new StationaryController();
    }
    
//    if(word == "AttackController"){
//        controller = new AttackController();
//    }
    
    chara = new Character(symbol, strength, stamina, controller);
    m_chars.push_back(chara);
    dm.place(p1, chara);
}

void GameEngine::helpDoor(istringstream& stream, string s)
{
    string word;
    Passive* pTile;
    Active* aTile;
    Position p1, p2;


    //nacheinander Reihe/Spalte eingelesen
    stream >> p1.reihe;
    stream >> p1.spalte;  
    
    dm.setTile(p1.spalte, p1.reihe, s);
    pTile = dynamic_cast<Passive*> (dm.findTile(p1));

        stream >> word;
        stream >> p2.reihe;
        stream >> p2.spalte;
    
        
        dm.setTile(p2.spalte, p2.reihe, word);
        aTile = dynamic_cast<Active*> (dm.findTile(p2));

         
        aTile->setpPassive(pTile);

}


void GameEngine::helpItem(istringstream& stream)
{
    string word;
    Position p1;
    Item* item;
    Floor* floor;

    stream >> word >> p1.spalte >> p1.reihe;
    floor = dynamic_cast<Floor*> (dm.findTile(p1));

    // if(dm.findTile(p1)->getChar() == '.'){
    if (word == "Greatsword")
    {
        item = new Greatsword();
    }
    if (word == "Armingsword" || word == "ArmingSword")
    {
        item = new ArmingSword;
    }
    if (word == "Club")
    {
        item = new Club;
    }
    if (word == "Rapier&Dagger" || word == "RapierAndDagger")
    {
        item = new RapierAndDagger();
    }
    if (word == "Gambeson")
    {
        item = new Gambeson;
    }
    if (word == "MailArmour" || "Mailarmour")
    {
        item = new MailArmour;
    }
    if (word == "Shield")
    {
        item = new Shield();
    }
    if (word == "FullPlateArmour")
    {
        item = new FullPlateArmour;
    }
    // }
    floor->setItem(item);
}

void GameEngine::menue(){
    int eingabe;
    
    cout << "\nMenü: \n";
    cout << "0. Programm beenden \n1. Spielerinfo \n2. Weiter" << endl;
            
            cin >> eingabe;
    switch(eingabe){
    case 0:          
        exit(0);
        
    case 1:     for(int i=0;i<m_chars.size();i++){
        m_chars.at(i)->showInfo();
    }
    break;
    break;
    case 2:     break;
    }
}


//funktioniert noch nicht richtig
void GameEngine::helpTrap(istringstream& stream, string word){
    Position p1;
    
    stream >> p1.reihe >> p1.spalte;
    
    dm.setTile(p1.spalte,p1.reihe, word);
    
}
