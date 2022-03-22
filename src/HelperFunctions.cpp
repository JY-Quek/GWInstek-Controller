#include "HelperFunctions.h"

// for string delimiter
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

// Convert a nth number of letter in string to uppercase and the rest lowercase
string convertUpper ( string inputstr, int numberupper ) {
	
	for (size_t i = 0; i < inputstr.length(); i++) {
		if (i < (size_t) numberupper)
			inputstr[i] = toupper(inputstr[i]);
		else
			inputstr[i] = tolower(inputstr[i]);
	}
	return inputstr;
}

double convertStringScNotationToDouble (string inputstr) {
	istringstream os(inputstr);
	double outputDouble;
	os >> outputDouble;
	return outputDouble;
}