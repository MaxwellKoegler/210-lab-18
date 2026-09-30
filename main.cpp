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
        Review *cur = head;
        double t = 0;
        int c = 0;
        while (cur) {
            cout << "Rating: " << cur->rating << endl;
            cout << "Review: " << cur->comment << endl;
            t += cur->rating;
            c++;
            cur = cur->next;
        }
        if (c > 0) {
            cout << "Average rating: " << t / c << endl;
        }
        cout << endl;
    }

    ~Movie() {
        Review *c = head;
        while (c) {
            Review *next = c->next;
            delete c;
            c = next;
        }
    }
    Movie(Movie &other) {
        title = other.title;
        head = nullptr;
        Review *c = other.head;
        while (c) {
            addReview(c->rating, c->comment);
            c = c->next;
        }
    }
    Movie& operator=(const Movie &other) {
        title = other.title;
        Review *c = head;
        while (c) {
            Review *next = c->next;
            delete c;
            c = next;
        }
        head = nullptr;
        c = other.head;
        while (c) {
            addReview(c->rating, c->comment);
            c = c->next;
        }
        return *this;
    }
};

int main(){
    ifstream file("input.txt"); //input file init
    string comment;
    vector<Movie> movies; //vector storage of type movies
    Movie movie1("Movie 1");
    Movie movie2("Movie 2");
    Movie movie3("Movie 3");
    Movie movie4("Movie 4");

    for(int i = 0; i < 3; i++){
        getline(file, comment);
        double rating = 1.0 + (rand() % 41) / 10.0;
        movie1.addReview(rating, comment);
    }

    for(int i = 0; i < 3; i++){
        getline(file, comment);
        double rating = 1.0 + (rand() % 41) / 10.0;
        movie2.addReview(rating, comment);
    }

    for(int i = 0; i < 3; i++){
        getline(file, comment);
        double rating = 1.0 + (rand() % 41) / 10.0;
        movie3.addReview(rating, comment);
    }

    for(int i = 0; i < 3; i++){
        getline(file, comment);
        double rating = 1.0 + (rand() % 41) / 10.0;
        movie4.addReview(rating, comment);
    }



}