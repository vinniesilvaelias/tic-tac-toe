#ifndef PLAYER_H
#define PLAYER_H

#include <QChar>

#include <QMessageBox>

class Player
{
public:
    Player() { };

    Player(const QString&,const QChar&);

    QChar getSymb() const;

    void setSymb(QChar value);

    bool isEnable() const;

    void setEnable(bool value);

    QString getName() const;

    void setName(const QString &value);

private:
    QString name;
    QChar symb;
    bool enable;
};

inline Player::Player(const QString &n, const QChar &s)
{
    setName(n);
    setSymb(s);
}

inline QChar Player::getSymb() const
{
    return symb;
}

inline void Player::setSymb(QChar value)
{
    value.toUpper();
    if (value != 'X' && value != 'O') {
        throw QString("Invalid symbol");
    }
    symb = value;
}

inline bool Player::isEnable() const
{
    return enable;
}

inline void Player::setEnable(bool value)
{
    enable = value != enable ? value: enable;
}
inline QString Player::getName() const
{
    return name;
}

inline void Player::setName(const QString &value)
{
    name = value;
}

#endif // PLAYER_H
