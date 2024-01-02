#pragma once

class Action {
public:
	virtual void interact() = 0;
	virtual ~Action() = default;
};