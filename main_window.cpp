#include "main_window.hpp"

#include "stacked_widget.hpp"

#include <QStatusBar>

MainWindow::MainWindow(QWidget* p)
        :QMainWindow(p)
{
        m_stacked = new stacked_widget(this);
        setCentralWidget(m_stacked);
        resize(300, 300);
        setWindowTitle("ADD ME");
        connect(m_stacked, SIGNAL(status_bar_changed(const QString&, bool)), this, SLOT(update_status_bar(const QString&, bool)));
        statusBar()->showMessage("Login");
}

void MainWindow::update_status_bar(const QString& s, bool color_red)
{
        color_red ? statusBar()->setStyleSheet("color : red")
                : statusBar()->setStyleSheet("color : black");
        statusBar()->showMessage(s);
}
