#ifndef Domain_BattleBoats_CruiserBoat_hpp
#define Domain_BattleBoats_CruiserBoat_hpp

#include "Boat.hpp"

namespace Domain::BattleBoats
{
	class CruiserBoat : public Boat
	{
	public:
		CruiserBoat();
		CruiserBoat(char s);
	};

	inline CruiserBoat::CruiserBoat(char s)
	{
		length = 3;
		symbol = s;
	}

	inline CruiserBoat::CruiserBoat()
	{
		length = 3;
		symbol = 'C';
	}
	



}


#endif // !Domain_BattleBoats_CruiserBoat_hpp
