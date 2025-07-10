#include <string>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

class Candidate {
 private:
  bool eliminated;
  int votes;
  std::string name;
};