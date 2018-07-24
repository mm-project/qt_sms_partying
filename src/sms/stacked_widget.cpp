#include "stacked_widget.hpp"

#include "login_window_gui.hpp"
#include "send_window_gui.hpp"
#include "controller.hpp"

#include <QStackedLayout>

stacked_widget::stacked_widget(QWidget* parent)
        : QWidget(parent)
{
        m_layout = new QStackedLayout;
        m_login = new login_window(this);
        m_send = new send_window(this);
        m_layout->addWidget(m_login);
        m_layout->addWidget(m_send);
        m_layout->setCurrentWidget(m_login);
        setLayout(m_layout);

        connect(m_login, SIGNAL(accept_user()), this, SLOT(change_window()));
        connect(m_login, SIGNAL(change_status_bar(const QString&,bool, bool)), this, SLOT(update_statusbar(const QString&, bool, bool)));
		
		//connect(Controller::get_instance(), SIGNAL(signal_balance_request_done(bool,const QString&)), this, SLOT(on_balance_response_availble(bool,const QString&)));
		
}

void stacked_widget::change_window()
{
        m_layout->setCurrentWidget(m_send);
		//m_send->disable_inputs();
        //emit status_bar_changed("Current balance: getting data... ", true,true); 
		//Controller::get_instance()->request_get_balance();
}

/*
void stacked_widget::disable_inputs() {
	
}

void stacked_widget::enable_inputs() {
}
*/

void stacked_widget::on_balance_response_availble(bool rcode, const QString& res)
{
		if ( !rcode ) {
			emit status_bar_changed("Current balance:  "+res, true); 
			m_send->enable_inputs();
		} else {
			emit status_bar_changed("Current balance:  "+res, false); 
			
		}
		
}

void stacked_widget::update_statusbar(const QString& s,bool res, bool processing)
{
        emit status_bar_changed(s, res, processing);
}
