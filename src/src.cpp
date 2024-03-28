#include<iostream>
using namespace std;

template<typename T>
class Array
{
private:
	T* A;
	int size, length;
	void Swap(int i, int j)
	{
		T temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

public:
	
	Array()
	{
		size = 10;
		length = 0;
		A = new T[size];
	}

	Array(int size,int length)
	{
		this->size = size;
		this->length = length;
		A = new T[size];
	}

	void Init()
	{
		for (int i = 0; i < length; i++)
			cin >> A[i];
	}

	void Display() const
	{
		for (int i = 0; i < length; i++)
			cout << A[i] << ' ';
		cout << endl;
	}

	void Append(T value) 
	{
		if (length < size)
			A[length++] = value;
		
	}

	void Insert(int index, T value)
	{
		if (length < size && index >= 0 && index < length)
		{
			for (int i = length; i > index; i--)
				A[i] = A[i - 1];
			A[index] = value;
			length++;
		}
	}

	T Delete(int index)
	{
		T value;
		if (index < length && index>=0)
		{
			value = A[index];
			for (int i = index; i < length - 1; i++)
				A[i] = A[i + 1];
			length--;
		}
		value = static_cast<T>(0);
		return value;
	}

	int LinearSearch(T value) 
	{
		for (int i = 0; i < length; i++)
			if (value == A[i])
			{
			    //Swap(i,i-1);                                 // Transposition Method
				//array.Swap(i, 0);                          // Move to Head Method
				return i;
			}
		return -1;
	}

	int BinarySearch(T value) const
	{
		int l = 0, h = length - 1, mid;
		while (l <= h)
		{
			mid = (l + h) / 2;
			if (value == A[mid])
				return mid;
			else if (value < A[mid])
				h = mid - 1;
			else
				l = mid + 1;
		}
		return -1;
	}

	int RBinarySearch(int l, int h, T value)
	{
		if (l <= h)
		{
			int mid = (l + h) / 2;
			if (value == A[mid])
				return mid;
			else if (value < A[mid])
				return RBinarySearch(l, mid - 1, value);
			else
				return RBinarySearch(mid + 1, h, value);
		}
		return -1;
	}

	T Get(int index) const
	{
		if (index < length && index >= 0)
		{
			return A[index];
		}
		return -1;
	}

	void Set(int index, T value)
	{
		if (index < length && index >= 0)
		{
			A[index] = value;
		}
	}

	T Max() const
	{
		T max = A[0];
		for (int i = 1; i < length; i++)
			if (A[i] > max)
				max = A[i];
		return max;
	}

	T Min() const
	{
		T min = A[0];
		for (int i = 1; i < length; i++)
			if (A[i] < min)
				min = A[i];
		return min;
	}

	T Sum() const
	{
		T sum = 0;
		for (int i = 0; i < length; i++)
			sum += A[i];
		return sum;
	}

	float Avg() const
	{
		return static_cast<float>(Sum()) / length;
	}

	void reverse()
	{
		T* B = new T[length];
		for (int i = 0, j = length - 1; i < length; i++, j--)
			B[j] = A[i];
		for (int i = 0; i < length; i++)
			A[i] = B[i];
		delete[] B;
	}

	void Reverse()
	{
		for (int i = 0, j = length - 1; i < j; i++, j--)
			Swap(i, j);
	}

	void Rotate(int direction) //+1 Right, -1 Left
	{
		T temp;
		if (direction == +1)
		{
			temp = A[length - 1];
			Delete(length - 1);
			Insert(0, temp);
		}
		else if (direction == -1)
		{
			temp = A[0];
			Delete(0);
			Append(temp);
		}
	}

	void InsertInSorted(T value)
	{
		if (length == size)
			return;
		int i = length - 1;
		while (A[i] > value && i >= 0)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = value;
		length++;
	}

	bool IsSorted()
	{
		for (int i = 0; i < length - 1; i++)
			if (A[i] > A[i + 1])
				return 0;
		return 1;
	}

	void RearrangePN()
	{
		int i = 0, j = length - 1;
		while (i < j)
		{
			while (A[i] < 0)
				i++;
			while (A[j] >= 0)
				j--;
			if (i < j)
				Swap(i, j);
		}
	}

	Array<T>* MergeSorted(const Array<T>& arr2)
	{
		int i = 0, j = 0, k = 0;
		Array<T>* arr3 = new Array<T>(size + arr2.size, length + arr2.length);
		while (i < length && j < arr2.length)
			if (A[i] < arr2.A[j])
				arr3->A[k++] = A[i++];
			else
				arr3->A[k++] = arr2.A[j++];
		for (; i < length; i++, k++)
			arr3->A[k] = A[i];
		for (; j < arr2.length; j++, k++)
			arr3->A[k] = arr2.A[j];
		return arr3;
	}

	Array<T>* UnionOfSorted(const Array<T>& arr2)
	{
		int i = 0, j = 0, k = 0;
		Array<T>* arr3 = new Array<T>(size + arr2.size, length + arr2.length);
		while (i < length && j < arr2.length)
			if (A[i] < arr2.A[j])
				arr3->A[k++] = A[i++];
			else if (A[i] > arr2.A[j])
				arr3->A[k++] = arr2.A[j++];
			else
			{
				arr3->A[k++] = A[i++];
				j++;
			}
		for (; i < length; i++, k++)
			arr3->A[k] = A[i];
		for (; j < arr2.length; j++, k++)
			arr3->A[k] = arr2.A[j];
		arr3->length = k;
		return arr3;
	}

	Array<T>* IntersectionOfSorted(const Array<T>& arr2)
	{
		int i = 0, j = 0, k = 0;
		Array<T>* arr3 = new Array<T>(size + arr2.size, length + arr2.length);
		while (i < length && j < arr2.length)
			if (A[i] < arr2.A[j])
				i++;
			else if (A[i] > arr2.A[j])
				j++;
			else
			{
				arr3->A[k++] = A[i++];
				j++;
			}
		arr3->length = k;
		return arr3;
	}

	Array<T>* DifferenceOfSorted(Array<T>& arr2)     //arr1-arr2
	{
		int i = 0, j = 0, k = 0;
		Array<T>* arr3 = new Array<T>(size + arr2.size, length + arr2.length);
		while (i < length && j < arr2.length)
			if (A[i] < arr2.A[j])
				arr3->A[k++] = A[i++];
			else if (A[i] > arr2.A[j])
				j++;
			else
			{
				i++;
				j++;
			}
		for (; i < length; i++, k++)
			arr3->A[k] = A[i];
		arr3->length = k;
		return arr3;
	}

	~Array()
	{
		delete[] A;
	}
};

int main()
{
	int size, length, index, choice;
	float value;
	cout << "Enter size and Length of First Array" << endl;
	cin >> size;
	cin >> length;
	Array<float> arr1(size, length);
	Array<float>* arr;
	cout << "Enter Elements" << endl;
	arr1.Init();
	cout << "Entered Array is:" << endl;
	arr1.Display();

	do
	{
		cout << "MENU" << endl;
		cout << "1.Append" << endl;
		cout << "2.Insert" << endl;
		cout << "3.Delete" << endl;
		cout << "4.Linear Search" << endl;
		cout << "5.Binary Search" << endl;
		cout << "6.Get" << endl;
		cout << "7.Set" << endl;
		cout << "8.Statistics" << endl;
		cout << "9.Reverse" << endl;
		cout << "10.Rotation" << endl;
		cout << "11.Sorted Check" << endl;
		cout << "12.Insert in Sorted" << endl;
		cout << "13.Rearrange Positive and Negative" << endl;
		cout << "14.Binary Operations" << endl;
		cout << "15.Exit" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter element to Append" << endl;
			cin >> value;
			arr1.Append(value);
			cout << "New Appended Array is:" << endl;
			arr1.Display();
			break;
		case 2:
			cout << "Enter Index and element to Insert" << endl;
			cin >> index;
			cin >> value;
			arr1.Insert(index, value);
			cout << "New Inserted Array is:" << endl;
			arr1.Display();
			break;
		case 3:
			cout << "Enter Index to Delete" << endl;
			cin >> index;
			cout << "Deleted Element is: " << arr1.Delete(index) << endl;
			cout << "New Array is:" << endl;
			arr1.Display();
			break;
		case 4:
			cout << "Enter Element for Linear Search" << endl;
			cin >> value;
			cout << "Found at index: " << arr1.LinearSearch(value) << endl;
			cout << "Your Array is:" << endl;
			arr1.Display();
			break;
		case 5:
			cout << "Enter Element for Binary Search" << endl;
			cin >> value;
			cout << "Found at index: " << arr1.BinarySearch(value) << endl;
			cout << "Your Array is:" << endl;
			arr1.Display();
			break;
		case 6:
			cout << "Enter index to Get" << endl;
			cin >> index;
			cout << "Value: " << arr1.Get(index) << endl;
			break;
		case 7:
			cout << "Enter index and value to Set" << endl;
			cin >> index;
			cin >> value;
			arr1.Set(index, value);
			cout << "New Array is:" << endl;
			arr1.Display();
			break;
		case 8:
			cout << "Max: " << arr1.Max() << endl;
			cout << "Min: " << arr1.Min() << endl;
			cout << "Sum: " << arr1.Sum() << endl;
			cout << "Avg: " << arr1.Avg() << endl;
			break;
		case 9:
			arr1.Reverse();
			cout << "New Reversed Array is:" << endl;
			arr1.Display();
			break;
		case 10:
			cout << "Enter direction of Rotation(R(+1),L(-1))" << endl;
			cin >> value;
			arr1.Rotate(value);
			cout << "New Rotated Array is:" << endl;
			arr1.Display();
			break;
		case 11:
			cout << "Sorted check: " << arr1.IsSorted() << endl;
			break;
		case 12:
			cout << "Enter element to insert in Sorted array" << endl;
			cin >> value;
			arr1.InsertInSorted(value);
			cout << "New Array is:" << endl;
			arr1.Display();
			break;
		case 13:
			arr1.RearrangePN();
			cout << "New Array is:" << endl;
			arr1.Display();
			break;
		case 15:
			return 0;
		default:
			break;
		}
	} while (choice != 14);

