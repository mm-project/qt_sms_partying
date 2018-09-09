#ifndef SEND_WINDOW_GUI_HPP
#define SEND_WINDOW_GUI_HPP

#include <QWidget>

#include <map>

#include "simple_get_handler.hpp"

class QPushButton;
class QComboBox;
class QLineEdit;
class QTextEdit;
class countries_custom_widget;

class send_window : public QWidget
{
        Q_OBJECT

public:
        send_window(QWidget* = 0);

public:
		void disable_inputs();
		void enable_inputs();

signals: 
		void change_status_bar(const QString&,bool, bool = false);

private slots:
		void on_send_clicked();
		void on_send_ok();
		void on_send_err();
		//void on_country_combo_changed(const QString &text);
		void update_to_line_edit_completer(const QString &text);
		
		//void QComboBox::currentTextChanged(const QString &text
		//void update_to_line_edit_completer(const QStringList& wordlist);
		
		
private:
		RequestHandler* m_sms_handler;

private:
		QLineEdit* m_from_edt;
		countries_custom_widget* m_countries_widget;
        QTextEdit* m_msg_txt;
        QPushButton* m_send_button;	
		
};

/// @class coutries_custom_widget for Levon janik))
class countries_custom_widget : public QWidget
{
	Q_OBJECT

public:
	countries_custom_widget(QWidget* p = 0);

private slots:
	void update_country_combo_icon(int);

private:
	void fill_countries();

private:
	QComboBox* m_countries;
	QLineEdit* m_code;
	QLineEdit* m_number;

	std::map<QString, QStringList> m_operators;

	int m_selected_index;
};
#endif
