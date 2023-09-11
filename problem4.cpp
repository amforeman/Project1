#include <iostream>
#include <string>
#include <vector>

struct Library{
  std::string title;
  std::vector<std::string> authors;
  std::string catalogNumber;
  std::vector<std::string> subjectHeadings;
  std::string publisher;
  int publicationYear;
  bool circulatingStatus;
}
