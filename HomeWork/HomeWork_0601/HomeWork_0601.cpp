#include <iostream>
#include <list>
#include <vector>
#include <assert.h>

using DataType = int;


class HList
{
private:
	class ListNode
	{
	public:
		DataType Value;
		ListNode* Prev = nullptr;
		ListNode* Next = nullptr;
	};


public:
	class iterator
	{
		friend HList;

	private:
		ListNode* CurNode = nullptr;

	public:
		iterator()
		{

		}

		iterator(ListNode* _Node)
			: CurNode(_Node)
		{

		}
		bool operator !=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		iterator& operator ++()
		{
			CurNode = CurNode->Next;
			return *this;
		}

		DataType& operator*()
		{
			return CurNode->Value;
		}
	};

	HList()
	{
		StartNode = new ListNode();
		EndNode = new ListNode();

		// 이게 더미 노드 방식
		StartNode->Next = EndNode;
		EndNode->Prev = StartNode;
	}
	~HList()
	{
		if (StartNode != nullptr)
		{
			delete StartNode;
			StartNode = nullptr;
		}
		if (EndNode != nullptr)
		{
			delete EndNode;
			EndNode = nullptr;
		}
	}
	// void Push_front를 만들어보세요.

	void Push_front(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* NextNode = StartNode->Next;

		StartNode->Next = NewNode;
		NewNode->Prev = StartNode;

		NextNode->Prev = NewNode;
		NewNode->Next = NextNode;
	}

	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* PrevNode = EndNode->Prev;

		PrevNode->Next = NewNode;
		EndNode->Prev = NewNode;

		NewNode->Next = EndNode;
		NewNode->Prev = PrevNode;
	}

	iterator erase(const iterator& _Iter)
	{
		ListNode* Node = _Iter.CurNode;

		if (StartNode == Node
			|| EndNode == Node)
		{
			assert(false);
			return iterator(EndNode);
		}
		ListNode* NextNode = Node->Next;
		ListNode* PrevNode = Node->Prev;

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;

		if (nullptr != Node)
		{
			delete Node;
			Node = nullptr;
		}

		return iterator(NextNode);
	}

	iterator begin()
	{
		return iterator(StartNode->Next);
	}

	iterator end()
	{
		return iterator(EndNode);
	}

	void Clear()
	{
		ListNode* Node = StartNode->Next;
		while (Node != nullptr && EndNode != Node)
		{
			ListNode* NextNode = Node->Next;
			Node->Value = 0;
			delete Node;

			Node = NextNode;
		}
	}

private:
	ListNode* StartNode;
	ListNode* EndNode;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	{
		HList NewList;


		for (int i = 0; i < 10; i++)
		{
			NewList.Push_front(i);
		}

		HList::iterator StartIter = NewList.begin();
		HList::iterator EndIter = NewList.end();

		//++EraseIter;
		//++EraseIter;
		//++EraseIter;
		//++EraseIter;
		//++EraseIter;

		//EraseIter = NewList.erase(EraseIter);


		for (; StartIter != EndIter; ++StartIter)
		{
			//StartIter = NewList.erase(StartIter);
			// 순회를 하면서 모든 인자를 도는 와중에 삭제를 합니다.
			std::cout << (*StartIter) << std::endl;
		}

		NewList.Clear();

	}

}