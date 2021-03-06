#ifndef PROMPTWIDGET_H
#define PROMPTWIDGET_H

#include <QFrame>
#include <functional>

class QLabel;
class QDialogButtonBox;

//!
//! \brief The PromptMessage class
//!
//! Class for handling message that will be visible in PromptWidget and
//! callback function that will be called after widget is accepted

class PromptMessage
{
public:
    PromptMessage(const QString &text,
                  const std::function<void()> &acceptCallBack = nullptr,
                  const std::function<void()> &rejectCallBack = nullptr) :
        m_text(text),
        m_acceptCallBack(acceptCallBack),
        m_rejectCallBack(rejectCallBack)
    {}

    QString getText() const { return m_text; }
    bool containsButtonCb() const { return nullptr != m_acceptCallBack; }
    void runAcceptCallBack() { if (m_acceptCallBack) m_acceptCallBack(); }
    void runRejectCallBack() { if (m_rejectCallBack) m_rejectCallBack(); }

private:
    QString m_text;
    std::function<void()> m_acceptCallBack;
    std::function<void()> m_rejectCallBack;
};

//!
//! \brief The PromptWidget class
//!
//! Widget for displaying messages and questions to the user.

class PromptWidget : public QFrame
{
    Q_OBJECT
public:
    explicit PromptWidget(QWidget *parent = nullptr);
    ~PromptWidget();

    void setHideAfterAccepted(bool hide) { m_hideAfterAccepted = hide; }
    void setText(const QString &text);
    void setPromptMessage(PromptMessage *promptMessage);
    void cleanPromptMessage();
    bool isMMMErrorPrompt() const;
    bool isBackupPrompt() const;

    static QString MMM_ERROR;
    static QString BACKUP_PROMPT;
    static QString MORE_RECENT_BACKUP_PROMPT;

signals:
    void accepted();
    void rejected();

protected slots:
    void onAccepted();
    void onRejected();

private:
    void initButtons();


    bool m_hideAfterAccepted;
    QLabel *m_messageLabel;
    QDialogButtonBox *m_buttonBox;
    PromptMessage *m_promptMessage;
};

#endif // PROMPTWIDGET_H
