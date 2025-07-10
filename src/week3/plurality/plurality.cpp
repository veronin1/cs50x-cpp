#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#define MAX 9

class Candidate {
 private:
  std::string name;
  size_t votes;

 public:
  Candidate() : name(""), votes(0) {}
  Candidate(std::string name) : name(name), votes(0) {}

  std::string getName() const { return name; }
  void setName(std::string name) { this->name = name; }

  int getVotes() const { return votes; }
  void incrementVotes() { ++votes; }
};

std::vector<Candidate> candidates;

bool vote(std::string name);

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: plurality [candidate ...]\n";
    return 1;
  }

  if (candidates.size() > MAX) {
    std::cout << "Maximum number of candidates is " << MAX << std::endl;
  }

  for (int i = 1; i < argc; ++i) {
    Candidate newCand;

    newCand.setName(argv[i]);
    candidates.push_back(newCand);
  }

  int voterCount;
  std::cout << "Number of voters:";
  std::cin >> voterCount;

  for (int i = 0; i < voterCount; ++i) {
    std::string name;
    std::cout << "Vote: ";
    std::cin >> name;

    if (!vote(name)) {
      std::cout << "Invalid vote\n";
    }
  }
}

bool vote(std::string name) {
  for (Candidate& c : candidates) {
    if (c.getName() == name) {
      c.incrementVotes();
      return true;
    }
  }
  return false;
}

void printWinner() {
  size_t maxVotes = 0;
  for (Candidate& c : candidates) {
    if (c.getVotes() > maxVotes) {
      maxVotes = c.getVotes();
    }
  }

  for (Candidate& c : candidates) {
    if (c.getVotes() == maxVotes) {
      std::cout << c.getName();
    }
  }
}