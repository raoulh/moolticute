#ifndef NOTESMANAGEMENT_H
#define NOTESMANAGEMENT_H

#include <QWidget>
#include "WSClient.h"

namespace Ui {
class NotesManagement;
}

class NotesManagement : public QWidget
{
    Q_OBJECT

public:
    explicit NotesManagement(QWidget *parent = nullptr);
    ~NotesManagement();

    void setWsClient(WSClient *c);

private slots:
    void on_pushButtonSaveNote_clicked();

private:
    Ui::NotesManagement *ui;

    WSClient *wsClient;
};

#endif // NOTESMANAGEMENT_H