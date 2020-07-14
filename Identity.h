#pragma once
#include <iostream>
#include <fstream>
#include "globalFile.h"
using namespace std;

class Identity {
public:
	virtual void OperMenu() = 0;
public:
	string m_Name;
	string m_Pwd;
};