#ifndef RESULT_H
#define RESULT_H

#include <QDialog>

#include <QMovie>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();
    void setResult(bool,const QString&);
private:
    Ui::Result *ui;
};

#endif // RESULT_H
