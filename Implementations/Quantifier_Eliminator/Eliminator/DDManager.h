
#ifndef _DDMANAGER_H
#define	_DDMANAGER_H

    #include <string>
    #include <iostream>
    #include <sys/time.h>

    #include "Eliminator.h"
    #include "ILP_Eliminator.h"
    #include "DDNode.h"
    #include "HashTable_WithStandardKeys.h"   
    #include "ImplicationCacheTree.h"
    #include "BitBlaster.h"
    #include "util.h"
    #include "cudd.h"


    #include <fstream>
    #include <list>
    #include <set>
    
    using namespace std;

    extern DAGManager dm;
    extern char* qEliminator_type;
    extern char* Elimination_Type;
    extern bool order_based_on_vars_to_elim;
    

    extern time_t SMTSolver_Time_In_ImplicationCheck;
    extern time_t ExSolver_Time_In_ImplicationCheck;
    extern time_t Simulator_Time_In_ImplicationCheck;
    extern int simplification_mode;
    extern FILE *ImpCheckFile;
    extern unsigned long long int Calls_For_ImpCheck;
    extern unsigned long long int Calls_For_ImpCheck_By_Simulator;
    extern unsigned long long int Calls_For_ImpCheck_By_Exsolver;
    extern unsigned long long int Calls_For_ImpCheck_By_SMTsolver;
    extern unsigned long long int Cache_Hits_For_ImpCheck;
    extern unsigned long long int Cache_Misses_For_ImpCheck;
    extern unsigned long long int Calls_For_ImpCheck_By_Overlap_Checking;
    extern unsigned long long int Show_ImpCheck_Calls;  
    extern unsigned long long int Successful_ImpCheck_Calls; 
    extern unsigned long long int Failed_ImpCheck_Calls; 
    extern unsigned long long int Second_Level_Cache_Hits_For_ImpCheck;
    extern unsigned long long int Second_Level_Cache_Misses_For_ImpCheck;

    extern ImplicationCacheTree CacheTree;
    extern bool make_squarings_independent;
    extern bool reorderingBasedOnSharing_Enabled;

    extern FILE *FILE_Blowup;
    extern unsigned long long int apply_shrinks;
    extern unsigned long long int apply_blows;
    extern unsigned long long int ite_shrinks;
    extern unsigned long long int ite_blows;
    extern float blow_max_ite;
    extern float blow_min_ite;
    extern float blow_max_apply;
    extern float blow_min_apply;
    extern vector< set<string> > SignalClass;
    extern map<string, int> SignalEquivalenceClass;
    extern unsigned long long int applystepwithimpcheck_cache_non_trivial_hit;
    extern unsigned long long int applystepwithimpcheck_cache_trivial_hit;
    extern unsigned long long int applystepwithimpcheck_calls;
    extern unsigned long long int applystepwithimpcheck_local_cache_hit;

    extern unsigned long long int applyitewithimpcheck_calls;
    extern unsigned long long int applyitewithimpcheck_local_cache_hit;

    extern unsigned long long int applystepwithimpcheck_local_cache_max_size;
    extern unsigned long long int applyitewithimpcheck_local_cache_max_size;
    extern unsigned long long int applystepwithimpcheck_max_context_size;
    extern unsigned long long int applyitewithimpcheck_max_context_size;

    extern time_t time_in_local_hashing_in_applystepwithimpcheck;
    extern time_t time_in_local_hashing_in_applyitewithimpcheck;
    extern unsigned long long int applystepwithimpcheck_local_cache_trivial_hit;
    extern unsigned long long int applyitewithimpcheck_local_cache_trivial_hit;
    extern unsigned long long int applystepwithimpcheck_local_cache_level1_hit;
    extern unsigned long long int applyitewithimpcheck_local_cache_level1_hit;
    extern unsigned long long int eliminate_incons_paths_int_local_cache_level1_hit;
    extern unsigned long long int max_context_size_imp_check;
    extern unsigned long long int applystepwithimpcheck_external_cache_hit;
    extern unsigned long long int applystepwithimpcheck_external_cache_miss;
    extern unsigned long long int createitewithimpcheck_external_cache_hit;
    extern unsigned long long int createitewithimpcheck_external_cache_miss;
    extern unsigned long long int applystepwithimpcheck_misses;
    extern unsigned long long int applyitewithimpcheck_misses;
    extern unsigned long long int effect_of_reduce;

    extern bool trimming_context_mod_based;
    extern bool trimming_context_class_based;
    extern bool trimming_context_overapproximate;
    extern bool trimming_context_strategy_four;
    extern bool cache_tree_on;

    extern unsigned long long int trim_context_strategy_four_times;
    extern unsigned long long int level_2_trimming_effect;
    extern time_t trimming_time;


    extern unsigned long long int thunsat_calls;

    extern time_t LMDD_Creation_Time;
    extern time_t QElim_Time;
    extern int Max_Inter_LMDD_Size;

// Declarations for timeout
extern time_t time_out;
extern time_t time_out_start;
extern bool timed_out;
// Declarations for timeout ends here

// Declarations for comparing with OmegaTest
extern time_t Total_Omega_Test_Time;
extern time_t Total_AP_QElim_Time;
extern bool compare_apqelim_omegatest;
extern unsigned long long Total_Omega_Test_Time_In_ms;
extern unsigned long long Total_AP_QElim_Time_In_ms;
// Declarations for comparing with OmegaTest end here


// Declarations for comparing with Bit-blasting
extern bool compare_apqelim_blasting;
extern unsigned long long int Total_Blasting_Time_In_ms;
extern time_t Total_Blasting_Time;
// Declarations for comparing with Bit-blasting

// Declarations for LMDD:BDD
extern int bdd_index;
extern map<string, int> NameIndexMap;
extern map<int, string> IndexNameMap;
extern DdManager *manager;
// Declarations for LMDD:BDD end here

extern bool output_conjunctions;

extern string internal_solver;

 extern bool order_lmes_before_lmis;
 
 // For QE with Monniaux type simplifications 
 extern bool use_monniaux_type_simplification_in_dd;
 extern bool SMTCheckBeforeCombining_in_monniaux_type_simplification_in_dd;
 extern DAGNode* PartialResult_In_LMDDWithMonniauxTypeSimplifications; 
 
 DAGNode* Project(vector<DAGNode*> &Constraints, set<string> &VarsToElim, map<string, int> &WidthTable, int project_depth);
 void createVariableMap(map<string, int> &WidthTable);
 DAGNode* callMonniaux_Quantifier_Eliminator_WithSupportForLMIs(DAGNode *F, set<string> &VarSetToElim, map<string, int> &WidthTable, int project_depth);
 string simpleSMTChecks(DAGNode* formula, set<string> &VarsToElim, map<string, int> &WidthTable);
 // Declaration of functions defined in DAGEliminator.cpp 
 
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_on_zero;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_hits;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_misses_on_unsat;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_misses_with_project;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_misses_without_project;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_first_smt_calls;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_second_smt_calls;
extern time_t call_LMDD_Monniaux_SingleVar_calls_first_smt_calls_total_time;
extern time_t call_LMDD_Monniaux_SingleVar_calls_second_smt_calls_total_time;
extern unsigned long long int LMDD_Monniaux_SingleVar_calls;
extern bool check_path_condition_in_lmdd_with_monniaux;
extern bool check_simplified_path_condition_in_lmdd_with_monniaux;
extern bool check_h_condition_in_lmdd_with_monniaux;
extern bool check_f_condition_in_lmdd_with_monniaux;
extern DDNode* current_root_LMDD_node_in_lmdd_with_monniaux;

extern bool check_effectiveness_of_first_smt_solver_call;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_misses_on_sat;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_misses_on_sat_sat_with_pi;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_misses_on_sat_unsat_with_pi;

extern bool check_f_condition_in_chunks_in_lmdd_with_monniaux;
extern int f_condition_chunk_size_in_lmdd_with_monniaux;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_first_smt_calls_after_chunk_projects;
extern unsigned long long int min_call_LMDD_Monniaux_SingleVar_calls_first_smt_calls_for_satisfactory_truncation;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_misses_on_unsat_after_chunk_projects;
extern float satisfactory_truncation_in_lmdd_with_monniaux;
extern bool use_original_f_for_checking_in_lmdd_with_monniaux;

extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_to_simplified_path_condition;
extern unsigned long long int call_LMDD_Monniaux_SingleVar_calls_to_simplified_path_condition_sat;

extern bool use_path_based_strategy_in_lmdd_monniaux;
extern bool do_monniaux_at_start_up_in_use_path_based_strategy_in_lmdd_monniaux;
extern int monniaux_calls_at_start_up_in_use_path_based_strategy_in_lmdd_monniaux;


extern unsigned long long int start_up_smt_calls_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int time_in_start_up_smt_calls_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int max_path_depth_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int hit_nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int zero_nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int one_nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int qe_lmdd_nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int smt_calls_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int time_in_smt_calls_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int unsat_nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;

extern float NoVarsToElim_To_NoVars_Ratio_For_Monniaux;
extern int NoVarsRemaining_For_Monniaux;
extern int Lowest_Support_Nodes_For_QE_LMDD;
extern int  Highest_Level_For_QE_LMDD;
extern int Lowest_Size_For_QE_LMDD;
extern int select_strategy_calls;
extern int select_strategy_ddfreeofvar;
extern int select_strategy_dagresolve;
extern int select_strategy_lownodeswith_lmi_in_support;
extern int select_strategy_size;
extern int select_strategy_for_monniax;
extern int select_strategy_for_lmdd_default;
extern int select_strategy_lowlevel;

extern unsigned long long int time_spent_in_qe_lmdd;
extern bool apply_lmebased_simplification_on_sat_path;
extern bool use_dag_instead_of_lmdd_in_smt_calls_in_path_based_strategy_in_lmdd_monniaux;
extern DAGNode* original_dag_in_path_based_strategy_in_lmdd_monniaux;
extern bool debug_check_in_path_based_strategy_in_lmdd_monniaux;
extern bool remove_already_eliminated_variables_in_path_based_strategy;
extern int number_of_variables_for_which_no_elimination_needed;
extern list<string> OrderInWhichVariablesAreEliminated;
extern string FinalQEDoneByWhom;

extern unsigned long long int startup_project_calls_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int start_up_qe_lmdd_nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int start_up_time_spent_in_qe_lmdd;
extern unsigned long long int free_nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int dagresolve_nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int nonterminal_nodes_on_path_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int computed_offpathchild_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int hashed_offpathchild_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int zero_offpathchild_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int one_offpathchild_in_path_based_strategy_in_lmdd_monniaux;
extern unsigned long long int project_calls_on_path_in_path_based_strategy_in_lmdd_monniaux;

extern unsigned long long int int_time_spent_in_qe_lmdd_for_select_strategy_ddfreeofvar;
extern unsigned long long int int_time_spent_in_qe_lmdd_for_select_strategy_dagresolve;
extern unsigned long long int int_time_spent_in_qe_lmdd_for_select_strategy_lowlevel;
extern unsigned long long int int_time_spent_in_qe_lmdd_for_select_strategy_size;
extern unsigned long long int int_time_spent_in_qe_lmdd_for_select_strategy_default;
extern string select_strategy_basis;
extern int int_select_strategy_calls;
extern int int_select_strategy_ddfreeofvar;
extern int int_select_strategy_dagresolve;
extern int int_select_strategy_lownodeswith_lmi_in_support;
extern int int_select_strategy_size;
extern int int_select_strategy_for_monniax;
extern int int_select_strategy_for_lmdd_default;
extern int int_select_strategy_lowlevel;

extern unsigned long long int ext_time_spent_in_qe_lmdd_for_select_strategy_ddfreeofvar;
extern unsigned long long int ext_time_spent_in_qe_lmdd_for_select_strategy_dagresolve;
extern unsigned long long int ext_time_spent_in_qe_lmdd_for_select_strategy_lowlevel;
extern unsigned long long int ext_time_spent_in_qe_lmdd_for_select_strategy_size;
extern unsigned long long int ext_time_spent_in_qe_lmdd_for_select_strategy_default;
extern int ext_select_strategy_calls;
extern int ext_select_strategy_ddfreeofvar;
extern int ext_select_strategy_dagresolve;
extern int ext_select_strategy_lownodeswith_lmi_in_support;
extern int ext_select_strategy_size;
extern int ext_select_strategy_for_monniax;
extern int ext_select_strategy_for_lmdd_default;
extern int ext_select_strategy_lowlevel;

