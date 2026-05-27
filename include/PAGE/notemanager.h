#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QStringList>
#include <QString>

class NoteManager
{
public:
    static QStringList loadNotes();
    static void saveNotes(const QStringList &notes);
    static void addNote(const QString &note);
    static void deleteNote(int index);
    static QString getFilePath();
};

#endif