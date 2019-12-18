//二叉堆
//顺序储存
//最小堆

#include <iostream>

using namespace std;

class BinaryHeap
{
    public:
        //上浮节点，用于插入
        void upAdjust(int *array, int len)
        {
            int childIndex = len - 1;
            int parentIndex = (childIndex - 1) / 2;
            int tmp = array[childIndex];

            

            while (array[parentIndex] > tmp && childIndex > 0)
            {
                array[childIndex] = array[parentIndex];
                childIndex = parentIndex;
                parentIndex = (childIndex - 1) / 2;
            }
            array[childIndex] = tmp;
        }

        //下沉节点
        void downAdjust(int *array, int index, int len)
        {
            int tmp = array[index];
            //左孩子节点序号
            int childrenIndex = index * 2 + 1;
            int parentIndex = index;
            while (childrenIndex < len)
            {
                //判断哪个孩子更小
                if (childrenIndex + 1 < len && array[childrenIndex + 1] < array[childrenIndex])
                {
                    childrenIndex++;
                }

                if (array[childrenIndex] < tmp)
                {
                    array[parentIndex] = array[childrenIndex];
                    parentIndex = childrenIndex;
                    childrenIndex = 2 * parentIndex + 1;
                }
                else
                {
                    break;
                }
            }
            array[parentIndex] = tmp;
        }

        //构建最小堆
        void buildHeap(int *array, int len)
        {
            //从最后一个非叶子节点开始，依次下沉
            for (int i = len / 2; i >= 0; i--)
            {
                downAdjust(array, i, len);
            }
        }
};

int main()
{
    BinaryHeap binary_heap;
    
    int array1[] = {1, 3, 2, 6, 5, 7, 8, 9, 10, 0};
    
    binary_heap.upAdjust(array1, sizeof(array1) / sizeof(array1[0]));
    for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;

    int array2[9] = {7, 1, 3, 10, 5, 2, 8, 9, 6};
    binary_heap.buildHeap(array2, sizeof(array2) / sizeof(array2[0]));
    for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); i++)
    {
        cout << array2[i] << " ";
    }
    cout << endl;

}
