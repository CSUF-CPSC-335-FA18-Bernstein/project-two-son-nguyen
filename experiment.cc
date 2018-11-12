///////////////////////////////////////////////////////////////////////////////
// experiment.cc
//
// Example code showing how to run an algorithm once and measure its elapsed
// time precisely. You should modify this program to gather all of your
// experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>

#include "project2.hh"
#include "timer.hh"

using namespace std;

void sort_n_fixed(const string_vector& all_words);
void sort_n_increased(const string_vector& all_words);

int main()
{
  string_vector all_words;
  if ( ! load_words(all_words, "words.txt") ) {
    cerr << "error: cannot open \"words.txt\"" << endl;
    return 1;
  }
  sort_n_increased(all_words);
  sort_n_fixed(all_words);
  return 0;
}

void sort_n_fixed(const string_vector& all_words)
{
  string_vector n_words1, n_words2;
  int n = 50000;
  Timer timer;
  double elapsed_1 = 0.00, elapsed_2 = 0.00;

  cout << "\nRun 20 times with n = 50,000 to calculate the average and stdev\n\n";
  cout << "---------------------------\n";
  cout << "  n  |Merge Sort|Quick Sort\n";
  cout << "---------------------------\n";

  for (int i = 0; i < 20; i++)
  {
    n_words1.clear();
    n_words2.clear();
    for (int i = 0; i < n; i++)
      n_words1.push_back(all_words[i]);

    randomize_list(n_words1);
    for (int i = 0; i < n; i++)
      n_words2.push_back(n_words1[i]);

    timer.reset();
    mergesort(n_words1);
    elapsed_1 = timer.elapsed();

    timer.reset();
    quicksort(n_words2);
    elapsed_2 = timer.elapsed();

    cout << setw(5) << n << "|" << setw(10) << right << elapsed_1 << "|"
      << setw(10) << right << elapsed_2 << endl;
  }
  return;
}

void sort_n_increased(const string_vector& all_words)
{
  string_vector n_words1, n_words2;
  Timer timer;
  double elapsed_1 = 0.00, elapsed_2 = 0.00;
  int n = 5000;

  cout << "\nRun for n = 5,000 to 90,000, step = 5,000 to plot and draw chart\n\n";

  cout << "---------------------------\n";
  cout << "  n  |Merge Sort|Quick Sort\n";
  cout << "---------------------------\n";
  while (n <= 90000)
  {
    n_words1.clear();
    n_words2.clear();
    for (int i = 0; i < n; i++)
      n_words1.push_back(all_words[i]);

    randomize_list(n_words1);
    for (int i = 0; i < n; i++)
      n_words2.push_back(n_words1[i]);

    timer.reset();
    mergesort(n_words1);
    elapsed_1 = timer.elapsed();

    timer.reset();
    quicksort(n_words2);
    elapsed_2 = timer.elapsed();

    cout << setw(5) << n << "|" << setw(10) << right << elapsed_1 << "|"
      << setw(10) << right << elapsed_2 << endl;
    n+= 5000;
  }
  return;
}
