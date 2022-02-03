# Assignment-1

**Team Members**
|   Enrollment No.  |   Name   | GithubId |
|   --------------  |   ----   | -------- |
|    IEC2021048 |   Pranav Tiwari | GammaMicrowave |
|    IEC2021049  |   Sreevardhan | sreevardhan0 | 
|    IEC2021046  |   Mohd Kaif |  iec2021046 |
|    IEC2021047  |   Shriyansh Lohiya |  LohiyaShriyansh |

**Group No-**"12"

**Faculty Name-**"Mohammed Javed Sir"

**Mentor Name-** "Md. Meraz"

---
## Problem Statement
Create a structure to specify data on students as given below: Roll number, Name, Department, Course, and Year of joining.
Assume that there are not more than 450 students in the college.                                        (a) Write a function to print the names of all students who joined in the last 3 years.			          (b) Write a function to print the data of a student whose roll numbers are divisible by 4

---
## How to use code
In our code we made the use of structure to store the data of the students, For the end user to use the code he would have to first enter of the above mentioned students and after entering data of the given students and after the program gets the value it would run 2 functions which would give the answers according to the problem statement.

```
#Download project
git clone https://github.com/PranavTiwari14/ITP2022/Group_Assignment_02/
```
Project Initialize 
```
cd ITP2022

#go to Group_Assignment_02
cd Group_Assignment_02

```
---

Compile and run the code
```
gcc Group_Assignment_02_code.c
a.exe
```
---

**Test case**

Find max
```
Test Case-1
Input:
Enter the number of students studying in the college : 4
Enter the roll number of student 1 : 46
Enter the name of student 1 : Mohd Kaif
Enter the department of student 1 : ECE
Enter the course of student 1 : LAL
Enter the joining year of student 1 : 2018
Enter the roll number of student 2 : 47
Enter the name of student 2 : Shriyansh Lohiya
Enter the department of student 2 : ECE
Enter the course of student 2 : ITP
Enter the joining year of student 2 : 2020
Enter the roll number of student 3 : 48
Enter the name of student 3 : Pranav  Tiwari
Enter the department of student 3 : ECE
Enter the course of student 3 : PoM
Enter the joining year of student 3 : 2016
Enter the roll number of student 4 : 49
Enter the name of student 4 : Sreevardhan
Enter the department of student 4 : ECE
Enter the course of student 4 : ECE
Enter the joining year of student 4 : 2019

Output:
Names of the students who joined in past 3 years are given below:-

Shriyansh Lohiya
Sreevardhan


Data of the Students whose Roll No. is divisible by 4 are given below:-

Roll number : 48
Name : Pranav  Tiwari
Department : ECE
Course : PoM
Year : 2016
```

--------------------------

### Theory
---
I.	Structure:
---

 A structure is a user defined data type in C. It is used to store multiple items under a single type. For example, it can be used to store price of all food grains in a shop.
One can initialize a structure by writing the below command:-
```
struct struct_name
{
//data_types_stored;
};
```
Here you can have multiple data types stored as mentioned above.

---
II.	DO WHILE LOOP:
---
A Do while loop is a repetition control structure which allows us to write a loop which runs until the condition in the while statement becomes false. In this kind of loop even when the condition is false the loop would run for one time, where as in While loop the loop would not run at all.
The basic form of declaring a Do while loop is given below:-
```
do
{
     //Statements you want to run in the loop.
} while(condition for the loop to repeat);
```
---
III.	FOR LOOP:
---
A for loop is used to make a loop executed for given number of times. Unlike Do while loop we can use this loop when we have fix conditions of initialization and some increments after each loop. The basic form of making a for loop is given below:-
```
for(initialization; ccondition ; increment)
{
    //statement you want to execute in the loop.
}
```
---
IV.	IF ELSE STATEMENTS:
---
If else statements are conditional statements which are used to run statements if they follow a certain condition mentioned by the if else statements. The basic form of writing a if else statement is given below :- 
```
If(condition)
{
    //body of the statement.
}
Else if(condition)
{
    //body of the statement.
}
Else{
    //body of the statement.
}
```
Here if none of the given conditions are true, instead of just ending the process the program would run the else statement since it doesn't have any condition. NOTE: You can only write one else statement per if else series.

---
V.	NESTING OF FOR LOOP:
---
Sometimes  we feel the need of adding another loop inside a existing loop in order to have 2 elements which changes on their own conditions. For example if one wants to input elements of 3x3 matrix, he/she cannot just go and make a loop for 9 elements, he/she would first have to make a loop for the rows followed by a loop of column such that each each time a row loop is running, the values of columns are the only one changing while row index is remaining constant.
	The basic form of declaring a nested loop in C is given below:-
  ```
for(initialization; condition ; increment)
{
   for(initialization; coniditon; increment)
       {
            //the statements that you want to execute.
        }
}
```


