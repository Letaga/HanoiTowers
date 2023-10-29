#include <iostream>

using namespace std;

int Enter();
void HanoiTower(int disk, int from, int to, int buf);


int main()
{
    int disk, from, to, buf;
    cout << "Enter number of disks\n";
    cin >> disk;
    cout << "Enter the first tower of 3\n";
    from = Enter();
    cout << "Enter the end tower of 3\n";
    to = Enter();
    if (from == to)
    {
        cout << "Moving is not required";
        return 0;
    }

    if (((from == 1) && (to == 2)) || ((from == 2) && (to == 1)))
        buf = 3;
    else if (((from == 1) && (to == 3)) || ((from == 3) && (to == 1)))
        buf = 2;
    else
        buf = 1;

    if (disk % 2 == 0)
        cout << "First move to " << buf << endl;
    else
        cout << "First move to " << to << endl;

    cout << "The order of moving disks\nfrom -> to\n";
    HanoiTower(disk, from, to, buf);

    cout << "f t b " << from << to << buf;
        
}
int Enter()
{
    int x;
    cin >> x;
    if ((x > 0) && (x <= 3))
        return x;
    else
    {
        cout << "Error, enter another number\n";
        Enter();
    }
}

void HanoiTower(int disk, int from, int to, int buf)
{
	if (disk != 0)
	{
        HanoiTower(disk - 1, from, buf, to);

		cout << from << " -> " << to << endl;

        HanoiTower(disk - 1, buf, to, from);
	}
}
