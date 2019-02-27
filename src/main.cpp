#include <global.hpp>

int main() {
	
	Global::load();
	Global::process();
	Global::finish();

	return 0;
}
