#ifndef DOMAIN_BATTLEBOATS_CELL_HPP
#define DOMAIN_BATTLEBOATS_CELL_HPP


namespace Domain::BattleBoats
{
	class Cell
	{
		public:
			Cell();
			Cell(int r, int c);

			int getRow();
			int getColumn();
			bool getPresent();
			char getSymbol();
			bool getGuessed();

			void setSymbol(char s);
			void setPresent(bool p);
			void setGuessed(bool g);

			~Cell();

	private:
		int row;
		int column;
		bool shipPresent = false;
		bool cellGuessed = false;
		char symbol = '#';
	};

}


#endif // !DOMAIN_BATTLEBOATS_CELL_HPP
