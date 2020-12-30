#ifndef GAME_H
#define GAME_H

#include "player.h"

#include <QChar>

#include <QDebug>

class Game
{
public:
    Game(const Player &, const Player &);

    ~Game() { delete board; delete goodSequence; }

    void play(Player *, int);

    bool validPosition(int);

    bool isWinner(const QChar&);

    bool isTie();

    bool getEnable() const;

    void reset();

    Player *getWinner() const;

    int getBoardSize() const;

    int *getGoodSequence() const;

    void setGoodSequence(const QChar &symb);

private:
   Player player1;
   Player player2;
   Player* winner;
   QChar* board;
   int* goodSequence;
   bool enable;
   int boardSize;
   void setBoard();
   void setEnable(bool value);

};

#endif // GAME_H
