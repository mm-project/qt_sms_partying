#ifndef SEND_WINDOW_GUI_HPP
#define SEND_WINDOW_GUI_HPP

#include <QWidget>
#include "simple_get_handler.hpp"

class QPushButton;
class QComboBox;
class QLineEdit;
class QTextEdit;

class send_window : public QWidget
{
        Q_OBJECT

public:
        send_window(QWidget* = 0);

public:
		void disable_inputs();
		void enable_inputs();

private:
		void update_to_combo();

 
signals: 
		void change_status_bar(const QString&,bool, bool = false);

private slots:
		void on_send_clicked();
		void on_send_ok();
		void on_send_err();

		void update_to_line_edit_completer(const QString&);
		
private:
		RequestHandler* m_sms_handler;

private:
		QLineEdit* m_from_edt;
		QComboBox* m_countries;
        QLineEdit* m_to_edit;
        QTextEdit* m_msg_txt;
        QPushButton* m_send_button;
		
};
#endif
