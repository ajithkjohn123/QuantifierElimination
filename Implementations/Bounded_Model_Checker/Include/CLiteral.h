#ifndef __CLITERAL_H
#define __CLITERAL_H

#include <string>
#include <string.h>
#include <set>


#include "COperand.h"
using namespace std;

class CLiteral:public COperand
{
	string value;
public:
	CLiteral();
	~CLiteral();
	CLiteral(int type, string value, string unit="");
	string getValue();
	virtual void print();
	virtual string getOper();
	virtual int adjustRange(string entityName); 
	virtual bool unAdjusted();
	virtual void setLowerBits(int numberofbits);
	virtual string getName();
	virtual CDAGNode* getDAG(string entName, int previous, set<string>& setRelation);
	virtual CDAGNode* getSymbolicExpressions(string entName, int delta, set<string>& setRelation, list<ProcessSExpressions*> & SymbolicExpressions); // Added on 9/9/08
};

#endif