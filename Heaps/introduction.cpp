while(i <= size)
{
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;

    if(left <= size && A[left] > A[largest])
        largest = left;

    if(right <= size && A[right] > A[largest])
        largest = right;

    if(largest != i)
    {
        swap(A[i], A[largest]);
        i = largest;
    }
    else
        break;
}