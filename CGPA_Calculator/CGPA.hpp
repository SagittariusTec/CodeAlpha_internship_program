#include <iostream>
#include <string>
#include "GradeRule.h"
#include <vector>

using std::string;
using std::cout;
using std::endl;
//----------------
//this class represent each course
//-------------------
class Course 
{
	private:
		double finalGrade;
		int creditHours;
	public:
	//constructor
		Course(double finalGrade, int creditHours):finalGrade(finalGrade), creditHours(creditHours){};
	//access method
		double getFinalGrade () const {
			return finalGrade;
		}

		int getCreditHours () const{
			return creditHours;
		}
		//weighted score is the grade of the course multiplied with the credited of the smae course (not every course hase the same impact on the CGPA)
		double getWeightedScore(const GradingScale& scale) const {
    		return scale.getCoursGradePoints(getFinalGrade()) * creditHours;
		}

		void display() const {
			cout <<"| Credit Hours: " << creditHours << " | Final Grade: " << finalGrade << endl;
		}
};

//--------------
//this class represent all the courses created and add them to a vector
//--------------------

class CGPACalculator 
{
	private: 
		std::vector<Course> courses;
		GradingScale gradingScale;
	public:
	//adding a course to the vector of courses
		void addCourse(const Course& course){
			courses.push_back(course);
		}

		// Non-const version (used in main to add rules)
		GradingScale& getScale() {
			return gradingScale;
		}

		// Const version (used internally during GPA calculation)
		const GradingScale& getScale() const {
			return gradingScale;
		}


		//get the total credite hourse of all the courses
		int getTotalCreditHours() const {
			int sum = 0;
			for (const Course& c : courses) {
				sum += c.getCreditHours();
			}
			return sum;
		}

		//return the total of weighted score of all the courses
		double getTotalWeightedScore() {
    		double sumw = 0.0;
			for (const Course& c : courses) {
			sumw += c.getWeightedScore(getScale());
			}
				
    		return sumw;
		}

		void displayCourses () const {
			for (int i = 0; i < courses.size(); i++){
				courses[i].display();
			}
		}


		//return the GPA
		double calculateGPA() {
    		int totalCredits = getTotalCreditHours();
			double totalWeightedScore = getTotalWeightedScore();
    		return totalWeightedScore / totalCredits;
		}

};
