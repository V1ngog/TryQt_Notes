#ifndef EDITNOTEPAGE_H
#define EDITNOTEPAGE_H

#include "basepage.h"
#include "notemanager.h"
#include "noteeditorwidget.h"

class EditNotePage : public BasePage
{
    Q_OBJECT

public:
    explicit EditNotePage(QWidget *parent = nullptr);

    void setNote(int id, const QString &text);

    void onPageEnter() override;
    void onPageExit() override;

signals:
    void noteEdited();

private slots:
    void onSave();
    void onCancel();

private:
    NoteEditorWidget *m_editor;
    int m_noteID = -1;
    QString m_originalText;

};
#endif