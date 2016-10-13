#include "CJunctionNode.h"

CJunctionNode::CJunctionNode()
{
	traversed = false;
}

CJunctionNode::CJunctionNode(CSeqStmt* p_parent)
{
	parent = p_parent;
	traversed = false;
}

void CJunctionNode::print()
{
	//printf("\n*** Junction node statement ***\n");
}

void CJunctionNode::createNode(FILE *fp, string parent1)
{
/*	if(traversed = true)
	{
		fprintf(fp, "%s -> seqstmt%u;\n",parent.c_str(), this); 
	}
	else*/
// 	{
	fprintf(fp, "seqstmt%u [label=\" JUNCTION \"];\n",this); 
	fprintf(fp, "seqstmt%u -> seqstmt%u;\n",this, parent); 
	fprintf(fp, "%s -> seqstmt%u;\n",parent1.c_str(), this);
// 	}
}


void CJunctionNode::adjustStmt(string entityName)
{

}

//void CJunctionNode::getOrientedStmts(CExpression* cond, list<OrientedStmt*> & ostmts)
//{
//}

void CJunctionNode::getChangedLHS(list<CSensitiveElement*>& sensitivityList)
{
}

// Added on 5/9/08

void CJunctionNode::getOutputs(list<ProcessSExpressions*> & SymbolicExpressions)
{
}

// End of additions

// Added on 9/9/08

void CJunctionNode::getSymbolicExpressions(list<ProcessSExpressions*> & SymbolicExpressions, string entName, int delta)
{
}

// End of additions


void CJunctionNode::getChangedRHS(list<COperand*>& sensitivityList)
{
}

void CJunctionNode::createEdgeInArgDepGraph(Graph *ArgDepGraph)
{
}

	

       




