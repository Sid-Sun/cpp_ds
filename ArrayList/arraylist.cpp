#include <iostream>
#include <cstring>

template <class T>
class arraylist
{
private:
    T *arr;
    const int minSize = 16;
    int size = 16;
    int len = -1;
    float multiplier = 1.5;

    void swap(int a, int b)
    {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    void rotateRight(int s, int e)
    {
        int last = arr[e];
        int nxt = arr[s];
        for (int i = s; i < e; i++)
        {
            int tmp = arr[i + 1];
            arr[i + 1] = nxt;
            nxt = tmp;
        }
        arr[s] = last;
    }

    int findMinInRange(int s, int e)
    {
        int min = INT16_MAX;
        int minVal = INT16_MAX;
        for (int i = s; i <= e; i++)
            if (arr[i] < minVal)
            {
                minVal = arr[i];
                min = i;
            }
        return min;
    }

    // Unused Function, can remove
    int findMaxInRange(int s, int e)
    {
        int max = INT16_MIN;
        int maxVal = INT16_MIN;
        for (int i = s; i <= e; i++)
            if (arr[i] > maxVal)
            {
                maxVal = arr[i];
                max = i;
            }
        return max;
    }

    struct minMaxAt
    {
    public:
        int maxAt;
        int minAt;
    };

    minMaxAt findMinMax(int s, int e)
    {
        minMaxAt out;
        int maxVal = INT16_MIN, minVal = INT16_MAX;
        for (int i = s; i <= e; i++)
        {
            if (arr[i] > maxVal)
            {
                maxVal = arr[i];
                out.maxAt = i;
            }
            if (arr[i] < minVal)
            {
                minVal = arr[i];
                out.minAt = i;
            }
        }
        return out;
    }

    int binaryInsertionSearch(T tgt, int e)
    {
        unsigned int s = 0;
        unsigned int mid;

        while (s <= e)
        {
            mid = s + (e - s) / 2;

            if (s == e)
            {
                if (arr[mid] < tgt)
                    // If tgt is greater than min, add to the right - that's the optimum position
                    return mid + 1;
                return mid;
            }

            if (arr[mid] == tgt)
                return mid;

            if (arr[mid] < tgt)
                // Move right
                s = mid + 1;
            else
                // Move left
                e = mid - 1;
        }

        return mid;
    }

    void merge(int s, int m, int e)
    {
        unsigned int i = s, j = m, k = 0;

        T tmp[e - s];

        while (i < m && j <= e)
        {
            if (arr[i] < arr[j])
            {
                tmp[k] = arr[i];
                i++;
            }
            else
            {
                tmp[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i < m)
        {
            tmp[k] = arr[i];
            i++;
            k++;
        }

        while (j <= e)
        {
            tmp[k] = arr[j];
            j++;
            k++;
        }

        k = 0;
        for (int i = s; i <= e; i++)
        {
            arr[i] = tmp[k];
            k++;
        }
    }

    void merge2(int s, int m, int x)
    {
        unsigned int i = s, j = m, e = -1, ec = 0;

        while (i <= m && j <= x)
        {
            if (arr[j] < arr[i])
            {
                if (e == -1)
                {
                    swap(i, j);
                    // Extra is at j
                    e = j;
                    j++;
                    ec++;
                }
                else
                {
                    swap(i, j);
                    ec++;
                    j++;
                    if (arr[e] < arr[i])
                    {
                        m = e + ec - 1;
                        merge2(i, e, m);
                        e = -1;
                        ec = 0;
                    }
                }
            }
            else if (e != -1 && arr[e] < arr[i])
            {
                m = e + ec - 1;
                merge2(i, e, m);
                e = -1;
                ec = 0;
            }
            i++;
        }
    }

    int findPivot(int s, int e)
    {
        int p = e - 1;

        int i = s - 1;
        int j = s;

        while (j < p)
        {
            if (arr[j] < arr[p])
            {
                i++;
                swap(i, j);
            }
            j++;
        }

        i++;
        swap(i, p);
        return i;
    }

    void sortQuick(int s, int e)
    {
        if (s < e)
        {
            int p = findPivot(s, e);
            sortQuick(s, p);
            sortQuick(p + 1, e);
        }
    }

public:
    arraylist()
    {
        arr = (T *)malloc(size * sizeof(T));
    }

    ~arraylist()
    {
        free(arr);
    }

    int push_back(std::initializer_list<T> vals)
    {
        if (vals.size() == 0)
            return -1;

        for (T val : vals)
        {
            this->push_back(val);
        }
        return 0;
    }

    void push_back(T val)
    {
        if (len == (size - 1))
        {
            size = (multiplier * size);

            /* Realloc */
            arr = (T *)realloc(arr, size * sizeof(int));

            /* Manual copy */
            // int *arr2 = (T *)malloc(size * sizeof(T));
            // for (int i = 0; i <= len; i++)
            // {
            //     arr2[i] = arr[i];
            // }
            // free(arr);
            // arr = arr2;
        }
        len++;
        arr[len] = val;
    }

    void bubbleSort()
    {
        bool swapped;
        for (int i = 0; i <= len; i++)
        {
            swapped = false;
            for (int j = 0; j < len - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swapped = true;
                    swap(j, j + 1);
                }
            }
            if (!swapped)
                return;
            print();
        }
    }

    void binaryInsertionSort()
    {
        for (int i = 1; i < len; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                if (arr[i + 1] < arr[0])
                    rotateRight(0, i + 1);
                else
                {
                    rotateRight(binaryInsertionSearch(arr[i + 1], i), i + 1);
                }
            }
        }
    }

    void insertionSort()
    {
        for (int i = 1; i < len; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                int j = 0;
                // Process new element
                while (j <= i)
                {
                    if (arr[j] >= arr[i + 1])
                    {
                        rotateRight(j, i + 1);
                    }
                    j++;
                }
            }
            print();
        }
    }

