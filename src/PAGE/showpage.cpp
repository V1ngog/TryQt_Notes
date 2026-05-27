#include "showpage.h"
#include "notemanager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

ShowPage::ShowPage(QWidget *parent) : BasePage(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *helpwidgetlayout = new QVBoxLayout();
    QVBoxLayout *helpbuttontlayout = new QVBoxLayout();

    listNotes = new QListWidget(this);
    exitButton  = new QPushButton("Exit", this);
    deleteButton = new QPushButton("Delete", this);

    deleteButton->setFixedSize(200, 50);    
    exitButton->setFixedSize(200, 50);
    listNotes->setFixedSize(500, 550);

    helpwidgetlayout->addWidget(listNotes);
    helpwidgetlayout->addStretch();

    helpbuttontlayout->addStretch();
    helpbuttontlayout->addWidget(deleteButton);
    helpbuttontlayout->addWidget(exitButton);

    layout->addLayout(helpwidgetlayout);
    layout->addStretch();
    layout->addLayout(helpbuttontlayout);

    setLayout(layout);

    connect(exitButton, &QPushButton::clicked, this, &ShowPage::exitRequested);
    connect(deleteButton, &QPushButton::clicked, this, &ShowPage::onDeleteClicked);
    connect(listNotes, &QListWidget::itemDoubleClicked, this, [this](QListWidgetItem *item) {
        int row = listNotes->row(item);
        if (row >= 0 && row < notes.size()) {
            emit editRequested(row, notes[row]);
        }
    });
}

void ShowPage::onPageEnter() 
{
    notes = NoteManager::loadNotes();
    listNotes->clear();

    for (int i = 0; i < notes.size(); ++i) {
        QString numberedNote = QString("%1. %2").arg(i + 1).arg(notes[i]);
        listNotes->addItem(numberedNote);
    }
}

void ShowPage::onDeleteClicked() {
    int row = listNotes->currentRow();
    if (row >= 0) {
        NoteManager::deleteNote(row);
        onPageEnter(); 
    }
}