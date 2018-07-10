#ifndef SEND_WINDOW_GUI_HPP
#define SEND_WINDOW_GUI_HPP

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>

class send_window : public QWidget
{
        Q_OBJECT

public:
		void disable_inputs();
		void enable_inputs();
public:
        send_window(QWidget* = 0);
		
private:
		QLineEdit* m_from_edt;
        QLineEdit* m_to_edt;
        QTextEdit* m_msg_txt;
        QPushButton* m_send_button;
 
 
private slots:
		void on_send_clicked();

};
#endif
