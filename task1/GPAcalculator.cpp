#include <iostream>
using namespace std;
// Course Class
class Course {
private:
    double gPoints;
    size_t credit_hours;
public:
    void writeGrade(string g) {
        if( g=="A+" || g=="A") gPoints=4.00;
        else if( g=="A-" ) gPoints=3.67;
        else if( g=="B+" ) gPoints=3.33;
        else if( g=="B"  ) gPoints=3.00;
        else if( g=="B-" ) gPoints=2.67;
        else if( g=="C+" ) gPoints=2.33;
        else if( g=="C"  ) gPoints=2.00;
        else if( g=="C-" ) gPoints=1.67;
        else if( g=="D+" ) gPoints=1.33;
        else if( g=="D"  ) gPoints=1.00;
        else if( g=="F"  ) gPoints=0.00;
        else throw runtime_error("Invalid Inputs!");
    }
    void   writeChour(size_t ch) { credit_hours=ch; }
    double readGPoint() const { return gPoints; }
    size_t readChours() const { return credit_hours; }
};
// Helper Functions
double sum(double* products,size_t courses) {
    double summation=0;
    for(size_t i=0;i<courses;i++)
        summation+=products[i];
    return summation;
}
double sum(Course* c,size_t courses) {
    double summation=0;
    for(size_t i=0;i<courses;i++)
        summation+=c[i].readChours();
    return summation;
}
double* pro(Course* c,size_t courses) {
    double *products=new double[courses];
    for(size_t i=0;i<courses;i++) {
        products[i]=c[i].readGPoint()*c[i].readChours();
    }
    return products;
}
void result(Course* c,size_t courses) {
    double* pros=pro(c,courses);
    double result=sum(pros,courses)/sum(c,courses);
    cout<<"\nResult:\nGPA: "<<result;
    delete[] pros; pros=nullptr;
}
// Main Function
int main() {
    size_t courses;
    cout<<"Enter the number of courses: "; cin>>courses;
    Course *c=new Course[courses];
    string grade;
    size_t credit_hours;
    for(size_t i=0;i<courses;i++) {
        cout<<"\nEnter Data For Course "<<i+1<<":\n";
        cout<<"Grade: "; cin>>grade;
        cout<<"Credit Hours: "; cin>>credit_hours;
        c[i].writeGrade(grade);
        c[i].writeChour(credit_hours);
    }
    result(c,courses);
    delete[] c; c=nullptr;
    return 0;
}