#include "Mail.h"

#include <QMetaType>
#include <QDebug>
#include <QMetaEnum>

Mail::State Mail::state() const
{
    return mState;
}

void Mail::setState(Mail::State state) {
    mState = state;
}

void Mail::setState(int stateValue) {
    const int stateIndex = Mail::staticMetaObject.indexOfEnumerator("State");
    const QMetaEnum metaEnum = Mail::staticMetaObject.enumerator(stateIndex);

    for(int keyIdx = 0; keyIdx < metaEnum.keyCount(); ++keyIdx) {
        if(stateValue == metaEnum.value(keyIdx)) {
            mState = static_cast<Mail::State>(stateValue);
            qDebug() << "State set to" << metaEnum.key(keyIdx);
            return;
        }
    }

    qDebug() << "Could not set state from" << stateValue;
}


int Mail::stateValue() const {
    return static_cast<int>(mState);
}
