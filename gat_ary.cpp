#include<iostream>
#include<cstdlib>
#include<ctime>

class Array
{
private:
    int index, sum = 0, max = 0, target = 0, count = 0;
    int* num_arr = nullptr;

    void start_randum()
    {
        srand(time(NULL));
    }

public:
    int get_index() // 인덱스 생성
    {
        return rand() % 10 + 5;
    }

    int* get_ary(int index) // 배열 생성
    {
        this->index = index;

        if (num_arr != nullptr) {
            delete[] num_arr;
        }

        num_arr = new int[index];

        for (int i = 0; i < index; i++)
        {
            num_arr[i] = rand() % 100;
        }

        return num_arr;
    }

    int get_sum(int* num_arr) // get_sum 파라미터: 정수형 배열 numArr / return sum
    {
        sum = 0;
        this->num_arr = num_arr;

        for (int i = 0; i < index; i++)
        {
            sum += *(num_arr + i);
        }

        return sum;
    }

    int get_max(int* num_arr) // get_max 파라미터: 정수형 배열 numArr / return max
    {
        max = 0;
        for (int i = 0; i < index; i++)
        {
            max = max < *(num_arr + i) ? *(num_arr + i) : max;
        }

        return max;
    }

    int get_count(int* num_arr) // get_count 파라미터: 정수형 배열 numArr / return count
    {
        target = rand() % 100;
        count = 0;
        for (int i = 0; i < index; i++)
        {
            count = target > *(num_arr + i) ? count + 1 : count;
        }

        return count;
    }

    void swap(int* num_arr) // swapArry 파라미터: 정수형 배열 numArr / void
    {
        output(index, num_arr);

        for (int i = 0; i < (index / 2); i++)
        {
            *(num_arr + i) = *(num_arr + i) ^ *(num_arr + index - 1 - i);
            *(num_arr + index - 1 - i) = *(num_arr + i) ^ *(num_arr + index - 1 - i);
            *(num_arr + i) = *(num_arr + i) ^ *(num_arr + index - 1 - i);
        }
        output(index, num_arr);
    }

    void output(int index, int* num_arr) // 출력
    {
        for (int i = 0; i < index; i++)
        {
            std::cout << *(num_arr + i);
            if (i != index - 1)
            {
                std::cout << "->";
            }
        }
        std::cout << std::endl;
    }

    ~Array()
    {
        delete[] num_arr;
    }
};

int main(void)
{
    Array array;

    int index = array.get_index();

    int* pary = array.get_ary(index);

    int sum = array.get_sum(pary);
    std::cout << "sum: " << sum << std::endl;

    int max = array.get_max(pary);
    std::cout << "max: " << max << std::endl;

    int count = array.get_count(pary);
    std::cout << "count: " << count << std::endl;

    array.swap(pary);

    return 0;
}