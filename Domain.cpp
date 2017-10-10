#include "Domain.h"



Domain::Domain()
{
}


Domain::~Domain()
{
}

void Domain::addVec(vector<String*> in)
{
	for (unsigned int i = 0; i < in.size(); i++) {
		strings.insert(in[i]->toString());
	}
}

void Domain::toString()
{
	cout << "Domain(" << strings.size() << "):" << endl;
	for (set<string>::iterator it = strings.begin(); it != strings.end(); ++it) {
		cout << "  " << *it << endl;
	}
}
