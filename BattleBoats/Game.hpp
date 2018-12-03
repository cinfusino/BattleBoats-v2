#ifndef Domain_BattleBoats_Game_HPP
#define Domain_BattleBoats_Game_HPP

#include <memory>

#include "Board.hpp"
#include "AIBoard.hpp"
#include "PlayerBoard.hpp"
#include "Boat.hpp"


namespace Domain::BattleBoats
{
	class Game
	{

		public:
			Game();
			void playGame();
			~Game();


		private:

			Domain::BattleBoats::Board * baseBoard = new Domain::BattleBoats::PlayerBoard;
			
			Domain::BattleBoats::Board * attackBoard = new Domain::BattleBoats::AIBoard;


	};
}




#endif // !Domain_BattleBoats_Game_HPP
