//#251. Flatten 2D Vector
//Medium
//Method: two indexs
//Complexity: Time O(N); Space O(1)

class Vector2D {
private:
    int outer;
    int inner;
    vector<vector<int> > data;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        outer = 0;
        inner = 0;
        data = vec2d;
    }

    int next() {
        int& tmp = data[outer][inner];
        inner++;
        return tmp;
    }

    bool hasNext() {
        while (outer != data.size() && inner == data[outer].size()) {
            inner = 0;
            outer++;
        }
        return (outer != data.size());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */