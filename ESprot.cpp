#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>

using namespace std;

/* instantiated list */ 
int instlt[11] = {11, 0}; 
/* statement stack */ 
int statsk[11] = {11, 0};
int /* clause stack */ clausk[11], sn, f, i, j, s, k, /*stack pointer */ sp;

//SY = symptom, DO = disorder, DE = depression, WG = weight gain, LL = losso of Loved one, D2 = Depression greater than 2 years
//DC = Difficulty concentrating, HY = hyperactivity, FB = food binging, SI = suicidal ideation, FI = feelings of isolation
//IS = Irregular sleep patterns, AX = anxiety, PA = Panic attack, A2 = anxiety greater than two years, HA = hallucinations
//ME = manic episodes, FA = Fatigue, FH = Feelings of helplessness, IN = Insomnia, MT= Missing time, ED = Extreme debilitation
//AP = avoiding people/places
string variableList[23] = {"SY","DO","DE","WG","LL","D2","DC","HY","FB","SI","FI",
"IS","AX","PA","A2","HA","ME","FA","FH","IN","MT","ED","AP"};
string conclusionList[24]; 
string clauseVarList[520];
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
	for (int i = 0; i<24; i++) {
		
		conclusionList[i] = "diagnosis";
		if (i == 1) {
			conclusionList[i] = "disorder";
		}
    }
    for (int i = 1; i<520; i++) {
    	if (i == 1 || i == 45 || i == 67 || i == 89 || 
		i == 111 || i == 133 || i == 155 || i == 177 || 
		i == 199 || i == 221 || i == 243 || i == 265 || 
		i == 287 || i == 309 || i == 331 || i == 353 || 
		i == 375 || i == 397 || i == 419 || i == 441 || 
		i == 463 || i == 485 || i == 507) {
			//symptoms / SY
			clauseVarList[i] = "SY";
		}
		if (i == 23 || i == 46 || i == 68 || i == 90 || 
		i == 112 || i == 134 || i == 156 || i == 178 || 
		i == 200 || i == 222 || i == 244 || i == 266 || 
		i == 288 || i == 310 || i == 332 || i == 354 || 
		i == 376 || i == 398 || i == 420 || i == 442 || 
		i == 464 || i == 486 || i == 508) {
			//disorder / DO
			clauseVarList[i] = "DO";
		}
		if (i == 47 || i == 69 || i == 91 || i == 201 || i == 223 || i == 245 ) {
			//depression / DE
			clauseVarList[i] = "DE";
		}
		if (i == 70 || i == 92  ) {
			//loss of loved one / LL
			clauseVarList[i] = "LL";
		}
		
		if (i == 93 ) {
			//depressed > 2 yrs / D2
			clauseVarList[i] = "D2";
		}
		if (i == 113 || i == 135 || i == 157 || i == 179 ) {
			//weight gain / WG
			clauseVarList[i] = "WG";
		}
		if (i == 114 || i == 136 ) {
			//difficulty concentrating / DC
			clauseVarList[i] = "DC";
		}
		if (i == 137) {
			//hyperactivity / HY
			clauseVarList[i] = "HY";
		}
		if (i == 180) {
			//food binging / FB
			clauseVarList[i] = "FB";
		}
		if (i == 202 || i == 224 || i == 246 ) {
			//suicidal ideation / SI
			clauseVarList[i] = "SI";
		}
		if (i == 225 ) {
			//feelings of isolation / FI
			clauseVarList[i] = "FI";
		}
		if (i == 247) {
			//irregular sleep patterns / IS
			clauseVarList[i] = "IS";
		}
		if (i == 289 ) {
			//missing time / MT 
			clauseVarList[i] = "MT";
		}
		if (i == 311 || i == 333) {
			//panic attack / PA
			clauseVarList[i] = "PA";
		}
		if (i == 334) {
			//avoiding people/places / AP
			clauseVarList[i] = "AP";
		}
		if (i == 355 || i == 377 || i == 399 || i == 421 || i == 443 || i == 465 || i == 487 || i == 509) {
			//anxiety / AX
			clauseVarList[i] = "AX";
		}
		if (i == 356) {
			//extreme debilitation / ED
			clauseVarList[i] = "ED";
		}
		if (i == 400 || i == 422 || i == 444 || i == 466 || i == 488 || i == 510) {
			//anxiety > 2 yrs / A2
			clauseVarList[i] = "A2";
		}
		if (i == 423 || i == 445 || i == 467  ) {
			//fatigue / FA
			clauseVarList[i] = "FA";
		}
		if (i == 446) {
			//feelings of helplessness / FH 
			clauseVarList[i] = "FH";
		}
		if (i == 468) {
			//insomnia / IN 
			clauseVarList[i] = "IN";
		}
		if (i == 489 || i == 511) {
			//hallucinations / HA
			clauseVarList[i] = "HA";
		}
		if (i == 512) {
			//manic episodes / ME
			clauseVarList[i] = "ME";
		}
		
	}

    cout << "Conclusion List: " << endl ;
	for (int i = 0; i<24; i++){
		cout << 10*(i+1) << ": "<< conclusionList[i] << endl;
	}
	cout << "Variable List: " << endl ;
	for (int i = 0; i<23; i++) {
		cout << "Variable "<< i+1 << " " << variableList[i] << endl;
	}	
	cout << "Clause Var list: " << endl;
	for (int i = 1; i <520; i++) {
		if (i == 1) {
			cout << "Clause Number: " << 1 << endl;
		}
		 cout << "Clause # " << i <<  " " << clauseVarList[i] << endl;
		if (i%22 == 0) {
			cout << "Clause Number: " << i/22 + 1<< endl;
		}
	}
	
	
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
