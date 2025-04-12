// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <vector>
#include <string>
#include "note.h"

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
    bool loadNotes_deletenote(); // Lädt Notizen aus einer Datei (derzeit deaktiviert)
    bool saveNoteToFile(const Note& note); // Speichert eine Notiz in einer Datei (derzeit deaktiviert)
    std::string getCurrentTimestamp() const; // Gibt einen Zeitstempel zurück
};

#endif // NOTEBOOK_H
