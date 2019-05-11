

class List:
    class _Node:
        __slots__ = ('value', 'next')

        def __init__(self, value, next=None):
            self.value = value
            self.next = next

    def __init__(self, iterable=None):
        self._head = None
        self.tail = None
        self._length = 0
        if iterable is not None:
            self.extend(iterable)

    def append(self, value):
        node = List._Node(value)
        if len(self) == 0:
            self._head = self._tail = node
        else:
            self._tail.next = node
            self._tail = node
        self._length += 1

    def __len__(self):
        return self._length

    def extend(self, iterable):
        for value in iterable:
            self.append(value)

    def __getitem__(self, index):
        if index < 0:
            index += len(self)

        if not 0 <= index < len(self):
            raise IndexError('List index is out of range')
        node = self._head

        for _ in range(index):
            node = node.next
        return node.value

    def __iter__(self):
        node = self._head
        while node is not None:
            yield node.value
        node = node.next


if __name__ == "__main__":
    numbers = List(range(10000000))
    for x in numbers:
        if x % 1000 == 0:
            print(x)
