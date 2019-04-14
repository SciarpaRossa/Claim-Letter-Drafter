// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"



int
GetBWP(string & data)
{
	if (data.empty())
		return 0;

	int length;
	int npos = data.find('=');
	if (npos != -1)
		data.erase(0, npos + 1);

	istringstream ss(data);
	ss >> length;

	return length;
}



bool
IsHourly(string & data)
{
	if (data.empty() || data.find('/') == -1)
		return false;

	return true;
}



char
TypeGet(string & data)
{
	string type;
	const string H = "Hospital";
	const string A = "Accident";

	if (type == H)
		return 'H';
	if (type == A)
		return 'A';
	else
		return 'I';
}



/* The format() function edits the string argument passed by appending the HTML code
   indicated by the const string argument. */
   // RETURN VALUE: The resulting string with the included HTML formatting.

string
format(string& str, const string& html)
{
	if (str.empty())
		return str;

	string newstr(html);
	string slashhtml;
	int checksum = 0;

	for (int i = 0; i < html.length(); ++i)
		checksum += html[i];
	switch (checksum) {
	case B_NUM: // <b>
		slashhtml = SLASH_B;
		break;
	case I_NUM: // <i>
		slashhtml = SLASH_I;
		break;
	case U_NUM: // <u>
		slashhtml = SLASH_U;
		break;
	case P_NUM: // <p>
		slashhtml = SLASH_P;
		break;
	case PCB_NUM: // PCB
		slashhtml = SLASH_PCB;
		break;
	case PCU_NUM: // PCU
		slashhtml = SLASH_PCU;
		break;
	default:
		abort();
	}
	newstr += str;
	newstr += slashhtml;

	return newstr;
}


/* The ReadFile() function will read in the file of the given FileName argument, opening
/* the file and then creating a single string of all the characters in the file. */

// RETURN VALUE: 0 upon success of the file read in, else -1 upon error condition.

int 
ReadFile(const string & FileName, vector<string> & data)
{
	if (FileName.empty())
		return -1;

	ifstream fin;
	char buffer[STR_SIZE + 1];
	string str;

	fin.open(FileName);
	if (!fin.is_open())
		return -1;

	while (!fin.eof()) {
		fin.getline(buffer, STR_SIZE);
		str += buffer;
		data.push_back(buffer);
	}
	fin.close();
	fin.clear();

	return 0;
}



// RETURN VALUE:

vector<string> 
ParseLine(string& str, const char delim)
{
	vector<string> strs;
	string data;
	int npos;

	if (str.empty())
		return strs;

	npos = str.find(delim);
	while (npos != -1) {
		data = str.substr(0, npos);
		strs.push_back(data);
		str.erase(0, npos + 1);
		npos = str.find(delim);
	} 
	strs.push_back(str);
	str.clear();

	return strs;
}



string
PrintBWP(string & bwp, string & dod, int policy)
{
	ostringstream ss;
	int length;
	vector<string> bwpparsed = ParseLine(bwp, FILE_DELIM);
	vector<string> dodparsed = ParseLine(dod, FILE_DELIM);
	string benefit_from = dodparsed[BENEFIT_FROM_COLUMN];
	string str;
	/*
	if (IsHourly(bwpparsed[3]))
		length = GetBWP(bwpparsed[BWP_COLUMN]);
	else
		length = GetBWP(bwpparsed[BWP_COLUMN]);
		*/
	length = GetBWP(bwpparsed[BWP_COLUMN]);
	const char TYPE = TypeGet(bwpparsed[TYPE_COLUMN]);

	str = BWP_INTRO;
	ss << length;
	str += ss.str();
	str += DAYS;

	if (TYPE == 'A') {
		str += A_GENERAL;
		str += dodparsed[DOD_COLUMN];
		str += BEGIN_ON;
		str += dodparsed[BENEFIT_FROM_COLUMN];
	}
	else if (TYPE == 'H') {
		str += H_GENERAL;
		str += dodparsed[DOD_COLUMN];
		str += BEGIN_ON;
		str += dodparsed[BENEFIT_FROM_COLUMN];
	}
	else {
		str += DISABLED_ON;
		str += dodparsed[DOD_COLUMN];
		str += I_GENERAL;
		str += dodparsed[BENEFIT_FROM_COLUMN];
	}
	str += ".";

	return format(str, P);
}


/* The compress() function takes a vector of strings, and consolidates them into one
   single string object to be handled. */

// RETURN VALUE: The string object resulting from the vector consolidation; else, NULL
// upon error.

string 
compress(vector<string> & strs)
{
	if (strs.empty())
		return NULL;

	vector<string>::iterator it = strs.begin();
	string str;

	do {
		str += *it;
		++it;
	} while (it != strs.end());

	return str;
}

string
compress(vector<string> & strs, const char delim)
{
	if (strs.empty())
		return NULL;

	vector<string>::iterator penultim = strs.end() - 1;
	vector<string>::iterator it = strs.begin();
	string str;

	do {
		str += *it;
		if (it != penultim)
			str += delim;
		++it;
	} while (it != strs.end());

	return str;
}


/* The clip() function copies the argument string's text to the clipboard. */
// RETURN VALUE: 0 upon success, else -1 if an empty string is passed. 

int 
clip(string & str)
{
	if (str.empty())
		return -1;

	int cstrlen = str.length() + 1;

	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, cstrlen);
	memcpy(GlobalLock(hMem), str.c_str(), cstrlen);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();

	return 0;
}

/* The read() function handles the user input of a string from the console. */
// RETURN VALUE:

int
read()
{
	string text;

	cout << "Enter the text to copy to the clipboard: ";
	getline(cin, text);
	text = format(text, PCB);

	return clip(text);
}



void
display(vector<string> strs)
{
	if (strs.empty()) 
		cout << "Empty vector." << endl;
	else {
		for (vector<string>::iterator it = strs.begin(); it < strs.end(); ++it) {
			cout << *it << endl;
		}
	}
	cout << endl;

	return;
}


int
main()
{
	const string name = "C:\\Users\\scott\\Downloads\\New Template.txt";
	vector<string> strs;
	if (ReadFile(name, strs))
		abort();

	display(strs);
	string strtwo = PrintBWP(strs[BWP_LINE - 1], strs[DOD_LINE - 1], 1);
	cout << strtwo << endl << endl;
	clip(strtwo);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file