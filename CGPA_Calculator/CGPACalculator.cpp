#include <iostream>
#include <iomanip>   // for std::fixed and std::setprecision
#include "CGPA.hpp"

int main() {
    CGPACalculator calculator;

	// Define grading rules
	calculator.getScale().addRule(90, 100, 4.0);
	calculator.getScale().addRule(80, 89, 3.0);
	calculator.getScale().addRule(70, 79, 2.0);
	calculator.getScale().addRule(60, 69, 1.0);
	calculator.getScale().addRule(0, 59, 0.0);

    calculator.addCourse(Course(95, 4)); // Math
    calculator.addCourse(Course(85, 3)); // Physics
    calculator.addCourse(Course(78, 3)); // Programming


    int totalCredits = calculator.getTotalCreditHours();
    double totalWeightedScore = calculator.getTotalWeightedScore();
    double gpa = calculator.calculateGPA();

    

    std::cout << "========== Academic Results ==========\n";
    std::cout << "Total Credit Hours : " << totalCredits << "\n";
    std::cout << "Total weighted score: " << totalWeightedScore << "\n";
    std::cout << "GPA               : "
              << std::fixed << std::setprecision(2)
              << gpa << "\n";
    std::cout << "======================================\n";

    return 0;
}
