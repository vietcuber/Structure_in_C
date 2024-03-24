#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
//Nguyen Viet Anh

typedef struct student {
	long ID;
	char name[40];
	char class_[20];
	float CPA;
};

int main() {
	int n;
	float max_CPA = 0;
	//Declare student s1
	student s1 = { 20233260, "Nguyen Viet Anh", "CTTN ET1 K68", 3.5 };
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
		if (max_CPA < s[i].CPA) 
			max_CPA = s[i].CPA;
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
	}
	//Display the student with the highest CPA in the array
	printf("---Display the student with the highest CPA in the arrray\n");
	printf("The highest CPA is: %.2f\n", max_CPA);
	printf("The students with the highest CPA are:\n");
	for (int i = 0; i < n; i++) {
		if (s[i].CPA != max_CPA) continue;
		printf("Student_%d:\n", i + 1);
		printf("ID: %d\n", (p + i)->ID);
		printf("Name: %s\n", (p + i)->name);
		printf("Class: %s\n", (p + i)->class_);
		printf("CPA: %.2f\n", (p + i)->CPA);
	}
	return 0;
}