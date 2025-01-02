#include <iostream>
using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* data;      // 템플릿을 활용하여 타입에 의존하지 않고 데이터를 받는 배열 생성
	int currentSize;
	int currentCapacity;
public:
	SimpleVector(int capacity = 10) : currentSize(0), currentCapacity(capacity)
	{
		data = new T[capacity];    // 배열 동적 할당
	}
	void resize(int newCapacity) {}
	void push_back(const T& value)  // 인자로 받은 원소를 맨 뒤에 추가
	{
		if (currentSize == currentCapacity) {
			return;
		}
		data[currentSize] = value;
		currentSize++;
	}
	void pop_back()  // 벡터의 마지막 원소 제거
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
		delete[] data;  // 동적 할당 메모리 해제
	}
};