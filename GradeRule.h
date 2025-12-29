#ifndef GRADERULE_H
#define GRADERULE_H

#include <vector>
#include <iostream>

class GradeRule {
private:
    double minScore;
    double maxScore;
    double gradePoints;

public:
    GradeRule(double minS, double maxS, double gp)
        : minScore(minS), maxScore(maxS), gradePoints(gp) {}

    bool matches(double score) const {
        return score >= minScore && score <= maxScore;
    }

    double getGradePoints() const {
        return gradePoints;
    }
};

class GradingScale {
    private:
        std::vector<GradeRule> rules;

    public:
        void addRule(double minScore, double maxScore, double gradePoints) 
        {
        rules.push_back(GradeRule(minScore, maxScore, gradePoints));
        }


        double getCoursGradePoints(double score) const {
            for (const GradeRule& rule : rules) {
                if (rule.matches(score)) {
                    return rule.getGradePoints();
                }
            }

            std::cout << "Error: Invalid score " << score << std::endl;
            return 0.0;
        }

        
    };

#endif // GRADERULE_H
