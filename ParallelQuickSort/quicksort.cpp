/* C++ implementation of QuickSort */
#include <chrono>
#include <cstdint>
#include <iostream>
#include <omp.h>
#include <random>
#include <vector>
#include <algorithm>

////////// START BLOCK: DO NOT TOUCH ANY CODE IN THIS HELPER FUNCTIONS
/* Function to print an array */
void printArray(const std::vector<int64_t>& vec) {
  for(auto e : vec) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

bool checkCorrectness(const std::vector<int64_t>& vec) {
  const bool sorted = std::is_sorted(std::begin(vec), std::end(vec));
  if(!sorted){
    std::cerr << "Sorting failed." << std::endl;
    return false;
  }
  return true;
}

// A utility function to swap two elements
void swap(int64_t* a, int64_t* b) {
  int64_t t = *a;
  *a        = *b;
  *b        = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int64_t partition(int64_t* arr, int64_t low, int64_t high) {
  int64_t pivot = arr[high];  // pivot
  int64_t i     = (low - 1);  // Index of smaller element and indicates the right position of pivot found so far

  for (int64_t j = low; j <= high - 1; j++) {
    // If current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++;  // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}
////////// END BLOCK: DO NOT TOUCH ANY CODE IN THIS HELPER FUNCTIONS

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort_par(int64_t* arr, int64_t low, int64_t high) {
  // TODO: modify/implement a), and later b)
  if (low < high)
  { 
    // pi is partitioning index, arr[p] is now
    // at right place
    int64_t pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition

      #pragma omp task 
      {
        quickSort_par(arr, low, pi - 1);
      }
      #pragma omp task 
      {
        quickSort_par(arr, pi + 1, high);
      }

    
  }
}

void quickSort_ser(int64_t* arr, int64_t low, int64_t high) {
  if (low < high) {
    /* pi is partitioning index, arr[p] is now
    at right place */
    int64_t pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort_ser(arr, low, pi - 1);
    quickSort_ser(arr, pi + 1, high);
  }
}

int main(int argc, char* argv[]) {
  using namespace std::chrono;
  const int nval = 20000000;  // Length of array to sort
  const int nt   = 8;         // Max. number of threads that is tested
  const int SIZE = nval;

  // Prepare randomness
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1, std::numeric_limits<int>::max());

  // Initialization of array with random values
  const auto t3 = high_resolution_clock::now();
  std::vector<int64_t> unsorted_vals, unsorted_vals_back;
  unsorted_vals.resize(SIZE);
  for (int64_t i = 0; i < SIZE; i++) {
    unsorted_vals[i] = (dist(rng));
  }
  const auto t4         = high_resolution_clock::now();
  const auto time_span2 = duration_cast<duration<double>>(t4 - t3);
  std::cout << "Generating took " << time_span2.count() << " seconds." << std::endl;
  unsorted_vals_back = unsorted_vals;

  int64_t* arr = unsorted_vals.data();
  int64_t n    = SIZE;

  // Serial reference of quicksort
  const auto t5 = high_resolution_clock::now();
  quickSort_ser(arr, 0, n - 1);
  const auto t6         = high_resolution_clock::now();
  const auto time_span3 = duration_cast<duration<double>>(t6 - t5);
  std::cout << "Serial QuickSort took " << time_span3.count() << " seconds." << std::endl;
  unsorted_vals = unsorted_vals_back;  // Set array back for next run

  // Parallel quicksort with up to given number of threads
  // Parallel quicksort with up to given number of threads
  std::vector<int> pow2;
  for (int i = 1; i <= nt; i *= 2) {
    pow2.push_back(i);
  }

  for (int numt : pow2) {
    omp_set_num_threads(numt);

    auto t1 = high_resolution_clock::now();

    // TODO implement parallel call for task a)
    #pragma omp parallel 
    {
      #pragma omp single 
      quickSort_par(arr, 0, n - 1);
    }


    //  Print timing information for this run
    const auto t2        = high_resolution_clock::now();
    const auto time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "(" << numt << "): ";
    std::cout << "It took me " << time_span.count() << " seconds." << std::endl;
    checkCorrectness(unsorted_vals);
    // Set back for next run
    unsorted_vals = unsorted_vals_back;
  }

  return 0;
}

// Original code-base was contributed by rathbhupendra
// https://gist.github.com/shoyushen/11807475ef5993d25848b33d9b36aeb5
