#include "login_window_gui.hpp"
#include "controller.hpp"
#include "main_window.hpp"
#include "request_handler.hpp"
#include "simple_get_handler.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>
#include <QValidator>

login_window::login_window(QWidget* parent)
	: QWidget(parent)
{
	QGridLayout* layout = new QGridLayout;
	m_username = new QLineEdit(this);
	m_password = new QLineEdit(this);

	m_username->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+"), this));
	m_username->addAction(QIcon("C:\\Users\\elen\\Desktop\\qt_sms\\original_sms\\qt_sms_partying\\etc\\icons\\login2.png"), QLineEdit::LeadingPosition);
	m_password->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]+"), this));
	m_password->addAction(QIcon("C:\\Users\\elen\\Desktop\\qt_sms\\original_sms\\qt_sms_partying\\etc\\icons\\password2.png"), QLineEdit::LeadingPosition);

	m_login_button = new QPushButton("Login", this);
	m_login_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	QLabel* username_label = new QLabel("Key:", this);
	QLabel* password_label = new QLabel("Secret:", this);
	layout->addWidget(username_label, 0, 0, Qt::AlignRight);
	layout->addWidget(m_username, 0, 1);
	layout->addWidget(password_label, 1, 0, Qt::AlignRight);
	layout->addWidget(m_password, 1, 1);
	layout->addWidget(m_login_button, 2, 1, Qt::AlignRight);
	layout->rowStretch(2);
	QVBoxLayout* main_layout = new QVBoxLayout;
	main_layout->addLayout(layout);
	QGroupBox* box = new QGroupBox("Account info");
	box->setLayout(main_layout);
	box->setFlat(false);
	QHBoxLayout* l = new QHBoxLayout;
	l->addWidget(box);
	setLayout(l);

	//FIXME
	//connect(m_username, SIGNAL(clicked()), this, SLOT(user_field_clicked()));
	m_controller = Controller::get_instance();

	//m_controller->register_handler(SimpletGetHandler(""),on_login_ok,on_login_err);
	login_handler = new SimpleGetHandler("account/get-balance/%1/%2");	
	connect(login_handler, SIGNAL(sig_error()), this, SLOT(on_login_err()));
	connect(login_handler, SIGNAL(sig_pass()), this, SLOT(on_login_ok()));
		
	connect(m_login_button, SIGNAL(clicked()), this, SLOT(login_button_clicked()));
	
	//connect(m_login_button, SIGNAL(clicked()), this, SLOT(login_button_clicked()));
	//connect(m_controller, SIGNAL(login_successed()), this, SLOT(on_login_ok()));
	//connect(m_controller, SIGNAL(login_failed(const QString&)), this, SLOT(on_login_err(const QString&)));
}

///FIXME
/*
void login_window::user_field_clicked() {
	emit change_status_bar("",true);	
}
*/

bool login_window::pre_validate() 
{
	//FIXME TODO
	//if ( ! check_inputs_validity() ) return false;
	set_state(DISABLED);
	emit change_status_bar("Logging in...", true,true);		
	return true;
}

void login_window::post_validate(bool res, const QString& msg) 
{
	if(!res) {
		set_state(ENABLED);
		emit change_status_bar("Error: "+msg,false);
	} else {
		emit change_status_bar("Availble balance: "+msg,true);	
		emit accept_user();
	}
}

void login_window::on_login_ok() {
	m_controller->get_engine()->set_authorized(m_username->text(),m_password->text());
	post_validate(true,QString::number(login_handler->get_response_value("value").toDouble()));
}

void login_window::on_login_err() {
	m_controller->get_engine()->unset_authorized();
	post_validate(false,login_handler->get_error_message());
}


/*
void login_window::on_login_err(const QString& res) {
	post_validate(false,"ERROR: "+res);
}
*/

void login_window::login_button_clicked()
{
	if ( !pre_validate() ) return;
	login_handler->set_args(login_handler->get_pattern().arg(m_username->text()).arg(m_password->text()));
	login_handler->execute();
	
	//answer will be handled by
	//on_login_err or on_login_ok
}

void login_window::set_state(state s)
{
	bool f = s == ENABLED;
	m_login_button->setEnabled(f);
	m_username->setEnabled(f);
	m_password->setEnabled(f);
}