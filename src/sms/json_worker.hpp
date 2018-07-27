#ifndef JSON_WORKER_HPP
#define JSON_WORKER_HPP

#include "requester.hpp"

#include <QString>

class JsonWorker 
{
    public:
		JsonWorker() {
		
		}
		
		void print_json_key_value(const QJsonObject& json);
		QString json_to_string(const QJsonObject& j);
		QJsonValue get_value(const QJsonObject& j,const QString& s);
		
		
};


#endif // JSON_WORKER_HPP
