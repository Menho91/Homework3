#include <iostream>
using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* data;      // ���ø��� Ȱ���Ͽ� Ÿ�Կ� �������� �ʰ� �����͸� �޴� �迭 ����
	int currentSize;
	int currentCapacity;
public:
	void printVector()
	{
		cout << "current size : " << currentSize << ", current capacity : " << currentCapacity << endl;
		cout << "{ ";
		for (int i = 0; i < currentSize; i++)
		{
			cout << data[i] << " ";
		}
		cout << "}" << endl;
	}
	SimpleVector(int capacity = 10) : currentSize(0), currentCapacity(capacity)
	{
		data = new T[capacity];    // �迭 ���� �Ҵ�
	}
	SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity)
	{
		data = new T[other.capacity()];
		for (int i = 0; i < currentSize; i++)
		{
			data[i] = other.data[i];
		}
	}
	void resize(int newCapacity)
	{
		if (newCapacity > currentCapacity)
		{
			currentCapacity = newCapacity;
			T* newData = new T[currentCapacity];
			for (int i = 0; i < currentSize; i++)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}
	}
	void push_back(const T& value)  // ���ڷ� ���� ���Ҹ� �� �ڿ� �߰�
	{
		if (currentSize == currentCapacity) {
			resize(currentCapacity + 5);
		}
		data[currentSize++] = value;
	}
	void pop_back()  // ������ ������ ���� ����
	{
		if (currentSize > 0)
		{
			currentSize--;
		}
	}
	int size() const { return currentSize; }
	int capacity() const { return currentCapacity; }
	void sortData()
	{
		data.sort(data, data + currentSize);
	}
	~SimpleVector()
	{
		delete[] data;  // ���� �Ҵ� �޸� ����
	}
};

int main()
{
	SimpleVector<int> sv(3);
	sv.push_back(10);
	sv.push_back(20);
	sv.push_back(30);
	sv.printVector();
	sv.pop_back();
	sv.printVector();

	SimpleVector<int> sv_copy(sv);
	sv_copy.printVector();

	sv_copy.push_back(40);
	sv_copy.push_back(50);
	sv_copy.printVector();

	sv.printVector();
	return 0;
}