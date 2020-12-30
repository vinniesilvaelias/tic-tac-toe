#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <player.h>

#include "dataplayers.h"

#include "result.h"

#include "game.h"

#include <QDebug>

#include <QPushButton>

#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnPos0_clicked();

    void on_btnPos1_clicked();

    void on_btnPos2_clicked();

    void on_btnPos3_clicked();

    void on_btnPos4_clicked();

    void on_btnPos5_clicked();

    void on_btnPos6_clicked();

    void on_btnPos7_clicked();

    void on_btnPos8_clicked();

    void on_btnNewGame_clicked();

private:
    void setUp();
    void setBtn();
    void setCurrentPlayer();
    void resetWindow();
    void resetBtn();
    void setMove(QPushButton *, int);
    void setBtnEnable(bool);
    void changeBtnColor();
    void setResult();
    void closeEvent(QCloseEvent *event);
    enum positions { POS_0,POS_1,POS_2,POS_3,POS_4,POS_5,POS_6,POS_7,POS_8 };
    Ui::MainWindow *ui;
    QPushButton **btn;
    DataPlayers *dataPlayers;
    Player *currentPlayer;
    Game   *game;
    Player *player1;
    Player *player2;
    Result *res;
};
#endif // MAINWINDOW_H
