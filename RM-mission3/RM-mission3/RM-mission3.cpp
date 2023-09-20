// RM-mission2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//百思不得其解：Mat&重载运算符为什么非得加引用？this
//using this when +or- nor youwill get wrong answer with creating a new natrix andreturn it.WWWHHHYYY???
//矩阵拷贝构造！！！

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Mat
{
private:
    int width;
    int length;
    int* pmat;
public:
    Mat();
    Mat(int wid, int len);
    ~Mat();
    Mat(const Mat& b)
    {
        this->length = b.length;
        this->width = b.width;
        this->pmat = new int[width * length];
        for (int i = 0; i < width * length; i++)
            this->pmat[i] = b.pmat[i];
        cout << "This matrix has been successfully created.(Copied)\n";
    }
    bool is_same(const Mat& b)
    {
        return (b.length == this->length) && (b.width == this->width);
    }
    Mat operator+(const Mat& b)
    {
        if (this->is_same(b))
        {
            Mat mat(this->width, this->length);
            for (int i = 0; i < width * length; i++)
                mat.pmat[i] = this->pmat[i] + b.pmat[i];
            return mat;
        }
        else
        {
            cout << "ERROR:Not the same type matrix.\n";
            return *this;
        }
    }
    Mat& operator=(const Mat& b)
    {
        if (this != &b)
        {
            if (this->is_same(b))
            {
                for (int i = 0; i < width * length; i++)
                    this->pmat[i] = b.pmat[i];
            }
            else
            {
                cout << "ERROR:Not the same type matrix.\n";
            }
        }
        return *this;
    }
    Mat operator-(const Mat& b)
    {
        if (this->is_same(b))
        {
            Mat mat(this->width, this->length);
            for (int i = 0; i < width * length; i++)
                mat.pmat[i] = this->pmat[i] - b.pmat[i];
            return mat;
        }
        else
        {
            cout << "ERROR:Not the same type matrix.\n";
            return *this;
        }

    }
    Mat operator*(const Mat& b)
    {
        if (this->length == b.width)
        {
            int temp = 0;
            Mat mat(this->width, b.length);
            for (int i = 0; i < this->width; i++)
                for (int j = 0; j < b.length; j++)
                {
                    temp = 0;
                    for (int k = 1; k <= this->length; k++)
                        temp += this->pmat[i * this->length + k - 1] * b.pmat[(k - 1) * b.length + j];
                    mat.pmat[i * b.length + j] = temp;
                }
            return mat;
        }
        else
        {
            cout << "illegal matrix multiplication.\n";
            return *this;
        }
    }
    void output()
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < length; j++)
                cout << pmat[i * length + j] << " ";
            cout << endl;
        }
    }
    void RandomAssign()
    {
        for (int i = 0; i < width * length; i++)
            pmat[i] = rand() % 100;
    }
    void setvalue(int i, int j, int value)
    {
        if ((1 <= i) && (i <= width) && (1 <= j) && (j <= length))
            this->pmat[(i - 1) * length + j - 1] = value;
        else
            cout << "Error:illegal input for assignment.\n";
    }
};

Mat::Mat()
{
    length = 0;
    width = 0;
    pmat = NULL;
}

Mat::Mat(int wid, int len)
{
    length = len;
    width = wid;
    pmat = new int[wid * len];
    cout << "This matrix has been successfully created." << endl;
}

Mat::~Mat()
{
    if (pmat != NULL)
        delete[] pmat;
    cout << "This matrix has been successfully deleted." << endl;
}



int main()
{
    srand(time(NULL));
    Mat mat1(6, 2);
    Mat mat2(2, 6);
    Mat mat3(6, 6);
    mat1.RandomAssign();
    mat2.RandomAssign();
    //mat1.setvalue(1, 2, 0);
    mat1.output();
    mat2.output();

    mat3 = mat1 * mat2;
    mat3.output();
    mat1.output();

    return 0;
}
