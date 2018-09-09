#include "send_window_gui.hpp"
#include "controller.hpp"

#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QCompleter>

send_window::send_window(QWidget* parent)
        : QWidget(parent)
{
	m_from_edt = new QLineEdit(this);
	m_from_edt->setFixedHeight(26);
	m_msg_txt = new QTextEdit(this);
	m_countries_widget = new countries_custom_widget(this);
	m_send_button = new QPushButton("Send", this);
	m_send_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	m_send_button->setEnabled(false);

	m_from_edt->setMaxLength(10);
	m_from_edt->setPlaceholderText("QtSMS");

	QLabel* from_l = new QLabel("From:", this);
	QLabel* to_l = new QLabel("To:", this);
	QLabel* message_l = new QLabel("Message:", this);
	QGridLayout* grid = new QGridLayout;
	
	grid->addWidget(from_l, 0, 0, Qt::AlignRight);
	grid->addWidget(m_from_edt, 0, 1);
	grid->addWidget(to_l, 1, 0, Qt::AlignRight);
	grid->addWidget(m_countries_widget, 1, 1);
	grid->addWidget(message_l, 2, 0);
	grid->addWidget(m_msg_txt, 3, 0, 1, 2);
	grid->addWidget(m_send_button, 4, 1, Qt::AlignRight);

	QVBoxLayout* v_l = new QVBoxLayout;
	v_l->addLayout(grid);
	setLayout(v_l);		

	m_sms_handler = new SimpleGetHandler("sms/json", false);
		
	m_send_button->setEnabled(false);		
	connect(m_sms_handler, SIGNAL(sig_pass()), this, SLOT(on_send_ok()));
	connect(m_sms_handler, SIGNAL(sig_error()), this, SLOT(on_send_err()));
	connect(m_send_button,SIGNAL(clicked()),this,SLOT(on_send_clicked()));
	//connect(m_countries, SIGNAL(currentTextChanged(const QString&)), this, SLOT(update_to_line_edit_completer(const QString&)));
	//m_countries
}



void send_window::disable_inputs() {
	m_from_edt->setEnabled(false);
	//m_countries->setEnabled(false);
	//m_to_edit->setEnabled(false);
	m_msg_txt->setEnabled(false);
	m_send_button->setEnabled(false);
}

void send_window::enable_inputs() {
	m_from_edt->setEnabled(true);
	//m_countries->setEnabled(true);
	//m_to_edit->setEnabled(true);
	m_msg_txt->setEnabled(true);
	m_send_button->setEnabled(true);
}

void send_window::on_send_clicked() {

	//check validity m_from_edt
	//check validity m_to_edt
	//check size message_l
	
	//Controller->get_instance()->get_engine()->create_variant_for_sms(m_from_edt->text(),m_to_combo->currentText(),m_msg_txt->toPlainText());
	disable_inputs();
	emit change_status_bar("Sending... ",true,true);	
	//m_sms_handler->execute2(Controller::get_instance()->get_engine()->create_qvariant_for_sms(m_from_edt->text(),m_countries->currentText()+m_to_edit->text(),m_msg_txt->toPlainText()));	
}

void send_window::on_send_ok() {
	enable_inputs();	
	emit change_status_bar("Message send.",true);	
}

void send_window::on_send_err() {
	enable_inputs();
	emit change_status_bar("Send Error: "+m_sms_handler->get_error_message(),false);	
}

//void send_window::update_to_line_edit_completer(const QStringList& wordlist)
void send_window::update_to_line_edit_completer(const QString &str)
{
	std::cout << str.toStdString() << std::endl;
	// validate if s is from coutries combo list
	//QStringList wordlist = m_operators[str];
	// get wordlist from s , maybe map
	//QCompleter* completer = new QCompleter(wordlist, this);
	//completer->setCompletionMode(QCompleter::PopupCompletion);
	//m_to_edit->setCompleter(completer);
}

/// @class coutries_custom_widget
countries_custom_widget::countries_custom_widget(QWidget* p)
	: QWidget(p)
{
	m_countries = new QComboBox(this);
	m_code = new QLineEdit(this);
	m_number = new QLineEdit(this);
	QHBoxLayout* layout = new QHBoxLayout;
	layout->setSpacing(0);
	layout->addWidget(m_countries, 2);
	layout->addWidget(m_code, 1);
	layout->addWidget(m_number, 3);
	setLayout(layout);
	layout->setMargin(0);

	fill_countries();

	m_countries->setFixedHeight(26);
	m_code->setFixedHeight(26);
	m_number->setFixedHeight(26);
	m_countries->setStyleSheet("border-right: none"); //don't work :(
	m_code->setStyleSheet("border-left: none");

	m_code->setPlaceholderText("+CODE");
	m_number->setPlaceholderText("PHONE NUMBER");
	m_number->setValidator(new QRegExpValidator(QRegExp("[0-9]+"), this));
	m_code->setValidator(new QRegExpValidator(QRegExp("[0-9]+"), this));
	m_code->setMaxLength(6); //?
	m_number->setMaxLength(20);
	m_countries->setCurrentText("");

	connect(m_countries, SIGNAL(currentIndexChanged(int)), this, SLOT(update_country_combo_icon(int)));
}

void countries_custom_widget::fill_countries()
{
	m_countries->setEditable(true);
	//only after setEditable(true)
	m_countries->completer()->setCompletionMode(QCompleter::PopupCompletion);
	//m_countries->setValidator(new QRegExpValidator(QRegExp("[?+(1)][0-9]+"), this));

	//add from my file countries list.
	//TODO add engines
	foreach(GenericCountry* c, Controller::get_instance()->get_engine()->get_country_infos())
	{
		m_countries->addItem(c->get_country_name());
		//m_countries->setItemData(i ,, Qt::UserRole);
		std::cout << c->get_phone_code().toStdString() << "--->" << c->get_mobile_operator_codes().size() << std::endl;
		m_operators[c->get_phone_code()] = c->get_mobile_operator_codes();
	}
	m_countries->addItem("");

}
void countries_custom_widget::update_country_combo_icon(int i)
{
	//m_countries->clearEditText();

	if (i != 200) {
		m_selected_index = i;
		m_countries->setCurrentText("");
		m_countries->setItemIcon(200, Controller::get_instance()->get_engine()->get_country_infos()[i]->get_flag_icon());
		m_countries->setCurrentIndex(200);
	}
	
	//m_countries->setEditText(Controller::get_instance()->get_engine()->get_country_infos()[i]->get_country_name());
}

