#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dataPlayers = new DataPlayers;
    dataPlayers->exec();
    setUp();
}

MainWindow::~MainWindow() {
    delete ui;
    delete player1;
    delete player2;
    for (int i=0; i < game->getBoardSize(); ++i ) {
        delete  btn[i];
    }
    delete btn;
    delete game;
    delete dataPlayers;
    delete res;
}

void MainWindow::on_btnPos0_clicked()
{
    setMove(btn[POS_0],POS_0);
}

void MainWindow::on_btnPos1_clicked()
{
    setMove(btn[POS_1],POS_1);
}

void MainWindow::on_btnPos2_clicked()
{
    setMove(btn[POS_2],POS_2);
}

void MainWindow::on_btnPos3_clicked()
{
    setMove(btn[POS_3],POS_3);
}

void MainWindow::on_btnPos4_clicked()
{
    setMove(btn[POS_4],POS_4);
}

void MainWindow::on_btnPos5_clicked()
{
    setMove(btn[POS_5],POS_5);
}

void MainWindow::on_btnPos6_clicked()
{
    setMove(btn[POS_6],POS_6);
}

void MainWindow::on_btnPos7_clicked()
{
    setMove(btn[POS_7],POS_7);
}

void MainWindow::on_btnPos8_clicked()
{
    setMove(btn[POS_8],POS_8);
}

void MainWindow::on_btnNewGame_clicked()
{
    resetWindow();
}

void MainWindow::setUp()
{
    player1 = new Player(dataPlayers->getNamePlayerOne(),
    dataPlayers->getSymbPlayerOne());

    player2 = new Player(dataPlayers->getNamePlayerTwo(),
    dataPlayers->getSymbPlayerTwo());

    game = new Game(*(player1),*(player2));

    setBtn();

    player1->setEnable(true);

    player2->setEnable(false);

    ui->lblCurrentPlayer->setText("Current Player: " + player1->getName());

    qDebug() << "PLAYER ONE NAME: " << player1->getName()
             << "PLAYER ONE SYMB: " << player1->getSymb() << '\n'
             << "PLAYER TWO NAME: " << player2->getName()
             << "PLAYER TWO SYMB: " << player2->getSymb() << '\n';
}

void MainWindow::setBtn()
{
    btn = new QPushButton*[game->getBoardSize()];

    btn[0] = ui->btnPos0;
    btn[1] = ui->btnPos1;
    btn[2] = ui->btnPos2;
    btn[3] = ui->btnPos3;
    btn[4] = ui->btnPos4;
    btn[5] = ui->btnPos5;
    btn[6] = ui->btnPos6;
    btn[7] = ui->btnPos7;
    btn[8] = ui->btnPos8;
}

void MainWindow::setCurrentPlayer()
{
    if (player1->isEnable()) {
        player1->setEnable(false);
        player2->setEnable(true);
        currentPlayer = player2;
    }
    else {
        player1->setEnable(true);
        player2->setEnable(false);
        currentPlayer = player1;
    }
}

void MainWindow::resetWindow()
{
    game->reset();
    resetBtn();
    setBtnEnable(true);
    setCurrentPlayer();
    ui->lblCurrentPlayer->setText("Current Player: "
    + currentPlayer->getName());
}

void MainWindow::resetBtn()
{
    for (int i=0; i < game->getBoardSize();++i) {
        btn[i]->setText("");
        btn[i]->setChecked(false);
        btn[i]->setStyleSheet(
        "background-color: rgb(82, 173, 151);");
    }
}

void MainWindow::setMove(QPushButton* currentBtn,int pos)
{
    if (game->validPosition(pos)) {
        setCurrentPlayer();

        ui->lblCurrentPlayer->setText(
        "Current Player: " + currentPlayer->getName());

        currentBtn->setStyleSheet(
        "background-color: rgb(247, 210, 80);");

        ui->lblCurrentPlayer->setText(
        "Current Player: " + currentPlayer->getName());

        game->play(currentPlayer,pos);

        currentBtn->setText(currentPlayer->getSymb());

        currentBtn->setChecked(true);

        if (!game->getEnable()) {
            setResult();
        }
    }
}

void MainWindow::setBtnEnable(bool status)
{
    for (int i=0; i < game->getBoardSize(); ++i) {
        btn[i]->setEnabled(status);
    }
}

void MainWindow::changeBtnColor()
{
    if (game->isTie()) {
        for (int i=0; i<game->getBoardSize(); ++i) {
            btn[i]->setStyleSheet(
            "background-color: rgb(105,82,173);");
        }
    }
    else {
         for (int i=0; i<3; ++i) {
             btn[game->getGoodSequence()[i]]->setStyleSheet(
             "background-color: rgb(173,82,104);");
         }
    }
}

void MainWindow::setResult()
{
    changeBtnColor();
    res = new Result(this);
    bool tie = game->isTie();
    QString msg = tie ? "Tie"
                      : "Congratulation, winner is "
                      + game->getWinner()->getName();

    res->setResult(tie,msg);
    res->exec();
    setBtnEnable(false);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    QMessageBox msgBox;

    msgBox.setWindowTitle("Close Game");

    msgBox.setText("Do you want to exit the game?");

    msgBox.setStandardButtons(
    QMessageBox::Yes | QMessageBox::Cancel);

    switch (msgBox.exec()) {
    case QMessageBox::Yes:    e->accept(); break;
    case QMessageBox::Cancel: e->ignore(); break;
    }
}
