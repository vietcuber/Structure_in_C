#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

struct date { int day, month, year; };
enum status { freshman = 1, sophomore, junior, senior };

typedef struct student {
	long ID;
	char name[40];
	char class_[20];
	float CPA;
	struct date birthdate; 
	enum status status_;
};

int main() {
	int n;
	//Declare student s1
	student s1 = { 20233260, "Nguyen Viet Anh", "CTTN ET1 K68", 4.0, {1, 6, 2005}, freshman };
	//Declare student s2
	printf("---Enter Student_2's information:\n");
	student s2;
	printf("ID: ");
	scanf_s("%d", &s2.ID);
	printf("Name: ");
	cin.ignore(); // C++ Library
	gets_s(s2.name);
	printf("Class: ");
	gets_s(s2.class_);
	printf("CPA: ");
	scanf_s("%f", &s2.CPA);
	s2.CPA = (round(s2.CPA * 100)) / 100;
	printf("Birthdate (day, month, year):\n");
	scanf_s("%d%d%d", &s2.birthdate.day, &s2.birthdate.month, &s2.birthdate.year);
	printf("Status: ");
	scanf_s("%d", &s2.status_);
	//Make an array of student
	printf("---Create an array of students\n");
	printf("Number of students (n < 10): ");
	scanf_s("%d", &n);
	student s[9];
	for (int i = 0; i < n; i++) {
		printf("Enter Student_%d information:\n", i + 1);
		printf("ID: ");
		scanf_s("%d", &s[i].ID);
		printf("Name: ");
		cin.ignore(); //C++ library
		gets_s(s[i].name);
		printf("Class: ");
		gets_s(s[i].class_);
		printf("CPA: ");
		scanf_s("%f", &s[i].CPA);
		s[i].CPA = (round(s[i].CPA * 100)) / 100;
		printf("Birthdate (day, month, year):\n");
		scanf_s("%d%d%d", &s[i].birthdate.day, &s[i].birthdate.month, &s[i].birthdate.year);
		printf("Status: ");
		scanf_s("%d", &s[i].status_);
	}
	//Use pointer to display the array on the screen
	printf("---Use pointer to display the array on the screen: \n");
	student* p = s;
	for (int i = 0; i < n; i++) {
		printf("The information of student_%d:\n", i + 1);
		printf("ID: %d\n", (p + i)->ID);
		printf("Name: %s\n", (p + i)->name);
		printf("Class: %s\n", (p + i)->class_);
		printf("CPA: %.2f\n", (p + i)->CPA);
		printf("Birthdate: %d %d %d\n", (p + i)->birthdate.day, (p + i)->birthdate.month, (p + i)->birthdate.year);
		switch (s[i].status_) {
		case freshman:
			printf("Status: Freshman\n");
			break;
		case sophomore:
			printf("Status: Sophomore\n");
			break;
		case junior:
			printf("Status: Junior\n");
			break;
		case senior:
			printf("Status: Senior\n");
			break;
		}
	}
	return 0;
}