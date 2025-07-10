#include <string>
#include <vector>

#define MAX 9

class Candidate {
 private:
  std::string name;
  int votes;

 public:
  Candidate() : name(""), votes(0) {}
  Candidate(std::string name) : name(name), votes(0) {}

  std::string getName() const { return name; }
  void setName(std::string name) { this->name = name; }

  int getVotes() const { return votes; }
  void incrementVotes() { ++votes; }
};

std::vector<Candidate> candidates;