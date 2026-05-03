#include<stdio.h>

typedef struct
{
    char name[20];
    int age;
    float gpa;
}Student;

void print(Student student)
{
    printf("\nName: %s ",student.name);
    printf("\nAge: %d ",student.age);
    printf("\nGPA: %.1f ",student.gpa);
    printf("\n");
}

int main()
{
    int n;
    Student student[10];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",student[i].name);
        scanf("%d",&student[i].age);
        scanf("%f",&student[i].gpa);
    }
    
    for(int i=0; i<n; i++)
    print(student[i]);
}