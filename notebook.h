#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <vector>
#include <string>
#include "note.h"

class Notebook {
public:
    Notebook();
    bool addNote(const Note& note);
    bool editNote(int index, const Note& note);
    bool deleteNote(int index);
    std::vector<Note> getNotes() const;

private:
    std::vector<Note> notes;
    bool loadNotes();
    bool saveNoteToFile(const Note& note);
    std::string getCurrentTimestamp() const;
};

#endif // NOTEBOOK_H
