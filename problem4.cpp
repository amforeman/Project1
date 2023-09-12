#include <iostream>
#include <sstream>
#include <string>
#include <vector>
  
struct Book{
  std::string title;
  std::vector<std::string> authors;
  std::string catalogNumber;
  std::vector<std::string> subjects;
  std::string publisher;
  int publicationYear;
  bool circulationStatus;
};

struct libraryT {
  std::vector<Book> bookVec;
};

std::vector<Book> searchBySubject(libraryT libdata, std::string subject);
void printBookSearch(std::vector<Book>);
std::string printVector(std::vector<std::string>);
void addBook(libraryT libdata);
void setTitle(Book b, std::string title);
void setAuthors(Book b, std::vector<std::string>);
void setCatalogNumber(Book b, std::string);
void setSubjects(Book b, std::vector<std::string>);
void setPublisher(Book b, std::string);
void setPublicationYear(Book b, int year);
void setCirculationStatus(Book b, bool circulationStatus);
void displayTitleAndAuthor(libraryT libdata);
  
int main(){
  libraryT libdata;
  
  Book book1;
  book1.title = "Little Women";
  book1.authors.push_back("Louisa May Alcott");
  book1.catalogNumber = "94068255";
  book1.subjects.push_back("Mothers and Daughters");
  book1.subjects.push_back("Young women");
  book1.subjects.push_back("Sisters");
  book1.subjects.push_back("New England");
  book1.subjects.push_back("March family");
  book1.publisher = "Courage Books";
  book1.publicationYear = 1868;
  book1.circulationStatus = true;
  libdata.bookVec.push_back(book1);
  
  Book book2;
  book2.title = "Pride and Prejudice";
  book2.authors.push_back("Jane Austen");
  book2.catalogNumber = "81005215";
  book2.subjects.push_back("Courtship");
  book2.subjects.push_back("Sisters");
  book2.subjects.push_back("Family life");
  book2.subjects.push_back("England");
  book2.publisher = "Raintree Publisher";
  book2. publicationYear = 1813;
  book2.circulationStatus = true;
  libdata.bookVec.push_back(book2);
  
  Book book3;
  book3.title = "Great Expectations";
  book3.authors.push_back("Charles Dickens");
  book3.catalogNumber = "72177918";
  book3.subjects.push_back("Ex-convicts");
  book3.subjects.push_back("Benefactors");
  book3.subjects.push_back("Young men");
  book3.subjects.push_back("Revenge");
  book3.subjects.push_back("Orphans");
  book3.publisher = "Holt, Rinehart, Winston";
  book3.publicationYear = 1861;
  book3.circulationStatus = false;
  libdata.bookVec.push_back(book3);
  
  Book book4;
  book4.title = "To Kill a Mockingbird";
  book4.authors.push_back("Harper Lee");
  book4.catalogNumber = "95191280";
  book4.subjects.push_back("Fathers and Daughters");
  book4.subjects.push_back("Race relations");
  book4.subjects.push_back("Southern States");
  book4.publisher = "Harper Collins Publishers";
  book4.publicationYear = 1960;
  book4.circulationStatus = true;
  libdata.bookVec.push_back(book4);
  
  Book book5;
  book5.title = "The Things They Carried";
  book5.authors.push_back("Tim O'Brien");
  book5.catalogNumber = "2010292325";
  book5.subjects.push_back("Vietnam War");
  book5.publisher = "Houghton Mifflin Harcourt";
  book5.publicationYear = 1990;
  book5.circulationStatus = true;
  libdata.bookVec.push_back(book5);

  std::cout<<"Options:"<<std::endl;
  std::cout<<"1 - Add Book"<<std::endl;
  std::cout<<"2 - Search By Subject"<<std::endl;
  std::cout<<"3 - Display all book titles and authors"<<std::endl;
  std::cout<<"What would you like to do?"<<std::endl;
  std::string answer;
  std::cin>>answer;
  if(answer == "Add book" || answer == "1"){
    addBook(libdata);
  }
  else if (answer == "Search" || answer == "Search by subject" || answer == "2"){
    std::cout<<"What subject would you like to search for?"<<std::endl;
    std::string search;
    std::cin.ignore();
    std::getline(std::cin, search);
    std::vector<Book> results = searchBySubject(libdata, search);
    printBookSearch(results);
  }
  else if (answer == "Display all book titles and authors" || answer == "3" || answer == "Display books"){
    displayTitleAndAuthor(libdata);
  }
  else {
    std::cout<<"Invalid input"<<std::endl;
  }
  return 0;
}

