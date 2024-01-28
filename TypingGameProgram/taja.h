#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <cmath>


#include <locale> 
#include <codecvt> 


using namespace std;
void addGame();
void make_file();
void printStartOption();
void printGameOption();
void dataOption();
void addOption();
void eraseOption();
void changeOption();
void logOut();
int option_input();
int count_char(const string& filename);
string getUserInput();
void add_data(const string& filename);
void erase_data(const string& filename);
void change_data(const string& filename);
void printFile(const string& filename);
int getLineNum(const string& filename);
void gameStart(const string& filename);
//////////////////////////////////////////
int random(int min, int max);
void StartaddGame();
void DyingMessage();
void addGame();

