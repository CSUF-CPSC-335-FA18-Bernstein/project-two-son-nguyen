
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vector_int;
typedef vector<string> vector_string;

void swap(int& a, int& b);
void mergeTwoHalves(vector_int& v, int first, int middle, int last);
int hoarePartition(vector_int& v, int l, int r);
void quickSort(vector_int& v, int l, int r);
void printVector(const vector_string& v);
void mergeTwoHalves(vector_string& v, size_t start, size_t mid, size_t end);
int hoarePartition(vector_string& v, int l, int r);
void quickSort(vector_string& v, int l, int r);
void printVector(const vector_string& v);

int main()
{
	//vector_int v = { 7, 3, 4, 5, 9, 2, 6, 1, 8, 12, 18, 25, 14 };
	//vector_string v_s = {"WA", "IL", "CA", "NY", "TX", "NV", "GA", "MA", "OR", "FL", "MO", "NM", "TX"};
	vector_string v_s = {"CA", "NV", "NY", "IL", "TX", "WA", "FL", "GA", "MA", "MO", "NM", "OR", "TX"};
	printVector(v_s);
	mergeTwoHalves(v_s, 0, 6, 12);
	//cout << "Pivot position: " << hoarePartition(v, 0, v.size() - 1) << endl;
	//quickSort(v_s, 0, v_s.size() - 1);
	printVector(v_s);

	return 0;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printVector(const vector_int& v)
{
	int len = v.size();
	for (int i = 0; i < len; i++)
		cout << v[i] << " ";
	cout << endl;
}

void mergeTwoHalves(vector_int& v, int first, int middle, int last)
{
	if (v[middle - 1] <= v[middle])
		return;
	int i = first, j = middle;
	vector_int temp;

	while (i < middle && j <= last)
	{
		if (v[i] > v[j])
			temp.push_back(v[j++]);
		else
			temp.push_back(v[i++]);
	}

	while (i < middle)
		temp.push_back(v[i++]);
	while (j <= last)
		temp.push_back(v[j++]);

	v.empty();
	v = temp;
}

int hoarePartition(vector_int& v, int left, int right)
{
	int pivot = v[left];
	int i = left, j = right + 1;
	do
	{
		do
		{
			i++;
		} while (v[i] < pivot);
		do
		{
			j--;
		} while (v[j] > pivot);
		swap(v[i], v[j]);
	} while (i < j);

	swap(v[i], v[j]);
	swap(v[left], v[j]);
	return j;
}
void quickSort(vector_int& v, int left, int right)
{
	if (left < right)
	{
		int p = hoarePartition(v, left, right);
		quickSort(v, left, p - 1);
		quickSort(v, p + 1, right);
	}
}
void printVector(const vector_string& v)
{
	int len = v.size();
	for (int i = 0; i < len; i++)
		cout << v[i] << " ";
	cout << endl;
}

void mergeTwoHalves(vector_string& v, size_t start, size_t mid, size_t end)
{
	if (v[mid - 1] <= v[mid])
		return;
	int i = start, j = mid;
	vector_string temp;

	while (i < mid && j <= end)
	{
		if (v[i] > v[j])
			temp.push_back(v[j++]);
		else
			temp.push_back(v[i++]);
	}

	while (i < mid)
		temp.push_back(v[i++]);
	while (j <= end)
		temp.push_back(v[j++]);

	v.empty();
	v = temp;
}

int hoarePartition(vector_string& v, int left, int right)
{
	string pivot = v[left];
	int i = left, j = right + 1;
	do
	{
		do
		{
			i++;
		} while (i < right && v[i] < pivot);
		do
		{
			j--;
		} while (v[j] > pivot);
		swap(v[i], v[j]);
	} while (i < j);

	swap(v[i], v[j]);
	swap(v[left], v[j]);
	return j;
}
void quickSort(vector_string& v, int left, int right)
{
	if (left < right)
	{
		int p = hoarePartition(v, left, right);
		quickSort(v, left, p - 1);
		quickSort(v, p + 1, right);
	}
}
