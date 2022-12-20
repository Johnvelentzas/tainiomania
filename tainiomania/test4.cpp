#include "being.h"
#include "human.h"

int main() {
	human John(19, "John");
	human* Stelios = new human(19, "Stelios");
	delete Stelios;
	being* Maria = new human(20, "Maria");
	delete Maria;
	return 0;
}