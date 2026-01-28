#include<iostream>
using namespace std;

// Calculating the Average marks
float calculateAverage(int marks[], int numSubjects){
       int sum =0;
       for(int i=0; i<numSubjects; i++){
               sum += marks[i];
       }
  return static_cast<float>(sum)/numSubjects;
}

// Determining the grades as per average marks
char determineGrade(float average){
     if(average>=90){
            return 'A';
     }
    else if(average >= 80&& average< 90){
            return 'B';
     }
    else if(average >= 70 && average< 80){
            return 'C';
     }
     else if(average >=60 && average<70){
            return 'D';
      }
     else if(average < 60){
            return 'F';
     }
}

// Displaying the final result
void displayResult(int marks[], int numSubjects, char grade, float average) {
    cout << "\n------ Student Result ------\n";
    for (int i = 0; i < numSubjects; i++) {
        cout << "Subject " << i + 1 << ": " << marks[i] << endl;
    }
    cout << "Average Marks: " << average << endl;
    cout << "Final Grade: " << grade << endl;
}

// Main function
int main(){
    int numSubjects;
    cout<<"Enter the number of subjects"<<endl;
    cin>>numSubjects;

    if(numSubjects<=0){
        cout<<"Invalid numbers of subjects"<<endl;
        return 0;
    }

    cout<<"Enter the marks for each subject"<<endl;
    int marks[numSubjects];

    for(int i=0; i<numSubjects; i++){
        do{
          cout<<"Enter marks for subject "<<i+1<<" (0-100)"<<endl;
          cin>>marks[i];
        if(marks[i]<0 || marks[i]>100){
            cout<<"Invalid marks! Please enter marks between 0 to 100"<<endl;
        }
        } while(marks[i]<0 || marks[i]>100);
    }

    float average = calculateAverage(marks,numSubjects);
    char grade = determineGrade(average);
    displayResult(marks, numSubjects, grade, average);

    return 0;
}


