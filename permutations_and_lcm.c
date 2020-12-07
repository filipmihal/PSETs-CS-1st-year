#include <stdio.h>

long int gcd(long int a, long int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
long int findlcm(long int a[], long int n) {
  long int res = 1, i;
  for (i = 0; i < n; i++) {
    res = res*a[i]/gcd(res, a[i]);
  }
  return res;
}

long int main() {
  FILE *rules;
  rules = fopen("pravidla.in", "r");
  long int clerks;
  fscanf(rules, "%ld\n", &clerks);
  long int clerk_func[clerks], check_array[clerks], cycles[clerks];
  
  long int pointer;
  for (long int i = 0; i < clerks; i++)
  {
      fscanf(rules, "%ld", &pointer);
      fscanf(rules, "%ld", &clerk_func[pointer-1]);  
      check_array[i] = 0;
      cycles[i] = 0;
  }

  long int pos;
  long int cycle_num = 0;

  for (long int clerk = 0; clerk < clerks; clerk++)
  {
    if(!check_array[clerk]){
      pos = clerk;
      while(!check_array[pos]){
        check_array[pos] = 1;
        cycles[cycle_num]++;
        pos = clerk_func[pos]-1;
      }
      cycle_num++;
    }
  }
  long int result = findlcm(cycles, cycle_num);
  printf("%ld", result);
  return 0;
}