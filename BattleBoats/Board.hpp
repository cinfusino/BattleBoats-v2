#ifndef Domain_BattleBoats_Board_hpp
#define Domain_BattleBoats_Board_hpp

#include <memory>

#include "Boat.hpp"
#include "Cell.hpp"

namespace Domain::BattleBoats
{
	class Board
	{
		public:
			
			Board() = default;

			virtual void createFleet() = 0;

			virtual void placeBoat(std::shared_ptr<Domain::BattleBoats::Boat> boat) = 0;

			virtual void placeFleet() = 0;

			virtual void printGrid() = 0;

			virtual void performGuess() = 0;

			void createGrid();

			Cell * getCell(int r, int c);

			void decrementHealth();

			bool getDefeatFlag();

			


		protected: 

			Domain::BattleBoats::Cell Grid[10][10];

			std::shared_ptr<Domain::BattleBoats::Boat> Fleet[5];

			int health = 17;
			
			bool defeatFlag = false;
		


	};

}



#endif // !Domain_BattleBoats_Board_hpp
