class Shape {
public:
    virtual ~Shape() {}
    virtual Shape* clone() const = 0;
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    Shape* clone() const override {
        Shape* rect = new Rectangle(width , height);
        return rect;
    }
};

class Square : public Shape {
private:
    int length;

public:
    Square(int l) : length(l) {}

    int getLength() const {
        return length;
    }

    Shape* clone() const override {
        Shape* square = new Square(length);
        return square;
    }
};

class Test {
public:
    vector<Shape*> cloneShapes(const vector<Shape*>& shapes) {
        vector < Shape*> ans;
        for(auto ele : shapes){
            ans.push_back(ele->clone());
        }
        return ans;
    }
};
