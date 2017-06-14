/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.cpp
 * Author: stud
 * 
 * Created on 29. Mai 2017, 19:44
 */

#include "Item.h"

Item::Item()
{
}

Item::Item(const Item& orig)
{
}

Item::~Item()
{
}

void Item::print(){
    cout << "*";
}

ArmingSword::ArmingSword() : Item()
{

}

ArmingSword::~ArmingSword(){
    
}

int ArmingSword::modifyStrength(int strength){
    return 3;
}

int ArmingSword::modifyStamina(int stamina){
    return 0;
}

Greatsword::Greatsword() : Item()
{

}

Greatsword::~Greatsword(){
    
}

int Greatsword::modifyStrength(int strength){
    return 5;
}

int Greatsword::modifyStamina(int stamina){
    return -1;
}

Club::Club() : Item()
{

}

Club::~Club(){
    
}


int Club::modifyStrength(int strength){
    return strength*0.5;
}

int Club::modifyStamina(int stamina){
    return 0;
}

RapierAndDagger::RapierAndDagger() : Item()
{

}

RapierAndDagger::~RapierAndDagger(){
    
}


int RapierAndDagger::modifyStrength(int strength){
    return 2;
}

int RapierAndDagger::modifyStamina(int stamina){
    return 1;
}

Gambeson::Gambeson() : Item()
{

}

Gambeson::~Gambeson(){
    
}

int Gambeson::modifyStrength(int strength){
    return 0;
}

int Gambeson::modifyStamina(int stamina){
    return 1;
}

MailArmour::MailArmour() : Item()
{

}

MailArmour::~MailArmour(){
    
}

int MailArmour::modifyStrength(int strength){
    return 0;
}

int MailArmour::modifyStamina(int stamina){
    return 3;
}

Shield::Shield() : Item()
{

}

Shield::~Shield(){
    
}

int Shield::modifyStrength(int strength){
    return -1;
}

int Shield::modifyStamina(int stamina){
    return stamina;
}

FullPlateArmour::FullPlateArmour() : Item()
{

}

FullPlateArmour::~FullPlateArmour(){
    
}

int FullPlateArmour::modifyStrength(int strength){
    return -2;
}

int FullPlateArmour::modifyStamina(int stamina){
    return 6;
}