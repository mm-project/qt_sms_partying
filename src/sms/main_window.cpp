#include "main_window.hpp"

#include "stacked_widget.hpp"
#include "controller.hpp"

#include <QStatusBar>
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QPicture>
#include <QMovie>



#include <iostream>

MainWindow::MainWindow(QWidget* p)
        :QMainWindow(p)
{
        m_stacked = new stacked_widget(this);
		m_controller = Controller::get_instance();
		
        setCentralWidget(m_stacked);
        setFixedSize(300, 280);
        setWindowTitle("SMS FUN");
        
		connect(m_stacked, SIGNAL(status_bar_changed(const QString&, bool, bool)), this, SLOT(update_status_bar(const QString&, bool, bool)));
		//FIXME move to member
		//QString QT_ICON_DIR(MACRO_ICONS_DIR);
		
		m_gif = new QMovie(MACRO_ICONS_DIR_STR("gg.gif"));
		//assert(m_gif->isValid() != 0); // maybe need to check
		m_gif->setScaledSize(QSize(20, 20));
		m_gif_label = new QLabel(this);
		m_gif_label->setMovie(m_gif);		
		m_status_bar_label = new QLabel("Enter creditials to login.", this);
		statusBar()->addWidget(m_status_bar_label);
		statusBar()->addWidget(m_gif_label);
		m_gif_label->setHidden(true);
		setWindowIcon(QIcon(MACRO_ICONS_DIR_STR("logo.png")));
		
		std::cout << MACRO_ICONS_DIR_STR("logo.png").toStdString() << std::endl;
}

void MainWindow::update_status_bar(const QString& s, bool err, bool processing)
{
		QStatusBar* s_bar = statusBar();
		!err ? s_bar->setStyleSheet("color : red")
               : s_bar->setStyleSheet("color : black");
        m_status_bar_label->setText(s);
		if (!processing) {
			m_gif->stop();
			m_gif_label->setHidden(true);
		} else {
			m_gif->start();
			m_gif_label->setHidden(false);
		}
}
