#pragma once
#include <iostream>
#include "config.h"
#include<string>
#include <stdlib.h>
class DisplayTable
{
	public:
		/*Constructor*/								
		 DisplayTable();														
		 void displayTable();
		 void tick(uint16_t,uint8_t);
		 bool getErr();
		 bool getWinFlag();
		 bool getErrTick();
		 void checkWin(uint8_t);
		 void resetTable();
	private:
		bool err,errTick;
		bool isWin;
		uint16_t lastTickRow,latTickColumn;
		uint8_t numRow, numColumn;
		std::string table[MAX_ROW][MAX_COLUMN];
		
};