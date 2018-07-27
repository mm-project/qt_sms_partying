#include "engine.hpp"

#include <QString>

Engine::Engine() {
	is_auth = false;
}

bool Engine::is_authorized() {
	return is_auth;
}

void Engine::set_authorized(const QString& u, const QString& p) {
	is_auth = true;
	m_username = u;
	m_password = p;
}

void Engine::unset_authorized() {
	is_auth = false;
}



