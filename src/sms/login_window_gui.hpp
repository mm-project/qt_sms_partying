#ifndef LOGIN_WINDOW_GUI_HPP
#define LOGIN_WINDOW_GUI_HPP

#include "controller.hpp"

#include <QString>
#include <QPushButton>
#include <QWidget>


class QLineEdit;

class login_window : public QWidget
{
        Q_OBJECT
		
private:
	enum state { ENABLED = 0, DISABLED };

public:
        login_window(QWidget* = 0);
		bool pre_validate();
		void post_validate(bool,const QString&);

signals:
        void accept_user();
        void change_status_bar(const QString&,bool);
		
private slots:
		void login_button_clicked();
		void user_field_clicked();
		void on_login_ok();
		void start_process();
		void end_process();
		void on_login_err(const QString&);
		//void post_validate(bool res, const QString& err_msg); 

private:
	void set_state(state);

private:
        QLineEdit* m_username;
        QLineEdit* m_password;
		QPushButton* m_login_button;
		Controller* m_controller;
};

#endif
