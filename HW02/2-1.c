#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MAX_TEACHERS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char preferences[MAX_TEACHERS][MAX_NAME_LENGTH];
    char assigned_teacher[MAX_NAME_LENGTH];
} Student;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char preferences[MAX_STUDENTS][MAX_NAME_LENGTH];
    bool taken;
} Teacher;

void match_students_and_teachers(Student students[], Teacher teachers[], int num_students, int num_teachers) {
    for (int i = 0; i < num_students; ++i) {
        for (int j = 0; j < num_teachers; ++j) {
            char* preferred_teacher = students[i].preferences[j];
            bool teacher_taken = false;
            for (int t = 0; t < num_teachers; ++t) {
                if (strcmp(preferred_teacher, teachers[t].name) == 0) {
                    for (int k = 0; k < num_students; ++k) {
                        if (strcmp(teachers[t].preferences[k], students[i].name) == 0) {
                            if (!teachers[t].taken) {
                                strcpy(students[i].assigned_teacher, preferred_teacher);
                                teachers[t].taken = true;
                                teacher_taken = true;
                                break;
                            }
                        }
                    }
                    if (teacher_taken) break;
                }
            }
            if (teacher_taken) break;
        }
    }
}

int main() {
    Student students[MAX_STUDENTS];
    Teacher teachers[MAX_TEACHERS];
    int num_students, num_teachers;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    printf("Enter the number of teachers: ");
    scanf("%d", &num_teachers);

    for (int i = 0; i < num_students; ++i) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
    }

    printf("Enter the preferences of the students:\n");
    for (int i = 0; i < num_students; ++i) {
        printf("Enter the preferences for student %s: ", students[i].name);
        for (int j = 0; j < num_teachers; ++j) {
            scanf("%s", students[i].preferences[j]);
        }
    }

    printf("Enter the names of the teachers: ");
    for (int i = 0; i < num_teachers; ++i) {
        printf("Enter the name of teacher %d: ", i + 1);
        scanf("%s", teachers[i].name);
        teachers[i].taken = false;
    }

    printf("Enter the preferences of the teachers:\n");
    for (int i = 0; i < num_teachers; ++i) {
        printf("Enter the preferences for teacher %s: ", teachers[i].name);
        for (int j = 0; j < num_students; ++j) {
            scanf("%s", teachers[i].preferences[j]);
        }
    }

    match_students_and_teachers(students, teachers, num_students, num_teachers);

    printf("\nMatching results:\n");
    for (int i = 0; i < num_students; ++i) {
        printf("%s is assigned to %s\n", students[i].name, students[i].assigned_teacher);
    }
    return 0;
}
