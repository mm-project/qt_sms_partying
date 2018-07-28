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

send_window::send_window(QWidget* parent)
        : QWidget(parent)
{
        
        m_from_edt = new QLineEdit(this);
        m_to_combo = new QComboBox(this);
        m_msg_txt = new QTextEdit(this);
		m_send_button = new QPushButton("Send", this);
		m_send_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        
		QLabel* from_l = new QLabel("From:", this);
        QLabel* to_l = new QLabel("To:", this);
        QLabel* message_l = new QLabel("Message:", this);
        QGridLayout* grid = new QGridLayout;

        grid->addWidget(from_l, 0, 0, Qt::AlignRight);
        grid->addWidget(m_from_edt, 0, 1);
        grid->addWidget(to_l, 1, 0, Qt::AlignRight);
        grid->rowStretch(1);
        grid->addWidget(m_to_combo, 1, 1);
        grid->addWidget(message_l, 2, 0);
        grid->addWidget(m_msg_txt, 3, 0, 1, 2);
        grid->addWidget(m_send_button, 4, 1, Qt::AlignRight);

        QVBoxLayout* v_l = new QVBoxLayout;
        v_l->addLayout(grid);
        setLayout(v_l);
		

		update_to_combo();
		
		m_sms_handler = new SimpleGetHandler("sms/json", false);
		
		
		connect(m_sms_handler, SIGNAL(sig_pass()), this, SLOT(on_send_ok()));
		connect(m_sms_handler, SIGNAL(sig_err()), this, SLOT(on_send_err()));
		connect(m_send_button,SIGNAL(clicked()),this,SLOT(on_send_clicked()));
}

void send_window::disable_inputs() {
        m_from_edt->setEnabled(false);
        m_to_combo->setEnabled(false);
        m_msg_txt->setEnabled(false);
		m_send_button->setEnabled(false);
}

void send_window::enable_inputs() {
        m_from_edt->setEnabled(true);
        m_to_combo->setEnabled(true);
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
		m_sms_handler->execute2(Controller::get_instance()->get_engine()->create_qvariant_for_sms("LEVON","","TEST"));	
}

void send_window::on_send_ok() {
		enable_inputs();
		emit change_status_bar("Message send.",true);	
}

void send_window::on_send_err() {
		enable_inputs();
		emit change_status_bar("Send Error: "+m_sms_handler->get_error_message(),false);	
}

void send_window::update_to_combo()
{
		m_to_combo->setEditable(true);
		QIcon icon("C:\\Users\\levons\\Desktop\\git\\mm_project\\qt_sms_partying\\etc\\icons\\armenia_640.png");
		m_to_combo->addItem(icon, "+374");
}