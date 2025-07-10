#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int get_user_change_owed();
int calculate_change(int change);

int main(void) {
  int change = get_user_change_owed();
  int coins_used = calculate_change(change);
  printf("%d\n", coins_used);
  return 0;
}

int get_user_change_owed() {
  int change_owed;
  do {
    change_owed = get_int("Change owed (cents): ");
  } while (change_owed < 0);
  return change_owed;
}

int calculate_change(int change) {
  int coins_used = 0;
  while (change >= 25) {
    coins_used++;
    change = change - 25;
  }
  while (change >= 10) {
    coins_used++;
    change = change - 10;
  }
  while (change >= 5) {
    coins_used++;
    change = change - 5;
  }
  while (change >= 1) {
    coins_used++;
    change = change - 1;
  }

  return coins_used;
}