extern bool PerformProjectsInPathBasedStrategyAtLMDDLevel;

extern bool UseMonniauxEnabledAllVariableStrategy;
extern bool debug_check_in_use_monniaux_enabled_all_variable_strategy;

extern unsigned long long int CallsToQEWithMonEnabledAllVarStrategy;
extern unsigned long long int CallsToQEWithMonEnabledAllVarStrategyGlobalHashed;
extern unsigned long long int CallsToQEWithMonEnabledAllVarStrategyOnTerminals;
extern unsigned long long int CallsToQEWithMonEnabledAllVarStrategyOnNonTerminalsFreeOfAllVars;
extern unsigned long long int CallsToGetSimplifiedInstance;
extern unsigned long long int CallsToQEWithMonEnabledAllVarStrategyOnNonTerminalsWhereCallToGetSimplifiedInstanceSolved;
extern unsigned long long int TimeSpentInGetSimplifiedInstance;


extern bool ConvertProblemIntoDisjunctionOfTailedTriangles;// When enabled, the original
// QE problem on LMDDs, \exists X.(f) is converted into \exists X. (f_1 /\ C_1) \/ .... \/ \exists X. (f_n /\ C_n)
// and then each of them are solved using appropriate QE strategy
extern bool debug_check_in_ConvertProblemIntoDisjunctionOfTailedTriangles_strategy;
extern FILE* ConversionToDisjunctionOfProblemsFp;
extern unsigned long long int NumberOfTailedTriangles;
extern unsigned long long int NumberOfTailedTrianglesToQE;
extern unsigned long long int TotalSMTTimeInConversionToDisjunctionOfTailedTriangles;
extern unsigned long long int TotalQETimeInConversionToDisjunctionOfTailedTriangles;
extern map<DDNode*, pair<int, int> > PathCountsOfDDNodes;

extern HashTable <string, DDNode*> PerVariableHTForDagResolve_WithLMISupport;
//This HT stores \exists x.(f /\ e) = f'

extern unsigned long long int TotalSizeOfTriangles;
extern unsigned long long int TotalSizeOfTails;
extern unsigned long long int TotalVarsToElimFromTailedTriangles;
extern unsigned long long int TotalVarsEliminatedByLMEsFromTailedTriangles;
extern unsigned long long int TotalVarsEliminatedFreeTrianglesFromTailedTriangles;
extern unsigned long long int TotalRemainingVarsEliminatedFromTailedTriangles;

extern float AvgSizeOfTriangles;
extern float AvgSizeOfTails;
extern float AvgVarsToElimFromTailedTriangles;
extern float AvgVarsEliminatedByLMEsFromTailedTriangles;
extern float AvgVarsEliminatedFreeTrianglesFromTailedTriangles;
extern float AvgRemainingVarsEliminatedFromTailedTriangles;

extern unsigned long long int TimeSpentInProjectsInQE_LMDD;
 


extern bool ConvertProblemIntoDisjunctionOfTailedTrianglesWithAggressiveLMESimplification;// When enabled, the original
// QE problem on LMDDs, \exists X.(f) is converted into \exists X. (f_1 /\ C_1) \/ .... \/ \exists X. (f_n /\ C_n)
// and then each of them are solved using appropriate QE strategy similar to the case with ConvertProblemIntoDisjunctionOfTailedTriangles.
// Additionally 1) LME based simplification is applied as and when the LME is encountered and
// 2) No explicit list of tailed triangles is created.

extern unsigned long long int NoOfCallsToRecursiveAlgoInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int NoOfCallsToRecursiveAlgoInConProbDisjTailTriaWithMESimplificationFalse;
extern unsigned long long int NoOfCallsTogetSimplifiedInstanceUsingLMEsAndHashTableEntries;
extern unsigned long long int NoOfVarsInCallsTogetSimplifiedInstanceUsingLMEsAndHashTableEntries;
extern unsigned long long int NoOfVarsInCallsTogetSimplifiedInstanceUsingLMEsAndHashTableEntriesBenefitedByLMEs;
extern unsigned long long int NoOfVarsInCallsTogetSimplifiedInstanceUsingLMEsAndHashTableEntriesBenefitedByHT;
extern unsigned long long int TimeIngetSimplifiedInstanceUsingLMEsAndHashTableEntriesForLMEs;
extern unsigned long long int TimeIngetSimplifiedInstanceUsingLMEsAndHashTableEntriesForHT;

extern unsigned long long int NonecasesInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int SATCallsInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int SATCallsInConProbDisjTailTriaWithMESimplificationWhichAreSat;
extern unsigned long long int SATCallsInConProbDisjTailTriaWithMESimplificationWhichAreUnsat;
extern unsigned long long int TimeInSATCallsInConProbDisjTailTriaWithMESimplification;


extern unsigned long long int QE_LMDDCallsInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int TimeInQE_LMDDCallsInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int LeftcasesInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int RightcasesInConProbDisjTailTriaWithMESimplification;
extern int MaximumSizeOfLMDDForQELMDDInDisjunctionStrategy;
extern unsigned long long int TotalDDSizeInNonecasesInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int TotalCXSizeInNonecasesInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int TotalNegCXSizeInNonecasesInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int TotalCXSizeInFalsecasesInConProbDisjTailTriaWithMESimplification;
extern unsigned long long int TotalNegCXSizeInFalsecasesInConProbDisjTailTriaWithMESimplification;


extern bool LMEBasedSimplificationAsPreprocessor;
extern unsigned long long int DDSizeBeforeLMEBasedSimplificationAsPreprocessor;
extern unsigned long long int DDSizeAfterLMEBasedSimplificationAsPreprocessor;
extern unsigned long long int TimeInLMEBasedSimplificationAsPreprocessor;
extern unsigned long long int TimeInSimplifyLMDDInLMEBasedSimplificationAsPreprocessor;
extern unsigned long long int CallsToLMEBasedSimplificationAsPreprocessor;
extern unsigned long long int HitsInLMEBasedSimplificationAsPreprocessor;
extern unsigned long long int MissesInLMEBasedSimplificationAsPreprocessor;
extern set<string> VariablesBenefittedByLMEBasedSimplificationAsPreprocessor;
extern unsigned long long int TimeSpentInSMTCallsInsideDAGResolve;
extern unsigned long long int TimeSpentInLayer1CallsInsideDAGResolve;
extern unsigned long long int OriginalCallsToDAGResolve;
extern unsigned long long int RecursiveCallsToDAGResolve;
extern unsigned long long int RecursiveCallsToDAGResolveMissed;
extern unsigned long long int RecursiveCallsToDAGResolveMissedNonTerminals;
extern unsigned long long int RecursiveCallsToDAGResolveLeadingToLayer1Call;
extern unsigned long long int RecursiveCallsToDAGResolveLeadingToLayer1CallHit;
extern unsigned long long int RecursiveCallsToDAGResolveMissedNonTerminalsButFreeOfVarToElim;
extern unsigned long long int TimeSpentInHTLookUpInsideDAGResolve;
extern unsigned long long int TimeSpentInDDCreationInsideDAGResolve;
extern unsigned long long int TimeSpentInDDConversionInsideDAGResolve;
extern unsigned long long int CallsToLMEBasedSimplificationAsPreprocessorWhereLMDDIsFreeOfVar;
extern unsigned long long int QETimeUsingLMDDs;
extern list<int> CountsForVariablesEliminated;

extern HashTable <string, DAGNode*> TableForSimplifyLMCInsideSimplifyLMDD;
// hash table which stores the layer1 entries inside simplifyLMDD 

extern HashTable <string, DDNode*> MapForDDFromDAG;
// global hash table for DAG to DD operation
// used inside DDManager::createDDFromDAGWithoutImplicationCheck


extern bool LMEBasedSimplificationInsideQELMDD;

extern unsigned long long int call_QE_LMDD_Single_Var;
extern unsigned long long int call_QE_LMDD_Single_Var_Hashed;
extern unsigned long long int call_QE_LMDD_Single_Var_OnTerminalZero;
extern unsigned long long int call_QE_LMDD_Single_Var_OnTerminalOne;

extern unsigned long long int call_QE_LMDD_Single_Var_OnTerminalOne_Empty;
extern unsigned long long int call_QE_LMDD_Single_Var_OnTerminalOne_Unsat;
extern unsigned long long int call_QE_LMDD_Single_Var_OnTerminalOne_Sat;

extern unsigned long long int call_QE_LMDD_Single_Var_FreeOfVar;
extern unsigned long long int call_QE_LMDD_Single_Var_SimplifyLMDDCalls;
extern unsigned long long int call_QE_LMDD_Single_Var_SimplifyLMDDCalls_Hashed;
extern unsigned long long int call_QE_LMDD_Single_Var_SimplifyLMDDCalls_FreeOfVar;

extern unsigned long long int call_QE_LMDD_Single_Var_TraverseDown;
extern unsigned long long int call_QE_LMDD_Single_Var_TraverseDown_C_free_of_Var;
extern unsigned long long int call_QE_LMDD_Single_Var_TraverseDown_C_free_of_Var_ProperLME;
extern unsigned long long int call_QE_LMDD_Single_Var_TraverseDown_C_free_of_Var_ProperLME_dd_free_of_var;
extern unsigned long long int call_QE_LMDD_Single_Var_TraverseDown_C_free_of_Var_ProperLME_SimplifyLMDD_calls;
extern unsigned long long int call_QE_LMDD_Single_Var_TraverseDown_C_free_of_Var_ProperLME_Time;
extern unsigned long long int call_QE_LMDD_Single_Var_TraverseDown_C_bound_with_Var;

extern set<string> VariablesBenefittedByLMEBasedSimplificationInsideQELMDD;
extern list<int> SizesOfEliminatedLMDDs;

extern bool EagerConversionToDisjunctions;
// when true, performs conversion to disjunctions until the # of SMT calls >= threshold t_1
// or max triangle size <= threshold t_2
extern int MaximumNoOfSMTCallsInEagerConversionToDisjunctions;
extern int MaximumSizeOfTriangleInEagerConversionToDisjunctions;
extern int SMTCallsCommittedInEagerConversionToDisjunctions;

extern list<int> SizeOfTrianglesInEagerConversionToDisjunctions;
extern list<string> SatUnsatOfTrianglesInEagerConversionToDisjunctions;


extern bool PerformSimplifyLMDDInsidePreprocessingKeepingStructuralIsomorphism;

extern bool DemandBasedConversionToDisjunctions;
extern unsigned long long int NumberOfUnsatTailedTrianglesInDemandBasedConversionToDisjunctions;
extern unsigned long long int NumberOfSplitTailedTrianglesInDemandBasedConversionToDisjunctions;
extern int MaximumSizeOfTriangleInDemandBasedConversionToDisjunctions;
extern int MaximumNoOfSMTCallsInDemandBasedConversionToDisjunctions;
extern int SizeOfInputDDInDDBasedQE;


extern bool ConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;
extern int MaxNoOfSMTCallsInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;
extern int MaxTriangleSizeInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;
extern FILE* ConversionToDisjunctionOfProblemsWithSMTSolverFp;
extern FILE* ConversionToDisjunctionOfProblemsWithSMTSolverHierarchyFp;
extern int NoOfInitialSMTCallsInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCallsCommitted;
extern unsigned long long int TotalInitialSMTTimeInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;
extern unsigned long long int TotalInitialQETimeInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;
extern unsigned long long int NumberOfTailedTrianglesUnsatInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;
extern unsigned long long int NumberOfTailedTrianglesToQEInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;
extern unsigned long long int TotalHierarchySMTTimeInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;
extern unsigned long long int TotalHierarchyQETimeInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;
extern string StrategyForChoosingInConversionToDisjunctionOfTailedTrianglesUsingSMTSolverCalls;

