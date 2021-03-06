#include "CLoopStmt.h"

CWhileStmt::CWhileStmt()
{
}

CWhileStmt::CWhileStmt(CExpression* p_condition, CSeqStmt *p_body)
{
	condition = p_condition;
	body = p_body;
}


void CWhileStmt::print()
{
	//printf("\n*** loop statement ***\n");
	if(condition != NULL)
	{
		//cout<<endl<<"Condition: "<<endl;
		//condition->print(0);
	}

	//body->print();

	if(this->next != NULL)
	{
		//this->next->print();
	}
}

list<CSeqStmt *> CWhileStmt::getBranches()
{
	list<CSeqStmt *> temp_list;
	temp_list.push_back(body);

	return temp_list;
}

//void CWhileStmt::getOrientedStmts(CExpression* cond, list<OrientedStmt*> & ostmts)
//{
//}

// Added on 5/9/08

void CWhileStmt::getOutputs(list<ProcessSExpressions*> & SymbolicExpressions)
{
}

// End of additions

//Added on 9/9/08

void CWhileStmt::getSymbolicExpressions(list<ProcessSExpressions*> & SymbolicExpressions, string entName, int delta)
{
}

// End of additions
