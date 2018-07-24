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
		void disable_inputs();
		void enable_inputs();
public:
        send_window(QWidget* = 0);

private:
		void update_to_combo();
private:
		QLineEdit* m_from_edt;
        QComboBox* m_to_combo;
        QTextEdit* m_msg_txt;
        QPushButton* m_send_button;
 
private slots:
		void on_send_clicked();
		void on_send_ok();
		void on_send_err();
		
private:
		RequestHandler* m_sms_handler;
		
};
#endif
