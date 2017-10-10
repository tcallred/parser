#pragma once
#include <set>
#include "String.h"
class Domain
{
public:
	Domain();
	~Domain();
	void addVec(vector<String*> in);
	void toString();
private:
	set<string> strings;
};