---

### Procedure:
In the start of our program, first we have made a structure outside the main function so that we can access it easily in corresponding functions. In this structure we have made variables which would store various information regarding the students like roll no, name, department, course and year of joining. In order to store numbers, we used unsigned short int for roll number, since we know that roll numbers are always positive and their values would be quite small for int data type therefore used short.
Furthermore, storing department name, course name and name of the student we made an array of 25 size of char. The code for this structure is given below: -

 ```
struct student_info
{

    // here roll number cannot be negative and can be only between 0 to 450.
    unsigned short int roll_number;

    // according to international standards name should not exceed 25 characters.
    char name[25], department[25], course[25];

    // year of join is small number so use unsigned short int.
    unsigned short int year;
};
 ```

  After making the structure, we have declared two functions with the argument of a struct data type pointer. So that inside the function we can use the dynamic array more freely. Code for that is given below:- 

```
void names_of_prev_3yrs_students (struct student_info *);

void data_of_student_whose_roll_is_divisible_by_4(struct student_info *);
```
  Now, after making the struct and declaring the function, we started the main function in which we first made use of do while loop to store the number of students the end user want to input, where according the conditions of the do while loop end user would have to enter a number x which would lie in the range of [0,450);
 
```
unsigned short int no_of_students;
    do
    {
        printf("Enter the number of students studying in the college : ");
        scanf("%hu", &no_of_students);
    } while (no_of_students <= 0 || no_of_students > 450);
```
  Now our next step is to take input of data of the ‘n’ students and we can do that by using a for loop and inputting each value of the data inside that loop. We also made use of %*c%[^\n]  to take input a whole line, since the name of a student can be multiple words and the same can be said about department and course. There also some intentional limiations established in this part of the code like the roll no of a student can be only in between  (0 to 450) and year of joining cannot be above 2021.
The code for the step is given below: - 

```
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
        //~ As to take space seperated names as input we use "%*c%[^\n]".

        printf("Enter the department of student %hu : ", i + 1);
        scanf("%*c% [^\n]", student[i].department);
        //~ As to take space seperated names as input we use "%*c%[^\n]".

        

        printf("Enter the course of student %hu : ", i + 1);
        scanf("%*c%[^\n]", student[i].course);
        //~ As to take space seperated names as input we use "%*c%[^\n]".

        do
        {
            printf("Enter the joining year of student %hu : ", i + 1);
            scanf("%hu", &student[i].year);
        } while (student[i].year > 2021);
        //~ this is the maximum number of years in which a student can complete his/her b-tech.
    }
```

  After finishing the given steps we have a complete structure filled with student datas, so the only thing left is to write 2 functions, One for the names of the students who joined the college in last 3 years and the second is the data of the students whose roll numbers are divisible by 4.
	For doing this we made 2 separate functions named respectively and used pointers to access the structural array which we made to store data of the students. 
	The first one is the names of the students joined in past 3 years, here we have taken a pointer as an argument this pointer points towards an element of the structural array. Now inside the function we use this pointer and dereference it to find the year of joining of a given student and if it is above 2019 it would just print the name of the student and return the nothing since it’s a void function.
```
void names_of_prev_3yrs_students(struct student_info *pointer)
{
    
    if ((*pointer).year >= 2019)
    {
        printf("%s\n", (*pointer).name);
    }
}
```
  The other function is about giving data of students whose roll number are divisible by 4. For this we would again take a pointer to structure student as an argument and use later dereference it to an element of the Student so that we can find the data of that student whose roll number is divisible by 4.
  
The code for the following is given below:- 
```
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
```
  With the above two functions defined we would now use a for loop where a pointer which points at the first element of the Student structure array would also go inside and after each time the loop runs it would change the pointer and make it so that it points towards the next element of the struct student. And after doing this for the first function we would repeat it again for the second function. The code for the following is given below:-
```
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
```


**Time Complexity**

  Time complexity is the amount of time taken by an algorithm to run, as a function of the length of the input. It measures the time taken to execute each statement of code in an algorithm.
  In, this program the time complexity for loops is O(n) and an algorithm is said to take linear time, or O(n) time, if its time complexity is O(n). Informally, this means that the running time increases at most linearly with the size of the input. More precisely, this means that there is a constant c such that the running time is at most c*n for every input of size n.


---
