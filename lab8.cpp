#include <iostream>
#include <vector>
using namespace std;

int get_highest(int nums[], int size);
int get_lowest(int nums[], int size);
float get_average(int nums[], int size);

int main()
{
    int nums[100];
    int x;
    int size = 0;
    for (int i = 0; cin >> x && x != -1; i++)
    {
        nums[i] = x;
        size++;
    }

    cout << "Highest value: " << get_highest(nums, size) << '\n';
    cout << "Smallest value: " << get_lowest(nums, size) << '\n';
    printf("Average: %0.2f\n", get_average(nums, size));
}

int get_highest(int nums[], int size)
{
    int largest = nums[0];
    for (int i = 0; i < size; i++)
    {
        if (largest < nums[i])
        {
            largest = nums[i];
        }
    }
   return largest; 
}
int get_lowest(int nums[], int size)
{
    int smallest = nums[0];
    for (int i = 0; i < size; i++)
    {
        if (smallest > nums[i])
        {
            smallest = nums[i];
        }
    }
    return smallest;
}
float get_average(int nums[], int size)
{
    float sum = 0;
    float avg;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i]; 
    }
    return sum/size;
}

