#include <iostream>
#include <iomanip>

using namespace std;

// modified linear search
int linearSearch(int arr[], int target, int size, int start) {
  for (int i = start; i < size; ++i) {
    if (arr[i] == target)
      return i;
  }

  return -1;
}

int main() {
  int num_elements,
      max,
      target,
      num_results;

  cout << "Number of elements in the array: ";
  cin  >> num_elements;
  cout << "Max value that can exist in the array: ";
  cin  >> max;
  cout << "Target to search for: ";
  cin  >> target;
  cout << "Number of Targets to find: ";
  cin  >> num_results;
  cout << endl;

  int* arr = new int[num_elements];

  for (int i = 0; i < num_elements; ++i)
    arr[i] = rand() % max + 1;

  int* res = nullptr;
  res = new int[num_results];

  int index = -1, prev_value = 0;
  // find every value in the array up to the specified number of matches to the target.
  do {
    ++index;
    res[index] = linearSearch(arr, target, num_elements, prev_value + 1);
    prev_value = res[index];
  } while (res[index] != -1 && index < num_results);

  if (index != num_results)
    cout << "Only " << index << " match(es) found out of " << num_results << " requested." << endl << endl;
  else
    cout << index << " elements found matching target of " << target << endl << endl;

  cout << "Array:" << endl;
  for (int i = 0; i < num_elements; ++i) {
    if (i > 9 && i % 10 == 0)
      cout << endl;
    cout << setw(4) << arr[i];
  }
  cout << endl << endl;

  cout << "Results:" << endl;
  for (int i = 0; i < index; ++i)
    cout << res[i] << " ";
  cout << endl;

  delete [] res;
  delete [] arr;
  return 0;
}
