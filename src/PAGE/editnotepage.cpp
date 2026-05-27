#include "editnotepage.h"
#include <QVBoxLayout>

EditNotePage::EditNotePage(QWidget *parent) : BasePage(parent)
{
    m_editor = new NoteEditorWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_editor);
    setLayout(layout);

    connect(m_editor, &NoteEditorWidget::saveClicked, this, &EditNotePage::onSave);
    connect(m_editor, &NoteEditorWidget::cancelClicked, this, &EditNotePage::onCancel);
}

void EditNotePage::setNote(int id, const QString &text)
{
    m_originalText = text;
    m_noteID = id;
}

void EditNotePage::onPageEnter()
{
    m_editor->setText(m_originalText);
}

void EditNotePage::onPageExit() 
{
    m_editor->clear();
}

void EditNotePage::onSave()
{
    QString newText = m_editor->getText();
    if (!newText.isEmpty()) {
        QStringList notes = NoteManager::loadNotes();
        notes[m_noteID] = newText;
        NoteManager::saveNotes(notes);
    }
    emit noteEdited();
}

void EditNotePage::onCancel()
{
    emit noteEdited();
}