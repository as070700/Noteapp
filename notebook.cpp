#include "notebook.h"
#include <fstream>
#include <sstream>
#include <ctime>

// Konstruktor: Lädt die Notizen beim Start
Notebook::Notebook() {
    loadNotes(); // Derzeit deaktiviert, da keine Datei verwendet wird
}

// Fügt eine neue Notiz hinzu
bool Notebook::addNote(const Note& note) {
    notes.push_back(note); // Fügt die Notiz zur Sammlung hinzu
    // return saveNoteToFile(note); // Auskommentiert: Speichern in einer Datei
    return true; // Speichern nur im Speicher
}

// Bearbeitet eine bestehende Notiz
bool Notebook::editNote(int index, const Note& note) {
    if (index < 0 || index >= notes.size()) { // Überprüft, ob der Index gültig ist
        return false;
    }
    notes[index] = note; // Aktualisiert die Notiz
    // return saveNoteToFile(note); // Auskommentiert: Speichern in einer Datei
    return true; // Speichern nur im Speicher
}

// Löscht eine Notiz
bool Notebook::deleteNote(int index) {
    if (index < 0 || index >= notes.size()) { // Überprüft, ob der Index gültig ist
        return false;
    }
    notes.erase(notes.begin() + index); // Löscht die Notiz aus der Sammlung
    // Optional: Hier könnte die entsprechende Datei gelöscht werden
    return true;
}

// Gibt alle Notizen zurück
std::vector<Note> Notebook::getNotes() const {
    return notes; // Gibt die Sammlung von Notizen zurück
}

// Lädt Notizen aus einer Datei (derzeit deaktiviert)
bool Notebook::loadNotes() {
    // std::ifstream file("./sys/notes.txt"); // Datei mit gespeicherten Notizen
    // if (!file.is_open()) {
    //     return false; // Fehler beim Öffnen der Datei
    // }

    // std::string line;
    // while (std::getline(file, line)) {
    //     std::istringstream iss(line);
    //     Note note;
    //     if (std::getline(iss, note.title, '|') && std::getline(iss, note.content)) {
    //         notes.push_back(note); // Fügt die Notiz zur Sammlung hinzu
    //     }
    // }
    // file.close();
    return true; // Keine Notizen aus einer Datei laden
}

// Speichert eine Notiz in einer Datei (derzeit deaktiviert)
bool Notebook::saveNoteToFile(const Note& note) {
    // std::ofstream file("./sys/notes.txt", std::ios::app); // Datei im Anhangsmodus öffnen
    // if (!file.is_open()) {
    //     return false; // Fehler beim Öffnen der Datei
    // }
    // file << note.title << "|" << note.content << "\n"; // Speichert die Notiz im Format "Titel|Inhalt"
    // file.close();
    return true; // Kein Speichern in einer Datei
}

// Gibt einen Zeitstempel im Format "YYYY-MM-DD HH:MM:SS" zurück
std::string Notebook::getCurrentTimestamp() const {
    std::time_t now = std::time(nullptr); // Aktuelle Zeit abrufen
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now)); // Zeit formatieren
    return buf; // Zeitstempel zurückgeben
}
