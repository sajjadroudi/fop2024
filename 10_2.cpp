#include <iostream>
#define MAX_ARRAY_LENGTH 100

using namespace std;

typedef struct {
    string courseId;
    string studentId;
    float grade;
} CourseStudent;

int main() {
    CourseStudent array[MAX_ARRAY_LENGTH];
    int size = 0;

    while(true) {
        string command;
        cin >> command;

        if(command == "ADD") {
            // With the current implementation of structures, no need to do anything here!
        } else if(command == "GRADE") {
            while(true) {
                string courseId;
                cin >> courseId;

                if(courseId == "END")
                    break;

                string studentId;
                cin >> studentId;

                float grade;
                cin >> grade;

                CourseStudent item = {courseId, studentId, grade};
                array[size] = item;
                size++;
            }

        } else if(command == "STATS") {

            while(true) {
                string type;
                cin >> type;

                if(type == "END")
                    break;

                string id;
                cin >> id;

                if(type == "STUDENT") {
                    for(int i = 0; i < size; i++) {
                        if(array[i].studentId == id) {
                            printf("%s %.2f\n", array[i].courseId.c_str(), array[i].grade);
                        }
                    }
                } else {
                    for(int i = 0; i < size; i++) {
                        if(array[i].courseId == id) {
                            printf("%s %.2f\n", array[i].studentId.c_str(), array[i].grade);
                        }
                    }
                }
            }

        } else if(command == "EXIT") {
            return 0;
        }
    }
}