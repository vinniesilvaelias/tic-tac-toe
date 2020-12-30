#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
}

Result::~Result()
{
    delete ui;
}

void Result::setResult(bool tie, const QString & result)
{
    QString qstr = tie ? "tie" : "win";
    QMovie* movie = new QMovie("../tic-tac-toe/resources/"+
                               qstr + QString::number(rand() % 2) +
                               ".gif");

    ui->lblGif->setMovie(movie);
    movie->start();
    ui->lblResult->setText(result);
}