    void selectionSort()
    {
        for (int i = 0; i < len; i++)
        {
            int minAt = findMinInRange(i + 1, len);
            if (arr[minAt] < arr[i])
                swap(i, minAt);
            print();
        }
    }

    void quickSort()
    {
        sortQuick(0, len + 1);
    }

    void countSort(int top)
    {
        int range[top + 1];
        memset(range, 0, sizeof(range));

        for (int i = 0; i <= len; i++)
            range[arr[i]]++;

        int k = -1;
        for (int i = 0; i <= top; i++)
        {
            if (range[i] != 0)
            {
                for (int j = 0; j < range[i]; j++)
                {
                    k++;
                    arr[k] = i;
                }
            }
        }
    }

    void twoPointerSelectionSort()
    {
        int l = len / 2;
        for (int i = 0; i <= l; i++)
        {
            minMaxAt pos = findMinMax(i + 1, len - i);
            if (pos.minAt == pos.maxAt)
                return;
            if (arr[pos.minAt] < arr[i])
                swap(i, pos.minAt);
            else
                swap(len - i, pos.maxAt);
            print();
        }
    }

    void mergeSort(int s, int e)
    {
        if (s < e)
        {
            unsigned int m = s + ((e - s) / 2);
            mergeSort(s, m);
            mergeSort(m + 1, e);

            merge2(s, m + 1, e);
        }
    }

    int linearSearch(T tgt)
    {
        for (int i = 0; i <= len; i++)
        {
            if (arr[i] == tgt)
                return i;
        }
        return -1;
    }

    int twoPointerLinearSearch(T tgt)
    {
        int backCheck;
        for (int i = 0; i <= len / 2; i++)
        {
            if (arr[i] == tgt)
                return i;

            backCheck = len - i;
            if (arr[backCheck] == tgt)
                return backCheck;
        }
        return -1;
    }

    int twoPointerTranspositionLinearSearch(T tgt)
    {
        int backCheck;
        for (int i = 0; i <= len / 2; i++)
        {
            if (arr[i] == tgt)
            {
                if (i != 0)
                {
                    swap(i, i - 1);
                    i--;
                }
                return i;
            }

            backCheck = len - i;
            if (arr[backCheck] == tgt)
            {
                if (backCheck != len)
                {
                    swap(backCheck, backCheck + 1);
                }
                return backCheck--;
            }
        }
        return -1;
    }

    int transpositionLinearSearch(T tgt)
    {
        for (int i = 0; i <= len; i++)
        {
            if (arr[i] == tgt)
            {
                if (i != 0)
                {
                    swap(i, i - 1);
                    i--;
                }
                return i;
            }
        }
        return -1;
    }

    int binarySearch(T tgt)
    {
        // unsigned int improves performance
        unsigned int s = 0;
        unsigned int e = len;
        unsigned int mid;
        while (s <= e)
        {
            mid = s + (e - s) / 2;

            if (arr[mid] == tgt)
                return mid;

            // Move right
            if (arr[mid] < tgt)
                s = mid + 1;
            else
                // Move left
                e = mid - 1;
        }
        return -1;
    }

    int binarySearch(T tgt, unsigned int s, unsigned int e)
    {
        if (s <= e)
        {
            unsigned int mid = s + (e - s) / 2;
            if (arr[mid] == tgt)
                return mid;
            if (arr[mid] < tgt)
                return binarySearch(tgt, mid + 1, e);
            else
                return binarySearch(tgt, s, mid - 1);
        }
        else
            return -1;
    }

    int remove(T tgt)
    {

        if (int i = twoPointerLinearSearch(tgt); i != -1)
        {
            // Shift
            for (int j = i; j < len; j++)
            {
                arr[j] = arr[j + 1];
            }

            len--;

            // Resize
            int redSz = size / multiplier;
            if (size > minSize && len < redSz)
            {
                size = redSz;

                /* Realloc */
                arr = (T *)realloc(arr, size * sizeof(int));

                /* Manual Move */
                // int *arr2 = (T *)malloc(size * sizeof(T));
                // for (int i = 0; i <= len; i++)
                // {
                //     arr2[i] = arr[i];
                // }
                // free(arr);
                // arr = arr2;
            }

            std::cout << size << std::endl;

            return 0;
        }

        return -1;
    }

    void print()
    {
        if (len < 0)
            return;
        for (int i = 0; i <= len; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    unsigned int getLen()
    {
        return len;
    }

    int get(int index)
    {
        if (index > len || index < 0)
        {
            return -1;
        }
        return arr[index];
    }
};
