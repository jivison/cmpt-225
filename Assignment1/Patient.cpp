/*
 * Patient.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 *
 * Author: John Ivison
 * Date: January 23, 2021
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"

const string Patient::memberDefaultValue = "To be entered";
const string Patient::careCardDefaultValue = "0000000000";

// Default Constructor
// Description: Create a patient with a care card number of "0000000000".
// Postcondition: All data members set to "To be entered",
//                except the care card number which is set to "0000000000".
Patient::Patient()
{
  name = memberDefaultValue;
  address = memberDefaultValue;
  phone = memberDefaultValue;
  email = memberDefaultValue;
  careCard = careCardDefaultValue;
}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard)
{
  name = memberDefaultValue;
  address = memberDefaultValue;
  phone = memberDefaultValue;
  email = memberDefaultValue;
  setCareCard(aCareCard);
}

// Parameterized Constructor
// Description: Create a patient with the given parameters.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aName, string anAddress, string aPhone, string anEmail, string aCareCard)
{
  name = aName;
  address = anAddress;
  phone = aPhone;
  email = anEmail;
  setCareCard(aCareCard);
}
// Getters and setters -> You need to implement these methods.

// Getters
string Patient::getName() const { return name; }
string Patient::getAddress() const { return address; }
string Patient::getPhone() const { return phone; }
string Patient::getEmail() const { return email; }
string Patient::getCareCard() const { return careCard; }

// Setters
void Patient::setName(const string aName) { name = aName; }
void Patient::setAddress(const string anAddress) { address = anAddress; }
void Patient::setPhone(const string aPhone) { phone = aPhone; }
void Patient::setEmail(const string anEmail) { email = anEmail; }

void Patient::setCareCard(string aCareCard)
{
  careCard = aCareCard.length() == 10 ? aCareCard : careCardDefaultValue;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator==(const Patient &rhs)
{

  // Compare both Patient objects
  return this->careCard == rhs.getCareCard();

} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card
//              number of "rhs" Patient object
bool Patient::operator>(const Patient &rhs)
{

  // Compare both Patient objects
  return this->careCard > rhs.getCareCard();

} // end of operator >

// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is < the care card
//              number of "rhs" Patient object.
bool Patient::operator<(const Patient &rhs)
{

  // Compare both Patient objects
  return this->careCard < rhs.getCareCard();

} // end of operator <

// Description: Prints the content of "this".
ostream &operator<<(ostream &os, const Patient &p)
{

  os << p.careCard << " - Patient: " << p.name << ", "
     << p.address << ", " << p.phone << ", " << p.email;

  return os;

} // end of operator<<

// end of Patient.cpp
