#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student {
  double gpa;
  char *name;
  char homeroom;
  int grade;
};
void create(struct student *myStructuredStudent){
  srand(time(NULL));
  (*myStructuredStudent).gpa=(rand()%10000)/100.0;
  (*myStructuredStudent).name="Mario Tutuncu-Macias";
  (*myStructuredStudent).homeroom=rand()%128;
  (*myStructuredStudent).grade=rand()%4 * 2 + 1;
}
void structurePrinting(struct student myStructuredStudent){
  if(myStructuredStudent.gpa>65){
    printf("The student %s has a gpa of %lf, which is passing. His homeroom is %d%c%c\n",myStructuredStudent.name,myStructuredStudent.gpa,myStructuredStudent.grade,myStructuredStudent.homeroom,myStructuredStudent.homeroom);
  }
  else{
    printf("The student %s has a gpa of %lf, which is failing (to be expected). His homeroom is %d%c%c\n",myStructuredStudent.name,myStructuredStudent.gpa,myStructuredStudent.grade,myStructuredStudent.homeroom,myStructuredStudent.homeroom);
  }
}

void increaseGpa(struct student *myStructuredStudent, double increment){
  (*myStructuredStudent).gpa=(*myStructuredStudent).gpa+increment;
  printf("Let's try helping him out by giving him 7 points \n");
}
void increaseGrade(struct student *myStructuredStudent){
  (*myStructuredStudent).grade=(*myStructuredStudent).grade+2;
  printf("Oh Look, he's growing up\n");
}

int main(){
  struct student myStructuredStudent;
  create(&myStructuredStudent);
  structurePrinting(myStructuredStudent);
  increaseGpa(&myStructuredStudent,7);
  structurePrinting(myStructuredStudent);
  increaseGrade(&myStructuredStudent);
  structurePrinting(myStructuredStudent);
  return 0;
}
