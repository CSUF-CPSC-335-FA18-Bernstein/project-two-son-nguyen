///////////////////////////////////////////////////////////////////////////////
// project2.hh
//
// The three algorithms specified in the project 1 requirements
// document, plus helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "project2.hh"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


//-----------------------------------------------------------------------------
// Randomize the order of all items in the list
//-----------------------------------------------------------------------------
void randomize_list(string_vector & strings)
{

  int vector_size = strings.size(), random_num = 0;
  string s = "";
  srand(time(NULL));
  for (int i = 0; i < vector_size; i++)
  {
    random_num = rand() % (vector_size - 1);
    s = strings[i];
    strings[i] = strings[random_num];
    strings[random_num] = s;
  }
  return;
}

//-----------------------------------------------------------------------------
// Merge two sorted halves of a vector
// The first half: [start .. mid] and the second half: [mid + 1 .. last]
// After finishing, the string_vector strings is sorted
//-----------------------------------------------------------------------------
void merge(string_vector & strings, size_t start, size_t mid, size_t end) {

  	if (mid < end && strings[mid] <= strings[mid + 1])
  		return;
  	int i = start, j = mid + 1;
  	string_vector temp;

  	while (i <= mid && j <= end)
  	{
  		if (strings[i] > strings[j])
  			temp.push_back(strings[j++]);
  		else
  			temp.push_back(strings[i++]);
  	}

  	while (i <= mid)
  		temp.push_back(strings[i++]);
  	while (j <= end)
  		temp.push_back(strings[j++]);

    for (int i = 0; i < (int)temp.size(); i ++)
      strings[start + i] = temp[i];
  return;
}

//-----------------------------------------------------------------------------
// Sort the given list using the merge sort algorithm.
// This is a recursive method which splits the list into two
// parts, recursively calls itself on the two parts and then merges
// the two parts together using the merge() method.
//-----------------------------------------------------------------------------
void mergesort(string_vector & strings, size_t start, size_t end)
{
  if(start < end)
  {
    int mid = (start + end) / 2;
    mergesort(strings, start, mid);
    mergesort(strings, mid + 1, end);
    merge(strings, start, mid, end);
  }
  return;
}

//-----------------------------------------------------------------------------
// Implementation of the Hoare Partition.
// This partition uses the first element of the list as a partition
// and divides the list into less than and greater than the pivot value
// It returns the index of the final position of the pivot value.
//-----------------------------------------------------------------------------
int hoare_partition(string_vector & strings, int start, int end)
{
  string pivot = strings[start];
  int i = start, j = end + 1;
  do
  {
    do
    {
      i++;
    } while (i < end && strings[i] < pivot);
    do
    {
      j--;
    } while (strings[j] > pivot);
    swap(strings[i], strings[j]);
  } while (i < j);

  swap(strings[i], strings[j]);
  swap(strings[start], strings[j]);
  return j;
}

//-----------------------------------------------------------------------------
// Sort the given list using the quicksort algorithm.
// This is a recursive method which splits the list into two
// parts, recursively calls itself on the two parts and then merges
// the two parts together using the merge() method.
//-----------------------------------------------------------------------------
void quicksort(string_vector & strings, int start, int end)
{
  	if (start < end)
  	{
  		int p = hoare_partition(strings, start, end);
  		quicksort(strings, start, p - 1);
  		quicksort(strings, p + 1, end);
  	}

  return;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// ALREADY IMPLEMENTED
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Load words from the file at the given path. The words vector is
// cleared, and then each word from the file is added to the
// vector. Returns true on success or fale on I/O error.
//-----------------------------------------------------------------------------
bool load_words(string_vector& words, const std::string& path)
{
  //std::cout << "Loading words from [" << path << "]" << std::endl;
  words.clear();
  std::ifstream ifs(path.c_str());
  if (!ifs.is_open() || !ifs.good()) {
    //cout << "Failed to open [" << path << "]" << std::endl;
    return false;
  }
  int countWordsLoaded = 0;
  while (!ifs.eof()) {
    std::string lineBuffer;
    std::getline(ifs, lineBuffer);
    if (ifs.eof()) {
      break;
    }
    words.push_back(lineBuffer);
    countWordsLoaded++;
  }
  //std::cout << "Loaded " << countWordsLoaded << " words from [" << path << "]" << std::endl;;
  return true;
}

//-----------------------------------------------------------------------------
// Sort the given list using the merge sort algorithm.
// This method is simply a helper to make the initial
// call the recursive mergesort() method below that requires
// first and last indexes for sorting range
//-----------------------------------------------------------------------------
void mergesort(string_vector & strings) {
  if (strings.size() == 0) {
    return;
  }
  mergesort(strings, 0, strings.size() - 1);
  return;
}

//-----------------------------------------------------------------------------
// Sort the given list using the quicksort algorithm.
// This method is simply a helper to make the initial
// call the recursive mergesort() method below that requires
// first and last indexes for sorting range
//-----------------------------------------------------------------------------
void quicksort(string_vector & strings) {
  if (strings.size() == 0) {
    return;
  }
  quicksort(strings, 0, strings.size() - 1);
  return;
}
