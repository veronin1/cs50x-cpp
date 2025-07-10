#include <string>
#include <vector>

constexpr int MAX_VOTERS = 100;
constexpr int MAX_CANDIDATES = 9;

class Candidate {
 private:
  std::string name;
  size_t votes;
  bool eliminated;

 public:
  Candidate() : name(""), votes(0), eliminated(false) {}
  Candidate(const std::string &name)
      : name(name), votes(0), eliminated(false) {}

  std::string getName() const { return name; }
  void setName(const std ::string &name) { this->name = name; }
  void resetVotes() { votes = 0; }

  size_t getVotes() const { return votes; }
  void incrementVotes() { ++votes; }

  bool isEliminated() const { return eliminated; }
  void setEliminated(bool status) { eliminated = status; };
};

std::vector<Candidate> candidates;