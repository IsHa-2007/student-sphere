#include <stdio.h>
  
struct student {
    int roll_no;         
    char name[50];
    char course[50];
    int year;
    float gpa;
};

void addstudent(struct student s);
int main() {
    printf("Student Sphere project started!\n");
    struct student s;
    printf("Enter roll number, name, course, year and GPA:\n");
    scanf("%d %s %s %d %f", &s.roll_no, s.name, s.course, &s.year, &s.gpa);
    printf("\nEntered Data:\n");
    printf("Roll: %d\nName: %s\nCourse: %s\nYear: %d\nGPA: %.2f\n",
           s.roll_no, s.name, s.course, s.year, s.gpa);

           addstudent(s);
           printf("Student added successfully!\n");
    return 0;
}
void addstudent(struct student s) {
   FILE *fp;
   fp = fopen("students.exe", "a");
   if (fp == NULL) {
       printf("Error opening file!\n");
       return;
   }
   fprintf(fp, "%d %s %s %d %.2f\n", s.roll_no, s.name, s.course, s.year, s.gpa);
   fclose(fp);  

}
