#include "noteeditorwidget.h"
#include "notemanager.h"
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

NoteEditorWidget::NoteEditorWidget(QWidget *parent) : QWidget(parent)
{
    setupUI();

    connect(m_saveButton, &QPushButton::clicked, this, &NoteEditorWidget::onSave);
    connect(m_cancelButton, &QPushButton::clicked, this, &NoteEditorWidget::onCancel);
}

void NoteEditorWidget::setupUI()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    m_textEdit = new QTextEdit(this);
    m_textEdit->setPlaceholderText("Write your note: ");

    m_saveButton = new QPushButton("Save", this);
    m_cancelButton = new QPushButton("Exit", this);

    m_saveButton->setFixedSize(200, 50);
    m_cancelButton->setFixedSize(200, 50);
    
    QHBoxLayout *helpLayout = new QHBoxLayout();
    helpLayout->addWidget(m_cancelButton);
    helpLayout->addStretch();
    helpLayout->addWidget(m_saveButton);

    layout->addStretch();
    layout->addWidget(m_textEdit);
    layout->addStretch();
    layout->addLayout(helpLayout);

    setLayout(layout);
}

void NoteEditorWidget::clear()
{
    m_textEdit->clear();
}

QString NoteEditorWidget::getText() const
{
    return m_textEdit->toPlainText().trimmed();
}

void NoteEditorWidget::setText(const QString &text)
{
    m_textEdit->clear();
    m_textEdit->setText(text);
}

void NoteEditorWidget::onSave()
{
    emit saveClicked();
}

void NoteEditorWidget::onCancel()
{
    emit cancelClicked();
}