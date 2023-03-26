#ifndef GAME_H
#define GAME_H


#include <string>

class Game {
public:
	Game(int mode) : _mode(mode) {}
    void setupGame();
    void saveData();
    void startGame();
    void printInterface();    
    std::string getPlayerName() const { return playerName; }
    int getPlayerID() const { return playerID; }
    std::string getPlayerClass() const { return playerClass; }


private:
    std::string playerName;
    int playerID;
    std::string playerClass;
    int _mode;
	int _x, _y;
	bool isPlaying;
	int _lockedBlock;
	int _remainBlocks;
	int score;
};

#endif
