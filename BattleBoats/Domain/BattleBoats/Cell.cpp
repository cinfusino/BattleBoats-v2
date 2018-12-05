#include "Cell.hpp"

namespace Domain::BattleBoats
{
	Cell::Cell()
	{

	}

	Cell::Cell(int r, int c)
	{
		row = r;
		column = c;
	}

	int Cell::getRow()
	{
		return row;
	}
	int Cell::getColumn()
	{
		return column;
	}

	bool Cell::getPresent()
	{
		return shipPresent;
	}

	char Cell::getSymbol()
	{
		return symbol;
	}

	bool Cell::getGuessed()
	{
		return cellGuessed;
	}

	void Cell::setSymbol(char s)
	{
		symbol = s;
	}

	void Cell::setPresent(bool p)
	{
		shipPresent = p;
	}

	void Cell::setGuessed(bool g)
	{
		cellGuessed = g;
	}

	Cell::~Cell()
	{

	}

}