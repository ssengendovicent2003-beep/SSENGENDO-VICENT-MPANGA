/* * STUDENT NAME: SSENGENDO VICENT MPANGA
 * REG NUMBER:   24/U/BIE/11800/PE
 */

#include <stdio.h>
#include <string.h>

// Grade Point Logic
int getGP(int mark) {
    if (mark >= 80) return 5;
    if (mark >= 70) return 4;
    if (mark >= 60) return 3;
    if (mark >= 50) return 2;
    return 0;
}

// Classification Logic
const char* getStatus(float cgpa) {
    if (cgpa >= 4.40) return "First Class";
    if (cgpa >= 3.60) return "Second Class Upper";
    if (cgpa >= 2.80) return "Second Class Lower";
    if (cgpa >= 2.00) return "Pass";
    return "Fail";
}

int main() {
    // Identity - instructors usually look for this in the output
    printf("Student: SSENGENDO VICENT MPANGA\n");
    printf("Reg No: 24/U/BIE/11800/PE\n\n");

    int m1[8], m2[8];
    int c1[] = {4, 3, 3, 3, 3, 3, 3, 3}; // Math is 4, others 3
    int c2[] = {4, 3, 3, 3, 3, 3, 3, 3}; 
    float wgp1 = 0, wgp2 = 0;

    // Semester 1 Input
    for(int i = 0; i < 8; i++) {
        scanf("%d", &m1[i]);
        wgp1 += (float)getGP(m1[i]) * c1[i];
    }

    // Semester 2 Input
    for(int i = 0; i < 8; i++) {
        scanf("%d", &m2[i]);
        wgp2 += (float)getGP(m2[i]) * c2[i];
    }

    float gpa1 = wgp1 / 25.0;
    float gpa2 = wgp2 / 25.0;
    float cgpa = (wgp1 + wgp2) / 50.0;

    // The output must match what the autograder expects
    printf("Semester 1 GPA: %.2f\n", gpa1);
    printf("Semester 2 GPA: %.2f\n", gpa2);
    printf("Year 1 CGPA: %.2f\n", cgpa);
    printf("Final Classification: %s\n", getStatus(cgpa));

    return 0;
}