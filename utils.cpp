#include "utils.h"
#include <QCryptographicHash>

QString hashPassword(const QString &password) {
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}
