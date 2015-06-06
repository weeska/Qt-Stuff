#ifndef MAIL_H
#define MAIL_H

#include <QObject>

class Mail : public QObject
{
    Q_OBJECT
    Q_ENUMS(State)
public:
    enum State{Unread, Read, Archived, MarkedForDeletion};

    State state() const;
    int stateValue() const;

    void setState(State state);
    void setState(int stateValue);

private:
    State mState;
};

#endif // MAIL_H
