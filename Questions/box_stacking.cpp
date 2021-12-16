#include <vector>
#include <algorithm>
using namespace std;

struct Box
{
    int height;
    int width;
    int length;
    Box(int h, int w, int l)
    {
        height = h;
        width = w;
        length = l;
    }
};

int maxHeight(int height[], int width[], int length[], int n)
{

    vector<Box> boxes;
    for (int i = 0; i < n; i++)
    {

        int a = height[i];
        int b = width[i];
        int c = length[i];

        // height, width, length  --  generall kept width < length for ease
        struct Box b1 = Box(a, min(b, c), max(b, c));
        struct Box b2 = Box(b, min(a, c), max(a, c));
        struct Box b3 = Box(c, min(a, b), max(a, b));

        boxes.push_back(b1);
        boxes.push_back(b2);
        boxes.push_back(b3);
    }
    n = 3 * n;

    sort(boxes.begin(), boxes.end(), [](const Box &a, const Box &b)
         { return a.length * a.width > b.length * b.width; });

    vector<int> maxHeight;
    for (int i = 0; i < n; i++)
    {
        maxHeight.push_back(boxes[i].height);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (boxes[i].width < boxes[j].width && boxes[i].length < boxes[j].width)
            {
                if (maxHeight[i] < maxHeight[j] + boxes[i].height)
                {
                    maxHeight[i] = maxHeight[j] + boxes[i].height;
                }
            }
        }
    }

    return *max_element(maxHeight.begin(), maxHeight.end());
}