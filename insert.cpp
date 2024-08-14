#include <iostream>
#include <string>
using namespace std;

class Division
{
    int roll;
    float s;
    string name;

public:
    void insertionSort(float sgpa[], string name[], int roll[], int n)
    {
        for (int i = 1; i < n; ++i)
        {
            float sgpaKey = sgpa[i];
            string nameKey = name[i];
            int rollKey = roll[i];
            int j = i - 1;

            while (j >= 0 && sgpa[j] > sgpaKey)
            {
                sgpa[j + 1] = sgpa[j];
                name[j + 1] = name[j];
                roll[j + 1] = roll[j];
                j = j - 1;
            }
            sgpa[j + 1] = sgpaKey;
            name[j + 1] = nameKey;
            roll[j + 1] = rollKey;
        }
    }

    void shellSort(string name[], int roll[], float sgpa[], int n)
    {
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                string tempName = name[i];
                int tempRoll = roll[i];
                float tempSGPA = sgpa[i];
                int j;
                for (j = i; j >= gap && name[j - gap] > tempName; j -= gap)
                {
                    name[j] = name[j - gap];
                    roll[j] = roll[j - gap];
                    sgpa[j] = sgpa[j - gap];
                }
                name[j] = tempName;
                roll[j] = tempRoll;
                sgpa[j] = tempSGPA;
            }
        }
    }

    void countingSort(int roll[], string name[], float sgpa[], int n, int div)
    {
        int outputRoll[n];
        string outputName[n];
        float outputSGPA[n];
        int count[10] = {0};

        for (int i = 0; i < n; i++)
        {
            count[(roll[i] / div) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int index = (roll[i] / div) % 10;
            outputRoll[count[index] - 1] = roll[i];
            outputName[count[index] - 1] = name[i];
            outputSGPA[count[index] - 1] = sgpa[i];
            count[index]--;
        }

        for (int i = 0; i < n; i++)
        {
            roll[i] = outputRoll[i];
            name[i] = outputName[i];
            sgpa[i] = outputSGPA[i];
        }
    }

    void radixSort(int roll[], string name[], float sgpa[], int n)
    {
        int max = getMAX(roll, n);
        for (int div = 1; max / div > 0; div *= 10)
        {
            countingSort(roll, name, sgpa, n, div);
        }
    }

    int getMAX(int a[], int n)
    {
        int max = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
            }
        }
        return max;
    }

    void printARRAY(int roll[], string name[], float sgpa[], int n)
    {
        cout << "Roll Number\tName\t\tSGPA\n";
        cout << "------------------------------------\n";
        for (int i = 0; i < n; i++)
        {
            cout << roll[i] << "\t\t" << name[i] << "\t\t" << sgpa[i] << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    string name[n];
    float sgpa[n];
    int roll[n];
    int j;

    Division d;
    int m = 1;
    do
    {
        cout << "Enter 1 to input data, 2 to sort by roll number, 3 to sort alphabetically, and 4 to sort by SGPA: ";
        cin >> j;
        switch (j)
        {
        case 1:
            cout << "Enter the details of students in the following format:\n";
            cout << "Name RollNumber SGPA\n";
            for (int i = 0; i < n; i++)
            {
                cin >> name[i] >> roll[i] >> sgpa[i];
            }
            break;

        case 2:
            d.radixSort(roll, name, sgpa, n);
            d.printARRAY(roll, name, sgpa, n);
            break;

        case 3:
            d.shellSort(name, roll, sgpa, n);
            d.printARRAY(roll, name, sgpa, n);
            break;

        case 4:
            d.insertionSort(sgpa, name, roll, n);
            d.printARRAY(roll, name, sgpa, n);
            break;
        }
        cout << "Do you want to continue (1 or 0)? ";
        cin >> m;
    } while (m == 1);

    return 0;
}
