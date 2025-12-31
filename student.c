#include <stdio.h>

/* 
   Structure to store student information 
*/
struct student {
    int roll_no;         // Student roll number
    char name[50];       // Student name
    char course[50];     // Course name
    int year;            // Academic year
    float gpa;           // Grade Point Average
};

/*
   Function declaration
   This function will save student data into a file
*/
void addstudent(struct student s);

int main() {

    // Program start message
    printf("Student Sphere project started!\n");

    // Declare a structure variable of type student
    struct student s;

    // Taking input from the user
    printf("Enter roll number, name, course, year and GPA:\n");
    scanf("%d %s %s %d %f", 
          &s.roll_no, 
          s.name, 
          s.course, 
          &s.year, 
          &s.gpa);

    // Displaying entered student data
    printf("\nEntered Data:\n");
    printf("Roll: %d\nName: %s\nCourse: %s\nYear: %d\nGPA: %.2f\n",
           s.roll_no, s.name, s.course, s.year, s.gpa);

    // Call function to save student data in file
    addstudent(s);

    // Confirmation message
    printf("Student added successfully!\n");

    return 0;
}

/*
   Function Definition
   Saves student data into a file using file handling
*/
void addstudent(struct student s) {

   FILE *fp;   // File pointer

   // Open file in append mode (adds data without deleting old data)
   // using "students.txt" as the file name
   fp = fopen("students.txt", "a");

   // Check if file opened successfully
   if (fp == NULL) {
       printf("Error opening file!\n");
       return;
   }

   // Write student data into the file 
   fprintf(fp, "%d %s %s %d %.2f\n",
           s.roll_no, s.name, s.course, s.year, s.gpa);

   // Close the file 
   fclose(fp);
}