#include <bits/stdc++.h> 
#include <map>
#include <vector>
#include <string>
using namespace std;

//	***************************************************************
//						codeSequence
//	***************************************************************
//	Descripción: Codifica la representacion de una secuencua de 
//				 aminoacidos de 3 a 1 letra
//	Recibe: Un string de la secuencia de aminoacidos (3 letras)
//	Devuelve: Un string de la secuencia de aminoacidos (1 letra)
//	***************************************************************
string codeSequence(string sequence){
	// Diccionario amino acidos
	map<string, char> aminoAcids;
	aminoAcids["Ala"] = 'A';
	aminoAcids["Cys"] = 'C';
	aminoAcids["Asp"] = 'D';
	aminoAcids["Glu"] = 'E';
	aminoAcids["Phe"] = 'F';
	aminoAcids["Gly"] = 'G';
	aminoAcids["His"] = 'H';
	aminoAcids["Ile"] = 'I';
	aminoAcids["Lys"] = 'K';
	aminoAcids["Leu"] = 'L';
	aminoAcids["Met"] = 'M';
	aminoAcids["Asn"] = 'N';
	aminoAcids["Pro"] = 'P';
	aminoAcids["Gln"] = 'Q';
	aminoAcids["Arg"] = 'R';
	aminoAcids["Ser"] = 'S';
	aminoAcids["Thr"] = 'T';
	aminoAcids["Val"] = 'V';
	aminoAcids["Trp"] = 'W';
	aminoAcids["Tyr"] = 'Y';

	// Objetos para hacer un split de la cadena para separar residuos
    stringstream checkSequence(sequence); 
    string residue, codedSequence;
    // Separa residuos, los codifica a 1 letra y los concatena
    while(getline(checkSequence, residue, '-'))
    	codedSequence.append(1, aminoAcids[residue]);
    
    return codedSequence;
}

//	***************************************************************
//						convertToHP
//	***************************************************************
//	Descripción: Convierte una secuencia de aminoacidos al modelo HP
//	Recibe: Un string de la secuencia de aminoacidos (1 letra)
//	Devuelve: Un string de la secuencia de aminoacidos en modelo HP
//	***************************************************************
string convertToHP(string sequence){
	// Diccionario hidrofobicos
	map<char, char> hydrophobics;
	hydrophobics['A'] = 'H';
	hydrophobics['C'] = 'H';
	hydrophobics['D'] = 'P';
	hydrophobics['E'] = 'P';
	hydrophobics['F'] = 'H';
	hydrophobics['G'] = 'P';
	hydrophobics['H'] = 'P';
	hydrophobics['I'] = 'H';
	hydrophobics['K'] = 'P';
	hydrophobics['L'] = 'H';
	hydrophobics['M'] = 'H';
	hydrophobics['N'] = 'P';
	hydrophobics['P'] = 'H';
	hydrophobics['Q'] = 'P';
	hydrophobics['R'] = 'P';
	hydrophobics['S'] = 'P';
	hydrophobics['T'] = 'P';
	hydrophobics['V'] = 'H';
	hydrophobics['W'] = 'H';
	hydrophobics['Y'] = 'H';

	// Convierte a modelo HP
	string hpSequence;
	for (int i = 0; i < sequence.length(); i++)
		hpSequence.append(1, hydrophobics[sequence[i]]);

	return hpSequence;
}


int mRNAlength(string mRNA) {
	// Señales de start y stop
	string start = "aug";
	string stop1 = "uag";
	string stop2 = "uaa";
	string stop3 = "uga";

	int contTrip = 1, len = 0;
	bool mensaje = false;
	string trip;
	int startPos = mRNA.find(start);

	cout << "\nPosicion: " << startPos << endl;

	for (int i = startPos; i < mRNA.length(); i++) {
		trip.append(1, mRNA[i]);

		if (contTrip == 3){
			if (trip == start)
				mensaje = true;
			else if (trip == stop1 || trip == stop2 || trip == stop3){
				mensaje = false;
			}

			if (mensaje)
				len++;

			cout << trip << " ";
			//cout << trip;
			trip = "";
			contTrip = 0;
		}

		contTrip++;
	}

	return len;
}

int main() {
	int option;
	cout << "\nSecuencia = 0 / mRNA = 1: ";
	cin >> option;

	string input;
	if (option == 0){
		cout << "\nSecuencia: ";
		cin >> input;
		string sequence = codeSequence(input);
		string hpSequence = convertToHP(sequence);


		cout << "\nAminoacidos: " << sequence;
		cout << "\nModelo HP: " << hpSequence << endl;
	}
	else{
		cout << "\nmRNA: ";
		cin >> input;

		cout << endl << endl << "Longitud: " << mRNAlength(input) << endl;
	}
	
	return 0;
}