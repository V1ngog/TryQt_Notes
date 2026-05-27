#include "showpage.h"
#include "notemanager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

ShowPage::ShowPage(QWidget *parent) : BasePage(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *helpwidgetlayout = new QHBoxLayout();
    QHBoxLayout *helpbuttontlayout = new QHBoxLayout();

    listNotes = new QListWidget(this);
    exitButton  = new QPushButton("Exit", this);

    exitButton->setFixedSize(200, 50);
    listNotes->setFixedSize(500, 550);

    helpwidgetlayout->addWidget(listNotes);
    helpwidgetlayout->addStretch();

    helpbuttontlayout->addStretch();
    helpbuttontlayout->addWidget(exitButton);

    layout->addLayout(helpwidgetlayout);
    layout->addStretch();
    layout->addLayout(helpbuttontlayout);

    setLayout(layout);

    connect(exitButton, &QPushButton::clicked, this, &ShowPage::exitRequested);
}

void ShowPage::onPageEnter() 
{
    notes = NoteManager::loadNotes();

    listNotes->clear();
    listNotes->addItems(notes);
};