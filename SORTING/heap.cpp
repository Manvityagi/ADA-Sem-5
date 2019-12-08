void upheapify(int heap[], int i)
{
    int childIndex = i;
    int parentIndex = (childIndex - 1) / 2;

    while (childIndex > 0)
    {
        if (heap[childIndex] < heap[parentIndex])
        {
            // swap
            int temp = heap[childIndex];
            heap[childIndex] = heap[parentIndex];
            heap[parentIndex] = temp;

            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
        else
        {
            break;
        }
    }
}
void downheapify(int heap[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int index = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    while (leftChildIndex <= ei)
    {
        int minIndex = index;
        //Find min out of index, leftChildIndex and rightChildIndex
        if (heap[leftChildIndex] < heap[minIndex])
        {
            minIndex = leftChildIndex;
        }

        if (rightChildIndex <= ei && heap[rightChildIndex] < heap[minIndex])
        {
            minIndex = rightChildIndex;
        }

        if (minIndex != index)
        {
            //swap
            int temp = heap[minIndex];
            heap[minIndex] = heap[index];
            heap[index] = temp;

            index = minIndex;
            leftChildIndex = 2 * index + 1;
            rightChildIndex = 2 * index + 2;
        }
        else
        {
            break;
        }
    }
    //return temp;
}

void inplaceHeapSort(int input[], int n)
{
    if (n == 0)
        return;
    for (int i = 1; i < n; i++)
        upheapify(input, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = input[0];
        input[0] = input[i];
        input[i] = temp;

        downheapify(input, 0, i - 1);
    }
}
