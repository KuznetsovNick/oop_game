#pragma once
#include "field.h"
#include "fieldExc.h"
#include "fieldDec.h"

template<int h = 10, int w = 10>
class SizeField {
public:
	void operator()(Field* field) {
		if (h < 3 || w < 3) {
			throw FieldDecorator(new FieldExc(h, w));
		}
		else {
			field->resizeField(w, h);
		}
	}
};