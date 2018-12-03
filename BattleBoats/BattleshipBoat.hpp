#ifndef Domain_BattleBoats_BattleshipBoat_hpp
#define Domain_BattleBoats_BattleshipBoat_hpp

#include "Boat.hpp"

namespace Domain::BattleBoats
{
	class BattleshipBoat : public Boat
	{
	public:
		BattleshipBoat();
		BattleshipBoat(char s);
	};

	inline BattleshipBoat::BattleshipBoat(char s)
	{
		length = 4;
		symbol = s;
	}
	inline BattleshipBoat::BattleshipBoat()
	{
		length = 4;
		symbol = 'B';
	}


}


#endif // !Domain_BattleBoats_BattleshipBoat_hpp

