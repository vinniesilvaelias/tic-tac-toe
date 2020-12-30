#ifndef DATAPLAYERS_H
#define DATAPLAYERS_H

#include <QDialog>

namespace Ui {
class DataPlayers;
}

class DataPlayers : public QDialog
{
    Q_OBJECT

public:
    explicit DataPlayers(QWidget *parent = nullptr);
    ~DataPlayers();

    QString getNamePlayerOne() const { return namePlayerOne; }

    QString getNamePlayerTwo() const { return namePlayerTwo; }

    QChar getSymbPlayerOne()   const { return symbPlayerOne; }

    QChar getSymbPlayerTwo()   const { return symbPlayerTwo; }

private slots:
    void on_rbXPlayerOne_clicked();

    void on_rbOPlayerOne_clicked();

    void on_rbXPlayerTwo_clicked();

    void on_rbOPlayerTwo_clicked();

    void on_pushButton_clicked();

private:
    Ui::DataPlayers *ui;
    QString namePlayerOne;
    QString namePlayerTwo;
    QChar symbPlayerOne;
    QChar symbPlayerTwo;
};

#endif // DATAPLAYERS_H
