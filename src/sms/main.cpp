#include "main_window.hpp"
#include "controller.hpp"

#include <QApplication>
#include <Qstring>

Controller* Controller::m_instance = 0;

int main(int argc, char** argv)
{
        QApplication app(argc, argv);
        MainWindow window;
		QString style("QMainWindow {background : blue, qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgba(60, 186, 162, 255), stop:1 rgba(100, 211, 162, 255)); } QStatusBar::item { border: 0px solid black };");
		window.setStyleSheet(style);
        window.show();
        return app.exec();
}
