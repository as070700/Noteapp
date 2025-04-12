//
// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.
// The original code adapt for Qt6 and C++20.
// NOTE: This file is deprecated and no longer used in the project.

#ifndef OLD_NOTEBOOK_H
#define OLD_NOTEBOOK_H

#include <vector>
#include <string>
#include "old_note.h"

// Die Klasse Notebook verwaltet eine Sammlung von Notizen
class Notebook {
public:
    Notebook(); // Konstruktor: Lädt die Notizen beim Start
    bool addNote(const Note& note); // Fügt eine neue Notiz hinzu
    bool editNote(int index, const Note& note); // Bearbeitet eine bestehende Notiz
    bool deleteNote(int index); // Löscht eine Notiz
    std::vector<Note> getNotes() const; // Gibt alle Notizen zurück

private:
    std::vector<Note> notes; // Sammlung von Notizen
    bool loadNotes(); // Lädt Notizen aus dem Ordner "temp"
    bool saveNoteToFile(const Note& note); // Speichert eine Notiz in einer HTML-Datei
    void ensureTempDirectoryExists(); // Erstellt den Ordner "temp", falls er nicht existiert
    std::string getCurrentTimestamp() const; // Gibt einen Zeitstempel zurück
};

#endif // OLD_NOTEBOOK_H
