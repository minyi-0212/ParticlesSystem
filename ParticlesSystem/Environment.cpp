#include "Environment.h"

Environment& Environment::get_instance()
{
	static Environment instance;
	return instance;
}