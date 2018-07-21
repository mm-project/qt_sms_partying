#include "login_window_gui.hpp"
#include "controller.hpp"
#include "main_window.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>

login_window::login_window(QWidget* parent)
        : QWidget(parent)
{
        QGridLayout* layout = new QGridLayout;
        m_username = new QLineEdit(this);
        m_password = new QLineEdit(this);
        m_login_button = new QPushButton("Login", this);
        m_login_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        QLabel* username_label = new QLabel("Username:", this);
        QLabel* password_label = new QLabel("Password:", this);
        layout->addWidget(username_label, 0, 0, Qt::AlignRight);
        layout->addWidget(m_username, 0, 1);
        layout->addWidget(password_label, 1, 0, Qt::AlignRight);
        layout->addWidget(m_password, 1, 1);
        layout->addWidget(m_login_button, 2, 1, Qt::AlignRight);
        layout->rowStretch(2);
        QVBoxLayout* main_layout =  new QVBoxLayout;
        main_layout->addLayout(layout);
        QGroupBox* box = new QGroupBox("Account info");
        box->setLayout(main_layout);
        box->setFlat(false);
        QHBoxLayout* l = new QHBoxLayout;
        l->addWidget(box);
        setLayout(l);

		//FIXME
		m_controller = Controller::get_instance();
        
		connect(m_login_button, SIGNAL(clicked()), this, SLOT(login_button_clicked()));
		connect(m_username, SIGNAL(clicked()), this, SLOT(user_field_clicked()));
		connect(m_controller, SIGNAL(login_successed()), this, SLOT(on_login_ok()));
		connect(m_controller, SIGNAL(login_failed(const QString&)), this, SLOT(on_login_err(const QString&)));
		
		connect(m_controller, SIGNAL(processing_start()), this, SLOT(start_process()));
		connect(m_controller, SIGNAL(processing_end()), this, SLOT(end_process()));
}

//FIXME
void login_window::user_field_clicked() {
	emit change_status_bar("",true);	
}

bool login_window::pre_validate() 
{
	//FIXME TODO
	//if ( ! check_inputs_validity() ) return false;
	set_state(DISABLED);
	//emit change_status_bar("Logging in...", true);	
	return true;
}

void login_window::post_validate(bool res, const QString& err_msg) 
{
	if(!res) {
		set_state(ENABLED);
		emit change_status_bar("Error: "+err_msg,false);
	} else {
		emit accept_user();
	}
}

void login_window::on_login_ok() {
	post_validate(true,"");
}

void login_window::on_login_err(const QString& res) {
	post_validate(false,"ERROR: "+res);
}


void login_window::login_button_clicked()
{
        if ( !pre_validate() ) return;
		Controller::get_instance()->request_check_login(m_username->text(),m_password->text());
		//answer will be handled by
		//on_login_err or on_login_ok
}

void login_window::start_process()
{
	static_cast<MainWindow*>(parentWidget()->parentWidget())->start_processing();
}

void login_window::end_process()
{
	static_cast<MainWindow*>(parentWidget()->parentWidget())->end_processing();
}

void login_window::set_state(state s)
{
	bool f = s == ENABLED;
	m_login_button->setEnabled(f);
	m_username->setEnabled(f);
	m_password->setEnabled(f);
}