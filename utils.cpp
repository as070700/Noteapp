#include "utils.h"
#include <QCryptographicHash>

// Funktion: Hashing eines Passworts
// Verwendet den SHA-256-Algorithmus, um ein Passwort zu hashen.
// Gibt den Hash als Hexadezimal-String zurück.
QString hashPassword(const QString &password) {
    // Konvertiert das Passwort in UTF-8 und hasht es mit SHA-256
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}
