#ifndef Domain_BattleBoats_PlayerBoard_hpp
#define Domain_BattleBoats_PlayerBoard_hpp

#include <memory>

#include "Boat.hpp"
#include "Cell.hpp"
#include "Board.hpp"

namespace Domain::BattleBoats
{

	class PlayerBoard : public Domain::BattleBoats::Board
	{


	public:

		using Board::Board;
		PlayerBoard();
		void placeBoat(std::shared_ptr<Domain::BattleBoats::Boat> boat) override;

		void placeFleet() override;

		void performGuess() override;
		
		void printGrid() override;

		void createFleet() override;

	};

}



#endif // !Domain_BattleBoats_PlayerBoard_hpp
