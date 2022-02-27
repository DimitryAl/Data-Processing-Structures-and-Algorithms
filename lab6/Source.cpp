#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

#define length 4

void bubbleSort(int arr[length]);
void seqOutput(int arr[length]);
void shellsort(int arr[length]);

int main()
{
	setlocale(LC_ALL, "ru");
	system("color F0");

	int bubble[length], shell[length] = { 1, 14, 64, 28 };
	int i;

	srand(time(NULL));
	/*for (i = 0; i < length; i++)
	{
		bubble[i] = rand() % 100;
		shell[i] = bubble[i];
	}*/
	cout << "Последовательность:\n";
	seqOutput(bubble);

	cout << "\nСортировка методом прямого обмена\n";
	bubbleSort(bubble);

	cout << "\nСортировка методом Шелла\n";
	shellsort(shell);

	return 0;
}

void bubbleSort(int arr[length])
{
	using namespace std::chrono;

	int i, j, cnt, check;
	cnt = 0;

	system_clock::time_point start = system_clock::now();
	for (i = 0; i < length; i++)
	{
		check = 0;
		for (j = 0; j < length - 1 - i; j++)
		{
			cnt++;
			if (arr[j] > arr[j + 1])
			{
				arr[j] += arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] -= arr[j + 1];
				check = 1;
			}
		}
		cout << "i = " << i + 1<< "\t";
		seqOutput(arr);
		if (check == 0) break;
	}
	system_clock::time_point end = system_clock::now();
	duration<double> sec = end - start;
	cout << "\nРезультат\t\t";
	seqOutput(arr);
	cout << "Время сортировки\t" << sec.count()  << " секунд." << endl;
	cout << "Число сравнений\t\t" << cnt + 1 << endl;
}

void shellsort(int arr[length])
{
	using namespace std::chrono;

	int step, i, j, cnt, k;
	
	cnt = 0;
	k = 0;
	step = length / 2;
	system_clock::time_point start = system_clock::now();
	while (step > 0)
	{
		for (i = 0; i < length - step; i++)
		{
			j = i;
			while ((j >= 0) && (arr[j] > arr[j + step]))
			{
				arr[j + step] += arr[j];
				arr[j] = arr[j + step] - arr[j];
				arr[j + step] = arr[j + step] - arr[j];
				j--;
				cnt++;
			}
			cnt++;
		}
		cout << "i = " << k + 1 << "\t";
		seqOutput(arr);
		step = step / 2;
		k++;
	}
	system_clock::time_point end = system_clock::now();
	duration<double> sec = end - start;
	cout << "\nРезультат\t\t";
	seqOutput(arr);
	cout << "Время сортировки\t" << sec.count() << " секунд." << endl;
	cout << "Число сравнений\t\t" << cnt << endl;
}

void seqOutput(int arr[length])
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i];
		if (i != (length - 1)) cout << ", ";
		else cout << endl;
	}
}
