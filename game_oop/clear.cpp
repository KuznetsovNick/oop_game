#include "clear.h"

Clear::Clear(Cell* cell): cell(cell){}

void Clear::interact() {
	cell->setState(Cell::PASS);
}