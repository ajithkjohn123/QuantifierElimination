#include "CInstance.h"

CInstance::CInstance(string p_instance_name,
		string p_entity_name,
		list<CExpression*> p_actual_param,
		list<COperand*> p_formal_param)
{
	index = -1;
	instance_name = p_instance_name;
	entity_name = p_entity_name;

	actual_param.splice(actual_param.begin(), p_actual_param);
	formal_param.splice(formal_param.begin(), p_formal_param);
}

void CInstance:: print()
{
	//printf("\n*** Instance statement ***\n");
	//cout<<"instance name: "<<instance_name<<endl;
	//cout<<"entity name: "<<entity_name<<endl;

	//cout<<endl<<"Actual parameter list: "<<endl;


	if(formal_param.size() != 0)
	{
		list<CExpression*> ::iterator iparam;
		list<COperand*> ::iterator iop;
	
		for(	iparam = actual_param.begin(), iop=formal_param.begin();
			iparam != actual_param.end();
			iparam++,iop++)
		{
			(*iparam)->print(0);
			(*iop)->print();
		}
	}
	else
	{
		list<CExpression*> ::iterator iparam;
	
		for(	iparam = actual_param.begin();
			iparam != actual_param.end();
			iparam++)
		{
			(*iparam)->print(0);
		}
	}

}

string CInstance:: getEntName()
{
	return entity_name;
}

void CInstance::setIndex(int ind)
{
	index = ind;
}

string CInstance::getInstName()
{
	return instance_name;
}

int CInstance::getIndex()
{
	return index;
}

list<CExpression*>& CInstance::getActualParam()
{
	return actual_param;
}

list<COperand*>& CInstance::getFormalParam()
{
	return formal_param;
}
