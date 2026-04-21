/* * STUDENT NAME: SSENGENDO VICENT MPANGA
 * REG NUMBER:   24/U/BIE/11800/PE
 */

#include <stdio.h>
#include <string.h>

// Function for Grade Letters
const char* getGradeLetter(int mark) {
    if (mark >= 80) return "A";
    if (mark >= 70) return "B";
    if (mark >= 60) return "C";
    if (mark >= 50) return "D";
    return "F";
}

// Function for Grade Points (GP)
int getGradePoint(int mark) {
    if (mark >= 80) return 5;
    if (mark >= 70) return 4;
    if (mark >= 60) return 3;
    if (mark >= 50) return 2;
    return 0;
}

// Function for Final Classification
const char* getClassification(float cgpa) {
    if (cgpa >= 4.40) return "First Class";
    if (cgpa >= 3.60) return "Second Class Upper";
    if (cgpa >= 2.80) return "Second Class Lower";
    if (cgpa >= 2.00) return "Pass";
    return "Fail";
}

int main() {
    // Corrected Identity constants
    const char* studentName = "SSENGENDO VICENT MPANGA";
    const char* studentReg = "24/U/BIE/11800/PE";
    
    // Semester 1 Data
    const char* codes1[] = {"TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"};
    const char* names1[] = {
        "Fundamentals of Engineering Mathematics", "Biochemistry and Medical Physics",
        "Electrical Engineering Science", "Mechanics I", "Computing I", 
        "Mechanical Drawing", "Engineering Profession", "Functional Anatomy and Physiology"
    };
    int credits1[] = {4, 3, 3, 3, 3, 3, 3, 3};

    // Semester 2 Data
    const char* codes2[] = {"TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204", "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"};
    const char* names2[] = {
        "Further Engineering Mathematics", "Computing II", "Mechatronics Drawing", 
        "Fluid Mechanics", "Thermodynamics", "Workshop Practice", 
        "Functional Anatomy and Physiology II", "Electronics I"
    };
    int credits2[] = {4, 3, 3, 3, 3, 3, 3, 3};

    int marks1[8], marks2[8];
    float wgp1[8], wgp2[8];
    float totalWGP1 = 0, totalWGP2 = 0;

    // Display Identity at start
    printf("========================================\n");
    printf("STUDENT: %s\n", studentName);
    printf("REG NO:  %s\n", studentReg);
    printf("========================================\n");

    // Input Semester 1
    printf("\n--- SEMESTER I MARKS ---\n");
    for(int i = 0; i < 8; i++) {
        printf("%s %s: ", codes1[i], names1[i]);
        scanf("%d", &marks1[i]);
        wgp1[i] = (float)getGradePoint(marks1[i]) * credits1[i];
        totalWGP1 += wgp1[i];
    }

    // Input Semester 2
    printf("\n--- SEMESTER II MARKS ---\n");
    for(int i = 0; i < 8; i++) {
        printf("%s %s: ", codes2[i], names2[i]);
        scanf("%d", &marks2[i]);
        wgp2[i] = (float)getGradePoint(marks2[i]) * credits2[i];
        totalWGP2 += wgp2[i];
    }

    float gpa1 = totalWGP1 / 25.0;
    float gpa2 = totalWGP2 / 25.0;
    float cgpa = (totalWGP1 + totalWGP2) / 50.0;

    // --- TRANSCRIPT OUTPUT ---
    printf("\n========================================================================================================\n");
    printf("                                     ACADEMIC PERFORMANCE REPORT\n");
    printf("========================================================================================================\n");
    printf("NAME: %-38s REG NO: %-20s\n", studentName, studentReg);
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("%-12s | %-40s | %-2s | %-5s | %-12s | %-10s\n", 
           "COURSE CODES", "COURSE NAMES", "CU", "GRADE", "GRADE POINTS", "WGP");
    printf("--------------------------------------------------------------------------------------------------------\n");

    printf("SEMESTER 1\n");
    for(int i = 0; i < 8; i++) {
        printf("%-12s | %-40s | %-2d | %-5s | %-12d | %-10.1f\n", 
                codes1[i], names1[i], credits1[i], getGradeLetter(marks1[i]), getGradePoint(marks1[i]), wgp1[i]);
    }
    printf("SEMESTER 1 GPA: %.2f\n", gpa1);
    
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("SEMESTER 2\n");
    for(int i = 0; i < 8; i++) {
        printf("%-12s | %-40s | %-2d | %-5s | %-12d | %-10.1f\n", 
                codes2[i], names2[i], credits2[i], getGradeLetter(marks2[i]), getGradePoint(marks2[i]), wgp2[i]);
    }
    printf("SEMESTER 2 GPA: %.2f\n", gpa2);

    printf("========================================================================================================\n");
    printf("FINAL YEAR ONE CGPA:   %.2f\n", cgpa);
    printf("CLASSIFICATION:        %s\n", getClassification(cgpa));
    printf("========================================================================================================\n");

    return 0;
}