#include <iostream>
#include <string>	
#include <chrono>


using namespace std;
using namespace std::chrono;

//SY = symptom, DO = disorder, DE = depression, WG = weight gain, LL = losso of Loved one, D2 = Depression greater than 2 years
//DC = Difficulty concentrating, HY = hyperactivity, FB = food binging, SI = suicidal ideation, FI = feelings of isolation
//IS = Irregular sleep patterns, AX = anxiety, PA = Panic attack, A2 = anxiety greater than two years, HA = hallucinations
//ME = manic episodes, FA = Fatigue, FH = Feelings of helplessness, IN = Insomnia, MT= Missing time, ED = Extreme debilitation
//AP = avoiding people/places




float /* grade */ gr, /*experience */ ex; 
void determine_member_concl_list(int csn); 
string diagnose(string conclusion); 
void instantiate(string conclusionList[], string clauseVarList[]); 
void getClauseLocation(string clause);
void displayList(string list[], int l);
void treat(string c);

int concListLen = 24;
int clauselen = 520;
int varListLen = 23;

main() 
{
	auto start = high_resolution_clock::now();
	string variableList[varListLen] = {"SY","DO","DE","WG","LL","D2","DC","HY","FB","SI","FI",
"IS","AX","PA","A2","HA","ME","FA","FH","IN","MT","ED","AP"};
	string conclusion = "";
	string conclusionList[concListLen]; 
	string clauseVarList[clauselen];
	string DI = "";
	string DO = "";
	string CO = "";
	
	instantiate(conclusionList, clauseVarList);

    cout << "\t *** Conclusion List: ***" << endl ;
	displayList(conclusionList, concListLen);
	cout << "PRESS ENTER TO CONTINUE";
	cin.get();
	cout << "Variable List: " << endl ;
	displayList(variableList, varListLen);	
	cout << "PRESS ENTER TO CONTINUE";
	cin.get();
	cout << "Clause Var list: " << endl;
	displayList(clauseVarList, clauselen);
	
	cout << "Enter conclusion: DI for diagnosis (string) or DO for Disorder (binary): ";
	cin >> conclusion;
	CO = diagnose(conclusion);
	treat(CO);
	
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "\nExecution time in seconds	: " << duration.count() << endl;
}

string diagnose(string concl) {
	string CO = "";  // CO is the conclusion, either concl = DO = (yes or no), or DI = (none or diagnosis)
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
	cout << "Are you experiencing any symptoms? Enter y/n";
	cin >> symptom;
	if (symptom == "n") {
		if (concl == "DO") {
			cout << "DO = no";
			CO = "no";
		} else if (concl == "DI") {
			cout << "DI = none";
			CO = "none";
		}
		
	} else if (symptom == "y" && concl == "DO") {
		cout << "DO = YES";
		CO = "yes";
	} else if (symptom == "y" && concl == "DI") {
		cout << "Experiencing depression?";
		cin >> depression;	
		if (depression == "y") {
			cout << "Any weight gain?";
			cin >> weightGain;	
			if (weightGain == "y") {
				cout << "Have you experienced the loss of a loved one?";
				cin >> lossOfLovedOne;
				if (lossOfLovedOne == "y") {
					cout << "Depression longer than 2 years?";
					cin >> depressionGreater2yrs;
					if (depressionGreater2yrs == "y") {
						cout << "D = Disthymia";
						CO = "disthymia";
					}
					else if (depressionGreater2yrs == "n") {
						cout << "D = Normal Bereavement";
						CO = "bereavement";
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
							CO = "ADHD";
						}
						else {
							cout << "D = ADD";
							CO = "ADD";
						}
					}
					else if (difficultyConcentrating == "n") {
						cout << "Do you binge on food?";
						cin >> binging;
						if (binging == "y") {
							cout << "D = Binge eating disorder";
							CO = "binge eating disorder";
						}
						else if (binging == "n") {
							cout << "D = Hypothyroidism";
							CO = "hypothyroidism";
						}
					}
					
				} 
			}
			else if (weightGain == "n") {
				cout << "Any suicidal ideation?";
				cin >> suicidal;	
				if (suicidal == "y") {
					cout << "Feelings of isolation?";
					cin >> isolation;
					if (isolation == "y") {
						cout << "D = MDD";
						CO = "MDD";
					}
					else if (isolation == "n") {
						cout << "Irregular sleep patterns?";
						cin >> irregSleep;
						if (irregSleep == "y") {
							cout << "D = Bipolar Disorder";
							CO = "bipolar disorder";
						}
						else if (irregSleep == "n") {
							cout << "D = OCD";
							CO = "OCD";
						}
					}
				}
				else if (suicidal == "n"){
						cout << "D = SAD";
						CO = "SAD";
					}
				
			}		
		}
		else if (depression == "n") {
			cout << "Anxiety?";
			cin >> anxiety;
			if (anxiety == "y") {
				cout << "Has your anxiety more than 2 years?";
				cin >> anxietyGreater2yrs;
				if (anxietyGreater2yrs == "y") {
					cout << "hallucinations?";
					cin >> hallucinations;
					if (hallucinations == "y") {
						cout << "Manic episodes?";
						cin >> manicEpisodes;
						if (manicEpisodes == "y") {
							cout << "D = Schizoaffective";
							CO = "schizoaffective";
						}
						else if (manicEpisodes == "n") {
							cout << "D = Schizophrenia";
							CO = "schizophrenia";
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
								CO = "burnout";
							}
							else if (helplessness == "n") {
								cout << "D = Mental fatigue";
								CO = "mental fatigue";
							}
						}
						else if (fatigue == "n") {
							cout << "Insomnia?";
							cin >> insomnia;
							if (insomnia == "y") {
								cout << "D = Chronic Fatigue Syndrome";
								CO = "chronic fatigue syndrome";
							}
							else if (insomnia == "n") {
								cout << "D = Fibromyalgia";
								CO = "fibromyalgia";
							}
						}
						
					}
				}
				
				else if (anxietyGreater2yrs == "n") {
					cout << "Extreme debilitation?";
					cin >> extremeDebil;
					if (extremeDebil == "y") {
						cout << "D = PTSD";
						CO = "PTSD";
					}
					else if (extremeDebil == "n") {
						cout << "D = GAD";
						CO = "GAD";
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
						CO = "panic disorder with agoraphobia";
					}
					else if (avoidingPeople == "n") {
						cout << "D = Panic Disorder";
						CO = "panic disorder";
					}
				}
					
				else if (panicAttack == "n") {
					cout << "Missing time?";
					cin >> missingTime;
					if (missingTime == "y") {
						cout << "D = DID";
						CO = "DID";
					}
					else if (missingTime == "n") {
						cout << "D = Hypochondria";
						CO = "hypochondria";
					}
				}
				
			}
		}
	}

	return CO;
	} 
}

