#include "json_worker.hpp"

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <QString>

#include <iostream>

QString JsonWorker::json_to_string(const QJsonObject& j)
{
	QJsonDocument doc(j);
	QString strJson(doc.toJson(QJsonDocument::Compact));
	//std::cout << strJson.toStdString() << std::endl;	
	return strJson;
}

void JsonWorker::print_json_key_value(const QJsonObject& json) {

	foreach(const QString& key, json.keys()) {
        QJsonValue value = json.value(key);
        std::cout  << value.type() << "Key = " << key.toStdString() << ", Value = " << value.toString().toStdString() << std::endl;
    }
	
}

QJsonValue JsonWorker::get_value(const QJsonObject& json,const QString& key)
{
	//QJsonValue res = jo.value(key);
	
	//QJsonDocument doc(j);
	//QString strJson(doc.toJson(QJsonDocument::Compact));
	//std::cout << strJson.toStdString() << std::endl;	
	//foreach(const QString& key, json.keys()) {
    //   QJsonValue value = json.value(key);
    //    qDebug() << "Key = " << key << ", Value = " << value.toString();
    //}

	print_json_key_value(json);
	
	return json.value(key);
	//return jo.value(key).toString();
}

/*
QJsonObject JsonWorker::create_json(QList<>&);
{
	QJsonDocument doc(j);
	QString strJson(doc.toJson(QJsonDocument::Compact));
	//std::cout << strJson.toStdString() << std::endl;	
	return strJson;
}
*/
