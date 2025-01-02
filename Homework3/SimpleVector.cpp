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
	SimpleVector(int capacity = 10) : currentSize(0), currentCapacity(capacity)
	{
		data = new T[capacity];    // �迭 ���� �Ҵ�
	}
	void resize(int newCapacity) {}
	void push_back(const T& value)  // ���ڷ� ���� ���Ҹ� �� �ڿ� �߰�
	{
		if (currentSize == currentCapacity) {
			return;
		}
		data[currentSize] = value;
		currentSize++;
	}
	void pop_back()  // ������ ������ ���� ����
	{
		if (currentSize != 0)
		{
			data[currentSize] = NULL;
			currentSize--;
		}
	}
	int size() { return currentSize; }
	int capacity() { return currentCapacity; }
	~SimpleVector()
	{
		delete[] data;  // ���� �Ҵ� �޸� ����
	}
};