	cout << "Enter size and Length of Second Array" << endl;
	cin >> size;
	cin >> length;
	Array<float> arr2(size, length);
	cout << "Enter Elements of Second Array" << endl;
	arr2.Init();
	cout << "Entered Array 1 is:" << endl;
	arr1.Display();
	cout << "Entered Array 2 is:" << endl;
	arr2.Display();

	do
	{
		cout << "MENU" << endl;
		cout << "1.Merge" << endl;
		cout << "2.Union" << endl;
		cout << "3.Intersection" << endl;
		cout << "4.Difference" << endl;
		cout << "5.Exit" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			arr = arr1.MergeSorted(arr2);
			cout << "Merged Array is:" << endl;
			arr->Display();
			delete arr;
			break;
		case 2:
			arr = arr1.UnionOfSorted(arr2);
			cout << "Union of Arrays is:" << endl;
			arr->Display();
			delete arr;
			break;
		case 3:
			arr = arr1.IntersectionOfSorted(arr2);
			cout << "Intersection of Arrays is:" << endl;
			arr->Display();
			delete arr;
			break;
		case 4:
			arr = arr1.DifferenceOfSorted(arr2);
			cout << "Difference of Arrays is:" << endl;
			arr->Display();
			delete arr;
			break;
		default:
			break;
		}
	} while (choice != 5);

	cin.get();
}