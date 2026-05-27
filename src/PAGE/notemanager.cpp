#include "notemanager.h"
#include <QFile>
#include <QCoreApplication>
#include <QStandardPaths>
#include <QDir>

QString NoteManager::getFilePath()
{
    QString dir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/ToDoList";
    QDir().mkpath(dir);
    return dir + "/notes.txt";
}

QStringList NoteManager::loadNotes() 
{
    QStringList notes;
    QFile file(getFilePath());

    if(file.open(QIODevice::ReadOnly)) {
        while(!file.atEnd()) {
            QString line = QString::fromUtf8(file.readLine()).trimmed();
            if (!line.isEmpty()) {
                notes << line;
            }
        }
        file.close();
    }
    return notes;
}

void NoteManager::saveNotes(const QStringList &notes)
{
    QFile file(getFilePath());

    if (file.open(QIODevice::WriteOnly)) {
        for(const QString &note : notes) {
            file.write(note.toUtf8() + "\n");
        }
        file.close();
    }
}


void NoteManager::addNote(const QString &note)
{
    if (note.trimmed().isEmpty()) return;

    QStringList notes = loadNotes();
    notes << note;
    saveNotes(notes);
}

void NoteManager::deleteNote(int index)
{
    QStringList notes = loadNotes();
    if (index >= 0 && index <= notes.size()) {
        notes.removeAt(index);
        saveNotes(notes);
    }
}