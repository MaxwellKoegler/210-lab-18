//maxwell koegler | COMSC 210 | lab 18 | 9/29/26
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

using namespace std;
class Movie { //movie class with protected vars
private:
    struct Review { //protected review linked list
        double rating;
        string comment;
        Review *next;
    };
    string title;
    Review *head;
public:
Movie(string t){ //movie struct stored publically
    title = t;
    head = nullptr;
}
void addReview(double rating, string comment){ //add a review
    Review *newReview = new Review;
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = head;
    head = newReview;
}
void print() { //print all stored class information
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
    ~Movie() { //destruct and dismantle linked list and all internal class components
        Review *c = head;
        while (c) {
            Review *next = c->next;
            delete c;
            c = next;
        }
    }
    Movie(const Movie &other) { //instanciate this constructed class as a copy of another
        title = other.title;
        head = nullptr;
        Review *c = other.head;
        while (c) {
            addReview(c->rating, c->comment);
            c = c->next;
        }
    }
    Movie& operator=(const Movie &other) { //transfer all data from another class into this one
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
    Movie movie1("Interstellar");
    Movie movie2("Wall E.");
    Movie movie3("Saving Private Ryan");
    Movie movie4("Project Hail Mary");
    for(int i = 0; i < 3; i++){ //movie one reviews
        getline(file, comment);
        double rating = 1.0 + (rand() % 41) / 10.0;
        movie1.addReview(rating, comment);
    }
    for(int i = 0; i < 3; i++){ //movie two reviews
        getline(file, comment);
        double rating = 1.0 + (rand() % 41) / 10.0;
        movie2.addReview(rating, comment);
    }
    for(int i = 0; i < 3; i++){ //movie three revies
        getline(file, comment);
        double rating = 1.0 + (rand() % 41) / 10.0;
        movie3.addReview(rating, comment);
    }
    for(int i = 0; i < 3; i++){ // movie four reviews
        getline(file, comment);
        double rating = 1.0 + (rand() % 41) / 10.0;
        movie4.addReview(rating, comment);
    }
    movies.push_back(movie1); //vector ammendments
    movies.push_back(movie2);
    movies.push_back(movie3);
    movies.push_back(movie4);
    for (Movie m : movies) { //printing
        m.print();
    }
    return 0;
}