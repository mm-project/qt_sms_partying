#ifndef REQUESTER_HANDLER_HPP
#define REQUESTER_HANDLER_HPP

#include <QObject>
#include <QJsonObject>
#include <QString>

class RequestHandler : public QObject
{
    Q_OBJECT
	
public:
	virtual void execute() = 0;

public slots:

	virtual void on_error(const QJsonObject &) = 0;
	virtual void on_pass(const QJsonObject &) = 0;
	
	virtual QString get_error_message() = 0;
	
	virtual QString& get_pattern() = 0;
	virtual void set_args(const QString&) = 0;

signals:
	void sig_error();
	void sig_pass();

};

#endif 

