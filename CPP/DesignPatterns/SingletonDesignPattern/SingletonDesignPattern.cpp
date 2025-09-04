// SingletonDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Singleton.h"

SingletonGameSetting* SingletonGameSetting::gameSetting = nullptr; //3. Static member variable initialization

int main()
{
    SingletonGameSetting* GameSetting = SingletonGameSetting::getInstance();
    GameSetting->displaySettings();

    SingletonGameSetting* GameSetting2 = SingletonGameSetting::getInstance();
    GameSetting2->setBrightness(100);
    GameSetting2->displaySettings();
    //Same object is shared all the places at whole progran because of singleton design pattern.
    return 0;
}