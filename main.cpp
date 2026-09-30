//maxwell koegler | COMSC 210 | lab 15 | 9/29/26
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

using namespace std;
class Movie { //movie class with protected vars and appropriate setters and getters
private:
    struct Review {
        double rating;
        string comment;
        Review *next;
    };
    string title;
    Review *head;
public:
Movie(string t){
    title = t;
    head = nullptr;
}

void addReview(double rating, string comment){
    Review *newReview = new Review;
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = head;
    head = newReview;
}

void setTitle(string w) {
    title = w;
}
string getTitle() {
    return title;
}
void print() {
        cout << "Title: " << title << endl;

        Review *current = head;
        double t = 0;
        int c = 0;

        while (current) {
            cout << "Rating: " << current->rating << endl;
            cout << "Review: " << current->comment << endl;
            t += current->rating;
            c++;
            current = current->next;
        }
        if (c > 0) {
            cout << "Average rating: " << t / c << endl;
        }
        cout << endl;
    }

    ~Movie() {
        Review *current = head;
        while (current) {
            Review *next = current->next;
            delete current;
            current = next;
        }
    }

    



};

int main(){
    ifstream file("input.txt"); //input file init
    string line1;
    int line2;
    string line3;
    vector<Movie> movies; //vector storage of type movies
    while(getline(file, line1)) {
        file >> line2; //line reading
        file.ignore();
        getline(file, line3);  
        Movie temp = Movie(); //temp init
        temp.setTitle(line1);
        temp.setYearReleased(line2);
        temp.setScreenWriter(line3);
        movies.push_back(temp); //temp push to container
    }
    for(Movie m : movies){
        m.print();
    }
}