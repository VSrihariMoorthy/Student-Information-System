#include<stdio.h>
#include<stdlib.h>
void add();
void update();
void view_studentf();
void course();
void findstudent_course();
void count_student();
void find_student();
void delete_student();

struct student
{
    int roll;
    char fname[30],lname[30];
    float cgpa;
    char course[10];
}s;

int main()
{
    int choice;

    do
    {
        printf("Enter a choice:\n1.Add\n2.Update\n3.View Students\n4.Search Student by roll no\n5.Delete\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            update();
            break;
        case 3:
            view_studentf();
            break;
        case 4:
            find_student();
            break;
        case 5:
            delete_student();
            break;
        case 6:
            exit(1);
        default:
            printf("Invalid Choice");
        }
    }
    while(choice!=6);
    return 0;

}
void add()
{

    printf("Student Roll No.: ");
    scanf("%d",&s.roll);
    printf("Student first name: ");
    fflush(stdin);
    fgets(s.fname,30,stdin);
    printf("Student last name: ");
    fflush(stdin);
    fgets(s.lname,30,stdin);
     int choice;
    char rc[20];
    do{
    printf(" 1. COMPUTER SCIENCE ENGINEERING\n 2.MECHANICAL ENGINEERING\n  3.ELECTRONICS AND COMMUNICATION ENGINEERING \n  4.COMPUTER AND        COMMUNICATION ENGINEERING\n 5. ARTIFICIAL INTELLEGRNCE\n ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            rc="COMPUTER SCIENCE ENGINEERING";
            break;
        case 2:
            rc=".MECHANICAL ENGINEERING";
            break;
        case 3:
            rc="ELECTRONICS AND COMMUNICATION ENGINEERING";
            break;
        case 4:
           rc=".COMPUTER AND COMMUNICATION ENGINEERING";
            break;
        case 5:
            rc="ARTIFICIAL INTELLEGRNCE";
            break;
        default:
            printf("invalid");
        }
    }while(choice>=5);
    
    printf("Course: ");
    scanf("%s",&s.course);
    printf("CGPA: ");
    scanf("%f",&s.cgpa);
    FILE* fp;
    fp=fopen("student.dat","ab+");
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
}


void update()
{
    FILE *fp,*tmpfp;
    fp=fopen("student.dat","r");
    tmpfp=fopen("tmp.dat","w");
    int rollno,ch;
    printf("Enter roll no.: ");
    scanf("%d",&rollno);
    while(fread(&s,sizeof(s),1,fp))
    {
        if(s.roll==rollno)
        {
            printf("Choose:\n1.Student first name\n2.Student last name\n3.Course\n4.CGPA\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                printf("Student first name: ");
                fflush(stdin);
                fgets(s.fname,30,stdin);
                break;
            case 2:
                printf("Student last name: ");
                fflush(stdin);
                fgets(s.lname,30,stdin);
                break;
            case 3:
                printf("Course: ");
                scanf("%s",&s.course);
                break;
            case 4:
                printf("CGPA: ");
                scanf("%f",&s.cgpa);
                break;
            default:
                printf("Invalid");
            }
            fwrite(&s,sizeof(s),1,tmpfp);
        }
        else
        {
            fwrite(&s,sizeof(s),1,tmpfp);
        }
    }
    fclose(fp);
    fclose(tmpfp);
    remove("student.dat");
    rename("tmp.dat","student.dat");
}

void view_studentf()
{
    FILE *fp;
    fp=fopen("student.dat","r");
    while(fread(&s,sizeof(s),1,fp))
    {
        printf("\nStudent Roll No.: %d",s.roll);
        printf("\nStudent first name: %s",s.fname);
        printf("Student last name: %s",s.lname);
        printf("Course: %s",s.course);
        printf("\nCGPA: %f\n",s.cgpa);
    }
    fclose(fp);
}

void find_student()
{
    int rollno;
    FILE *fp;
    fp=fopen("student.dat","r");
    printf("Enter a roll no to be searched: ");
    scanf("%d",&rollno);
    while(fread(&s,sizeof(s),1,fp))
    {
        if(s.roll==rollno)
        {
            printf("\nStudent Roll No.: %d",s.roll);
            printf("\nStudent first name: %s",s.fname);
            printf("Student last name: %s",s.lname);
            printf("Course: %s",s.course);
            printf("\nCGPA: %f\n",s.cgpa);
            break;
        }
    }
    fclose(fp);
}

void delete_student()
{
    int found = 0;
    int studentDelete = 0;

    struct student s = {0};
    FILE *fp;
    FILE *tmp;
    fp = fopen("student.dat","r");
    tmp= fopen("tmp.dat","w");
    printf("\n\t\t\tEnter Student ROLL NO. for delete:");
    scanf("%d",&studentDelete);
    while (fread (&s, sizeof(s), 1, fp))
    {
        if(s.roll!= studentDelete)
        {
            fwrite(&s,sizeof(s), 1, tmp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmp);
    remove("student.dat");
    rename("tmp.dat","student.dat");
}
void findstudent_course()
{
    char rgc[30];
    FILE*fp;
    fp=fopen("student.dat","r");
    printf("\n enter the course of the student to be found: ");
    scanf("%s",&rgc);
    while(fread(&s,sizeof(s),1,fp))
    {
      if(!(strcmpi(rgc,s.course)))
        {
        printf("\nStudent Roll No.: %d",s.roll);
        printf("\nStudent first name: %s",s.fname);
        printf("Student last name: %s",s.lname);
        printf("Course: %s",s.course);
        printf("\nCGPA: %f\n",s.cgpa);
        }
      }
      fclose(fp);
}
void count_student()
{
    int count=0;
    FILE*fp;
    fp=fopen("student.dat","r");
    while(fread(&s,sizeof(s),1,fp))
    {
        count++;
    }
     printf("no of students in database :%d",count);
     fclose(fp);
}

