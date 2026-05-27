#ifndef NOTEEDITORWIDGET_H
#define NOTEEDITORWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

class NoteEditorWidget : public QWidget 
{
    Q_OBJECT

public:
    explicit NoteEditorWidget(QWidget *parent);

    QString getText() const;
    void setText(const QString &text);
    void clear();

signals:
    void saveClicked();
    void cancelClicked();

private slots:
    void onSave();
    void onCancel();

private:
    QTextEdit *m_textEdit;
    QPushButton *m_saveButton;
    QPushButton *m_cancelButton;

    void setupUI();
};
#endif