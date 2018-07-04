#ifndef LOGIN_WINDOW_GUI_HPP
#define LOGIN_WINDOW_GUI_HPP

#include <QWidget>

class QLineEdit;

class login_window : public QWidget
{
        Q_OBJECT

public:
        login_window(QWidget* = 0);

signals:
        void accept_user();
        void change_status_bar(const QString&);

private slots:
        void validate();

private:
        QLineEdit* m_username;
        QLineEdit* m_password;
};

#endif
