#include "dataplayers.h"
#include "ui_dataplayers.h"

DataPlayers::DataPlayers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataPlayers)
{
    ui->setupUi(this);
}

DataPlayers::~DataPlayers()
{
    delete ui;
}
void DataPlayers::on_rbXPlayerOne_clicked()
{
    ui->rbOPlayerTwo->setChecked(true);
    ui->rbXPlayerTwo->setChecked(false);
    ui->rbOPlayerOne->setChecked(false);
    symbPlayerOne = 'X';
    symbPlayerTwo = 'O';
}

void DataPlayers::on_rbOPlayerOne_clicked()
{
    ui->rbXPlayerTwo->setChecked(true);
    ui->rbOPlayerTwo->setChecked(false);
    ui->rbXPlayerOne->setChecked(false);
    symbPlayerOne = 'O';
    symbPlayerTwo = 'X';
}

void DataPlayers::on_rbXPlayerTwo_clicked()
{
    ui->rbOPlayerOne->setChecked(true);
    ui->rbXPlayerOne->setChecked(false);
    ui->rbOPlayerTwo->setChecked(false);
    symbPlayerOne = 'O';
    symbPlayerTwo = 'X';
}

void DataPlayers::on_rbOPlayerTwo_clicked()
{
    ui->rbXPlayerOne->setChecked(true);
    ui->rbOPlayerOne->setChecked(false);
    ui->rbXPlayerTwo->setChecked(false);
    symbPlayerOne = 'X';
    symbPlayerTwo = 'O';
}


void DataPlayers::on_pushButton_clicked()
{
    namePlayerOne = ui->lePlayerOneName->text().isEmpty() ? "Player One"
                                                          : ui->lePlayerOneName->text();

    namePlayerTwo = ui->lePlayerTwoName->text().isEmpty() ? "Player Two"
                                                          : ui->lePlayerTwoName->text();
    if (!ui->rbOPlayerOne->isChecked() && !ui->rbXPlayerOne->isChecked() &&
        !ui->rbOPlayerTwo->isChecked() && !ui->rbOPlayerTwo->isChecked()) {
        symbPlayerOne = 'X';
        symbPlayerTwo = 'O';
    }
    this->close();
}