void displayTitleAndAuthor(libraryT libdata){
  for(int i = 0; i < libdata.bookVec.size(); i++){
    std::cout<<"Title: "<<libdata.bookVec[i].title<<", Author: "<<printVector(libdata.bookVec[i].authors)<<std::endl;
  }
}

std::vector<Book> searchBySubject(libraryT libdata, std::string subject){
  std::vector<Book> subjectMatches;
  for (int i = 0; i < libdata.bookVec.size(); i++){
    Book current = libdata.bookVec[i];
    for (int j = 0; j < libdata.bookVec[i].subjects.size(); j++){
      if (current.subjects[j] == subject){
	subjectMatches.push_back(current);
      }
    }
  }
  return subjectMatches;
}

void printBookSearch(std::vector<Book> vec){
  for(int i = 0; i < vec.size(); i++){
    std::cout<<"Book "<<i+1<<": "<<std::endl;
    std::cout<<"Title: "<<vec[i].title<<", Author: "<<vec[i].authors[0]<<", Catalog Number: "<<vec[i].catalogNumber<<std::endl;
  }
}

std::string printVector(std::vector<std::string> vec){
  std::string vecString;
  for(int i = 0; i < vec.size(); i++){
    vecString += vec[i];
    vecString += ", ";
  }
  return vecString;
}

void addBook(libraryT libdata){
  Book b;
  std::cout<<"Enter the title of the book: "<<std::endl;
  std::string title;
  std::cin.ignore();
  std::getline(std::cin, title);
  setTitle(b, title);
  
  std::cout<<"Enter the up to five authors, with a comma between each name if there are multiple: "<<std::endl;
  std::string authorsInput;
  std::vector<std::string> authors;
  std::cin.ignore();
  std::getline(std::cin, authorsInput);
  std::stringstream ss(authorsInput);
  char comma;
  std::string current;
  for (int i; ss >> current;){
    authors.push_back(current);
    ss>>comma;
  }
  setAuthors(b, authors);
  
  std::cout<<"Enter the Library of Congress catalog number: "<<std::endl;
  std::string catalogNumber;
  std::cin>>catalogNumber;
  setCatalogNumber(b, catalogNumber);
  
  std::cout<<"Enter up to five subject headings, with a comma between each if there are multiple: "<<std::endl;
  std::string subjectInput;
  std::vector<std::string> subjects;
  std::cin.ignore();
  std::getline(std::cin, subjectInput);
  std::stringstream ss2(subjectInput);
  for (int i; ss2 >> current;){
    subjects.push_back(current);
    ss2>>comma;
  }
  setSubjects(b, subjects);
  
  std::cout<<"Enter the publisher: "<<std::endl;
  std::string publisher;
  std::cin.ignore();
  std::getline(std::cin, publisher);
  setPublisher(b, publisher);

  std::cout<<"Enter the year of publication: "<<std::endl;
  int publicationYear;
  std::cin>>publicationYear;
  setPublicationYear(b, publicationYear);

  std::cout<<"Is the book in circulation? (yes/no): "<<std::endl;
  std::string input;
  std::cin>>input;
  bool circulationStatus;
  if (input == "yes"){
    circulationStatus = true;
  }
  else {
    circulationStatus = false;
  }
  setCirculationStatus(b, circulationStatus);
  libdata.bookVec.push_back(b);
  std::cout<<title<<" has been added."<<std::endl;
}

void setTitle(Book b, std::string title){
  b.title = title;
}

void setAuthors(Book b, std::vector<std::string> authors){
  b.authors = authors;
}

void setCatalogNumber(Book b, std::string catalogNumber){
  b.catalogNumber = catalogNumber;
}

void setSubjects(Book b, std::vector<std::string> subjects){
  b.subjects = subjects;
}

void setPublisher(Book b, std::string publisher){
  b.publisher = publisher;
}

void setPublicationYear(Book b, int year){
  b.publicationYear = year;
}

void setCirculationStatus(Book b, bool status){
  b.circulationStatus = status;
}
