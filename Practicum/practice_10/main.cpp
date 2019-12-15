#include <iostream>
#include <algorithm>

const unsigned int N = 20;

/// Ex. 1
/// Print the addresses of: bool, char, int, double, float
void PrintAddresses()
{
    int a;
    char b;
    double c;
    float d;
    bool e;
    std::cout << "0x" << std::hex << (long long) &a << std::endl;
    std::cout << "0x" << std::hex << (long long) &b << std::endl;
    std::cout << "0x" << std::hex << (long long) &c << std::endl;
    std::cout << "0x" << std::hex << (long long) &d << std::endl;
    std::cout << "0x" << std::hex << (long long) &e << std::endl;
}

// global objects are usually named with g_ prefix
int g_Array[N];

/// Ex. 2
/// Printing arrays
void PrintArrayAddresses(int * arr, unsigned size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "0x" << std::hex << (long long) &arr[i] << std::dec << "   " << arr[i] << std::endl;
    }
}
/// Ex. 3
/// Swapping values
void Swap(int * a, int * b)
{
    if(a != nullptr && b != nullptr)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

/// Ex.4
/// Reading Array
void ReadArray(int * arr, unsigned size)
{
    if(arr != nullptr && size != 0)
    {
        for (size_t i = 0; i < size; ++i)
        {
            std::cin >> arr[i];
        }   
    }
}

/// Ex. 5
/// Printing Array
void PrintArray(int * arr, unsigned size)
{
    if (arr != nullptr && size != 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    }
    
}


int* CreateArray(unsigned long long size)
{
	int * a = new(std::nothrow) int[size]; // std::nothrow will return nullptr if the allocation fails (ex. when we dont have enough memory)
	return a;
}

void Release(int*& arr)
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = nullptr;
}

int main(int, char**) 
{
    int Array[N]; // local array

    PrintAddresses();
    PrintArrayAddresses(g_Array, N);
    PrintArrayAddresses(Array, N);
    
    int a = 5;
    int b = 7;
    std::cout << "a=" << a << " "<< "b=" << b << std::endl << "Swap(&a, &b)\n";
    Swap(&a, &b);
    std::cout << "a=" << a << " " << "b=" << b << std::endl;

    unsigned size = 4;
    ReadArray(Array, size);

    PrintArray(Array, size);

    unsigned long long n;
    std::cin >> n;
    { // scope of myArray -------------------------------------------
        int * myArray = CreateArray(n);

        ReadArray(myArray, n);
        std::sort(myArray, myArray + n); // this one is my favorite :P
        PrintArray(myArray, n);

        Release(myArray); // releasing myArray at the end of the scope
    }
    return 0;
}
