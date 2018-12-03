#ifndef Domain_BattleBoats_Boat_hpp
#define Domain_BattleBoats_Boat_hpp


namespace Domain::BattleBoats
{
	class Boat
	{

		public:
			
			int getLength();
			char getSymbol();
			
			Boat()=default;

		protected:
			int length;
			char symbol;
			bool placed = false;
		
	};

	inline int Boat::getLength()
	{
		return length;
	}

	inline char Boat::getSymbol()
	{
		return symbol;
	}
}


#endif // !Domain_BattleBoats_Session_hpp