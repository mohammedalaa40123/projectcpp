void enroll(string StudentID, string courseName, string grade)
{
    lower(StudentID);
    lower(courseName);

    if (!Course::exist(courseName))
    {
        cout << "This course does not exist;" << endl;
        return;
    }

    if (student::Students[StudentID].course_grade.find(courseName) != student::Students[StudentID].course_grade.end())
    {
        cout << "student already enrolled in this course";
        return;
    }

    Course::Courses[courseName].no_students++;
    student::Students[StudentID].course_grade[courseName] = grade;
    student::Students[StudentID].no_courses++;
}

void drop(string StudentID, string courseName)
{
    lower(StudentID);
    lower(courseName);

    if (!Course::exist(courseName))
    {
        cout << "This course does not exist;" << endl;
        return;
    }

    if (student::Students[StudentID].course_grade.find(courseName) == student::Students[StudentID].course_grade.end())
    {
        cout << "student not enrolled in this course";
        return;
    }

    Course::Courses[courseName].no_students--;
    student::Students[StudentID].course_grade.erase(courseName);
    student::Students[StudentID].no_courses--;
}

void delete_student(string id1)
{
    if (!student::exist(id1))
    {
        cout << "This ID does not exist" << endl;
        return; // cout
    }

    for (auto z = student::Students[id1].course_grade.begin(); z != student::Students[id1].course_grade.end(); z++)
    {
        drop(id1, (z->first).getName());
    }

    student::Students.erase(id1);
}