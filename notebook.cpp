#include "notebook.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <chrono>

namespace fs = std::filesystem;
namespace ch = std::chrono;

Notebook::Notebook() {
    loadNotes();
}

bool Notebook::addNote(const Note& note) {
    notes.push_back(note);
    return saveNoteToFile(note);
}

bool Notebook::editNote(int index, const Note& note) {
    if (index < 0 || static_cast<std::vector<Note>::size_type>(index) >= notes.size()) {
        return false;
    }
    notes[index] = note;
    return saveNoteToFile(note);
}

bool Notebook::deleteNote(int index) {
    if (index < 0 || static_cast<std::vector<Note>::size_type>(index) >= notes.size()) {
        return false;
    }
    Note& note = notes[index];
    if (fs::exists(note.filename)) {
        fs::remove(note.filename);
    }
    notes.erase(notes.begin() + index);
    return true;
}

std::vector<Note> Notebook::getNotes() const {
    return notes;
}

bool Notebook::loadNotes() {
    bool success = true;
    std::string path = "./temp/";
    if (!fs::exists(path)) {
        fs::create_directory(path);
    }
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();
            if (filename.find("note_") == 0 && filename.find(".txt") != std::string::npos) {
                std::ifstream infile(entry.path());
                if (!infile.is_open()) {
                    success = false;
                    continue;
                }

                Note note;
                std::getline(infile, note.title);
                std::getline(infile, note.content);
                note.filename = entry.path().string();
                notes.push_back(note);
                infile.close();
            }
        }
    }
    return success;
}

bool Notebook::saveNoteToFile(const Note& note) {
    std::string path = "./temp/";
    if (!fs::exists(path)) {
        fs::create_directory(path);
    }
    std::string filename = path + "note_" + getCurrentTimestamp() + ".txt";
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        return false;
    }
    outfile << note.title << "\n" << note.content << "\n";
    outfile.close();
    return true;
}

std::string Notebook::getCurrentTimestamp() const {
    auto now = ch::system_clock::now();
    auto in_time_t = ch::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y%m%d%H%M%S");
    return ss.str();
}
