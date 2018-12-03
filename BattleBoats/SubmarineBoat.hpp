#ifndef Domain_BattleBoats_SubmarineBoat_hpp
#define Domain_BattleBoats_SubmarineBoat_hpp

#include "Boat.hpp"

namespace Domain::BattleBoats
{
	class SubmarineBoat : public Boat
	{
	public:
		SubmarineBoat();
		SubmarineBoat(char s);
	};

	inline SubmarineBoat::SubmarineBoat(char s)
	{
		length = 3;
		symbol = s;
	}
	
	inline SubmarineBoat::SubmarineBoat()
	{
		length = 3;
		symbol = 'S';
	}

}


#endif // !Domain_BattleBoats_SubmarineBoat_hpp

