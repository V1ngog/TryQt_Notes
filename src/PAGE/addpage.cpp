#include "addpage.h"
#include "notemanager.h"
#include "QHBoxLayout"
#include "QVBoxLayout"

AddPage::AddPage(QWidget *parent) : BasePage(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    contentEdit = new QTextEdit(this);
    contentEdit->setPlaceholderText("Write your note: ");

    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Exit", this);

    saveButton->setFixedSize(200, 50);
    cancelButton->setFixedSize(200, 50);
    
    QHBoxLayout *helpLayout = new QHBoxLayout();
    helpLayout->addWidget(cancelButton);
    helpLayout->addStretch();
    helpLayout->addWidget(saveButton);

    layout->addStretch();
    layout->addWidget(contentEdit);
    layout->addStretch();
    layout->addLayout(helpLayout);

    setLayout(layout);

    connect(saveButton, &QPushButton::clicked, this, &AddPage::onSaveClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddPage::onCancelClicked);
}

void AddPage::onSaveClicked()
{
    QString note = contentEdit->toPlainText().trimmed();

    if(note.isEmpty()) return;

    NoteManager::addNote(note);
    contentEdit->clear();
}

void AddPage::onCancelClicked()
{
    emit noteAdded();
}

void AddPage::onPageExit()
{
    contentEdit->clear();
}