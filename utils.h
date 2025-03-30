#ifndef UTILS_H
#define UTILS_H

#include <QString>

// Funktion: Hashing eines Passworts
// Diese Funktion nimmt ein Passwort als QString und gibt dessen SHA-256-Hash als QString zurück.
QString hashPassword(const QString &password);

#endif // UTILS_H
