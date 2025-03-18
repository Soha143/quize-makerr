#include <iostream>
#include <vector>
#include <string>

using namespace std; 

struct Question {
    string question;
    vector<string> options;
    int correctAnswer;
};


void addQuestion(vector<Question> &quiz) {
    Question q;
    cin.ignore();

    cout << "Enter question: ";
    getline(cin, q.question);

    cout << "Enter 4 answer choices:\n";
    for (int i = 0; i < 4; i++) {
        string option;
        cout << "Choice " << i + 1 << ": ";
        getline(cin, option);
        q.options.push_back(option);
    }

    cout << "Enter the correct answer (1-4): ";
    cin >> q.correctAnswer;

    quiz.push_back(q);
    cout << "Question added successfully!\n";
}


void takeQuiz(vector<Question> &quiz) {
    if (quiz.empty()) {
        cout << "No questions available!\n";
        return;
    }

    int score = 0;
    for (int i = 0; i < quiz.size(); i++) {
        cout << quiz[i].question << endl;
        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << quiz[i].options[j] << endl;
        }

        int userAnswer;
        cout << "Your answer (1-4): ";
        cin >> userAnswer;

        if (userAnswer == quiz[i].correctAnswer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong answer!\n";
        }
    }

    cout << "You scored " << score << " out of " << quiz.size() << ".\n";
}


int main() {
    vector<Question> quiz;
    int choice;

    while (true) {
        cout << "\nQuiz Maker\n";
        cout << "1. Add Question\n";
        cout << "2. Take Quiz\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addQuestion(quiz);
        } else if (choice == 2) {
            takeQuiz(quiz);
        } else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}	
