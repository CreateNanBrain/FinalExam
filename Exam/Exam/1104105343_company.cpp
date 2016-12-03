#include "1104105343_company.h";
Company::Company(string in_name="", string in_contact="", string in_Phone="") {
	Name = in_name;
	Contact_Person = in_contact;
	Phone = in_Phone;
}
string Company::getname() {
	return Name;
}
string Company::getContact_Person() {
	return Contact_Person;
}
string Company::getPhone() {
	return Phone;
}
void Company::setname(string in_name) {
	Name = in_name;
}
void Company::setpContact_Person(string in_Contact) {
	Contact_Person = in_Contact;
}
void Company::setPhone(string in_Phone) {
	Phone = in_Phone;
}