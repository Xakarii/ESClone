#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>

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
stack <int> clauseStack;
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
	int conclusionStatementNum = 0;
	string symptom = "";
	string depression = "";
	string weightGain = "";
	string lossOfLovedOne = "";
	string depressionGreater2yrs = "";
	string difficultyConcentrating = "";
	string hyper = "";
	string binging = "";
	string suicidal = "";
	string isolation = "";
	string irregSleep = "";
	string anxiety = "";
	string panicAttack = "";
	string anxietyGreater2yrs = "";
	string hallucinations = "";
	string manicEpisodes = "";
	string fatigue = "";
	string helplessness = "";
	string insomnia = "";
	string missingTime = "";
	string extremeDebil = "";
	string avoidingPeople = "";
	
	
	cout << "Any symptoms? Enter y/n";
	cin >> symptom;
	if (symptom == "y") {
		cout << "Depression?";
		cin >> depression;	
		if (depression == "y") {
			cout << "Weight gain?";
			cin >> weightGain;	
			if (weightGain == "y") {
				cout << "Loss of Loved one?";
				cin >> lossOfLovedOne;
				if (lossOfLovedOne == "y") {
					cout << "Depression longer than 2 years?";
					cin >> depressionGreater2yrs;
					if (depressionGreater2yrs == "y") {
						cout << "D = Disthymia";
					}
					else if (depressionGreater2yrs == "n") {
						cout << "D = Normal Bereavement";
					}
				}
				else if (lossOfLovedOne == "n") {
					cout << "Difficulty concentrating?";
					cin >> difficultyConcentrating;
					if (difficultyConcentrating == "y") {
						cout << "Hyperactivity?";
						cin >> hyper;
						if (hyper == "y") {
							cout << "D = ADHD";
						}
						else {
							cout << "D = ADD";
						}
					}
					else if (difficultyConcentrating == "n") {
						cout << "Food binging?";
						cin >> binging;
						if (binging == "y") {
							cout << "D = Binge eating disorder";
						}
						else if (binging == "n") {
							cout << "D = Hypothyroidism";
						}
					}
					
				}
			}
			else if (weightGain == "n") {
				cout << "suicidal?";
				cin >> suicidal;	
				if (suicidal == "y") {
					cout << "feelings of isolation?";
					cin >> isolation;
					if (isolation == "y") {
						cout << "D = MDD";
					}
					else if (isolation == "n") {
						cout << "Irregular sleep patterns?";
						cin >> irregSleep;
						if (irregSleep == "y") {
							cout << "D = Bipolar Disorder";
						}
						else if (irregSleep == "n") {
							cout << "D = OCD";
						}
					}
				}
				else if (suicidal == "n"){
						cout << "D = S.A.D.";
					}
				
			}		
		}
		else if (depression == "n") {
			cout << "anxiety?";
			cin >> anxiety;
			if (anxiety == "y") {
				cout << "Lasting more than 2 years?";
				cin >> anxietyGreater2yrs;
				if (anxietyGreater2yrs == "y") {
					cout << "hallucinations?";
					cin >> hallucinations;
					if (hallucinations == "y") {
						cout << "Manic episodes?";
						cin >> manicEpisodes;
						if (manicEpisodes == "y") {
							cout << "D = Schizoaffective";
						}
						else if (manicEpisodes == "n") {
							cout << "D = Schizophrenia";
						}
					}
					else if (hallucinations == "n") {
						cout << "Fatigue?";
						cin >> fatigue;
						if (fatigue == "y") {
							cout << "Feelings of helplessness?";
							cin >> helplessness;
							if (helplessness == "y") {
								cout << "D = burnout";
							}
							else if (helplessness == "n") {
								cout << "D = Mental fatigue";
							}
						}
						else if (fatigue == "n") {
							cout << "Insomnia?";
							cin >> insomnia;
							if (insomnia == "y") {
								cout << "D = Chronic Fatigue Syndrome";
							}
							else if (insomnia == "n") {
								cout << "D = Fibromyalgia";
							}
						}
						
					}
				}
				else if (anxietyGreater2yrs == "n") {
					cout << "extremeDebil?";
					cin >> extremeDebil;
					if (extremeDebil == "y") {
						cout << "D = PTSD";
					}
					else if (extremeDebil == "n") {
						cout << "D = GAD";
					}
				}
				
			}
			else if (anxiety == "n") {
				cout << "panicAttack?";
				cin >> panicAttack;
				if (panicAttack == "y") {
					cout << "Avoiding people or places?";
					cin >> avoidingPeople;
					if (avoidingPeople == "y") {
						cout << "D = Panic Disorder with Agoraphobia";
					}
					else if (avoidingPeople == "n") {
						cout << "D = Panic Disorder";
					}
				}
					
				else if (panicAttack == "n") {
					cout << "Missing time?";
					cin >> missingTime;
					if (missingTime == "y") {
						cout << "D = DID";
					}
					else if (missingTime == "n") {
						cout << "D = Hypochondria";
					}
				}
				
			}
		}
		
		
	}
		
	
	/*
	string fatigue = "";
	string helplessness = "";
	string insomnia = "";
	string missingTime = "";
	string extremeDebil = "";
	string avoidingPeople = "";
	*/
	//statementStack.push_back(1);
	//statementStack.push_back(2);
	
	//determine_member_concl_list(conclusionStatementNum);
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
