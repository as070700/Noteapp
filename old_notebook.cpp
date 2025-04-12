//
// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.
// The original code adapt for Qt6 and C++20.
// NOTE: This file is deprecated and no longer used in the project.

#include "old_notebook.h"
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs = std::filesystem; // Alias für std::filesystem
namespace ch = std::chrono;     // Alias für std::chrono

// Konstruktor: Lädt die Notizen beim Start
Notebook::Notebook() {
    ensureTempDirectoryExists(); // Sicherstellen, dass der Ordner existiert
    loadNotes(); // Notizen aus dem Ordner "temp" laden
}

// Fügt eine neue Notiz hinzu
bool Notebook::addNote(const Note& note) {
    notes.push_back(note); // Fügt die Notiz zur Sammlung hinzu
    return saveNoteToFile(note); // Speichert die Notiz in einer Datei
}

// Bearbeitet eine bestehende Notiz
bool Notebook::editNote(int index, const Note& note) {
    if (index < 0 || index >= notes.size()) { // Überprüft, ob der Index gültig ist
        return false;
    }
    notes[index] = note; // Aktualisiert die Notiz
    return saveNoteToFile(note); // Speichert die aktualisierte Notiz in einer Datei
}

// Löscht eine Notiz
bool Notebook::deleteNote(int index) {
    if (index < 0 || index >= notes.size()) { // Überprüft, ob der Index gültig ist
        return false;
    }
    Note& note = notes[index];
    if (fs::exists(note.filename)) { // Prüfen, ob die Datei existiert
        fs::remove(note.filename); // Datei löschen
    }
    notes.erase(notes.begin() + index); // Löscht die Notiz aus der Sammlung
    return true;
}

// Gibt alle Notizen zurück
std::vector<Note> Notebook::getNotes() const {
    return notes; // Gibt die Sammlung von Notizen zurück
}

// Lädt Notizen aus dem Ordner "temp"
bool Notebook::loadNotes() {
    ensureTempDirectoryExists(); // Sicherstellen, dass der Ordner existiert
    for (const auto& entry : fs::directory_iterator("temp/")) {
        if (entry.is_regular_file()) {
            std::ifstream infile(entry.path());
            if (!infile.is_open()) {
                std::cerr << "Fehler beim Öffnen der Datei: " << entry.path() << std::endl;
                continue;
            }

            Note note;
            note.filename = entry.path().string(); // Vollständigen Pfad speichern

            // HTML-Inhalt lesen und Titel/Inhalt extrahieren
            std::string line;
            while (std::getline(infile, line)) {
                if (line.find("<h1>") != std::string::npos) { // Titel extrahieren
                    size_t start = line.find("<h1>") + 4;
                    size_t end = line.find("</h1>");
                    note.title = line.substr(start, end - start);
                } else if (line.find("<p>") != std::string::npos) { // Inhalt extrahieren
                    size_t start = line.find("<p>") + 3;
                    size_t end = line.find("</p>");
                    note.content = line.substr(start, end - start);
                }
            }
            notes.push_back(note); // Notiz zur Sammlung hinzufügen
            infile.close();
        }
    }
    return true;
}

// Speichert eine Notiz in einer HTML-Datei
bool Notebook::saveNoteToFile(const Note& note) {
    ensureTempDirectoryExists(); // Sicherstellen, dass der Ordner existiert
    std::ofstream outfile(note.filename);
    if (!outfile.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei: " << note.filename << std::endl;
        return false;
    }

    // HTML-Inhalt schreiben
    outfile << "<!DOCTYPE html>\n";
    outfile << "<html lang=\"de\">\n";
    outfile << "<head>\n";
    outfile << "    <meta charset=\"UTF-8\">\n";
    outfile << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    outfile << "    <title>" << note.title << "</title>\n";
    outfile << "</head>\n";
    outfile << "<body>\n";
    outfile << "    <h1>" << note.title << "</h1>\n";
    outfile << "    <p>" << note.content << "</p>\n";
    outfile << "</body>\n";
    outfile << "</html>\n";

    outfile.close();
    return true;
}

// Erstellt den Ordner "temp", falls er nicht existiert
void Notebook::ensureTempDirectoryExists() {
    std::string path = "temp/";
    if (!fs::exists(path)) {
        fs::create_directory(path);
    }
}

// Gibt einen Zeitstempel im Format "YYYY-MM-DD HH:MM:SS" zurück
std::string Notebook::getCurrentTimestamp() const {
    std::time_t now = std::time(nullptr); // Aktuelle Zeit abrufen
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now)); // Zeit formatieren
    return buf; // Zeitstempel zurückgeben
}
