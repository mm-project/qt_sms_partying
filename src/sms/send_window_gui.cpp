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
	m_countries = new QComboBox(this);
	m_to_edit = new QLineEdit(this);
	m_msg_txt = new QTextEdit(this);
	m_send_button = new QPushButton("Send", this);
	m_send_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	m_send_button->setEnabled(false);

	//m_to_edit->setMinimumSize(m_countries->size());
	m_to_edit->setPlaceholderText("12345678");
	m_to_edit->setValidator(new QRegExpValidator(QRegExp("[0-9]+"), this));
	m_from_edt->setMaxLength(10);
	m_from_edt->setPlaceholderText("QtSMS");

	QLabel* from_l = new QLabel("From:", this);
	QLabel* to_l = new QLabel("To:", this);
	QLabel* message_l = new QLabel("Message:", this);
	QGridLayout* grid = new QGridLayout;

	QHBoxLayout* ll = new QHBoxLayout;
	ll->addWidget(m_countries);
	ll->addWidget(m_to_edit);

	grid->addWidget(from_l, 0, 0, Qt::AlignRight);
	grid->addWidget(m_from_edt, 0, 1);
	grid->addWidget(to_l, 1, 0, Qt::AlignRight);
	grid->addLayout(ll, 1, 1);
	grid->addWidget(message_l, 2, 0);
	grid->addWidget(m_msg_txt, 3, 0, 1, 2);
	grid->addWidget(m_send_button, 4, 1, Qt::AlignRight);

	QVBoxLayout* v_l = new QVBoxLayout;
	v_l->addLayout(grid);
	setLayout(v_l);		

	update_to_combo();
	
	m_sms_handler = new SimpleGetHandler("sms/json", false);
		
	m_send_button->setEnabled(false);		
	connect(m_sms_handler, SIGNAL(sig_pass()), this, SLOT(on_send_ok()));
	connect(m_sms_handler, SIGNAL(sig_error()), this, SLOT(on_send_err()));
	connect(m_send_button,SIGNAL(clicked()),this,SLOT(on_send_clicked()));
	connect(m_countries, SIGNAL(currentTextChanged(const QString&)), this, SLOT(update_to_line_edit_completer(const QString&)));
}


void send_window::disable_inputs() {
	m_from_edt->setEnabled(false);
	m_countries->setEnabled(false);
	m_to_edit->setEnabled(false);
	m_msg_txt->setEnabled(false);
	m_send_button->setEnabled(false);
}

void send_window::enable_inputs() {
	m_from_edt->setEnabled(true);
	m_countries->setEnabled(true);
	m_to_edit->setEnabled(true);
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
	m_sms_handler->execute2(Controller::get_instance()->get_engine()->create_qvariant_for_sms(m_from_edt->text(),m_countries->currentText()+m_to_edit->text(),m_msg_txt->toPlainText()));	
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
	m_countries->setEditable(true);
	// only after setEditable(true)
	m_countries->completer()->setCompletionMode(QCompleter::PopupCompletion);
	m_countries->setValidator(new QRegExpValidator(QRegExp("(^\+)[0-9]+"), this));
	
	//add from my file countries list.
	//TODO add engines
	m_countries->addItem(QIcon(MACRO_ICONS_DIR_STR("armenia.png")), "+374");
	//m_countries->addItem(QIcon(MACRO_ICONS_DIR_STR("georgia.png")), "+955");
	
	//TODO add from mobile list.
	update_to_line_edit_completer(m_countries->currentText());
}



void send_window::update_to_line_edit_completer(const QString& country)
{
	// validate if s is from coutries combo list
	QStringList wordlist;
	// get wordlist from s , maybe map
	QCompleter* completer = new QCompleter(wordlist, this);
	completer->setCompletionMode(QCompleter::PopupCompletion);
	m_to_edit->setCompleter(completer);
}
