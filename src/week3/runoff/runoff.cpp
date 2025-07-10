#include <cstddef>
#include <iostream>
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
std::vector<std::vector<int>> preferences(MAX_VOTERS,
                                          std::vector<int>(MAX_CANDIDATES));

bool vote(int voter, int rank, std::string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: runoff [candidate ... ]\n";
    return 1;
  }

  if (argc - 1 > MAX_CANDIDATES) {
    std::cout << "Maximum number of candidates is" << MAX_CANDIDATES;
    return 2;
  }

  for (int i = 1; i < argc; ++i) {
    candidates.emplace_back(argv[i]);
  }

  size_t voterCount;
  std::cout << "Number of voters: " << std::flush;
  std::cin >> voterCount;
  if (voterCount > MAX_VOTERS) {
    std::cout << "Maximum number of voters is" << MAX_VOTERS << '\n';
    return 3;
  }

  for (int i = 0; i < voterCount; i++) {
    for (int j = 0; j < candidates.size(); j++) {
      std::string name;
      std::cout << "Rank " << j + 1 << ": " << std::endl;
      std::getline(std::cin, name);

      if (!vote(i, j, name)) {
        throw std::runtime_error("Invalid vote for candidate: " + name);
        return 4;
      }
    }

    std::cout << std::endl;
  }

  while (true) {
    tabulate();

    bool won = print_winner();
    if (won) {
      break;
    }

    int min = find_min();
    bool tie = is_tie(min);

    if (tie) {
      for (Candidate &c : candidates) {
        if (!c.isEliminated()) {
          std::cout << c.getName();
        }
      }
      break;
    }
  }
  return 0;
}

bool vote(int voter, int rank, std::string &name) {
  for (size_t i = 0; i < candidates.size(); ++i) {
    if (candidates[i].getName() == name) {
      preferences[voter][rank] = i;
      return true;
    }
  }
  return false;
}

void tabulate(void) {
  for (Candidate &c : candidates) {
    c.resetVotes();
  }

  for (size_t voter; voter < preferences.size(); ++voter) {
    for (size_t rank; rank < candidates.size(); ++rank) {
      int candidateIndex = preferences[voter][rank];

      if (!candidates[candidateIndex].isEliminated()) {
        candidates[candidateIndex].incrementVotes();
        break;
      }
    }
  }
}

bool print_winner(void) {
  size_t totalVotes = 0;
  for (Candidate &c : candidates) {
    totalVotes += c.getVotes();
  }

  for (Candidate &c : candidates) {
    if (c.getVotes() > (totalVotes / 2.0)) {
      std::cout << c.getName();
      return true;
    }
  }
  return false;
}

int find_min(void);
bool is_tie(int min);
void eliminate(int min);