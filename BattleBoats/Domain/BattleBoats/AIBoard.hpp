#ifndef Domain_BattleBoats_AIBoard_hpp
#define Domain_BattleBoats_AIBoard_hpp

#include <memory>

#include "Boat.hpp"
#include "Cell.hpp"
#include "Board.hpp"

namespace Domain::BattleBoats
{

	class AIBoard : public Domain::BattleBoats::Board
	{


	public:

		using Board::Board;
		AIBoard();
		void placeBoat(std::shared_ptr<Domain::BattleBoats::Boat> boat) override;

		void placeFleet() override;

		void performGuess() override;

		void printGrid() override;

		void createFleet() override;


	};

}



#endif // !Domain_BattleBoats_AIBoard_hpp
