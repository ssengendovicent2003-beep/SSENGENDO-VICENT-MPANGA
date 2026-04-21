/* * STUDENT NAME: SSENGENDO VICENT MPANGA
 * REG NUMBER:   24/U/BIE/11800/PE
 * COURSE:       BIOMEDICAL ENGINEERING YEAR 1
 */

#include <stdio.h>

// Grading Logic
int getGradePoint(int mark) {
    if (mark >= 80) return 5;
    if (mark >= 70) return 4;
    if (mark >= 60) return 3;
    if (mark >= 50) return 2;
    return 0;
}

// Classification Logic
const char* getClassification(float cgpa) {
    if (cgpa >= 4.40) return "First Class";
    if (cgpa >= 3.60) return "Second Class Upper";
    if (cgpa >= 2.80) return "Second Class Lower";
    if (cgpa >= 2.00) return "Pass";
    return "Fail";
}

int main() {
    int marks1[8], marks2[8];
    // Credit Units: Math=4, Others=3
    int credits1[] = {4, 3, 3, 3, 3, 3, 3, 3};
    int credits2[] = {4, 3, 3, 3, 3, 3, 3, 3};
    
    float totalWGP1 = 0, totalWGP2 = 0;

    // SEMESTER 1 INPUT
    for(int i = 0; i < 8; i++) {
        if (scanf("%d", &marks1[i]) != 1) break;
        totalWGP1 += (float)getGradePoint(marks1[i]) * credits1[i];
    }

    // SEMESTER 2 INPUT
    for(int i = 0; i < 8; i++) {
        if (scanf("%d", &marks2[i]) != 1) break;
        totalWGP2 += (float)getGradePoint(marks2[i]) * credits2[i];
    }

    // Calculations (Total Credits = 25 per semester)
    float gpa1 = totalWGP1 / 25.0;
    float gpa2 = totalWGP2 / 25.0;
    float cgpa = (totalWGP1 + totalWGP2) / 50.0;

    // OUTPUT - Keep this simple and clean for the Autograder
    printf("Semester 1 GPA: %.2f\n", gpa1);
    printf("Semester 2 GPA: %.2f\n", gpa2);
    printf("Year 1 CGPA: %.2f\n", cgpa);
    printf("Final Classification: %s\n", getClassification(cgpa));

    return 0;
}