extern unsigned long long int NumberOfTimesCollectedTailedTrianglesToQE;
extern bool CollectConsecutiveSatTailedTriangles_In_ConversionToDisjunctionOfTailedTriangles;

 // For QE with Monniaux type simplifications end here

// Declarations for analysing the times
extern FILE* TimeAnalysisFourierMotzkinFp;// output file for printing the relevant data on time for Fourier-Motzkin type calls
extern FILE* TimeAnalysisFp;// output file for printing the relevant data on time for all calls
extern unsigned long long int TimePerConjunctInSMTAndGeneralize;

// For blast_and_output mode
extern bool dynamic_variable_ordering_in_blast_and_output;
 
    class DDManager
    {
        public:
            
	    int count; // no: of APs created so far
	    map<DAGNode*, int> APMap;


	    // FUNCTIONS FOR BASIC LMDD OPERATIONS AND QUANTIFIER ELIMINATION
	    
	    // Sets the global variable "count" which denotes the # of LMEs
	    // created so far to -1
	    DDManager();



	    // Returns true if an entry exists in the APMap with index = u_index. Else returns false
	    bool checkIfIndexExists(int u_index);


	    // Returns the index of this node
            int getIndex(DDNode *dd);


	    // set the index of the given predicate node pred as new_index
            void setIndex(DAGNode *pred, int new_index);


	    //to create DDNode for terminal values '1' and '0', and return the DDNode
            DDNode* createDD(int);   


	    //to create DDNode for LME new_predicate, and return the DDNode
	    DDNode* createDD(DAGNode*, map<string, int> &WidthTable);   


	    // Function to create DDNode (new_predicate, right, left) and return the DDNode.
	    // Assumption : new_predicate is already there in the APMap in cannonical form.
	    DDNode* createDD(DAGNode* , DDNode*, DDNode*);   
	 
	    
	    // return the result v1->getVal() op v2->getVal()
	    int evaluateOp(string op, DDNode *v1, DDNode *v2);


	    // return minimum of i and j
	    int findMin(int i, int j);


	    // Returns the LME corresponding to the given index.
	    // Exits from the program if no LME exists in the APMap for the given index.
	    DAGNode* findAPFromIndex(int u_index);


	    // Implements Bryant's reduce function.
	    // Given DDNode* v, returns reduced DDNode*.
	    DDNode* Reduce(DDNode *v);


	    // Function to insert into Q. Called by Reduce()
	    void insertIntoQ(map< pair<int, int>, list<DDNode*> > &Q, int key1, int key2, DDNode* u);



	    //Implementation of Bryant's Traverse function. Called by Reduce()
	    void Traverse(DDNode *v, list<DDNode*> vlist[]);


	    // Gets the # of nodes in the DD rooted at "v" in "NoOfNodesInDD"
	    void getNoOfNodesInDD(DDNode *v, int &NoOfNodesInDD);


	    // return the DDNode for not(v1)
	    DDNode* createDDNot(DDNode* v1);


	    // Function to create a DD from a DAG with elimination of inconsistent paths
	    DDNode* createDDFromDAGWithImplicationCheck(DAGNode *dag, map<string, int> WidthTable);


	    // Simplify ite(condn, then, els) if possible, and return the simplified DDNode*
	    DDNode* evaluateITE(DDNode *condn, DDNode *then, DDNode *els);


	    // Performs \exists VarSetToElim. root  with LMDD based approach
	    // Implemets QuaLMoDE, All Path QE, Version of QuaLMoDE which tries to eliminate all variables to eliminate in 
	    // a single shot, and QBV_Solve depending on the command line options
	    DAGNode* Quantifier_Eliminator(DAGNode *root, set<string> VarSetToElim, map<string, int> &WidthTable);


	    // Implements Bryant's apply function for binary operators on LMDDs
	    DDNode* apply(string op, DDNode* v1, DDNode* v2);


	    // The internal function called by apply function
	    DDNode* applyStep(string op, DDNode* v1, DDNode* v2);


	    // Implements Bryant's apply function for  ite operator on LMDDs
	    DDNode* createITE(DDNode* condn, DDNode* then, DDNode* els);


	    // The internal function called by createITE function
	    DDNode* applyITE(DDNode* condn, DDNode* then, DDNode* els);


	    // Function to create a DAG from a DD
	    DAGNode* createDAGFromDD(DDNode *dd);


	    // Internal function called by createDAGFromDD function
	    DAGNode* createDAGFromDDStep(DDNode *dd, HashTable <string, DAGNode*> *PtrMapForDAGFromDD);


	    // Implementation of QuaLMoDE in our CAV'11 work.
	    // Returns \exists VarsToElim. f as DDNode*.
	    DDNode* MultiVarQElimWithStrategy(list<string> VarsToElim, DDNode* f, map<string, int> WidthTable);


	    // Find the # of nodes in which each variable occures in the LMDD rooted at "v".
	    // Called from chooseVar	    
            void findDropVarsStep(DDNode *v, map<string, int> &VarsToElimCount);


	    // Updates the variable ---> # occurances map given an LME "predicate"
	    // Called from findDropVarsStep
	    void updateVarsToElimCount(DAGNode *predicate, map<string, int> &VarsToElimCount);


	    // Returns the variable to be eliminated next from the given LMDD
            string chooseVar(DDNode *v, list<string> &VarsToElim);


	    // Calls the function QE1_LMDD in CAV'11 work.
	    // Returns the LMDD for \exists VarToElim. f.
	    DDNode* callQElim(string VarToElim, DDNode* f, map<string, int> WidthTable);

	    
	    // Function QE1_LMDD in CAV'11 work with elimination of inconsistent paths
	    // Returns the LMDD for \exists VarToElim. (f/\E/\D)
	    DDNode* QElimWithDPModifiedWithImplicationCheck(string VarToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, map<string, int> WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified);



	    // Check if the instance \exists VarToElim. (f /\ E/\ D) is already encountered
	    // If yes, return the result; NULL otherwise
	    DDNode* getEntryFromTableForQElimModified(string VarToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, HashTable <string, DDNode*> *PtrTableForQElimModified);



	    // Return true if /\E /\ D is unsat; false otherwise
	    // Uses STP/yices
	    bool ThUnsat(set<DAGNode*> E, set<DAGNode*> D, map<string, int> WidthTable);



	    // Enter \exists VarToElim. (f /\ E/\ D) ---> result into Hash Table
	    void insertEntryIntoTableForQElimModified(string VarToElim, DDNode*f, set<DAGNode*> E, set<DAGNode*> D, DDNode* value, HashTable <string, DDNode*> *PtrTableForQElimModified);


	    // Copy the set<DAGNode*> source into set<DAGNode*> dest
	    void copySet(set<DAGNode*> &dest, set<DAGNode*> source);


	    // Return true if the LMDD "f" is free of the variable "VarToElim";
	    // Return false otherwise
	    bool DDFreeOfVar(DDNode *f, string VarToElim);


	    // Returns true if DAGResolve (simplifyLMDD in CAV'11 work) is applicable
	    // i.e. returns true if set of LMEs E is non-empty or if there exists at least a single
	    // LMD at bit-level; returns false otherwise
	    bool DAGResolveApplicable(set<DAGNode*> &E, set<DAGNode*> &D, map<string, int> &WidthTable);


	    // Find \exists VarToElim. (/\ E /\ D) and convert the result to LMDD, and return the result 
	    DDNode* APResolveModified(set<DAGNode*> E, set<DAGNode*> D, string VarToElim, map<string, int> WidthTable, HashTable <string, DDNode*> *PtrTableForAPResolveModified);


	    // checks if \exists VarToElim. (/\ E /\ D) is already encountered
	    // return the result if yes; return NULL otherwise
	    DDNode* getEntryFromTableForAPResolveModified(string VarToElim, set<DAGNode*> E, set<DAGNode*> D, HashTable <string, DDNode*> *PtrTableForAPResolveModified);


	    // enter \exists VarToElim. (/\ E /\ D) ---> result into HashTable
	    void insertEntryIntoTableForAPResolveModified(string VarToElim, set<DAGNode*> E, set<DAGNode*> D, DDNode* value, HashTable <string, DDNode*> *PtrTableForAPResolveModified); 
	    

	    // return true if the coefficient of VarToElim in LME "equation" is odd; return false otherwise
	    bool coeffIsOdd(DAGNode *equation, string VarToElim);


	    // RemainingVarNames = VarNames without first entry
	    void createRemainingVarNames(list<string> VarNames, list<string> &RemainingVarNames);


	    // Select LME/bit-level LMD with the least coefficient for the variable to be eliminated, and return it
	    // Implements selectLME in CAV'11 work
	    DAGNode* selectEquationWithLeastCoefficientForVarToElimAdvanced(set<DAGNode*> &E, set<DAGNode*> &D, string VarToElim, map<string, int> &WidthTable);


	    // Implements All Path QE 
	    // Returns DDNode* for \exists VarsToElim. (f/\E/\D)
	    DDNode* QElimWithNoDP(set<string> VarsToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, map<string, int> WidthTable);


	    // Implements All Path QE 
	    // Returns DDNode* for \exists VarsToElim. f
	    DDNode* MultiVarQElimWithNoDPNoStrategy(list<string> VarsToElim, DDNode* f, map<string, int> WidthTable);


	    // Returns DDNode* for \exists VarsToElim. (/\E/\D)
	    DDNode* APResolveModifiedWithMultipleVariables(set<DAGNode*> E, set<DAGNode*> D, set<string> VarsToElim, map<string, int> WidthTable);

	    

	    // Show the APMap
	    void showAPMap();


	    // This function initializes the APMap before creating the LMDD from DAG
	    // This helps in smaller LMDDs
	    void initializeAPMap(list<DAGNode*> &APList, map<string, int> &WidthTable);

            
	    // Evaluate v1->getVal() op v2->getVal() if v1 and v2 point to terminal nodes;
	    // Else return -1
	    int evaluateOpOnTerminals(string op, DDNode *v1, DDNode *v2);
	    

	    // evaluate ITE if all operands are constants. Else return -1
            int evaluateITEOnTerminals(DDNode *condn, DDNode *then, DDNode *els);


	    // modified version of applyITE with context based simplification using implication check
            DDNode* applyITEWithImplicationCheck(DDNode* condn, DDNode* then, DDNode* els, set<DAGNode*> E, set<DAGNode*> D, map<string, int> &WidthTable, set<DAGNode*> &Useful_Context, map<string, map<set<DAGNode*>, DDNode*> > *PtrLocalHashTable, map<string, DDNode*> *PtrLocalHashTable_Level_1);


	    // Version of apply with implication checks
            DDNode* applyWithImplicationCheck(string op, DDNode* v1, DDNode* v2, map<string, int> &WidthTable);


	    // Version of apply's internal with implication checks
            DDNode* applyWithImplicationCheckInternal(string op, DDNode* v1, DDNode* v2, map<string, int> &WidthTable);

	    
	    // Version of createITE with implication checks
            DDNode* createITEWithImplicationCheck(DDNode* condn, DDNode* then, DDNode* els, map<string, int> &WidthTable);


	    // Version of createITE's internal with implication checks
            DDNode* createITEWithImplicationCheckInternal(DDNode* condn, DDNode* then, DDNode* els, map<string, int> &WidthTable);


	    // check if E/\D/\u_AP is unsat using STP/yices
	    bool implicationCheck(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP, map<string, int> &WidthTable);


	    // Display the implication check /\E/\D => u_AP on a file
	    void showImplicationCheck(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP);


	    // Show f, E, and D
	    void showContext(DDNode *f, set<DAGNode*> E, set<DAGNode*> D);


	    // return size of the LMDD rooted at "dd"
	    int getSizeOfDD(DDNode *dd);


	    // Final version of simplifyLMDD (CAV'11 work)
	    // Returns simplified version of LMDD rooted at "dd" 
	    DDNode*  DagResolveModifiedAdvancedWithDynamicVariableOrdering(DDNode *dd, DAGNode *equation, string VarToElim, map<string, int> WidthTable);


	    // Function which places NewPredicate next to MyPredicate
	    void dynamicOrdering(DAGNode *MyPredicate, DAGNode *NewPredicate);


	    // Increments the index of all LMEs above the given index
	    void incrementIndexOfLMEsInAPMAPAboveGivenIndex(int MyIndex);


	    // Function to display input to APResolve
	    void showContextOfAPResolve(string VarToElim, set<DAGNode*> E, set<DAGNode*> D);


	    // function to call yices with time recording
            void callYicesForImplicationCheck();


	    // Function to create a DD from a DAG without elimination of inconsistent paths
            // Note that the hash table used here is global
	    DDNode* createDDFromDAGWithoutImplicationCheck(DAGNode *dag, map<string, int> &WidthTable);


	    // Function QE1_LMDD in CAV'11 work without elimination of inconsistent paths
	    // Returns the LMDD for \exists VarToElim. (f/\E/\D)
            DDNode* QElimWithDPModifiedWithoutImplicationCheck(string VarToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, map<string, int> WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified);


	    // Function for elimination of inconsistent paths in the DD rooted at "dd"
	    // Returns the DD after elimination of inconsistent paths
            DDNode* eliminateInconsistentPaths(DDNode* dd, map<string, int> &WidthTable);

	    
	    // Internal function called by DDManager::eliminateInconsistentPaths
	    // Returns the DD after elimination of inconsistent paths 
	    // which is reduced in the caller function DDManager::eliminateInconsistentPaths
            DDNode* eliminateInconsistentPathsInternal(DDNode* v1, DDNode* v2, set<DAGNode*> E, set<DAGNode*> D, map<string, int> &WidthTable, set<DAGNode*> &Useful_Context, map<string, map<set<DAGNode*>, DDNode*> > *PtrLocalHashTable, map<string, DDNode*> *PtrLocalHashTable_Level_1);


	    // FUNCTIONS FOR UNBOUNDED MODEL CHECKING USING LMDDs



	    // create and return a dd which is isomorphic to the argument dd such that 
	    // in place of each LME e of the argument dd, we need e with deltas replaced according to the map
	    DDNode*  createShiftedDD(DDNode *dd, map<int, int> &DeltaMap, map<string, int> &WidthTable);


	    // Internal function called by DDManager::createShiftedDD to
	    // create and return shifted LMDD based on the DeltaMap
	    DDNode*  createShiftedDDInternal(DDNode *dd, map<int, int> &DeltaMap, map<string, int> &WidthTable, map<DDNode*, DDNode*> *PtrCreateShiftedDDTable);


	    // Get the support of the LMDD rooted at "v" in "VarsPresent" 
	    void getDDNames(DDNode *v, set<string> &VarsPresent);


	    // Finds the variables to be eliminated from an LMDD for iterative squaring computation.
	    // It is done by finding the support of the LMDD, and then finding the variables from them 
	    // such that their delta times are 1
	    void getVarsToElimInGetTransitiveClosure(DDNode* dd, set<string> &VarsToElim, int DeltaToEliminate);


	    // Get the transitive closure for the given transitive relation "TR" 
	    // for the number of times in "squaring_times"
	    DAGNode* getTransitiveClosure(DAGNode *PresentClosure_Dag, int squaring_times, map<string, int> &WidthTable,  string infilename);


	    // Push back a new LME "NewPredicate" into the APMap 
	    void pushBackPredicateIntoAPMap(DAGNode *NewPredicate);


	    // Get the set of LMEs in a LMDD
	    void getPredicates(DDNode *v, set<DAGNode*> &PredicatesPresent);


	    // Let we want to create a shifted clone of LMDD rooted at "dd" according to DeltaMap, 
	    // using the function DDManager::createShiftedDD. Then we need to insert the shifted 
	    // predicates of "dd" in proper places in APMap to get smaller LMDD sizes. This function
	    // achieves this.
	    void insertPredicatesIntoAPMapIncreateShiftedDD(DDNode *dd, map<int, int> &DeltaMap, map<string, int> &WidthTable);



	    // check if E/\D => u_AP is valid using a layered scheme
	    // Layers include: Hashing, Overlap checking, Simulation, QE, and SMT-Solver call
            bool callImplicationCheck(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP, DAGNode *Negated_u_AP, map<string, int> &WidthTable);



	    // returns true if Set1 is subset of Set2; false otherwise
	    // Set1 is subset of Set2 <=> (Set1 \ Set2 = empty set)
	    bool isSubSet(set<DAGNode*> &Set1, set<DAGNode*> &Set2);



	    // Print the APMap in a file "apmap.txt"
	    void printAPMap();



	    // Print the status of the implication check cache
	    void ImplicationCheckCacheStatus();


	    // function to call boolector with time recording	    
	    void callBoolectorForImplicationCheck();



	    // checks if E/\D/\u_AP is unsat by QE using Layer1 and Layer2 (Implemented in 
	    // function qEliminatorForSolving in Eliminator.cpp)
	    // Returns 'u' for unsat, 's' for sat, 'x' for don't know
            char implicationCheckByExQuantifierElimination(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP, map<string, int> &WidthTable);



	    // checks if E/\D/\~u_AP is sat by seeing if there is overlap of variables between E/\D and ~u_AP. 
	    // If there is no overlap, return 's' for sat, else return 'x' for don't know
            char implicationCheckByOverlapChecking(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP);


	    // Show the context from the cache tree
	    void showContextOfCacheTree();


	    // Function to check if the present context is the same as the path
	    void checkContext(set<DAGNode*> E, set<DAGNode*> D);


	    // Function to check if two sets are equal
	    bool setsEqual(set<DAGNode*> &SetA, set<DAGNode*> &SetB);


	    // Function to show the predicates in a dd 
	    void showPredicates(DDNode *dd, string WhoAmI);


	    // Function to show the predicates common between dd1 and dd2
	    void showCommonPredicates(DDNode *dd1, DDNode *dd2, string WhoisDD1, string WhoisDD2);


	    // Reorder the LMEs in APList to help in smaller LMDD sizes
	    void reorderingBasedOnSharing(list<DAGNode*> &APList, map<string, int> &WidthTable, map<int, int> &DeltaMapForFindingSharedMEs);


	    // Return true if common predicates exist between dd1 and dd2
	    bool commonPredicatesExists(DDNode *dd1, DDNode *dd2);


	    // Function which is exactly same as createShiftedDD except that the LMEs 
	    // which will get shared with the next frame will be pushed down in the order
	    DDNode* createShiftedDD_With_ReorderingBasedOnSharing_Enabled(DDNode *dd, map<int, int> &DeltaMap, map<string, int> &WidthTable);


	    // This function is exactly same as insertPredicatesIntoAPMapIncreateShiftedDD except that while inserting 
	    // the newly created LMEs, it pushes the shared LMEs down when the flag "reorderingBasedOnSharing_Enabled" is true
	    void insertPredicatesIntoAPMapIncreateShiftedDD_With_ReorderingBasedOnSharing_Enabled(DDNode *dd, map<int, int> &DeltaMap, map<string, int> &WidthTable);



	    // create DeltaMap for finding shared LMEs
	    // Used in the function DDManager::insertPredicatesIntoAPMapIncreateShiftedDD_With_ReorderingBasedOnSharing_Enabled
            void createDeltaMapForFindingSharedLMEs(map<int, int> &DeltaMap, map<int, int> &DeltaMapForFindingSharedLMEs);

	     
	    
	    // Call QE_LMC to obtain \exists VarsToElim. (E /\ D), and convert it to LMDD
	    DDNode* APResolveModifiedWithMultipleVariablesUsingLMA(set<DAGNode*> E, set<DAGNode*> D, set<string> VarsToElim, map<string, int> WidthTable);
	     

	    
	    // Functions to print information about dd blowup in createITE
	     void printBlowupInApply(string op, int s1,int s2,int s3,int s);


	     // Functions to print information about dd blowup in apply
	     void printBlowupInApply(string op, int s1,int s2,int s);

	     
	     // returns true if fixpoint is reached in iterative squaring; false otherwise
	     bool fixpointReached(DDNode *old_dd, DDNode *new_dd, map<string, int> &WidthTable);


	     
	     // Trim down E and D to useful context 
	     // Useful context has only LMEs and LMDs of #bits = #bits in u_AP
	     void trimContext(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP, set<DAGNode*> &Trimmed_E, set<DAGNode*> &Trimmed_D, map<string, int> &WidthTable);
	     

	     // Set the global variable SignalClass
	     void findSignalClass(list<DAGNode*> &APList);


	     // Given "SignalsWithDelta", get "Signals" which contain 
	     // variables in "SignalsWithDelta" without the delta field
	     void createDeltaTrimmedNames(set<string> &SignalsWithDelta, set<string> &Signals);


	     // Find the index of the set in SignalClass whose contents 
	     // share some variables with "Signals", and return it 
	     int findIntersectingSet(set<string> &Signals);


	     // show the global variable "SignalClass"
	     void showSignalClass();


	     // return true if "Set1" intersection "Set2" is non-empty; return false otherwise
	     bool intersectionExists(set<string> &Set1, set<string> &Set2);


	     // Set the global variable "SignalEquivalenceClass" from the global variable "SignalClass"
	     void createSignalEquivalenceClass();


	     // show the global variable "SignalEquivalenceClass"
	     void showSignalEquivalenceClass();

	     
	     // Find the equivalence class of the given LME/LMD. 
	     // Equivalence class of the LME/LMD is the equivalence class of any variable in it
	     int findEquivalenceClass(DAGNode *Constraint);


	     // Trim down E and D to useful context based on equivalence classes
	     void trimContextAdvanced(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP, set<DAGNode*> &Trimmed_E, set<DAGNode*> &Trimmed_D);


	     // Function to show the useful part of context in implication checks in apply
	     void showUsefulpartInApplyWithImpeck(string op, DDNode *v1, DDNode *v2, set<DAGNode*> &Useful_Context, DDNode *u);


	     // Display the implication check /\E/\D => u_AP on screen
	     void showImplicationCheckModified(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP);


	     // Function to get entry from the local hash table of ApplyWithImpCheck
	     // returns the hit entry if hit; returns NULL in case of miss
	     DDNode* getEntryFromLocalHashTableOfApplyWithImpCheck(map< pair< pair<DDNode*, DDNode*>, set<DAGNode*> >,  DDNode*> *PtrLocalHashTable, DDNode *v1, DDNode *v2, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &Useful_Context);


	     // Function to show the local hash table of ApplyWithImpCheck
	     void showLocalHashTableOfApplyWithImpCheck(map< pair< pair<DDNode*, DDNode*>, set<DAGNode*> >,  DDNode*> *PtrLocalHashTable);


	    // Another version of function to show the useful part of context in implication checks in apply 
	     void showContextInApplyWithImpCheck(string op, DDNode *v1, DDNode *v2, set<DAGNode*> &E, set<DAGNode*> &D);


	     // Function to get entry from the local hash table of EliminateInconsistentPaths
	     // returns the hit entry if hit; returns NULL in case of miss
	     DDNode* getEntryFromLocalHashTableOfEliminateInconsistentPaths(map< pair< DDNode*, set<DAGNode*> >,  DDNode*> *PtrLocalHashTable, DDNode *v1, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &Useful_Context);


	     // Function to get entry from the local hash table of ApplyITEWithImpCheck
	     // returns the hit entry if hit; returns NULL in case of miss
	     DDNode* getEntryFromLocalHashTableOfApplyITEWithImpCheck(map< pair< pair< pair<DDNode*, DDNode*>, DDNode*> , set<DAGNode*> >,  DDNode*> *PtrLocalHashTable, DDNode *condn, DDNode *then, DDNode *els, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &Useful_Context);


	     // Function to show the "context" of calling the implication check and the implied LMC "u_AP"
	     void showImplicationCheckContext(set<DAGNode*> &Context, DAGNode *u_AP);


	     // Version of copySet where the second argument is passed by reference
	     void copySetNew(set<DAGNode*> &dest, set<DAGNode*> &source);


	     // Another version of function to show the local hash table of ApplyWithImpCheck
	     void showLocalHashTableForApplyWithImpCheck(map< pair< pair<DDNode*, DDNode*>, set<DAGNode*> >,  DDNode*> *PtrLocalHashTable);


	     // The internal function called by applyWithImplicationCheck
	     // (uses with STL map for level-1 cache) 
             DDNode* applyStepWithImplicationCheck(string op, DDNode* v1, DDNode* v2, set<DAGNode*> E, set<DAGNode*> D, map<string, int> &WidthTable, set<DAGNode*> &Useful_Context, map<string, map<set<DAGNode*>, DDNode*> > *PtrLocalHashTable, map<string, DDNode*> *PtrLocalHashTable_Level_1);


	     // Trim down E and D to useful context very eagerly 
	     // The trimmed context may be an over-approximation of the original context
	     void trimContextEager(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP, set<DAGNode*> &Trimmed_E, set<DAGNode*> &Trimmed_D, map<string, int> &WidthTable);


	     // show the context
	     void showLMDEContext(set<DAGNode*> &Context);


	     // show a set of LMEs and a set of LMDs
	     void showLMEAndLMDContext(set<DAGNode*> &E, set<DAGNode*> &D);


	     // get entry from the efficient local hash table for binary operation
	     // return NULL if there is no entry
	     DDNode* getEntryFromEfficientLocalHashTableBinaryOperation(map<string, map<set<DAGNode*>, DDNode*> > *PtrLocalHashTable, DDNode *v1, DDNode *v2, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &Useful_Context);


	     // get entry from the efficient local hash table for ternary operation
	     // return NULL if there is no entry 
	     DDNode* getEntryFromEfficientLocalHashTableTernaryOperation(map<string, map<set<DAGNode*>, DDNode*> > *PtrLocalHashTable, DDNode *condn, DDNode *then, DDNode *els, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &Useful_Context);


	     // insert into the efficient local hash table for binary operation 
	     void insertIntoEfficientLocalHashTableBinaryOperation(map<string, map<set<DAGNode*>, DDNode*> > *PtrLocalHashTable, DDNode *v1, DDNode *v2, set<DAGNode*> &Useful_Context, DDNode *result);


	     // insert into the efficient local hash table for ternary operation
	     void insertIntoEfficientLocalHashTableTernaryOperation(map<string, map<set<DAGNode*>, DDNode*> > *PtrLocalHashTable, DDNode *condn, DDNode *then, DDNode *els, set<DAGNode*> &Useful_Context, DDNode *result);



	     // Function to trim down variables to be eliminated
             void trimVarSetToElim(set<string> &VarSetToElim);


	     // Trim down set of LMEs E and set of LMDs D to useful context : better version 
	     void trimContextStrategyFour(set<DAGNode*> E, set<DAGNode*> D, DAGNode *u_AP, set<DAGNode*> &Trimmed_E, set<DAGNode*> &Trimmed_D, map<string, int> &WidthTable);



	     // FUNCTIONS FOR IMPLEMENTING THE DIFFERENT ALGORITHMS COMPARED IN THE CAV'11 PAPER



	    // Copy SourceList to DestList
	    void copyList(list<DAGNode*> &DestList, list<DAGNode*> &SourceList);


	    // To change APList based on VarsToElim
	    // Note that APList determines the order of APs in APMap, which has a crucial impact on DD sizes
	    void modifyAPListBasedOnVarsToElim(list<DAGNode*> &APList, set<string> &VarsToElim);


	    // Function All_Path_QElim_With_Simplifications 
	    DDNode* All_Path_QElim_With_Simplifications(list<string> VarsToElim, DDNode* f, map<string, int> WidthTable);


	    // Internal function called by All_Path_QElim_With_Simplifications 
	    DDNode* All_Path_QElim_With_Simplifications_Internal(set<string> VarsToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, map<string, int> WidthTable, HashTable <string, DDNode*> *PtrTableForAPResolveModified, HashTable <string, DDNode*> *PtrTableForAll_Path_QElim_With_Simplifications_Internal);


	    // simplifyLMDD for the procedure All_Path_QElim_With_Simplifications
	    DDNode* MultiVarDAGQElim(DDNode *f, set<DAGNode*> &E, set<DAGNode*> &D, set<string> &VarsToElim, map<string, int> WidthTable, HashTable <string, DDNode*> *PtrTableForAPResolveModified);


	    // Function to get entry from the hash table for version of QuaLMoDE, which 
	    // tries to eliminate all the variables in a single shot (called All_Path_QElim_With_Simplifications)
	    DDNode* getEntryFromTableForAll_Path_QElim_With_Simplifications_Internal(set<string> VarsToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, HashTable <string, DDNode*> *PtrTableForAll_Path_QElim_With_Simplifications_Internal);


	    // Function to insert an entry into the hash table for version of QuaLMoDE, which 
	    // tries to eliminate all the variables in a single shot (called All_Path_QElim_With_Simplifications)
	    void insertEntryIntoTableForAll_Path_QElim_With_Simplifications_Internal(set<string> VarsToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, DDNode* value, HashTable <string, DDNode*> *PtrTableForAll_Path_QElim_With_Simplifications_Internal);


	   // copy set of strings in source into destination
           void copyStringSet(set<string> &dest, set<string> source);




           // FUNCTIONS FOR LMDD:BDD IMPLEMENTATION


	   // Function which calls QE1_LMDD for the LMDD:BDD implementation
           // Performs \exists VarToElim. f where f is a LMDD:BDD
	   DDNode* callFastQElimBlasting(string VarToElim, DDNode* f, map<string, int> WidthTable);

           
	   // Function QuaLMoDE for the LMDD:BDD implementation
	   // Performs \exists VarsToElim. f where f is a LMDD:BDD
	   DDNode* QuaLMoDEWithBlasting(list<string> VarsToElim, DDNode* f, map<string, int> WidthTable);


	   // Returns true if "f" which is LMDD:BDD is free of VarToElim; returns false otherwise
	   bool DDWithBDDFreeOfVar(DDNode *f, string VarToElim);


	   // The function simplifyLMDD for the LMDD:BDD implementation
	   DDNode*  DagResolveModifiedAdvancedWithDynamicVariableOrderingBlasting(DDNode *dd, DAGNode *equation, string VarToElim, map<string, int> WidthTable);


           // Function to insert entries into the hash table for the 
	   // function QE1_LMDD for the LMDD:BDD implementation
	   void insertEntryIntoTableForFastQElimBlasting(string VarToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, set<DdNode*> &BDDsInContext, DDNode* value, HashTable <string, DDNode*> *PtrTableForFastQElimBlasting);



           
           // Function to get entry from the hash table for the 
	   // function DDManager::APQElimBlasting for the LMDD:BDD implementation
           // DDManager::APQElimBlasting performs \exists VarToElim. (E /\ D /\ BDDsInContext)
	   DDNode* getEntryFromTableForAPQElimBlasting(string VarToElim, set<DAGNode*> E, set<DAGNode*> D, set<DdNode*> &BDDsInContext, HashTable <string, DDNode*> *PtrTableForAPQElimBlasting);



           
	   // Function to insert entries into the hash table for the 
	   // function DDManager::APQElimBlasting for the LMDD:BDD implementation
           // DDManager::APQElimBlasting performs \exists VarToElim. (E /\ D /\ BDDsInContext) 
	   void insertEntryIntoTableForAPQElimBlasting(string VarToElim, set<DAGNode*> E, set<DAGNode*> D, set<DdNode*> &BDDsInContext, DDNode* value, HashTable <string, DDNode*> *PtrTableForAPQElimBlasting);




	   // Performs \exists VarToElim. (E /\ D /\ BDDsInContext) 
           // Returns an LMDD:BDD as result
           // Used in the LMDD:BDD implementation
	   DDNode* APQElimBlasting(set<DAGNode*> E, set<DAGNode*> D, set<DdNode*> &BDDsInContext, string VarToElim, map<string, int> WidthTable, HashTable <string, DDNode*> *PtrTableForAPQElimBlasting);




           // Function to get entries from the hash table for the 
	   // function QE1_LMDD for the LMDD:BDD implementation
	   DDNode* getEntryFromTableForFastQElimBlasting(string VarToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, set<DdNode*> &BDDsInContext, HashTable <string, DDNode*> *PtrTableForFastQElimBlasting);




           // The function QE1_LMDD for the LMDD:BDD implementation
	   DDNode* FastQElimBlasting(string VarToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, set<DdNode*> &BDDsInContext, map<string, int> WidthTable, HashTable <string, DDNode*> *PtrTableForFastQElimBlasting, HashTable <string, DDNode*> *PtrTableForAPQElimBlasting);




           // Given "node" which is a propositional logic formula, and "VarSetToElim"  which is a set of variables,
	   // this function 1) creates a BDD for "node", 2) gets the indices of the variables to be eliminated, 
           // and 3) returns the BDD.
	   DdNode* createBDDInDDManager(DAGNode *node, map<DAGNode*, DdNode*> &DPTable, set<string> &VarSetToElim, set<int> &BooleanVarSetToElim);




           // Returns "BooleanVarSetToElim" as a cube
	   DdNode* createCubeBDDInDDManager(set<int> &BooleanVarSetToElim);




           // Given "node" which is a propositional logic formula, and "VarSetToElim"  which is a set of variables,
	   // this function returns the BDD for \exists VarSetToElim. node.
	   DdNode* quantifyUsingCUDDInDDManager(DAGNode *node, set<string> &VarSetToElim);




	   // Given "DAG_to_blast" which is a bv-logic formula, and "VarSetToElim"  which is a set of variables,
	   // this function performs \exists VarSetToElim. DAG_to_blast using bit-blasting + BDD
           DdNode* bitBlastAndQuantifyUsingCDDInDDManager(DAGNode *DAG_to_blast, set<string> VarSetToElim, map<string, int> WidthTable);




           // Get the support of the BDD node "node" in set "Support"
	   void getSupport(DdNode *node, set<string> &Support);
	   

 
           
           // Function internally called by DDManager::MultiVarQElimWithNoDPNoStrategyWithBlasting (which implements
	   // QBV_Solve) 
	  // Obtains \exists VarsToElim. (E/\D/\f) in "FinalResult"
           void QElimWithNoDPWithBlasting(set<string> VarsToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, map<string, int> WidthTable, DAGNode* &FinalResult);




	   // Function implementing QBV_Solve
	   // Obtains \exists VarsToElim. f in "FinalResult"
           void MultiVarQElimWithNoDPNoStrategyWithBlasting(list<string> VarsToElim, DDNode* f, map<string, int> WidthTable, DAGNode* &FinalResult);
         
 

	
          // Given a set of LMEs and LMDs, and a set of variables to be eliminated, 
	  // perform QE using GD Layer + bit-blasting + QE at bit-level. result is obtained in "FinalResult".
          // This implements BV_Solve function which was actually used in the CAV'11 experiments 
          void APResolveModifiedWithMultipleVariablesUsingLMAWithBlasting(set<DAGNode*> E, set<DAGNode*> D, set<string> VarsToElim, map<string, int> WidthTable, DAGNode* &FinalResult);




	  // Given an LME "Constraint" and a variable "Var",
	  // return true if the coefficient of "Var" in the LME is odd;
	  // return false otherwise
	  bool checkIfCoefficientForVariableForLMEIsOdd(DAGNode* Constraint, string Var, map<string, int> &WidthTable);




	  // Gets the set of variables with odd coefficients in LMEs in set "EasyVars"
	  void findVariablesWithOddCoefficients(set<DAGNode*> &E, map<string, int> &WidthTable, set<string> &Vars, set<string> &EasyVars);



          // Given a set of LMEs in "Constraints" and a variable "Var",
	  // return true if there exists an LME in "Constraints" such
	  // that the coefficient of "Var" in the LME is odd;
	  // return false otherwise
          bool checkIfOddConstraintExistsForVariable(set<DAGNode*> &Constraints, string Var, map<string, int> &WidthTable);



           
	
	// Given a set of constraints, and a set of variables to be eliminated, 
	// perform QE from the conjunction of constraints 
	// using bit-blasting + QE at bit-level. Result is returned
	// There is a similar function DDManager::qElimUsingBlasting, which is
	// exactly same as this function except that it takes only a single
	// dag node as input. 
	DAGNode* qElimHarderConstraints(set<DAGNode*> &Constraints, set<string> &VarSetToElim, map<string, int> &WidthTable);



	// Return DAG equivalent to the given BDD "resultDD" 
        DAGNode* synthesizeBVFormulaFromBDD(DdNode *resultDD, map<string, int> &WidthTable);



	// Function to create a DAG from a BDD 
        DAGNode* createDAGFromBDD(DdNode *dd, map<string, int> &WidthTable);



  	// Internal function called by DDManager::createDAGFromBDD
        DAGNode* createDAGFromBDDStep(DdNode *dd, HashTable <string, DAGNode*> *PtrMapForDAGFromBDD, map<string, int> &WidthTable);



	// Given BDD node "dd", return it as a selection expression
        DAGNode* getCondition(DdNode *dd, map<string, int> &WidthTable);



 	// Given "root" which is a conjunction of LMCs, return \exists VarsToElim. root.
	// Use the given strategy for QE
	DAGNode* QELIM_Conjunction_level(DAGNode *root, set<string> &VarsToElim, map<string, int> &WidthTable, string qelim_conj_level_strategy, string InFileName);


	// Function to observe the constraints given to the function
	// DDManager::QELIM_Conjunction_level
	void observeConstraints(set<DAGNode*> E, set<DAGNode*> D, set<string> VarsToElim, map<string, int> WidthTable,  int &number_of_vars_only_even, int &num_muls, int &num_adds);


	// Find the # of bvmul and # of bvadd nodes in the DAG rooted at "node"
	void findMulAdds(DAGNode *node, int &mul, int &add);


	// Internal function called by DDManager::findMulAdds
	void findMulAddsInternal(DAGNode *node, int &mul, int &add, set<DAGNode*> &MyMap);
	

	// Show the APMap on screen
	void printAPMapOnScreen();

	
	// Return true if /\E /\ D is unsat; false otherwise
	// Uses STP	
        bool ThUnsatInSMTLibFormat(set<DAGNode*> E, set<DAGNode*> D, map<string, int> WidthTable);



	// function to call STP with time recording
        void callSTPForImplicationCheck();




	// Given a dag rooted at "initialDAG", and a set of variables to be eliminated, 
	// perform QE from "initialDAG"
	// using bit-blasting + QE at bit-level. Result is returned
	// There is a similar function DDManager::qElimHarderConstraints, which is
	// exactly same as this function except that it takes a set of dag nodes as 
	// input which are internally conjuncted and the same processing is done.
        DAGNode* qElimUsingBlasting(DAGNode* initialDAG, set<string> &VarSetToElim, map<string, int> &WidthTable);
        
        
        
        // Functions for QE from LMDDs involving LMEs, LMDs, and LMIs
        
        
        
        // Returns \exists VarsToElim. f as DDNode* where f is an LMDD
        // involving LMEs, LMDs, and LMIs
        DDNode* QuaLMoDE_WithLMISupport(list<string> VarsToElim, DDNode* f, map<string, int> &WidthTable);
        
        
        
        // Calls the function QElim_WithLMISupport
        // Returns the LMDD for \exists VarToElim. f.
        DDNode* callQElim_WithLMISupport(string VarToElim, DDNode* f, map<string, int> &WidthTable, int project_depth);
        
        
        
        
        // Check if the instance \exists VarToElim. (f /\ E/\ D/\I) is already encountered
        // If yes, return the result; NULL otherwise
        DDNode* getEntryFromTableForQElimModified_WithLMISupport(string VarToElim, DDNode* f, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, HashTable <string, DDNode*> *PtrTableForQElimModified);




        // Return true if /\ E /\ D /\ I is unsat; false otherwise
        // Uses STP/yices
        bool ThUnsat(set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, map<string, int> &WidthTable);

        
        
        
        // Enter \exists VarToElim. (f /\ E /\ D /\ I) ---> result into Hash Table
        void insertEntryIntoTableForQElimModified_WithLMISupport(string VarToElim, DDNode*f, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, DDNode* value, HashTable <string, DDNode*> *PtrTableForQElimModified);

        
        
        // Show f, E, D, and I
        void showContext(DDNode *f, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I);
        
        
        
        // Function to compute the LMDD for \exists VarToElim. (f/\E/\D/\I)
        // where f is an LMDD involving LMEs, LMDs, and LMIs
        DDNode* QElim_WithLMISupport(string VarToElim, DDNode* f, set<DAGNode*> E, set<DAGNode*> D, set<DAGNode*> I, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);


        
        // Find \exists VarToElim. (/\ E /\ D /\ I), convert the result to LMDD, store the result in hash table, and return the result
        DDNode* callProjectReturningLMDD(set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, string VarToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);
                

        
        // Find \exists VarToElim. (/\ E /\ D /\ I), convert the result to LMDD, and return the result
        DDNode* ProjectReturningLMDD(set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, string VarToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);

        
        
        // checks if \exists VarToElim. (/\ E /\ D /\ I) is already encountered
        // return the result if yes; return NULL otherwise
        DDNode* getEntryFromTableForAPResolveModified_WithLMISupport(string VarToElim, set<DAGNode*> &E, set<DAGNode*> &D,  set<DAGNode*> &I, HashTable <string, DDNode*> *PtrTableForAPResolveModified);
        
        
        // enter \exists VarToElim. (/\ E /\ D /\ I) ---> result into HashTable
        void insertEntryIntoTableForAPResolveModified_WithLMISupport(string VarToElim, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, DDNode* value, HashTable <string, DDNode*> *PtrTableForAPResolveModified);


        
         //  Version of  call_applyLMILayer4 which (1) returns a DDNode* and (2) eliminates a single variable
        DDNode* call_applyLMILayer4_ReturningLMDD(vector<DAGNode*> &Constraints, string VarToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth, unsigned long long int &FMTime, unsigned long long int &NormalizationTime, unsigned long long int &MonTime);

        
        
        // Version of applyLMILayer4 which (1) handles only one variable and (2) returns DDNode*
        DDNode* applyLMILayer4_ReturningLMDD(DAGNode* Phi, string VarToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth, unsigned long long int &FMTime, unsigned long long int &NormalizationTime, unsigned long long int &MonTime);

 
        
        // simplifyLMDD with LMI Support
        DDNode*  DagResolveModifiedAdvancedWithDynamicVariableOrdering_WithLMISupport(DDNode *dd, DAGNode *equation, string VarToElim, map<string, int> &WidthTable);

        
        // Version of DDFreeOfVar with D.P. support
        bool DDFreeOfVar_WithDP(DDNode *dd, string VarToElim);
        
        
        // Function called by DDFreeOfVar_WithDP_Internal
        bool DDFreeOfVar_WithDP_Internal(DDNode *dd, string VarToElim, HashTable <string, bool> *PtrHTForDDFreeOfVar);
        
        // Function called by createDDFromDAGWithoutImplicationCheck
        DDNode* createDDFromDAGWithoutImplicationCheck_Internal(DAGNode *dag, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrMapForDDFromDAG);

        
        // Efficient version of findDropVarsStep
        void findDropVarsStepEfficient(DDNode *v, map<string, int> &VarsToElimCount, HashTable <string, bool> *PtrDropVarsHT);
        
        
        // Returns an LMDD g such that g \vee PartialResult_In_LMDDWithMonniauxTypeSimplifications \equiv \exists VarsToElim. f
        // f is an LMDD involving LMEs, LMDs, and LMIs
        DDNode* QuaLMoDE_WithLMISupport_WithMonniauxTypeSimplifications(list<string> VarsToElim, DDNode* f, map<string, int> &WidthTable);
        
        
        // Calls the function QElim_WithLMISupport_WithMonniauxTypeSimplifications
        // Returns an LMDD g such that g with PartialResult_In_LMDDWithMonniauxTypeSimplifications is \exists VarToElim. f
        DDNode* callQElim_WithLMISupport_WithMonniauxTypeSimplifications(set<string> &VarSetToElim, string VarToElim, DDNode* f, map<string, int> &WidthTable, int project_depth);
        
        
        
             
        // calls Project
        // Dynamic programming is not used, because,
        // Constraints are the set of all constraints encountered on a path of an LMDD, and
        // 1) There cannot be two identical paths in an LMDD and
        // 2) Our algorithm will not call Project on the same path again
        DAGNode* callProject(set<DAGNode*> &Constraints, set<string> &VarsToElim, map<string, int> &WidthTable, int project_depth);

        
              
        
        // Returns an LMDD g such that g with PartialResult_In_LMDDWithMonniauxTypeSimplifications is \exists VarToElim. f
        DDNode* call_LMDD_Monniaux_SingleVar(set<string> &VarSetToElim, string VarToElim, DDNode* f, set<DAGNode*> &Neg_x_Context, set<DAGNode*> &Local_Neg_x_Context, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);
        
        
        
        DDNode* LMDD_Monniaux_SingleVar(set<string> &VarSetToElim, string VarToElim, DDNode* f, set<DAGNode*> Neg_x_Context, set<DAGNode*> Local_Neg_x_Context, set<DAGNode*> E, set<DAGNode*> D, set<DAGNode*> I, map<string, int> &WidthTable, map<string, string> &Model_Of_SatCondition, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);


        // Update the given context by traversing the LMDD f through the path guided by
        // assignment in Model_In_LMDDWithMonniauxTypeSimplifications
        void updateContextFromGivenAssignment(DDNode* f, map<string, string> &Model_Of_SatCondition, map<string, int> &WidthTable, set<DAGNode*> &Context);

        
        // Used in LMDD+Monniaux style QE
        // Checks if the truncation achieved by Monniaux in LMDD+Monniaux
        // calls is insufficient (returns true) or sufficient (returns false)
        bool insufficientTruncationInLMDDWithMonniaux();
        
        
        // Function to try Monniaux on paths of LMDD current_root_LMDD_node_in_lmdd_with_monniaux
        void MonniauxOnLMDDPaths(set<string> &VarSetToElim,  map<string, int> &WidthTable, int project_depth);

        
        // call QE using path based strategy with both Monniaux and LMDD type simplifications turned on
        DDNode* callpathBasedQEStrategy_With_LMDD_Monniaux_Simplifications(set<string> &VarSetToElim, string VarToElim, DDNode* f, map<string, int> &WidthTable, int project_depth);

        
        
        //QE using path based strategy with both Monniaux and LMDD type simplifications turned on
        DDNode* pathBasedQEStrategy_With_LMDD_Monniaux_Simplifications(set<string> &VarSetToElim, string VarToElim, DDNode* f, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);

        
        //Show the present DD based path
        void showDDPath(vector< vector< DDNode*> > &CurrentPath);
        
        
        // Obtain the Path by traversing the LMDD f through the path guided by
        // assignment in Model_Of_SatCondition
        void obtainPathFromGivenAssignment(DDNode* f, map<string, string> &Model_Of_SatCondition, map<string, int> &WidthTable,  vector< vector< DDNode*> > &CurrentPath);

        
        // select the QE strategy to be chosen
        string selectStrategy(DDNode* f, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, map<string, int> &WidthTable, string VarToElim, set<string> &VarsToElim);
        
       
        //Extend CurrentPath with PartialPath
        void extendPath(vector< vector<DDNode*> > &CurrentPath, vector< vector<DDNode*> > &PartialPath);
        
        
        //Obtain context from path
        void obtainContextFromPath(vector< vector<DDNode*> > &CurrentPath, DDNode* h, set<DAGNode*>  &E, set<DAGNode*>  &D, set<DAGNode*>  &I, set<DAGNode*>  &Neg_x, string VarToElim);
        
        
        //Show the problem instance
        void showProblemInstance(DDNode* h, set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, set<DAGNode*> &Neg_x);


        // Obtain the Path by traversing the LMDD f through the path guided by
        // assignment in Model_Of_SatCondition only upto the point where LME
        // based simplification is possible.
        void obtainPathFromGivenAssignmentUpToPoint(DDNode* f, map<string, string> &Model_Of_SatCondition, map<string, int> &WidthTable,  vector< vector< DDNode*> > &CurrentPath, string VarToElim, bool parent_is_lme);

        
        // check if DAGResolve is applicable using this constraint
        bool DAGResolveApplicableUsingConstraint(DAGNode* C, string VarToElim, map<string, int> &WidthTable);
        
        // Returns the number of nodes in the DD with the variable in support
        int findNumberOfNodesWithVarInSupport(DDNode *v, string VarToElim);
        
      
        // Returns the level of the lowest LME with var. to elim
        int lowestLevelOfLMEWithVariable(DDNode* f, string VarToElim, int level);
        
        
        // Recreate the NonHashableNodesInCurrentPath by removing the DDNode* h
        void removeEntryFromNonHashableNodesInCurrentPath(set<DDNode*> &NonHashableNodesInCurrentPath, DDNode* NodeToRemove);
        
        
        //Enter all nodes in CurrentPath into NonHashableNodesInCurrentPath
        void updateNonHashableNodesInCurrentPath(set<DDNode*> &NonHashableNodesInCurrentPath, vector< vector< DDNode*> > &CurrentPath);


        //Show the set of DDNodes
        void showDDSet(string WhoamI, set<DDNode*> &NonHashableNodesInCurrentPath);
        
        
        // Update the given context by traversing the LMDD f through the path guided by
        // assignment in Model_In_LMDDWithMonniauxTypeSimplifications, and stop
        // at EasyNode, where EasyNode is 1) 1-node or 2) node free of VarToElim ,or
        // 3) node such that the occurances of VarToElim in it can be eliminated by an LME in Context
        void updateContextFromGivenAssignmentUptoEasyNode(DDNode* f, map<string, string> &Model_Of_SatCondition, map<string, int> &WidthTable, set<DAGNode*> &Context, DDNode* &EasyNode, string VarToElim);

        
        // Compute \exists VarsToElim. (f /\ Context) using LMDD approach
        // We should not create new hash tables. The existing hash tables
        // PtrTableForQElimModified and PtrTableForAPResolveModified
        // are passed as arguments
        DAGNode* QE_LMDD_ForMultipleVariables_UnderGivenContext(DDNode* f, set<DAGNode*> &Context, set<string> &VarSetToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);

        
        
        // Returns an LMDD g such that g \vee PartialResult_In_LMDDWithMonniauxTypeSimplifications \equiv \exists VarsToElim. f
        // f is an LMDD involving LMEs, LMDs, and LMIs
        // QE is done with LMDD based all-variable style QE combined with Monniaux type simplifications 
        DDNode* call_QuaLMoDE_WithLMISupport_WithMonniauxEnabledAllVariableStrategy(set<string> &VarsToElim, DDNode* f, map<string, int> &WidthTable);

        
        // The function called by call_QuaLMoDE_WithLMISupport_WithMonniauxEnabledAllVariableStrategy
        DDNode* QuaLMoDE_WithLMISupport_WithMonniauxEnabledAllVariableStrategy(set<string> VarSetToElim, DDNode* f, set<DAGNode*> C_X, set<DAGNode*> Neg_C_X, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForAPResolveModified, HashTable <string, DDNode*> *PtrTableForAllVarsQE, int project_depth, HashTable <string, DDNode*> *PtrPerVariableHT);

        
        
        // Check if the instance \exists VarSetToElim. (f /\ C_X) is already encountered
        // If yes, return the result; NULL otherwise
        DDNode* getEntryFromTableForAllVarsQE(set<string> &VarSetToElim, DDNode* f, set<DAGNode*> &C_X, HashTable <string, DDNode*> *PtrTableForAllVarsQE);
        
        
        
        // Return true if /\C_X is unsat; false otherwise
        // Uses STP/yices
        // Calls bool DDManager::ThUnsat(set<DAGNode*> &E, set<DAGNode*> &D, set<DAGNode*> &I, map<string, int> &WidthTable)
        // with empty dummy sets for D, I
        bool ThUnsat(set<DAGNode*> &C_X, map<string, int> &WidthTable);
        
        
        
        // Enter \exists VarSetToElim. (f /\ C_X) ---> result into Hash Table
        void insertEntryIntoTableForAllVarsQE(set<string> &VarSetToElim, DDNode* f, set<DAGNode*> &C_X, DDNode* result, HashTable <string, DDNode*> *PtrTableForAllVarsQE);

        
        
        // DDFreeOfVar_WithDP extended to a set of variables
        bool DDFreeOfVarSet_WithDP(DDNode *dd, set<string> &VarSetToElim);
        
        
        
        // Function called by DDFreeOfVarSet_WithDP
        bool DDFreeOfVarSet_WithDP_Internal(DDNode *dd, set<string> &VarSetToElim, HashTable <string, bool> *PtrHTForDDFreeOfVar);


        
        // Version of copySet which works on sets of strings
        void copySetNew(set<string> &dest, set<string> &source);
        
        
        
        // Given \exists X. (f \wedge C_{X}), this function returns
        // \exists X'. (f' \wedge C_{X'}) such that \exists X. (f \wedge C_{X}) \equiv \exists X'. (f' \wedge C_{X'})
        // where X' \subseteq X. The variables in X\X' are variables such that they can be 
        // eliminated easily from the LMDD f.
        void getSimplifiedInstance(DDNode* f, set<DAGNode*> &C_X, set<string> &VarSetToElim, DDNode* &Simplified_f, set<DAGNode*> &Simplified_C_X, set<string> &Simplified_VarSetToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForAllVarsQE, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth, HashTable <string, DDNode*> *PtrPerVariableHT);

        
        
        
        // Find \exists VarSetToElim. (/\ Constraints), convert the result to LMDD, store the result in hash table, and return the result
        DDNode* callProjectReturningLMDDForMultipleVariables(set<DAGNode*> &Constraints, set<string> &VarSetToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForAllVarsQE, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);
        
        
        
        // checks if \exists VarSetToElim. (/\ Constraints) is already encountered
        // return the result if yes; return NULL otherwise
        DDNode* getEntryFromTableForAPResolveModified_WithLMISupport_ForMultipleVariables(set<string> &VarSetToElim, set<DAGNode*> &Constraints, HashTable <string, DDNode*> *PtrTableForAPResolveModified);
        
        
        
        // Enter  \exists VarSetToElim. (/\ Constraints) ---> result into HashTable
        void insertEntryIntoTableForAPResolveModified_WithLMISupport_ForMultipleVariables(set<string> &VarSetToElim, set<DAGNode*> &Constraints, DDNode* value, HashTable <string, DDNode*> *PtrTableForAPResolveModified);


        //Function to get entry from the per variable hash table
        DDNode* getEntryFromPerVariableHT(DDNode* dd, DAGNode* LME, string VarToElim, HashTable <string, DDNode*> *PtrPerVariableHT);
        
        
        
        //Function to insert entry into the per variable hash table
        DDNode* insertEntryIntoPerVariableHT(DDNode* dd, DAGNode* LME, string VarToElim, DDNode* value, HashTable <string, DDNode*> *PtrPerVariableHT);


        // Function which performs \exists VarSetToElim. (f) by first
        // conversion of \exists VarSetToElim.(f) into 
        // \exists VarSetToElim. (f_1 /\ C_1) \/ .... \/ \exists VarSetToElim. (f_n /\ C_n)
        // and solving each of them using appropriate QE strategy
        DDNode* conversionToDisjunctionOfTailedTrianglesFollowedByQE(set<string> &VarSetToElim, DDNode* f, map<string, int> &WidthTable);
        
        
        // Function to convert \exists VarSetToElim.(f) into 
        // \exists VarSetToElim. (f_1 /\ C_1) \/ .... \/ \exists VarSetToElim. (f_n /\ C_n)
        void convertToSimplifiedInstances(DDNode* f, set<DAGNode*> Context, vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances);
        
        
        // Obtain the # of paths containing proper LMEs with variables to be eliminated through the right branch in RightPathCount and
        // the # of paths containing proper LMEs with variables to be eliminated through the left branch in LeftPathCount
        void obtainPathCounts(DDNode* f, int &LeftPathCount, int &RightPathCount);
        
        
        // Show the simplified instances
        void showSimplifiedInstances(vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances);
        
        
        // Take each \exists X. (C_i /\ f_i) from "SimplifiedInstances", compute it, and disjunct it to PartialResult_In_LMDDWithMonniauxTypeSimplifications
        DDNode* QEFromDisjunctionOfTailedTriangles(vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances, set<string> &VarSetToElim, map<string, int> &WidthTable);


        // Returns true if f is terminal false; true otherwise
        bool isFalseDD(DDNode* f);

        
        //Function to get entry from the global per variable hash table PerVariableHTForDagResolve_WithLMISupport
        DDNode* getEntryFromPerVariableHTForDagResolve_WithLMISupport(DDNode* dd, DAGNode* LME, string VarToElim);
        
        
        //Function to insert entry into the per variable global hash table PerVariableHTForDagResolve_WithLMISupport
        DDNode* insertEntryIntoPerVariableHTForDagResolve_WithLMISupport(DDNode* dd, DAGNode* LME, string VarToElim, DDNode* value);

        
        // Function which performs \exists VarSetToElim. (f) by 
        // conversion of \exists VarSetToElim.(f) into 
        // \exists VarSetToElim. (f_1 /\ C_1) \/ .... \/ \exists VarSetToElim. (f_n /\ C_n)
        // and solving each of them using appropriate QE strategy
        // with the following two additional features
        // 1) LME based simplification is applied as and when the LME is encountered and
        // 2) No explicit list of tailed triangles is created.
        DDNode* call_conversionToDisjunctionOfTailedTrianglesWithAggressiveLMEBasedSimplificationAndQE(set<string> &VarSetToElim, DDNode* f, map<string, int> &WidthTable);


        
        // The function called by call_conversionToDisjunctionOfTailedTrianglesWithAggressiveLMEBasedSimplificationAndQE
        void conversionToDisjunctionOfTailedTrianglesWithAggressiveLMEBasedSimplificationAndQE(set<string> VarSetToElim, DDNode* f, set<DAGNode*> C_X, set<DAGNode*> Neg_C_X, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForAPResolveModified, HashTable <string, DDNode*> *PtrTableForQElimModified, int project_depth);
        
        
        
        // Function to select between left and right edge depending on LME availability
       string selectEdgeDependingOnLMEAvailability(DDNode* f);
       
       
       // Version of QE_LMDD_ForMultipleVariables_UnderGivenContext such that there are no LMEs with vars to elim in the context
        DAGNode* QE_LMDD_ForMultipleVariables_UnderGivenContext_WhichIsFreeOfLMEs(DDNode* f, set<DAGNode*> &Context, set<string> &VarSetToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);
        
        
        // Version of getSimplifiedInstance such that the simplification is done using both LMEs and hash table entries
        void getSimplifiedInstanceUsingLMEsAndHashTableEntries(DDNode* f, set<DAGNode*> &Context, set<string> &VarSetToElim, DDNode* &Simplified_f, set<DAGNode*> &Simplified_C_X, set<string> &Simplified_VarSetToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForQElimModified, HashTable <string, DDNode*> *PtrTableForAPResolveModified, int project_depth);


        // returns true if we decide to check if \exists X. f/\Context is contained in PartialResult already through an SMT solver call; false otherwise
        bool SMTCallNeededInConversionToDisjunctionOfTailedTrianglesWithAggressiveLMEBasedSimplificationAndQE(DDNode* f);
        
        
        //Performs LME based simplification as a preprocessing step before doing the QE
        DDNode* callPerformLMEBasedSimplificationAsPreprocessor(set<string> &VarsToElim, DDNode* dd, map<string, int> &WidthTable);
        
        
        //Function called by callPerformLMEBasedSimplificationAsPreprocessor
        DDNode* performLMEBasedSimplificationAsPreprocessor(set<string> VarSetToElim, DDNode* f, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForPerformLMEBasedSimplificationAsPreprocessor);

        
        // Check if performLMEBasedSimplificationAsPreprocessor is already encountered on f
        // If yes, return the result; NULL otherwise
        DDNode* getEntryFromTableForLMEBasedSimplificationAsPreprocessor(DDNode* f, HashTable <string, DDNode*> *PtrTableForPerformLMEBasedSimplificationAsPreprocessor);

        
        // Enter f ---> result into performLMEBasedSimplificationAsPreprocessor's hash table
        void insertEntryIntoTableForLMEBasedSimplificationAsPreprocessor(DDNode* f, DDNode* value, HashTable <string, DDNode*> *PtrTableForPerformLMEBasedSimplificationAsPreprocessor);
        
        // return \exists VarToElim. (LMC \wedge LME) in simplifyLMDD
        DAGNode* simplifyLMCInsideSimplifyLMDD(DAGNode* MyPredicate, DAGNode* equation, string VarToElim, map<string, int> &WidthTable);
        
        // checks if \exists VarToElim. (LMC \wedge LMI) is already encountered
        // inside simplifyLMDD
        // return the result if yes; return NULL otherwise
        DAGNode* getEntryFromTableForSimplifyLMCInsideSimplifyLMDD(string VarToElim, set<DAGNode*> &Constraints);        
        
        // enter \exists VarToElim.(LMC \wedge LMI) ---> result into HashTable
        void insertEntryIntoTableForSimplifyLMCInsideSimplifyLMDD(string VarToElim, set<DAGNode*> &Constraints, DAGNode* value);
        
        
        // Version of obtainPathCounts which uses an SMT solver
        string obtainPathCountsUsingSMTSolver(DDNode* f, map<string, string> &Model_Of_SatCondition, map<string, int> &WidthTable);
        
        
        // Function to convert \exists VarSetToElim.(f) into 
        // \exists VarSetToElim. (f_1 /\ C_1) \/ .... \/ \exists VarSetToElim. (f_n /\ C_n)
        // by following a satisfiable path
        void convertToSimplifiedInstancesUsingSMTSolver(DDNode* f, set<DAGNode*> Context, vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances, map<string, string> &Model_Of_SatCondition, map<string, int> &WidthTable);

    
        // Function to convert \exists X.f into 
        // \bigvee \limits_{i=1}^n (\exists X. (f_i \wedge C_i)) such that
        // 1) \bigvee \limits_{i=1}^n (\exists X. (f_i \wedge C_i)) \equiv \exists X. f
        // 2) (SMTCallsCommittedInEagerConversionToDisjunctions >= MaximumNoOfSMTCallsInEagerConversionToDisjunctions) \vee 
        //     (size of all f_i's <= MaximumSizeOfTriangleInEagerConversionToDisjunctions)
        void convertToSimplifiedInstancesEager(DDNode* f, vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances);
        
        
        // Erase the entry at location i from SimplifiedInstances
        // Take each entry from SimplifiedInstances_New, concatenate ExistingContext with C_i of each,
        // and push back the tailed triangle at the end of SimplifiedInstances
        void recreateSimplifiedInstances(vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances, int i, vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances_New, set<DAGNode*> &ExistingContext);

        
        
        // Given an LMDD "dd", variable to eliminate "VarToElim", and equation "equation", this function replaces 
        // each occurance of "VarToElim" in the dd using layer1 and returns an LMDD which is structurally isomorphic to "dd"
        DDNode*  performSimplifyLMDDKeepingStructuralIsomorphism(DDNode *dd, DAGNode *equation, string VarToElim, map<string, int> &WidthTable);
        
        
        // Function internally called by DDManager::performSimplifyLMDDKeepingStructuralIsomorphism
        DDNode*  performSimplifyLMDDKeepingStructuralIsomorphismInternal(DDNode *dd, DAGNode *equation, string VarToElim, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrMapForPerformSimplifyLMDDKeepingStructuralIsomorphism);

        
        // Show sizes of the simplified instances
        void showSizesOfSimplifiedInstances(vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances);
        
        
        // Reverse the elements in SimplifiedInstances
        void obtainReversedSimplifiedInstances(vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances);
        
        
        // Version of DDManager::QEFromDisjunctionOfTailedTriangles, which
        // creates new disjuncts from an existing disjunct "dd" 
        // provided the number of SMT calls < threshold t_1 
        // and size of "dd" > threshold t_2 and QE from "dd" is required
        DDNode* QEFromDisjunctionOfTailedTrianglesWithDemandBasedDisjunctionCreation(vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances, set<string> &VarSetToElim, map<string, int> &WidthTable);
        
        
        
        // Recreate SimplifiedInstances in the following way:
        // Reverse SimplifiedInstances_New
        // Take each entry from SimplifiedInstances_New, concatenate ExistingContext with C_i of each,
        // and push back the tailed triangle at the end of recreated SimplifiedInstances
        // Push back the existing entries in SimplifiedInstances except the first one into recreated SimplifiedInstances
        void recreateSimplifiedInstancesForDemandBasedMode(vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances, vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances_New, set<DAGNode*> &ExistingContext);


        
               
        // Version of DDManager::conversionToDisjunctionOfTailedTrianglesFollowedByQE, which 
        // finds the tailed triangles using SMT solver calls    
        DDNode* conversionToDisjunctionOfTailedTrianglesFollowedByQEUsingSMTSolverCalls(set<string> &VarSetToElim, DDNode* f, map<string, int> &WidthTable);

        
        
        
        // Returns SimplifiedInstances and SimplifiedInstancesHierarchy such that
        // QE from the SimplifiedInstances based on SimplifiedInstancesHierarchy \equiv \exists X. f
        bool convertToSimplifiedInstancesBasedOnHierarchy(set<string> &VarSetToElim, DDNode* f, map<string, int> &WidthTable, vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances, map< int, vector<int> > &SimplifiedInstancesHierarchy, HashTable <string, DDNode*> *PtrTableForAPResolveModified, HashTable <string, DDNode*> *PtrTableForQElimModified, set<int> &BrokenTailedTriangles);
        
        
        
        // Variant of the function convertToSimplifiedInstancesUsingSMTSolver which forms tailed triangles based
        // on existing set of tailed triangles
        void convertToSimplifiedInstancesUsingSMTSolverBasedOnHierarchy(DDNode* f, set<DAGNode*> Context, vector< pair< set<DAGNode*>, DDNode* > > &LocalSimplifiedInstances, map<string, string> &Model_Of_SatCondition, map<string, int> &WidthTable, bool ParentTailedTriangleEncountered, int &ParentTailedTriangle, map< int, vector<int> > &SimplifiedInstancesHierarchy, vector< pair < set<DAGNode*>, DDNode* > > &SimplifiedInstances, set<int> &BrokenTailedTriangles);

        
        // Check if DDNode* f with context "Context" is already existing tailed triangle
        void obtainParentTriangle(DDNode* f, set<DAGNode*> &Context, vector< pair < set<DAGNode*>, DDNode* > > &SimplifiedInstances, bool &ParentTailedTriangleEncountered, int &ParentTailedTriangle, set<int> &BrokenTailedTriangles);
        
        
        // Update the hierarchy SimplifiedInstancesHierarchy 
        void updateHierarchy(int ParentTailedTriangle, int SimplifiedInstancesSize, int LocalSimplifiedInstancesSize,  map< int, vector<int> > &SimplifiedInstancesHierarchy);
        
        
        // Show the hierarchy SimplifiedInstancesHierarchy 
        void showHierarchy(map< int, vector<int> > &SimplifiedInstancesHierarchy);
        
        
        
        // Performs QE from SimplifiedInstances based on Hierarchy and returns the result in Pi
        void QEFromDisjunctionOfTailedTrianglesBasedOnHierarchy(set<string> &VarSetToElim, DDNode* f, map<string, int> &WidthTable, vector< pair < set<DAGNode*>, DDNode* > > &SimplifiedInstances, map< int, vector<int> > &SimplifiedInstancesHierarchy, HashTable <string, DDNode*> *PtrTableForAPResolveModified, HashTable <string, DDNode*> *PtrTableForQElimModified);
        
        
        //Reverse the given vector
        void reverseVector(vector<int> &MyVector);
        
        
        //Recreate TTriangleVector by inserting the content of NewTTriangleVector at position 0;
        void recreateTailedTriangleVector(vector<int> &TTriangleVector, vector<int> &NewTTriangleVector);
        
        
        // Decide if we want to proceed with the original tailed triangle or 
        // divided versions of the tailed triangle
        bool useDividedTailedTriangles();


        // Show the hierarchy SimplifiedInstancesHierarchy in the file ConversionToDisjunctionOfProblemsWithSMTSolverHierarchyFp
        void showHierarchyInFile(map< int, vector<int> > &SimplifiedInstancesHierarchy);
        
        
        // Show the simplified instances in the file ConversionToDisjunctionOfProblemsWithSMTSolverHierarchyFp
        void showSimplifiedInstancesInFile(vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances);
        
        // Version of DDManager::QEFromDisjunctionOfTailedTriangles, which collects consecutive sat 
        // C_i \wedge f_i's and performs QE on \vee (f_i\wedge C_i)
        DDNode* QEFromDisjunctionOfTailedTriangles_CollectConsecutiveSatTailedTriangles(vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances, set<string> &VarSetToElim, map<string, int> &WidthTable);
        
        
        //Function to convert a vector of sat. tailed triangles to a single DD
        DDNode* convertVectorOfTailedTrianglesToSingleDD(vector<int> &CollectedSatTailedTriangles, vector< pair< set<DAGNode*>, DDNode* > > &SimplifiedInstances, map<string, int> &WidthTable);


        // Checks if \exists VarToElim. (PhiDag /\ XiDag) \equiv \exists VarToElim. (PhiDag) using BDDs
        bool quantifiedFormulaeAreEquivalentUsingBlastingAndCudd(DAGNode* PhiDag, DAGNode* XiDag, string VarToElim, map<string, int> &WidthTable, unsigned long long int &BlastTimeLocal, unsigned long long int &DDTimeLocal, unsigned long long int &QETimeLocal);

        
        // This function fixes the order of variables before creating the bdds
        void AprioriFixOrderOfVariablesInBDD(DAGNode* PhiDag, DAGNode* XiDag, map<string, int> &WidthTable);
        
        
        // Given "DAG_to_blast" which is a bv-logic formula, 
        // this function does bit-blasting + BDD creation
        void bitBlastAndCreateBDDInDDManager(DAGNode *DAG_to_blast, time_t &duration, unsigned long long int &BDDCreationTime_msec);
        
        
        // Following two functions added by Ajith on 20 July 2015: All path qelim with support for LMIs
        DDNode* call_All_Path_QElim_WithLMISupport(set<string> &VarSetToElim, DDNode* f, map<string, int> &WidthTable);
        DDNode* All_Path_QElim_WithLMISupport(set<string> &VarSetToElim, DDNode* f, set<DAGNode*> C_X, map<string, int> &WidthTable, HashTable <string, DDNode*> *PtrTableForAPResolveModified, HashTable <string, DDNode*> *PtrTableForAllVarsQE, int project_depth, int &path_count);

        
        
    private:

	      HashTable <string, DDNode*> DD_HT; 
	      HashTable <string, DDNode*> TableForApply;
	      HashTable <string, DDNode*> TableForITE;
	      set<DDNode*> SetOfDDNodes;
	      map< pair<DDNode*, DAGNode*>, DDNode*> TableForDagResolve;
	      map< set<DAGNode*>, bool> ImplicationTable;
              HashTable <string, bool> FirstImplicationTable; 
	      HashTable <string, bool> SecondLevelImplicationTable; 
              HashTable <string, DDNode*> TableForApplyWithImpCheck;
	      HashTable <string, DDNode*> TableForITEWithImpCheck;
              HashTable <string, DDNode*> ExternalTableForApplyWithImpCheck;
              HashTable <string, DDNode*> ExternalTableForCreateITEWithImpCheck;
	      
	      //LMDD:BDD table
	      map<DDNode*, DdNode*> LMDD_BDD_Table;
	      
  
    };

#endif	/* _DDMANAGER_H */
