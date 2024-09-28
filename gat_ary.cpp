#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>

int main(void)
{
	srand(time(NULL));

	int index = rand() % 10 + 5;

	int* pary = new int[index];

	for (int i = 0; i < index; i++)
	{
		*(pary + i) = rand() % 100;
		std::cout << *(pary + i) << "  ";
	}

	std::cout << std::endl;

	//get_sum 파라미터: 정수형 배열 numArr / return sum
	int sum = 0;
	for (int i = 0; i < index; i++)
	{
		sum += *(pary + i);
	}

	//get_max 파라미터: 정수형 배열 numArr / return max

	int max = *std::max_element(pary, pary + index);

	//get_count 파라미터: 정수형 배열 numArr / return count
	int target = rand() % 100;
	int count = 0;
	for (int i = 0; i < index; i++)
	{
		target < *(pary + i) ? count++ : count;
	}

	//swapArry 파라미터: 정수형 배열 numArr / void
	for (int i = 0; i < (index/2); i++)
	{
		std::swap(*(pary + i), *(pary + index - 1 - i));
		//*(pary + i) = *(pary + i) ^ *(pary + index - 1 - i);
		//*(pary + i) = *(pary + index - 1 - i) ^ *(pary + i);
		//*(pary + i) = *(pary + i) ^ *(pary + index - 1 - i);
	}

	for (int i = 0; i < index; i++)
	{
		std::cout << *(pary + i) << "  ";
	}

	std::cout << std::endl;

	std::cout << sum << " | " << max << " | " << target << "->" << count << " | " << std::endl;

	delete[] pary;

	return 0;
}