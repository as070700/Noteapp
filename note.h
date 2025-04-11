// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#ifndef NOTE_H
#define NOTE_H

#include <string>

// Struktur, die eine Notiz repräsentiert
// Enthält den Titel und den Inhalt der Notiz
struct Note {
    std::string title;   // Titel der Notiz
    std::string content; // Inhalt der Notiz
};

#endif // NOTE_H
