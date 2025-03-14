#include "notebook.h"
#include <fstream>
#include <sstream>
#include <ctime>

Notebook::Notebook() {
    loadNotes();
}

bool Notebook::addNote(const Note& note) {
    notes.push_back(note);
    return saveNoteToFile(note);
}

bool Notebook::editNote(int index, const Note& note) {
    if (index < 0 || index >= notes.size()) {
        return false;
    }
    notes[index] = note;
    return saveNoteToFile(note);
}

bool Notebook::deleteNote(int index) {
    if (index < 0 || index >= notes.size()) {
        return false;
    }
    notes.erase(notes.begin() + index);
    // Optional: You might want to delete the corresponding file here.
    return true;
}

std::vector<Note> Notebook::getNotes() const {
    return notes;
}

bool Notebook::loadNotes() {
    std::ifstream file("./sys/notes.txt");
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Note note;
        if (std::getline(iss, note.title, '|') && std::getline(iss, note.content)) {
            notes.push_back(note);
        }
    }
    file.close();
    return true;
}

bool Notebook::saveNoteToFile(const Note& note) {
    std::ofstream file("./sys/notes.txt", std::ios::app);
    if (!file.is_open()) {
        return false;
    }
    file << note.title << "|" << note.content << "\n";
    file.close();
    return true;
}

std::string Notebook::getCurrentTimestamp() const {
    std::time_t now = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return buf;
}
