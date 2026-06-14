#include <iostream>

using namespace std;

//Data structures to store information
struct Semester
{
    int CourseCount = 0;
    string CourseCode[8] = {""};
    int Credit[8] = {0};
    string grade[8] = {""};
    double SGPA = 0;
};

void SemesterHandler(int &sem, Semester s[8])
{
    int n;

    cout << "For Semester " << sem + 1 << endl;
    cout << "Enter number of courses: " << endl;
    cin >> n;

    s[sem].CourseCount = n;

    for (int i = 0; i < n; i++)
    {
        cout << "For Course " << i + 1 << " :" << endl;

        cout << "Enter course code: " << endl;
        cin >> s[sem].CourseCode[i];

        cout << "Enter credit hours" << endl;
        cin >> s[sem].Credit[i];

        cout << "Enter grade : " << endl;
        cin >> s[sem].grade[i];
    }
}

int GradePointConvertor(string grade)
{
    if (grade == "O")
        return 10;
    else if (grade == "A+")
        return 9;
    else if (grade == "A")
        return 8;
    else if (grade == "B+")
        return 7;
    else if (grade == "B")
        return 6;
    else if (grade == "C")
        return 5;
    else if (grade == "P")
        return 4;
    else
        return 0;
}

double sgpaCalculator(int sem, Semester s[8])
{
    int TotalCreditPoint = 0;

    for (int i = 0; i< s[sem].CourseCount; i++)
    {
        TotalCreditPoint +=
            s[sem].Credit[i] *
            GradePointConvertor(s[sem].grade[i]);
    }

    int TotalCredit = 0;

    for (int i = 0; i<s[sem].CourseCount;  i++)
    {
        TotalCredit += s[sem].Credit[i];
    }

    s[sem].SGPA =
        (double)TotalCreditPoint / TotalCredit;

    return s[sem].SGPA;
}

double cgpaCalculator(int semCount, Semester s[8])
{
    double TotalWeightedSGPA = 0;
    int TotalCredits = 0;

    for (int sem = 0; sem < semCount; sem++)
    {
        int SemesterCredits = 0;

        for (int i = 0; i<s[sem].CourseCount; i++)
        {
            SemesterCredits += s[sem].Credit[i];
        }

        TotalWeightedSGPA +=
            s[sem].SGPA * SemesterCredits;

        TotalCredits += SemesterCredits;
    }

    return TotalWeightedSGPA / TotalCredits;
}

void DisplayReport(int semCount, Semester s[8])
{
    for (int sem = 0; sem < semCount; sem++)
    {
        cout << "\n===== SEMESTER "
             << sem + 1
             << " =====\n\n";

        cout << "Course Code\tGrade\n";

        for (int i = 0; i < s[sem].CourseCount; i++)
        {
            cout << s[sem].CourseCode[i]
                 << "\t\t"
                 << s[sem].grade[i]
                 << endl;
        }

        cout << "\nSGPA : "
             << s[sem].SGPA
             << endl;
    }

    if (semCount == 8)
    {
        cout << "\nCGPA : "
             << cgpaCalculator(semCount, s)
             << endl;
    }
}

int main()
{
    //CGPA Calculator

    /* This software application will take inputs for course code,
       course name grade and credit for each course across the semester.
       Then it would calculate SGPA.

       After the 8th semester it would calculate CGPA.

       Following its calculation, all courses and the grades
       will be displayed semester-wise and the CGPA
       in the form of a Report as tasked.
    */

    Semester s[8];

    int Command = 1, ithSem = 0;
    cout<<"Hello user,  \n\tThis is a CGPA Calculator";

    do
    {
        cout << "=≠===≠=======\n Menu bar\n=============" << endl;

        cout << "1. Add Semester" << endl;
        cout << "2. Edit Semester" << endl;
        cout << "3. Calculate SGPA" << endl;
        cout << "4. Display Report" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter the command : " << endl;
        cin >> Command;

        switch (Command)
        {
        case 1:
        {
            if (ithSem < 8)
            {
                SemesterHandler(ithSem, s);
                ithSem++;
            }
            else
            {
                cout << "Maximum semesters reached." << endl;
            }

            break;
        }

        case 2:
        {
            int n;

            cout << "Enter Semester No :" << endl;
            cin >> n;

            if (n <= 0 || n > ithSem)
                cout << "Semester No. invalid " << endl;
            else
            {
              n=n-1;
                SemesterHandler(n , s);
                }

            break;
        }

        case 3:
        {
            if (ithSem != 0)
            {
                cout << "SGPA = "
                     << sgpaCalculator(ithSem - 1, s)
                     << endl;

                if (ithSem == 8)
                    cout << "CGPA = "
                         << cgpaCalculator(ithSem, s)
                         << endl;
            }
            else
            {
                cout << "Semester No. invalid\n";
            }

            break;
        }

        case 4:
        {
            if (ithSem != 0)
                DisplayReport(ithSem, s);
            else
                cout << "No semester data available." << endl;

            break;
        }

        case 5:
        {
            cout << "Exiting...." << endl;
            break;
        }

        default:
            cerr << "Error message : \n\t Invalid value" << endl;
        }

    } while (Command != 5);

    return 0;
}
