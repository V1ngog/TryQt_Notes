#ifndef CREATENOTEPAGE_H
#define CREATENOTEPAGE_H

#include "basepage.h"
#include "notemanager.h"
#include "noteeditorwidget.h"

class CreateNotePage : public BasePage
{
    Q_OBJECT

public:
    explicit CreateNotePage(QWidget *parent = nullptr);

    void onPageEnter() override;
    void onPageExit() override;

signals:
    void noteCreated();

private slots:
    void onSave();
    void onCancel();

private:
    NoteEditorWidget *m_editor;
    
};
#endif