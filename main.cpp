#include <iostream>
#include<fstream>

using namespace std;

int *init_end(int n, int t);
int *init_begin(int n, int t);
void print_arr(int *arr, int n);
void print_tree(int *z, int n, int t);
int *next_tree(int *current, int *end, int n);
bool is_finished(int *current, int *end, int n);
void print_tree_Z(int *z, int n, int t);

fstream file;

int main()
{
	file.open("MP_L3.txt",fstream::out);
	cout << "This program generates t-ary trees" << endl;
	int n;
	cout << "\nGive n: ";
	cin >> n;
	int t;
	cout << "Give t: ";
	cin >> t;

	int *end = init_end(n, t);
	int *begin = init_begin(n, t);
	int counter = 0;

	do
	{
		print_tree(begin, n, t);
		print_tree_Z(begin, n, t);
		begin = next_tree(begin, end, n);
		counter++;
	} while (!is_finished(begin, end, n));

	print_tree(begin, n, t);
	print_tree_Z(begin, n, t);
	counter++;
	cout << endl << "Generated " << counter << " trees"<<endl;
	file << endl << "Generated " << counter << " trees" << endl;
	file.close();
	system("pause");
	return 0;
}

int *init_end(int n, int t)
{
	int *arr = new int[n];
	arr[0] = 1;
	for (int i = 1; i < n; i++)
	{
		arr[i] = arr[i - 1] + t;
	}

	return arr;
}

int *init_begin(int n, int t)
{
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	return arr;
}

void print_arr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		file << arr[i];
	}
	cout << endl;
	file << endl;
}

void print_tree(int *z, int n, int t)
{
	int tree_size = n * t;
	int *tree = new int[tree_size];
	for (int i = 0; i < tree_size; i++)
	{
		tree[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		int index = z[i] - 1;
		tree[index] = 1;
	}
	print_arr(tree, tree_size);
	delete[]tree;
}

int *next_tree(int *current, int *end, int n)
{
	if (n == 1)
	{
		return current;
	}
	for (int i = (n - 1); i >= 0; i--)
	{
		if (current[i] < end[i])
		{
			current[i] += 1;
			for (int j = (i + 1); j < n; j++)
			{
				current[j] = current[j - 1] + 1;
			}
			break;
		}
	}
	return current;
}

bool is_finished(int *current, int *end, int n)
{
	for (int i = (n - 1); i >= 0; i--)
	{
		if (current[i] != end[i])
		{
			return false;
		}
	}
	return true;
}
void print_tree_Z(int *z, int n, int t)
{
	int tree_size = n * t;
	int *tree = new int[tree_size];
	for (int i = 0; i < tree_size; i++)
	{
		tree[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cout << z[i];
		file << z[i];
	}
	cout << endl;
	file << endl;
}