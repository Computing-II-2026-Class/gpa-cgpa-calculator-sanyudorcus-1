/*
Name: SANYU DORCUS 
Registration Number: 25/U/BIE/01420/PE
*/

 #include <stdio.h>

/* --- FUNCTION PROTOTYPES --- */
float getGradePoint(float score) {
    if (score >= 80) return 5.0;
    if (score >= 70) return 4.0;
    if (score >= 60) return 3.0;
    if (score >= 50) return 2.0;
    return 0.0;
}

char* getGrade(float score) {
    if (score >= 80) return "A";
    if (score >= 70) return "B";
    if (score >= 60) return "C";
    if (score >= 50) return "D";
    return "F";
}

int main() {
    // Exact Course Codes from curriculum
    char *sem1_codes[] = {"TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", 
                          "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"};
    char *sem2_codes[] = {"TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204", 
                          "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"};

    // Exact Credit Units
    int sem1_units[] = {4, 3, 3, 3, 3, 3, 2, 3}; 
    int sem2_units[] = {4, 3, 3, 3, 3, 3, 3, 3}; 

    float sem1_scores[8], sem2_scores[8];
    float total_weighted1 = 0, total_weighted2 = 0;
    int total_credits1 = 0, total_credits2 = 0;

    printf("Enter the 16 scores in the following order:\n\n");

    // --- Input Semester I ---
    printf("Semester I\n");
    for(int i = 0; i < 8; i++) {
        printf("%d. %s: ", i + 1, sem1_codes[i]);
        if (scanf("%f", &sem1_scores[i]) != 1 || sem1_scores[i] < 0 || sem1_scores[i] > 100) {
            printf("Invalid score entered\n"); // Termination rule
            return 0;
        }
        total_weighted1 += getGradePoint(sem1_scores[i]) * sem1_units[i];
        total_credits1 += sem1_units[i];
    }

    // --- Input Semester II ---
    printf("\nSemester II\n");
    for(int i = 0; i < 8; i++) {
        printf("%d. %s: ", i + 9, sem2_codes[i]);
        if (scanf("%f", &sem2_scores[i]) != 1 || sem2_scores[i] < 0 || sem2_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
        total_weighted2 += getGradePoint(sem2_scores[i]) * sem2_units[i];
        total_credits2 += sem2_units[i];
    }

    float gpa1 = total_weighted1 / total_credits1;
    float gpa2 = total_weighted2 / total_credits2;
    float cgpa = (total_weighted1 + total_weighted2) / (total_credits1 + total_credits2);

    // --- Full Academic Report Output ---
    printf("\n%-12s %-8s %-8s %-8s %-8s %-15s\n", "Course", "Score", "Grade", "GP", "Unit", "Weighted");
    printf("------------------------------------------------------------\n");
    
    for(int i = 0; i < 8; i++) {
        // FIX: Pass the SCORE (sem1_scores[i]) to the functions, not the CODE
        printf("%-12s %-8.1f %-8s %-8.1f %-8d %-15.1f\n", 
               sem1_codes[i], sem1_scores[i], 
               getGrade(sem1_scores[i]), 
               getGradePoint(sem1_scores[i]), 
               sem1_units[i], 
               getGradePoint(sem1_scores[i]) * sem1_units[i]);
    }
    for(int i = 0; i < 8; i++) {
        // FIX: Pass the SCORE (sem2_scores[i]) to the functions, not the CODE
        printf("%-12s %-8.1f %-8s %-8.1f %-8d %-15.1f\n", 
               sem2_codes[i], sem2_scores[i], 
               getGrade(sem2_scores[i]), 
               getGradePoint(sem2_scores[i]), 
               sem2_units[i], 
               getGradePoint(sem2_scores[i]) * sem2_units[i]);
    }

    // --- Required Summary Output ---
    printf("\nSemester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);
    
    printf("Classification: ");
    if (cgpa >= 4.40) printf("First Class\n");
    else if (cgpa >= 3.60) printf("Second Class Upper\n");
    else if (cgpa >= 2.80) printf("Second Class Lower\n");
    else if (cgpa >= 2.00) printf("Pass\n");
    else printf("Fail\n"); // Below 2.00

    return 0;
}

/* --- FUNCTION DEFINITIONS --- */

// Logic based on required Grading Scale

       