/*class student{
    string name,id,department,grade;
    int no_courses;
    string *courses;
    char*grades;
    float GPA;
    public:
void add_student(){
    ofstream fo{"Student data.txt",ios::app};
    cout<<"What is the student's name:";
    getline(cin,name);
    cout<<"What is the student's ID:";
    cin>>id;
    cout<<"What is the department of the student:";
    getline(cin,department);
    getline(cin,department);
    cout<<"Enter the number of courses:";
    cin>>no_courses;
    courses=new string[no_courses];
    grades=new char[no_courses];
    for(int i=0;i<no_courses;i++){
        cout<<"Enter the name of the course #"<<i+1<<":";
        getline(cin,courses[i]);
        getline(cin,courses[i]);
        cout<<"Enter the grade in that course:";
        cin>>grades[i];
    }
    cout<<"What is his GPA:";
    cin>>GPA;
    cout<<"What is his current grade:";
   getline(cin,grade);
   getline(cin,grade);
    fo<<name<<endl<<id<<endl<<department<<endl<<no_courses<<endl;
    for(int i=0;i<no_courses;i++)
        fo<<courses[i]<<endl;
    for(int i=0;i<no_courses;i++)
        fo<<grades[i]<<endl;
    fo<<GPA<<endl;
    fo<<grade<<endl;
}
void list_students(){
ifstream of{"Student data.txt"};
int i=0;
while(of){
    string s;
    getline(of,s);
    if(s.size()==0)
        break;
    i++;
cout<<"Student #"<<i<<":"<<endl;

cout<<"Name:";

cout<<s<<endl;
cout<<"ID:";
getline(of,s);
cout<<s<<endl;
cout<<"Department:";
getline(of,s);
cout<<s<<endl;
int num;
string * cour;
char *grad;
cout<<"Number of courses:";
of>>num;
cout<<num<<endl;
cour=new string[num];
grad=new char[num];
getline(of,cour[i]);
for(int i=0;i<num;i++){

    getline(of,cour[i]);
}
for(int i=0;i<num;i++){
    of>>grad[i];
}
for(int i=0;i<num;i++){
    cout<<"Course #"<<i+1<<":";
    cout<<cour[i]<<endl;
    cout<<"Its grade:";
    cout<<grad[i]<<endl;
}
cout<<"GPA:";
getline(of,s);
getline(of,s);
cout<<s<<endl;
cout<<"Grade:";
getline(of,s);

cout<<s<<endl;

}
}

};
int main()
{
    student s;
    s.add_student();
    s.list_students();


    return 0;
}*/

