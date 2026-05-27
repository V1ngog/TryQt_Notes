#include "createnotepage.h"
#include <QVBoxLayout>

CreateNotePage::CreateNotePage(QWidget *parent) : BasePage(parent)
{
    m_editor = new NoteEditorWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_editor);
    setLayout(layout);

    connect(m_editor, &NoteEditorWidget::saveClicked, this, &CreateNotePage::onSave);
    connect(m_editor, &NoteEditorWidget::cancelClicked, this, &CreateNotePage::onCancel);
}

void CreateNotePage::onPageEnter()
{
    m_editor->clear();
}

void CreateNotePage::onPageExit()
{
    m_editor->clear();
}

void CreateNotePage::onSave()
{
    QString note = m_editor->getText();
    if(!note.isEmpty()) {
        NoteManager::addNote(note);
    }
    m_editor->clear();
}

void CreateNotePage::onCancel()
{
    emit noteCreated();
}