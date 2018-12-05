#ifndef Domain_BattleBoats_DestroyerBoat_hpp
#define Domain_BattleBoats_DestroyerBoat_hpp

#include "Boat.hpp"

namespace Domain::BattleBoats
{
	class DestroyerBoat : public Boat
	{
	public:
		DestroyerBoat();
		DestroyerBoat(char s);
	};

	inline DestroyerBoat::DestroyerBoat(char s)
	{
		length = 2;
		symbol = s;
	}
	inline DestroyerBoat::DestroyerBoat()
	{
		length = 2;
		symbol = 'D';
	}

}


#endif // !Domain_BattleBoats_DestroyerBoat_hpp

