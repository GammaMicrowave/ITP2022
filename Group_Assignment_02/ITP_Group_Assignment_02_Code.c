#include <stdio.h>
struct student_info
{

    //^ here roll number cannot be negative and can be only between 0 to 450.
    unsigned short int roll_number;

    //^ according to international standards name should not exceed 25 charecters.
    char name[25], department[25], course[25];

    //^ year of join is small number so use unsigned short int.
    unsigned short int year;
};

void names_of_prev_3yrs_students(struct student_info *);

void data_of_student_whose_roll_is_divisible_by_4(struct student_info *);

int main()
{
    unsigned short int no_of_students;
    do
    {
        printf("Enter the number of students studying in the college : ");
        scanf("%hu", &no_of_students);
    } while (no_of_students <= 0 || no_of_students > 450);
    //~ As per the question students are not more than 450 and students can't be 0.

    struct student_info student[no_of_students], *ptr;
    //~ dynamic initialization of structures.

    ptr = student;
    //~initializing the pointer to the structure.

    //~ taking input of all the students.
    for (unsigned short int i = 0; i < no_of_students; i++)
    {
        do
        {
            printf("Enter the roll number of student %hu : ", i + 1);
            scanf("%hu", &student[i].roll_number);
        } while (student[i].roll_number <= 0 || student[i].roll_number > 450);
        //~ As per the question students are not more than 450 and students can't be 0.

        printf("Enter the name of student %hu : ", i + 1);
        scanf("%*c%[^\n]", student[i].name);
        //~ As to take space seperated names as input we use "%[^\n]".

        printf("Enter the department of student %hu : ", i + 1);
        scanf("%*c%[^\n]", student[i].department);
        //~ As to take space seperated names as input we use "%[^\n]".

        printf("Enter the course of student %hu : ", i + 1);
        scanf("%*c%[^\n]", student[i].course);
        //~ As to take space seperated names as input we use "%[^\n]".

        do
        {
            printf("Enter the joining year of student %hu : ", i + 1);
            scanf("%hu", &student[i].year);
        } while (student[i].year > 2021);
        //~ this is the maximum number of years in which a student can complete his/her b-tech.
    }
    printf("\n\nNames of the students who joined in past 3 years are given below:-\n\n");
    for (unsigned short int i = 0; i < no_of_students; i++, ptr++)
    {
        names_of_prev_3yrs_students(ptr);
        //~sending data in the form of pointer to reduce memory allocation.
    }

    ptr = student;
    //~reinitializing the pointer to the structure.
    printf("\n\nData of the Students whose Roll No. is divisible by 4 are given below:-\n\n");
    for (unsigned short int i = 0; i < no_of_students; i++, ptr++)
    {
        data_of_student_whose_roll_is_divisible_by_4(ptr);
    }

    return 0;
}

void names_of_prev_3yrs_students(struct student_info *pointer)
{

    if ((*pointer).year >= 2019)
    {
        printf("%s\n", (*pointer).name);
    }
}
void data_of_student_whose_roll_is_divisible_by_4(struct student_info *pointer)
{

    if ((*pointer).roll_number % 4 == 0)
    {
        printf("Roll number : %hu\n", (*pointer).roll_number);
        printf("Name : %s\n", (*pointer).name);
        printf("Department : %s\n", (*pointer).department);
        printf("Course : %s\n", (*pointer).course);
        printf("Year : %hu\n\n", (*pointer).year);
    }
}

// References : 1.https://www.quora.com/What-does-scanf-n-c-name-mean
