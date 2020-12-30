#include "game.h"

Game::Game(const Player& p1, const Player& p2)
    : player1(p1)
    , player2(p2)
    , winner(nullptr)
{
    boardSize = 9;
    board = new QChar[boardSize];
    setBoard();
    setEnable(true);
}

bool Game::getEnable() const
{
    return enable;
}

void Game::reset()
{
    setBoard();
    setEnable(true);
    player1.setEnable(true);
    player1.setEnable(false);
}

void Game::setEnable(bool value)
{
    enable = value;
}

int Game::getBoardSize() const
{
    return boardSize;
}

Player *Game::getWinner() const
{
    return winner;
}

int *Game::getGoodSequence() const
{
    return goodSequence;
}

void Game::setGoodSequence(const QChar& symb)
{
    goodSequence = new int[3];
    if (board[0] == symb && board[1] == symb && board[2] == symb) {
        goodSequence[0] = 0;
        goodSequence[1] = 1;
        goodSequence[2] = 2;
    }
    if (board[3] == symb && board[4] == symb && board[5] == symb) {
        goodSequence[0] = 3;
        goodSequence[1] = 4;
        goodSequence[2] = 5;
    }
    if (board[6] == symb && board[7] == symb && board[8] == symb) {
        goodSequence[0] = 6;
        goodSequence[1] = 7;
        goodSequence[2] = 8;
    }
    if (board[0] == symb && board[3] == symb && board[6] == symb) {
        goodSequence[0] = 0;
        goodSequence[1] = 3;
        goodSequence[2] = 6;
    }
    if (board[1] == symb && board[4] == symb && board[7] == symb) {
        goodSequence[0] = 1;
        goodSequence[1] = 4;
        goodSequence[2] = 7;
    }
    if (board[2] == symb && board[5] == symb && board[8] == symb) {
        goodSequence[0] = 2;
        goodSequence[1] = 5;
        goodSequence[2] = 8;
    }
    if (board[0] == symb && board[4] == symb && board[8] == symb) {
        goodSequence[0] = 0;
        goodSequence[1] = 4;
        goodSequence[2] = 8;
    }
    if (board[2] == symb && board[4] == symb && board[6] == symb) {
        goodSequence[0] = 2;
        goodSequence[1] = 4;
        goodSequence[2] = 6;
    }
}

void Game::setBoard()
{
    for (int i=0; i < boardSize; i++) {
        board[i] = QChar(' ');
    }
}

void Game::play(Player *p, int pos)
{
    system("cls");
    if (enable && validPosition(pos)) {
        if (p->isEnable()) {
            board[pos] = p->getSymb();
        }
        if (isWinner(p->getSymb())) {
            winner = p;
            setEnable(false);
            setGoodSequence(p->getSymb());
        }
        else if (isTie()) {
            setEnable(false);
            winner = nullptr;
        }
    }
    qDebug() << "BOARD: \n"
             << board[0] << ' ' << board[1] << ' ' << board[2] << "\n"
             << board[3] << ' ' << board[4] << ' ' << board[5] << "\n"
             << board[6] << ' ' << board[7] << ' ' << board[8] << Qt::endl;
}

bool Game::validPosition(int pos)
{
    return board[pos] == ' ' && pos >= 0 && pos <= 8;
}

bool Game::isWinner(const QChar &symb)
{
    return  (board[0] == symb && board[1] == symb && board[2] == symb) ||
            (board[3] == symb && board[4] == symb && board[5] == symb) ||
            (board[6] == symb && board[7] == symb && board[8] == symb) ||
            (board[0] == symb && board[3] == symb && board[6] == symb) ||
            (board[1] == symb && board[4] == symb && board[7] == symb) ||
            (board[2] == symb && board[5] == symb && board[8] == symb) ||
            (board[0] == symb && board[4] == symb && board[8] == symb) ||
            (board[2] == symb && board[4] == symb && board[6] == symb);
}

bool Game::isTie()
{
    for (int i=0; i < boardSize; ++i) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return !isWinner('X') && !isWinner('O');
}
