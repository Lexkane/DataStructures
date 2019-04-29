#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>

using namespace std;

void show(int i)
{
	cout << i << ", ";
}

int main()
{
	list<int> ls;

	if (ls.empty())
		for (int i = 0; i < 5; i++)
			ls.push_back(i);
	

	cout << "Maxsize: " << ls.max_size() << endl;					// ��������� ����� ������
	cout << "Size: " << ls.size() << endl;							// ����� ������

	for_each(ls.begin(), ls.end(), show); cout << endl;
	for_each(ls.rbegin(), ls.rend(), show); cout << endl;

	ls.resize(10, 50);											// �������� ������ � n �������� � ���������

	cout << "newsize: " << ls.size() << endl;

	auto it = ls.begin();
	advance(it, 5);												// ��������� ��������

	ls.insert(it, 3, 120);										// ������� �������� � ���� �����


	ls.push_back(180);											// ������� � ������� ������
	ls.push_front(380);											// ������� � ����� ������

	for_each(ls.begin(), ls.end(), show); cout << endl;

	list<int> ls2;
	ls2.assign(5, 66);

	ls.sort(greater<int>());									// ���������� �� ����������
	cout << "Sortbygreaternumber: ";
	for_each(ls.begin(), ls.end(), show); cout << endl;

	ls.reverse();												// ��������� ����
	cout << "Reverse: ";
	for_each(ls.begin(), ls.end(), show); cout << endl;

	ls2.merge(ls);												// �������� ������
	cout << "Merge: ";
	for_each(ls2.begin(), ls2.end(), show); cout << endl;

	ls2.unique();												// ��������� ���������
	cout << "Unique: ";
	for_each(ls2.begin(), ls2.end(), show); cout << endl;

	system("pause");
	return 0;
}