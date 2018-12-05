#ifndef Domain_BattleBoats_AircraftCarrierBoat_hpp
#define Domain_BattleBoats_AircraftCarrierBoat_hpp

#include "Boat.hpp"

namespace Domain::BattleBoats
{
	class AircraftCarrierBoat : public Boat
	{
		public:
			AircraftCarrierBoat();
			AircraftCarrierBoat(char s);

	};

	inline AircraftCarrierBoat::AircraftCarrierBoat(char s)
	{
		length = 5;
		symbol = s;
	}

	inline AircraftCarrierBoat::AircraftCarrierBoat()
	{
		length = 5;
		symbol = 'A';
	}



}


#endif // !Domain_BattleBoats_AircraftCarrierBoat_hpp

