#include"display.h"
std::string cellVal[] = { "|  ","| ","|" };
std::string tickCell[] = {"| O ","| X ","| O |","| X |"};
DisplayTable::DisplayTable()
{
	this->numRow = MAX_ROW;
	this->numColumn = MAX_COLUMN;
	this->err = false;
	this->errTick=false;
	this->isWin = false;
	this->resetTable();
}

void DisplayTable:: resetTable()
{
	int count = 0;
	for (int i = 0; i < this->numRow; i++)
	{
		for (int j = 0; j < this->numColumn-1; j++)
		{
			this->table[i][j] = cellVal[count<10?0:count<100?1:2] + std::to_string(count++);
		}
		this->table[i][numColumn-1] = cellVal[count < 10 ? 0 : count < 100 ? 1 : 2] +std::to_string(count++)+"|";
	}
	this->err = false;
	this->isWin = false;
}

void DisplayTable::displayTable()
{
	system("cls");
	for (int i = 0; i < this->numRow; i++)
	{
		for (int j = 0; j < this->numColumn; j++)
		{
			std::cout<<this->table[i][j];
		}
		std::cout << std::endl;
	}
}
void DisplayTable::tick(uint16_t num,uint8_t val)
{
	uint8_t row = num / this->numRow;
	uint8_t col = num % this->numColumn;
	if (num >= (MAX_ROW * MAX_COLUMN))
	{
		this->errTick = true;
		return;
	}
	bool isLastCol = (num % MAX_COLUMN == (MAX_COLUMN - 1));
	if (isLastCol)
	{
		if (this->table[row][col].compare(cellVal[num < 10 ? 0 : num < 100 ? 1 : 2] + std::to_string(num++) + "|"))
		{
			this->errTick = true;
			return;
		}
		this->table[row][col] = tickCell[val] + "|";
		this->lastTickRow = row;
		this->latTickColumn = col;
	}
	else
	{
		if (this->table[row][col].compare(cellVal[num < 10 ? 0 : num < 100 ? 1 : 2] + std::to_string(num++)))
		{
			this->errTick = true;
			return;
		}
		this->table[row][col] = tickCell[val];
		this->lastTickRow = row;
		this->latTickColumn = col;
	}
	this->errTick = false;
}
bool DisplayTable::getErr()
{
	return this->err;
}
bool DisplayTable::getErrTick()
{
	return this->errTick;
}
bool DisplayTable::getWinFlag()
{
	return this->isWin;
}
void DisplayTable::checkWin(uint8_t val)
{
	uint8_t count[4] = { 0,0,0,0 };
	uint8_t condition[4] = {MIN_WIN,MIN_WIN,MIN_WIN,MIN_WIN};
	uint8_t row = this->lastTickRow ;
	uint8_t col = this->latTickColumn ;
	uint8_t otherVal = (val == 0 ? 1 : 0);
	for (int index = row; index >= 0; index--)
	{
		if ((!(this->table[index][col].compare(tickCell[val]))) || (!(this->table[index][col].compare(tickCell[val + 2]))))
		{
			count[0]++;
		}
		else if ((!(this->table[index][col].compare(tickCell[otherVal]))) || (!(this->table[index][col].compare(tickCell[otherVal + 2])))) {
			condition[0]++;
			break;
		}
		else
		{
			break;
		}
	}
	for (int index = row+1; index < this->numRow; index++)
	{
		if ((!(this->table[index][col].compare(tickCell[val]))) || (!(this->table[index][col].compare(tickCell[val + 2]))))
		{
			count[0]++;
		}
		else if ((!(this->table[index][col].compare(tickCell[otherVal]))) || (!(this->table[index][col].compare(tickCell[otherVal + 2])))) {
			condition[0]++;
			break;
		}
		else
		{
			break;
		}
	}
	if (count[0] >= condition[0])
	{
		this->isWin = true;
		return;
	}

	for (int index = col; index >= 0; index--)
	{
		if ((!(this->table[row][index].compare(tickCell[val]))) || (!(this->table[row][index].compare(tickCell[val + 2]))))
		{
			count[1]++;
		}
		else if ((!(this->table[row][index].compare(tickCell[otherVal]))) || (!(this->table[row][index].compare(tickCell[otherVal + 2])))) {
			condition[1]++;
			break;
		}
		else
		{
			break;
		}
	}
	for (int index = col + 1; index < this->numColumn; index++)
	{
		if ((!(this->table[row][index].compare(tickCell[val]))) || (!(this->table[row][index].compare(tickCell[val + 2]))))
		{
			count[1]++;
		}
		else if ((!(this->table[row][index].compare(tickCell[otherVal]))) || (!(this->table[row][index].compare(tickCell[otherVal + 2])))) {
			condition[1]++;
			break;
		}
		else
		{
			break;
		}
	}
	if (count[1] >= condition[1])
	{
		this->isWin = true;
		return;
	}


	for (int i = row,j=col; i >= 0&&j>=0; i--,j--)
	{
		if ((!(this->table[i][j].compare(tickCell[val]))) || (!(this->table[i][j].compare(tickCell[val + 2]))))
		{
			count[2]++;
		}
		else if ((!(this->table[i][j].compare(tickCell[otherVal]))) || (!(this->table[i][j].compare(tickCell[otherVal + 2])))) {
			condition[2]++;
			break;
		}
		else
		{
			break;
		}
	}
	for (int i=row+1,j = col + 1; i<this->numRow && j < this->numColumn; i++,j++)
	{
		if ((!(this->table[i][j].compare(tickCell[val]))) || (!(this->table[i][j].compare(tickCell[val + 2]))))
		{
			count[2]++;
		}
		else if ((!(this->table[i][j].compare(tickCell[otherVal]))) || (!(this->table[i][j].compare(tickCell[otherVal + 2])))) {
			condition[2]++;
			break;
		}
		else
		{
			break;
		}
	}
	if (count[2] >= condition[2])
	{
		this->isWin = true;
		return;
	}



	for (int i = row, j = col; i >= 0 && j < this->numColumn; i--, j++)
	{
		if ((!(this->table[i][j].compare(tickCell[val]))) || (!(this->table[i][j].compare(tickCell[val + 2]))))
		{
			count[3]++;
		}
		else if ((!(this->table[i][j].compare(tickCell[otherVal]))) || (!(this->table[i][j].compare(tickCell[otherVal + 2])))) {
			condition[3]++;
			break;
		}
		else
		{
			break;
		}
	}
	for (int i = row + 1, j = col -1; i < this->numRow && j >= 0; i++, j--)
	{
		if ((!(this->table[i][j].compare(tickCell[val]))) || (!(this->table[i][j].compare(tickCell[val + 2]))))
		{
			count[3]++;
		}
		else if ((!(this->table[i][j].compare(tickCell[otherVal]))) || (!(this->table[i][j].compare(tickCell[otherVal + 2])))) {
			condition[3]++;
			break;
		}
		else
		{
			break;
		}
	}
	if (count[3] >= condition[3])
	{
		this->isWin = true;
		return;
	}
}