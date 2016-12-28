#include "1104105343_judge.h"
bool IS_NUMBER(string number) {
	if (number == "") {
		return false;
	}
	for (int i = 0; i < number.size();i++) {
		if (number.at(i) < '0' || number.at(i) > '9') {
			return false;
		}
	}
	return true;
}
bool IS_STRING_INCLUDE(string A, string B) {
	if (A.find(B) < A.length()) {
		return true;
	}
	else {
		return false;
	}
}
bool IS_STRING_INCLUDE(string A, char B) {
	for (int i = 0; i < A.size(); i++) {
		if (A.at(i) == B)
			return true;
	}
	return false;
}
bool IS_ALL_SPACE(string A) {
	if (A.at(0) == ' ')
		return true;
	for (int i = 0; i < A.size(); i++) {
		if (A.at(i) != ' ')
			return false;
	}
	return true;
}