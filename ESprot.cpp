#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

/*****backward chaining *******/ 
/* Install your IF clauses in sequence in the first case 
   statement of the main program 
   example: if((a1==2) && (a2==6)) s=1; 
                      if(strcmp(j, NO") != 0) s=1; ?
   the then part of the above construction always 
   contains s=1; 
   install your the clauses in sequence in the second 
   case statement of the main program 
   example strcpy(po,"YES"); 
/*  conclusion list */ 
char conclt[10][3]; 
/*  variable list */ 
char varlt[10][3]; 
/*  clause vairable list */ 
char clvarlt[40][3]; 
char varble[3]; 
string variable;
char /* qualify */ qu[4], /* degree*/ de[4];
string symptoms, depression;
char /* discovery */ di[4], /* position */ po[4]; 
char buff[128]; 

/* instantiated list */ 
int instlt[11] = {11, 0}; 

/* statement stack */ 
int statsk[11] = {11, 0};

int /* clause stack */ clausk[11], sn, f, i, j, s, k, /*stack pointer */ sp;

//int sn, f, i, j, s, k, sp; 
string weightGain, lossOfLO, depressGreaterTwoYrs;
vector <string> variableList[10];
vector <string> conclusionList[10]; 
vector <string> clauseVarList[10];
vector <int> clauseStack = {10, 0};
vector <int> statementStack; 
vector <int> instantiatedList;
vector <string> buffer;

float /* grade */ gr, /*experience */ ex; 
void determine_member_concl_list(int csn); 
void push_on_stack(void); 
void instantiate(void); 
void getClauseLocation(string clause);

main() 
{
	cout << "Any symptoms?";
	int conclusionStatementNum = 0;
	string symptom;
	string depression;
	cin >> symptom;
	statementStack.push_back(1);
	cout << "Depression?";
	cin >> depression;
	statementStack.push_back(2);
	
	determine_member_concl_list(conclusionStatementNum);
	for (const int& i : statementStack) {
    	cout << i << "  ";
    }
}

void determine_member_concl_list(int conclusionStatementNum) {
	if (conclusionStatementNum != 0){ 
                  /* if sn = 0 then no conclusion of that name */  
                  /* push statement number (sn) and clause number=1 on goal 
                     stack which is composed of the statement stack (statsk) 
                     and clause stack (clausk) */ 
            push_on_stack();  
	               /* calculate clause location in clause-variable 
	                  list */ 
	}	
}
void push_on_stack(void) {
	cout << "...\n";
} 
void instantiate(void) {
	cout << "...\n";
}
void getClauseLocation(string clause) {
	cout << "...\n";
}
