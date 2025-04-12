//
// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#ifndef OLD_NOTE_H
#define OLD_NOTE_H

#include <string>

// Struktur, die eine Notiz repräsentiert
// Enthält den Titel, den Inhalt und den Dateinamen der Notiz
struct Note {
    std::string title;    // Titel der Notiz
    std::string content;  // Inhalt der Notiz
    std::string filename; // Dateiname, unter dem die Notiz gespeichert wird
};

#endif // OLD_NOTE_H