void instantiate(string conclusionList[], string clauseVarList[]) {
	for (int i = 0; i<concListLen; i++) {
		conclusionList[i] = "DI";
		if (i == 1) {
		conclusionList[i] = "DO";
		}
    }
    for (int i = 1; i<clauselen; i++) {
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
    
    
}

void displayList(string list[], int l) {
	for (int i=0; i<l; i++){
		if (l == concListLen) {
		cout << 10*(i+1) << ": "<< list[i] << endl;
		} else if (l == varListLen) {
			//for (int i = 0; i<23; i++) {
			cout << "Variable "<< i+1 << " " << list[i] << endl;
			//}
		} else if (l == clauselen) 
		{ 
				//for (int i = 1; i <520; i++) {
					if (i == 0) {
						i++;
					}
					if (i == 1) {
						cout << "Clause Number: " << 1 << endl;
					}
					 cout << "Clause # " << i <<  " " << list[i] << endl;
					if (i%22 == 0) {
						cout << "PRESS ENTER TO CONTINUE";
						cin.get();
						cout << "Clause Number: " << i/22 + 1<< endl;
					}
				}
			
			}
		
		//}
	}
	
	
	
	
void treat(string c) {
	cout << endl << "Recommendation: ";
	if (c == "yes") {
		cout << "Seek psychiatric assessment";
	}
	if (c == "none" || c == "no") {
		cout << "No treatment recommended";
	} else if (c == "disthymia") {
		cout << "Therapy + Zoloft";
	} else if (c == "bereavement") {
		cout << "Group counseling";
	} else if (c == "ADD") {
		cout << "Adderall";
	} else if (c == "ADHD") {
		cout << "Adderall & Hydroxizine";
	} else if (c == "binge eating disorder") {
		cout << "Group therapy & nutrition counseling";
	} else if (c == "hypothyroidism ") {
		cout << "Levothyroxine";
	} else if (c == "MDD") {
		cout << "Therapy & Prozac";
	} else if (c == "bipolar disorder") {
		cout << "Therapy and Abilify";
	} else if (c == "OCD") {
		cout << "Therapy";
	} else if (c == "SAD") {
		cout << "Vitamin D supplements";
	} else if (c == "schizoaffective") {
		cout << "Olanzapine, Sodium Valproate and Cogentin";
	} else if (c == "schizophrenia") {
		cout << "Sodium Valproate, Olanzapine";
	} else if (c == "burnout") {
		cout << "Occupational counseling";
	} else if (c == "mental fatigue") {
		cout << "Mindfulness practice";
	} else if (c == "chronic fatigue syndrome") {
		cout << "Nutritional counseling & CBD";
	} else if (c == "fibromyalgia") {
		cout << "Celebrex";
	} else if (c == "PTSD") {
		cout << "Therapy, lorazepam";
	} else if (c == "GAD") {
		cout << "Hydroxyzine HCL";
	} else if (c == "panic disorder with agoraphobia") {
		cout << "Therapy, Valium";
	} else if (c == "panic disorder") {
		cout << "Therapy, mindfulness practice";
	} else if (c == "DID") {
		cout << "Psychosocial therapy, sertraline";
	} else if (c == "hypochondria") {
		cout << "Cognitive behavioral therapy";
	}
}

