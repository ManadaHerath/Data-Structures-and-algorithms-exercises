void nonrecquicksort(vector<int>& array, int n){
    stack<int> stk;
    int l = 0, r = n - 1;
    stk.push(l);
    stk.push(r);

    while (!stk.empty())
    {
        r = stk.top();

        stk.pop();

        l = stk.top();

        stk.pop();

        int i = l;
        int j = r;
        int key = array[(l + r) / 2];

        while (i <= j)
        {
            while (array[i] < key)
                i++;
            while (array[j] > key)
                j--;
            if (i <= j)
            {
                swap(array[i], array[j]);
                i++;
                j--;
            }
        }

        if (l < j){
            stk.push(l);
            stk.push(j);
        }
        if (i < r){
            stk.push(i);
            stk.push(r);
        }
    }
}